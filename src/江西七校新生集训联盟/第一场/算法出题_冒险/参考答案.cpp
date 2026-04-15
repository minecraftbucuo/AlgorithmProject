#include<bits/stdc++.h>
using namespace std;


int main()
{
    int T;cin>>T;
    while (T--)
    {
        int n,m;cin>>n>>m;
        if (m<n||m==n+1)cout<<"QAQ"<<endl;
        else
        {
            int d=m-n;
            int ans;
            if (d%3==0)ans=d/3;
            else ans=d/3+1;
            cout<<ans<<endl;
        }
    }
    return 0;
}