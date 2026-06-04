#include <iostream>
using namespace std ;
int main()
{
    int n,i;
    int t1=0;
    int t2=1;
    cout<< "emter the number of digits ";
    cin>> n;
    for ( i = 1; i <= n; i++)
    {
        cout<< t1<<" ";
    int nextterm= t1+t2;
    t1=t2;
    t2=nextterm;
    }
    return 0;

}