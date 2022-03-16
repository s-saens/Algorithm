#include <iostream>
#include <algorithm>
#define ull unsigned long long int

using namespace std;

// 블럭 제거 2초
// 블럭 놓기 1초

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int X, Y;
    cin >> X >> Y;

    int floorSize = X * Y; // floorSize
    
    ull B;
    cin >> B;

    int blockCnt[floorSize];

    for(int i=0 ; i<floorSize ; ++i)
    {
        cin >> blockCnt[i];
    }

    sort(blockCnt, blockCnt+floorSize);

    int time = 0;

    return 0;
}