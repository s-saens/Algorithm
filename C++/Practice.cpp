#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct Tomato
{
    int linearIndex = 0;
    int state = 0;
    int days = 0; // 이 위치에 도달할 때까지 걸린 최소 시간
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int dimension = 11;
    int rippedCnt = 0; // 1이 차 있는 공간의 개수 : totalCnt - emptyCnt와 같아야 출력 가능
    int emptyCnt = 0; // -1이 차 있는 공간의 개수
    int totalCnt = 1; // 전체 배열 공간 크기
    int days = 0;


    // 각 차원의 크기를 입력
    int size[dimension];
    for(int i=0 ; i<dimension ; ++i)
    {
        cin >> size[i];
        totalCnt *= size[i];
    }

    // 방향 배열 초기화
    int dir[dimension * 2];
    for (int i = 0; i < dimension; ++i)
    {
        int mul = 1;
        for(int j=0 ; j<i ; ++j)
        {
            mul *= size[j];
        }
        dir[i * 2] = mul;
        dir[i * 2 + 1] = -mul;
    }

    // 토마토 배열 입력 : 1차원으로 표현
    Tomato tomatos[totalCnt];
    queue<Tomato> q;
    for(int i=0 ; i<totalCnt; ++i)
    {
        cin >> tomatos[i].state;
        tomatos[i].linearIndex = i;
        if(tomatos[i].state == 1) q.push(tomatos[i]);
        else if(tomatos[i].state == -1) emptyCnt++;
    }

    while(!q.empty())
    {
        Tomato f = q.front(); q.pop();
        rippedCnt++;
        days = f.days;

        cout << f.linearIndex << "\n";

        for(int i=0 ; i<dimension*2 ; ++i)
        {
            int newIndex = f.linearIndex + dir[i];

            int movingDist = abs(dir[i]);
            int dimSize = movingDist * size[i/2];
            int fmod = f.linearIndex % dimSize;
            int nmod = newIndex % dimSize;
            if(newIndex < 0 || newIndex >= totalCnt || abs(fmod-nmod) != movingDist) continue;

            if(tomatos[newIndex].state == 0)
            {
                tomatos[newIndex].state = 1;
                tomatos[newIndex].days = f.days + 1;
                q.push(tomatos[newIndex]);
            }
        }
    }

    if(rippedCnt == totalCnt - emptyCnt && rippedCnt > 0)
    {
        cout << days;
    }
    else
    {
        cout << -1;
    }

    return 0;
}