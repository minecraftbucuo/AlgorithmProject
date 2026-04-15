
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
#define int long long

mt19937_64 r(time(0));


signed main()
{
//	for(int ti=1;ti<=4;ti++)
//	{
//		string fin=to_string(ti)+".in";
//		string fout=to_string(ti)+".out";
//		
//		ofstream of(fin,ios::out);
//		
//		of<<N<<' '<<N<<' '<<endl;
//		uniform_int_distribution dist(0ll,1ll<<4);
//		for(int i=1;i<=N;i++)of<<dist(r)<<' ';
//		of<<endl;
//		
//		uniform_int_distribution qu1(1,N);
//		uniform_int_distribution qu2(1,50);
//		
//		for(int i=1;i<=N;i++)
//		{
//			int L,R;
//			if(i<=N/2)L=qu1(r),R=qu1(r);
//			else L=qu2(r),R=qu2(r);
//			if(L>R)swap(L,R);
//			of<<L<<' '<<R<<endl;
//		}
//	}
//	for(int ti=5;ti<=10;ti++)
//	{
//		string fin=to_string(ti)+".in";
//		string fout=to_string(ti)+".out";
//		
//		ofstream of(fin,ios::out);
//		
//		of<<N<<' '<<N<<' '<<endl;
//		uniform_int_distribution dist(0ll,(1ll<<32)-1);
//		for(int i=1;i<=N;i++)of<<dist(r)<<' ';
//		of<<endl;
//		
//		uniform_int_distribution qu1(1,N);
//		uniform_int_distribution qu2(10342,12412);
//		
//		for(int i=1;i<=N;i++)
//		{
//			int L,R;
//			if(i<=N/2)L=qu1(r),R=qu1(r);
//			else L=qu2(r),R=qu2(r);
//			if(L>R)swap(L,R);
//			of<<L<<' '<<R<<endl;
//		}
//	}
//	for(int ti=1;ti<=11;ti++)
//	{
//		string fin=to_string(ti)+".in";
//		string fout=to_string(ti)+".out";
//		ofstream of(fout,ios::out);
//	}
	
//		for(int ti=13;ti<=15;ti++)
//	{
//		string fin=to_string(ti)+".in";
//		string fout=to_string(ti)+".out";
//		
//		ofstream of(fin,ios::out);
//		
//		of<<N<<' '<<N<<' '<<endl;
//		uniform_int_distribution dist(0,15);
//		for(int i=1;i<=N;i++)
//		{
//			of<<(dist(r)<<10)<<' ';
//		}
//		of<<endl;
//		
//		uniform_int_distribution qu1(1,N);
//		uniform_int_distribution qu2(100,300);
//		
//		for(int i=1;i<=N;i++)
//		{
//			int L,R;
////			if(i<=N/2)L=qu1(r)>>10,R=qu1(r)>>10;
//			L=qu2(r),R=qu2(r);
//
//			if(L>R)swap(L,R);
//			of<<L<<' '<<R<<endl;
//		}
//	}
	
//	for(int ti=16;ti<=17;ti++)
//	{
//		string fin=to_string(ti)+".in";
//		string fout=to_string(ti)+".out";
//
//		ofstream of(fin,ios::out);
//
//		of<<N<<' '<<N<<' '<<endl;
//		uniform_int_distribution dist(1ll<<31,(1ll<<32)-1);
//		for(int i=1;i<=N;i++)
//		{
//			of<<dist(r)<<' ';
//		}
//		of<<endl;
//
//		uniform_int_distribution qu1(1,N);
//		uniform_int_distribution qu2(1234,1300);
//
//		for(int i=1;i<=N;i++)
//		{
//			int L,R;
//			L=qu2(r),R=qu2(r);
//			if(L>R)swap(L,R);
//			of<<L<<' '<<R<<endl;
//		}
//	}
    for(int ti=18;ti<=20;ti++)
	{
		string fin=to_string(ti)+".in";
		string fout=to_string(ti)+".out";

		ofstream of(fin,ios::out);

		of<<N<<' '<<N<<' '<<endl;
		uniform_int_distribution dist(1ll<<31,(1ll<<32)-1);
        uniform_int_distribution bit(0,32);

		for(int i=1;i<=N;i++)
		{
            int res=1ll<<bit(r)|1ll<<bit(r)|1ll<<bit(r);
			of<<res<<' ';
		}
		of<<endl;

		uniform_int_distribution qu1(1,N-5);
//		uniform_int_distribution qu2(1234,1300);
        int len=5;
		for(int i=1;i<=N;i++)
		{
			int L,R;
			L=qu1(r);//R=qu2(r);

            uniform_int_distribution rr(L,L+len-1);
            R=rr(r);
			if(L>R)swap(L,R);
			of<<L<<' '<<R<<endl;
		}
	}
	return 0;
}
