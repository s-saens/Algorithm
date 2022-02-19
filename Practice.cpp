#include <iostream>
#include <string>

using namespace std;

int MIN(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M; // N:세로, M:가로

    cin >> N >> M;

    string pieces[N];
    for (int i = 0; i < N; ++i)
    {
        cin >> pieces[i];
    }

    int minChangeCount = 5000;

    for (int i = 0; i <= N - 8; ++i)
    {
        for (int j = 0; j <= M - 8; ++j)
        {
            int changeCount_B = 0; // 맨 왼쪽 위가 Black이어야 한다고 가정할 때, 바뀌는 칸의 수
            int changeCount_W = 0; // 맨 왼쪽 위가 White~

            for (int k = 0; k < 8; ++k)
            {
                for (int l = 0; l < 8; ++l)
                {
                    // 맨 왼쪽 위(k+l = 0)가 B여야 할 때
                    // k+l 더한 값이 짝수인 (0포함) 곳에서 'W'인 경우,
                    // 홀수인 곳에서 'B'인 경우 바꿈
                    if (pieces[i + k][j + l] == 'W' && (k + l) % 2 == 0)
                    {
                        changeCount_B++;
                    }
                    if (pieces[i + k][j + l] == 'B' && (k + l) % 2 == 1)
                    {
                        changeCount_B++;
                    }

                    // 맨 왼쪽 위(k+l = 0)가 W여야 할 때
                    // k+l 더한 값이 짝수인 (0포함) 곳에서 'B'인 경우,
                    // 홀수인 곳에서 'W'인 경우 바꿈
                    if (pieces[i + k][j + l] == 'B' && (k + l) % 2 == 0)
                    {
                        changeCount_W++;
                    }
                    if (pieces[i + k][j + l] == 'W' && (k + l) % 2 == 1)
                    {
                        changeCount_W++;
                    }
                }
            }

            minChangeCount = MIN(minChangeCount, MIN(changeCount_B, changeCount_W));
        }
    }

    cout << minChangeCount;
}