#include <iostream>
using namespace std;
int main()
{
    int i=0,a,n;
    cout<< "enter the no.";
    cin>> n;
    while (a>=0)
    {
        a=n/10;
        ++i;
    }
   cout<< "the no. of digits in the number "<< n <<" is :"<< i;
}