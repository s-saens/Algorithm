#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, len;
    cin >> N >> len;

    vector<int> possiblesLengths;

    string ioioi;
    cin >> ioioi;

    int cnt = 0;
    int answer = 0;

    for (int i = 0; i < len; ++i)
    {
        if (cnt <= 0) // seq의 처음 시작은 I여야 함.
        {
            if (ioioi[i] == 'I')
            {
                cnt++;
            }
        }
        else if (i > 0) // seq가 시작됨.
        {
            if (ioioi[i - 1] == 'I' && ioioi[i] == 'O' && i < len - 1)
            {
                cnt++; // 마지막이 O일 경우, 다음 I가 나올 수 없으므로, 빼야 함.
            }
            else if (ioioi[i - 1] == 'O' && ioioi[i] == 'I')
            {
                cnt++;
            }
            else // seq 깨짐. cnt = 0
            {
                if (cnt >= 2 * N + 1)
                {
                    int l = (cnt - 1) / 2; // seq에서 O의 개수
                    answer += l - N + 1;
                }

                if (ioioi[i] == 'O')
                {
                    cnt = 0;
                }
                else if (ioioi[i] == 'I')
                {
                    cnt = 1;
                }
            }
        }
    }
    if (cnt >= 2 * N + 1)
    {
        int l = (cnt - 1) / 2; // seq에서 O의 개수
        answer += l - N + 1;
    }

    cout << answer;

    return 0;
}