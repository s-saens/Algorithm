#include <iostream>
#include <cmath>

using namespace std;
int getLength(long *mul)
{
    if (*mul == 0)
    {
        return 1;
    }

    int length = 0;
    for (int i = 1;; i *= 10)
    {
        if ((*mul) / i > 0)
        {
            length++;
        }
        else
        {
            break;
        }
    }
    return length;
}

int getNumOfIndex(long *mul, int index)
{
    long tmp = (*mul) / pow(10, index);
    return tmp % 10;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int max = -1;
    int A, B, C;
    cin >> A >> B >> C;

    int cnts[10];
    for(int i=0 ; i<10 ; ++i)
    {
        cnts[i] = 0;
    }

    long mul = A * B * C;

    int len = getLength(&mul);

    for(int i=len-1 ; i>=0 ; --i)
    {
        cnts[getNumOfIndex(&mul, i)]++;
    }

    for(int i=0 ; i<10 ; ++i)
    {
        cout << cnts[i] << "\n";
    }

    return 0;
}

