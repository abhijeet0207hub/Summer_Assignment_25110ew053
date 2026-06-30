#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

const int MAX_ACCOUNTS    = 50;
const int MAX_TXNS        = 10;   
const double MIN_BALANCE  = 500.0;


struct Account {
    int accNo;
    string holderName;
    string pin;                  
    double balance;
    string type;                 
    string history[MAX_TXNS];    
    int txnCount;
};

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;
int nextAccNo = 1001;           


string trim(const string &s) {
    size_t start = s.find_first_not_of(" \t\n\r");
    if (start == string::npos) return "";
    size_t end = s.find_last_not_of(" \t\n\r");
    return s.substr(start, end - start + 1);
}

string toLower(const string &s) {
    string r = s;
    transform(r.begin(), r.end(), r.begin(),
              [](unsigned char c) { return tolower(c); });
    return r;
}

string toTitleCase(const string &s) {
    string r = toLower(s);
    bool newWord = true;
    for (char &c : r) {
        if (isspace(static_cast<unsigned char>(c))) newWord = true;
        else if (newWord) { c = toupper(static_cast<unsigned char>(c)); newWord = false; }
    }
    return r;
}


bool isValidPin(const string &pin) {
    if (pin.length() != 4) return false;
    for (char c : pin)
        if (!isdigit(static_cast<unsigned char>(c))) return false;
    return true;
}

string maskAccountNo(int accNo) {
    string s = to_string(accNo);
    if (s.length() <= 4) return s;
    return string(s.length() - 4, '*') + s.substr(s.length() - 4);
}


// Find index of account by account number
int findByAccNo(int accNo) {
    for (int i = 0; i < accountCount; i++)
        if (accounts[i].accNo == accNo) return i;
    return -1;
}

// Find index of account by holder name 
int findByName(const string &query) {
    string q = toLower(trim(query));
    for (int i = 0; i < accountCount; i++)
        if (toLower(accounts[i].holderName).find(q) != string::npos)
            return i;
    return -1;
}



void logTransaction(Account &acc, const string &entry) {
    if (acc.txnCount < MAX_TXNS) {
        acc.history[acc.txnCount++] = entry;
    } else {
        for (int i = 0; i < MAX_TXNS - 1; i++)
            acc.history[i] = acc.history[i + 1];
        acc.history[MAX_TXNS - 1] = entry;
    }
}

// Open a new account
void openAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        cout << "Account database full. Cannot open more accounts.\n";
        return;
    }

    Account a;
    a.accNo = nextAccNo++;

    cout << "Enter account holder's full name: ";
    cin.ignore();
    string rawName;
    getline(cin, rawName);
    a.holderName = toTitleCase(trim(rawName));

    string pin;
    do {
        cout << "Set a 4-digit PIN: ";
        cin >> pin;
        if (!isValidPin(pin)) cout << "PIN must be exactly 4 digits.\n";
    } while (!isValidPin(pin));
    a.pin = pin;

    int typeChoice;
    cout << "Account type - 1) Savings  2) Current: ";
    cin >> typeChoice;
    a.type = (typeChoice == 2) ? "Current" : "Savings";

    cout << "Enter initial deposit (min " << MIN_BALANCE << "): ";
    double deposit;
    cin >> deposit;
    if (deposit < MIN_BALANCE) {
        cout << "Initial deposit must be at least " << MIN_BALANCE
             << ". Account not created.\n";
        return;
    }
    a.balance = deposit;
    a.txnCount = 0;

    logTransaction(a, "Account opened with deposit Rs." + to_string((int)deposit));

    accounts[accountCount++] = a;
    cout << "Account created successfully! Account No: " << a.accNo << "\n";
}

// Verify a PIN for a given account
bool verifyPin(int idx) {
    string entered;
    cout << "Enter PIN: ";
    cin >> entered;
    if (entered != accounts[idx].pin) {
        cout << "Incorrect PIN.\n";
        return false;
    }
    return true;
}

// Deposit money into an account
void deposit() {
    cout << "Enter account number: ";
    int accNo; cin >> accNo;
    int idx = findByAccNo(accNo);
    if (idx == -1) { cout << "Account not found.\n"; return; }

    cout << "Enter amount to deposit: ";
    double amt; cin >> amt;
    if (amt <= 0) { cout << "Amount must be positive.\n"; return; }

    accounts[idx].balance += amt;
    logTransaction(accounts[idx], "Deposited Rs." + to_string((int)amt));
    cout << "Deposit successful. New balance: " << fixed << setprecision(2)
         << accounts[idx].balance << "\n";
}

// Withdraw money from an account (with PIN check )
void withdraw() {
    cout << "Enter account number: ";
    int accNo; cin >> accNo;
    int idx = findByAccNo(accNo);
    if (idx == -1) { cout << "Account not found.\n"; return; }

    if (!verifyPin(idx)) return;

    cout << "Enter amount to withdraw: ";
    double amt; cin >> amt;
    if (amt <= 0) { cout << "Amount must be positive.\n"; return; }

    if (accounts[idx].balance - amt < MIN_BALANCE) {
        cout << "Withdrawal denied: balance cannot drop below Rs." << MIN_BALANCE << "\n";
        return;
    }

    accounts[idx].balance -= amt;
    logTransaction(accounts[idx], "Withdrew Rs." + to_string((int)amt));
    cout << "Withdrawal successful. New balance: " << fixed << setprecision(2)
         << accounts[idx].balance << "\n";
}

// Transfer money between two accounts
void transfer() {
    cout << "Enter sender's account number: ";
    int fromAcc; cin >> fromAcc;
    int fromIdx = findByAccNo(fromAcc);
    if (fromIdx == -1) { cout << "Sender account not found.\n"; return; }

    if (!verifyPin(fromIdx)) return;

    cout << "Enter receiver's account number: ";
    int toAcc; cin >> toAcc;
    int toIdx = findByAccNo(toAcc);
    if (toIdx == -1) { cout << "Receiver account not found.\n"; return; }
    if (toIdx == fromIdx) { cout << "Cannot transfer to the same account.\n"; return; }

    cout << "Enter amount to transfer: ";
    double amt; cin >> amt;
    if (amt <= 0) { cout << "Amount must be positive.\n"; return; }

    if (accounts[fromIdx].balance - amt < MIN_BALANCE) {
        cout << "Transfer denied: sender balance cannot drop below Rs." << MIN_BALANCE << "\n";
        return;
    }

    accounts[fromIdx].balance -= amt;
    accounts[toIdx].balance   += amt;

    logTransaction(accounts[fromIdx], "Transferred Rs." + to_string((int)amt) +
                                       " to A/C " + to_string(toAcc));
    logTransaction(accounts[toIdx], "Received Rs." + to_string((int)amt) +
                                     " from A/C " + to_string(fromAcc));

    cout << "Transfer successful.\n";
}

// Print one account summary line
void printAccountRow(const Account &a) {
    cout << left << setw(10) << a.accNo
         << setw(20) << a.holderName
         << setw(10) << a.type
         << right << setw(12) << fixed << setprecision(2) << a.balance << "\n";
}

// Display all accounts
void displayAll() {
    if (accountCount == 0) { cout << "No accounts to display.\n"; return; }

    cout << "\n" << left << setw(10) << "Acc No" << setw(20) << "Holder"
         << setw(10) << "Type" << right << setw(12) << "Balance" << "\n";
    cout << string(52, '-') << "\n";
    for (int i = 0; i < accountCount; i++)
        printAccountRow(accounts[i]);
    cout << "\n";
}

// Show full mini-statement for one account
void showStatement() {
    cout << "Enter account number: ";
    int accNo; cin >> accNo;
    int idx = findByAccNo(accNo);
    if (idx == -1) { cout << "Account not found.\n"; return; }

    const Account &a = accounts[idx];
    cout << "\nStatement for A/C " << a.accNo << " (" << maskAccountNo(a.accNo)
         << ") - " << a.holderName << "\n";
    cout << "Current balance: " << fixed << setprecision(2) << a.balance << "\n";
    cout << string(45, '-') << "\n";
    if (a.txnCount == 0) {
        cout << "No transactions yet.\n";
    } else {
        for (int i = 0; i < a.txnCount; i++)
            cout << (i + 1) << ". " << a.history[i] << "\n";
    }
    cout << "\n";
}

// Search by name or account number
void searchAccount() {
    cout << "Search by - 1) Account Number  2) Holder Name: ";
    int choice; cin >> choice;
    int idx = -1;

    if (choice == 1) {
        cout << "Enter account number: ";
        int accNo; cin >> accNo;
        idx = findByAccNo(accNo);
    } else {
        cout << "Enter name (or part of it): ";
        cin.ignore();
        string name; getline(cin, name);
        idx = findByName(name);
    }

    if (idx == -1) { cout << "No matching account found.\n"; return; }
    cout << "\nAccount found:\n";
    printAccountRow(accounts[idx]);
}

// Close an account
void closeAccount() {
    cout << "Enter account number to close: ";
    int accNo; cin >> accNo;
    int idx = findByAccNo(accNo);
    if (idx == -1) { cout << "Account not found.\n"; return; }

    if (!verifyPin(idx)) return;

    cout << "Closing account will withdraw remaining balance of "
         << fixed << setprecision(2) << accounts[idx].balance << ". Confirm? (y/n): ";
    char confirm; cin >> confirm;
    if (tolower(confirm) != 'y') { cout << "Closure cancelled.\n"; return; }

    for (int i = idx; i < accountCount - 1; i++)
        accounts[i] = accounts[i + 1];
    accountCount--;

    cout << "Account closed successfully.\n";
}


void showBankStats() {
    if (accountCount == 0) { cout << "No accounts available.\n"; return; }

    double total = 0, highest = accounts[0].balance, lowest = accounts[0].balance;
    int savingsCount = 0, currentCount = 0;

    for (int i = 0; i < accountCount; i++) {
        total += accounts[i].balance;
        highest = max(highest, accounts[i].balance);
        lowest  = min(lowest, accounts[i].balance);
        if (accounts[i].type == "Savings") savingsCount++; else currentCount++;
    }

    cout << fixed << setprecision(2);
    cout << "\nBank Statistics:\n";
    cout << "  Total accounts   : " << accountCount
         << " (Savings: " << savingsCount << ", Current: " << currentCount << ")\n";
    cout << "  Total deposits   : Rs." << total << "\n";
    cout << "  Average balance  : Rs." << (total / accountCount) << "\n";
    cout << "  Highest balance  : Rs." << highest << "\n";
    cout << "  Lowest balance   : Rs." << lowest << "\n";
}

// sample
void loadSampleData() {
    struct Seed { string name; string pin; string type; double deposit; };
    Seed seeds[] = {
        {"Ashish",  "1111", "Savings", 5000},
        {"Rohit", "2222", "Current", 15000},
        {"Priya ",  "3333", "Savings", 8200},
    };
    for (auto &s : seeds) {
        if (accountCount >= MAX_ACCOUNTS) break;
        Account a;
        a.accNo = nextAccNo++;
        a.holderName = s.name;
        a.pin = s.pin;
        a.type = s.type;
        a.balance = s.deposit;
        a.txnCount = 0;
        logTransaction(a, "Account opened with deposit Rs." + to_string((int)s.deposit));
        accounts[accountCount++] = a;
    }
    cout << "Sample accounts loaded. (PINs: 1111, 2222, 3333)\n";
}

void printMenu() {
    cout << "\n============ Bank Account Management ============\n";
    cout << "1. Open New Account\n";
    cout << "2. Deposit\n";
    cout << "3. Withdraw\n";
    cout << "4. Transfer Funds\n";
    cout << "5. Display All Accounts\n";
    cout << "6. Search Account\n";
    cout << "7. View Mini Statement\n";
    cout << "8. Close Account\n";
    cout << "9. Bank Statistics\n";
    cout << "10. Load Sample Data\n";
    cout << "0. Exit\n";
    cout << "===================================================\n";
    cout << "Enter choice: ";
}

int main() {
    int choice;

    do {
        printMenu();
        cin >> choice;

        switch (choice) {
            case 1:  openAccount();    break;
            case 2:  deposit();        break;
            case 3:  withdraw();       break;
            case 4:  transfer();       break;
            case 5:  displayAll();     break;
            case 6:  searchAccount();  break;
            case 7:  showStatement();  break;
            case 8:  closeAccount();   break;
            case 9:  showBankStats();  break;
            case 10: loadSampleData(); break;
            case 0:  cout << "Thank you for banking with us. Goodbye!\n"; break;
            default: cout << "Invalid choice, try again.\n";
        }
    } while (choice != 0);

    return 0;
}
