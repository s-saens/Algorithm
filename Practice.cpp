#include <iostream>

using namespace std;

int pow2(int a)
{
    return a * a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int psum = 0;
    for(int i=0 ; i<5 ; ++i)
    {
        int num;
        cin >> num;
        psum += pow2(num);
    }

    cout << psum%10;
}