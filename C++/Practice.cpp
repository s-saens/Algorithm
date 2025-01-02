#include <iostream>
#include <algorithm>
#define FOR(i,s,e) for(int i=s ; i<e; ++i)

using namespace std;

int numbers[5];

bool checkDivision(int a, int b, int c, int num)
{
    return num % a == 0 && num % b == 0 && num % c == 0;
}

int main()
{
    FOR(i,0,5) cin >> numbers[i];

    sort(numbers, numbers+5);

    FOR(num, numbers[0], 1000000)
    {
        FOR(i, 0, 5) FOR(j, i+1, 5) FOR(k, j+1, 5)
        {
            if(checkDivision(numbers[i], numbers[j], numbers[k], num))
            {
                cout << num;
                return 0;
            }
        }
    }

    return 0;
}