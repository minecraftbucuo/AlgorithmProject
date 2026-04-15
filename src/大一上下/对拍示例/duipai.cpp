#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t = 1;
    system("g++ shen.cpp -o shen.exe");
    system("g++ zhen.cpp -o zhen.exe");
    system("g++ my.cpp -o my.exe");
    while (true)
    {
        system("shen.exe > shen.out");
        system("zhen.exe < shen.out > zhen.out");
        system("my.exe < shen.out > my.out");

        if (system("fc my.out zhen.out"))
        {
            cout << t++ << ':' << "Wrong Answer" << endl;
            break;
        }
        else
        {
            cout << t++ << ':' << "Accepted" << endl;
        }
    }
    return 0;
}