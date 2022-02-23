#include <iostream>
#include <cmath>

using namespace std;

int MIN(int a, int b)
{
    if(a > b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y, w, h;

    cin >> x >> y >> w >> h;

    cout << MIN( MIN(x, y), MIN( abs(w-x), abs(h-y) ) );
}