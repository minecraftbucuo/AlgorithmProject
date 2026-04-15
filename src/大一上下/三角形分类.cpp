//#include<bits/stdc++.h>
#include<iostream> 
using namespace std;

int main()
{
    int a1, b1, c1;
    cin >> a1 >> b1 >> c1;
    int sum = a1 + b1 + c1;
    int a = min(min(a1, b1), c1);
    int c = max(max(a1, b1), c1);
    int b = sum - a - c;
    if (a + b > c)
    {
        if (a*a +b*b == c*c)
        {
            cout << "Right triangle"<< endl;
        }
        else if(a*a + b*b > c*c)
        {
            cout << "Acute triangle"<< endl;
        }
        else if(a*a + b*b < c*c)
        {
            cout << "Obtuse triangle"<< endl;
        }
        
        if (a == b || b == c)
        {
            cout <<"Isosceles triangle"<< endl;
        }
        if (a == c)
        {
            cout <<"Equilateral triangle"<< endl;
        }
    }
    else
    {
        cout << "Not triangle"<< endl;
    }
    return 0;
}
