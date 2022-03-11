#include <iostream>
#include <algorithm>

#define ull unsigned long long int

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    ull X, Y, parallel, diagonal;
    cin >> X >> Y >> parallel >> diagonal;

    bool canMoveDiagonally = 2*parallel >= diagonal;
    bool isParallelSmall = parallel < diagonal;

    ull answer;

    if(canMoveDiagonally)
    {
        ull maximum = max(X, Y);
        ull minimum = min(X, Y);

        ull diagonalMoveCnt = minimum;
        ull parallelMoveCnt = maximum - diagonalMoveCnt;
        ull diagonalAndParallel = diagonalMoveCnt * diagonal + parallelMoveCnt * parallel;

        ull diagonalOnly = maximum * diagonal - ((maximum-minimum)%2) * (diagonal - parallel);
        
        answer = min(diagonalAndParallel, diagonalOnly);
    }
    else
    {
        answer = (X + Y) * parallel;
    }

    cout << answer;

    return 0;
}