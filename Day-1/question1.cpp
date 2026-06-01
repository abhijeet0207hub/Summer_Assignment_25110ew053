#include<iostream>
using namespace std;

int main() {
    int n,sum=0, i=0;

    cout << "enter a positive integer: ";
    cin>> n;
while (i<=n)
{
sum+=i;
  i++;  
}
cout<<"the sum of first "<< n <<" natural number is:" << sum <<endl;
return 0;
}