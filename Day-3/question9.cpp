#include<iostream>
using namespace std;
int main()
{
    bool result=true;
    int n,i=2;
    cout<<"enter the number to be checked: ";
    cin>>n;
     if (n<=1)
     {
        result=false ;
     }              // numbers less than or equal t0 1 are not prime
     while (i<=n/2)
     {
    
        if ( n%i==0 )
        {
            result=false;
        break;
        }
      i++  ;
     }
     
     if ( result==false )
     {
        cout<<"the number is not prime";
     }
     else
     {
        cout<<"the number is prime";
     }
     
     return 0;
}