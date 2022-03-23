#include <iostream>

using namespace std;

bool paper[128][128];
int piecesCnt = 1;

void InitPapers()
{
    for(int i=0 ; i<128 ; ++i)
    {
        for(int j=0 ; j<128 ; ++j)
        {
            paper[i][j] = false;
        }
    }
}

int F(int x1, int y1, int length)
{
    bool zeroCnt = 0;
    bool oneCnt = 0; // Blue

    for(int y=y1 ; y<y1+length ; ++y)
    {
        for(int x=x1 ; x<x1+length ; ++x)
        {
            if(paper[y][x])
            {
                oneCnt = 1;
            }
            else // 1
            {
                zeroCnt = 1;
            }
        }
    }

    int half = length/2;

    if(zeroCnt == 0)
    {
        if(oneCnt == 0) // 0 0 : 이런건 없음
        {
            return 0;
        }
        else // 0 1 : Blue만 있음
        {
            return 1;
        }
    }
    else
    {
        if(oneCnt == 0) // 1 0 : 0만 있음
        {
            return 0;
        }
        else // 1 1 : 둘 다 있음 : 자르기
        {
            piecesCnt += 3; // 종이 하나를 4등분 하면, 종이가 하나였던 게 네개가 된다. 즉 종이 3개 증가.
            return F(x1, y1, half) + F(x1+half, y1, half) + F(x1, y1+half, half) + F(x1+half, y1+half, half);
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for(int y=0 ; y<N ; ++y)
    {
        for(int x=0 ; x<N ; ++x)
        {
            bool b;
            cin >> b;
            paper[y][x] = b;
        }
    }

    int blue = F(0, 0, N);
    int white = piecesCnt - blue;

    cout << white << "\n" << blue;

    return 0;
}