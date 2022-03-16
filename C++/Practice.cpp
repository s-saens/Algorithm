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

    int blocks[floorSize];
    int maxHeight = 0;
    int minHeight = 256;
    int diggables[floorSize];
    int empties[floorSize];

    for (int i = 0; i < floorSize; ++i)
    {
        cin >> blocks[i];
        maxHeight = max(maxHeight, blocks[i]);
        minHeight = min(minHeight, blocks[i]);
    }


    for(int i=0 ; i<floorSize ; ++i)
    {
        empties[i] = maxHeight - blocks[i];
    }
    for(int i=floorSize-1 ; i>=0 ; --i)
    {
        diggables[i] = blocks[i] - minHeight;
    }

    int minTime = 500 * 500 * 256;
    int answerHeight = 0;

    // sort(blocks, blocks + floorSize);


    for(int cuttingHeight = minHeight ; cuttingHeight <= maxHeight ; ++cuttingHeight)
    {
        int diggableCnt = 0;
        int emptyCnt = 0;
        for(int i=0 ; i<floorSize ; ++i)
        {
            if(blocks[i] < cuttingHeight) // 왼쪽에 있는 경우 : 채워야됨
            {
                emptyCnt += cuttingHeight - blocks[i];
            }
            else// 오른쪽에 있는 경우 : 파야됨
            {
                diggableCnt += blocks[i] - cuttingHeight;
            }
        }

        if(diggableCnt + B >= emptyCnt) // 채울 수 있음, 즉 height 만족 가능.
        {
            int t = diggableCnt * 2 + emptyCnt;
            if(minTime > t)
            {
                minTime = t;
                answerHeight = cuttingHeight;
            }
            else if(minTime == t)
            {
                answerHeight = max(cuttingHeight, answerHeight);
            }
        }
        else
        {
            break;
        }
    }

    cout << minTime << ' ' << answerHeight;

    return 0;
}