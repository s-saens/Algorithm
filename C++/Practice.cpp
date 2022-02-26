#include <iostream>
#include <map>

using namespace std;

string IsRightTriangle(int max, int a, int b)
{
    if(max*max == a*a + b*b)
    {
        return "right";
    }
    else
    {
        return "wrong";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a = 1;
    int b = 1;
    int c = 1;
    while(true)
    {
        cin >> a >> b >> c;
        if(a==0 && b==0 && c==0)
        {
            return 0;
        }

        if(a > b && a > c)
        {
            cout << IsRightTriangle(a, b, c);
        }
        else if(b > a && b > c)
        {
            cout << IsRightTriangle(b, a, c);
        }
        else if(c > a && c > b)
        {
            cout << IsRightTriangle(c, a, b);
        }
        else
        {
            cout << IsRightTriangle(a, b, c);
        }
        cout << "\n";
    }
}