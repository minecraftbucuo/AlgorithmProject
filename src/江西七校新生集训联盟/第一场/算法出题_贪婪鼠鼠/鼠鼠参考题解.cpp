#include<iostream>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        int n,m;cin>>n>>m;
        if (n&1)cout<<"1.00"<<endl;
        else cout<<"0.00"<<endl;
    }
    return 0;
}