#include <iostream>

using namespace std;

int numbers[10001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    for (int i = 0; i < 10001; ++i)
    {
        numbers[i] = 0;
    }

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int n;
        cin >> n;
        numbers[n]++;
    }

    for (int i = 0; i < 10001; ++i)
    {
        while (numbers[i] > 0)
        {
            cout << i << "\n";
            numbers[i]--;
        }
    }

    return 0;
}