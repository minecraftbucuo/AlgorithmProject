//#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    double a;
    cin >> a;
    a *= 10;
    int c = (int)(a);
    
    int b = 0;
    while (c != 0)
    {
        int ge = c % 10;
        c /= 10;
        
        b = 10 * b + ge;
    }
    
    printf("%.3f", (double)(b*0.001));
    return 0;
}
