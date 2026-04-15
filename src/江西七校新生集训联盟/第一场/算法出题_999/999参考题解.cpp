#include<iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        string str;
        cin>>str;
        int r=0;
        for (int i=0;i<str.size();i++)r=(r+(str[i]-'0'))%9;
        if (r)cout<<0<<endl;
        else cout<<1<<endl;
    }
    return 0;
}