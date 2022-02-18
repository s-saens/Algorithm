#include <iostream>
#include <string>

using namespace std;

int DPLeft[1001];
int DPRight[1001];

int MAX(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int longestLeft(int startIndex, int N, int *arr) // 사실 여기서 N은 의미 없지만, 코드 헷갈리니까 그냥 넣기로 함.
{
    if (DPLeft[startIndex] != -1)
    {
        return DPLeft[startIndex];
    }

    int lastLongest = 1;
    for (int i = startIndex - 1; i >= 0; --i)
    {
        // 왼쪽으로 감소해야 함
        if (arr[startIndex] > arr[i])
        {
            lastLongest = MAX(lastLongest, 1 + longestLeft(i, N, arr));
        }
    }

    DPLeft[startIndex] = lastLongest;
    return lastLongest;
}

int longestRight(int startIndex, int N, int *arr)
{
    if (DPRight[startIndex] != -1)
    {
        return DPRight[startIndex];
    }


    int lastLongest = 1;
    for (int i = startIndex + 1; i < N; ++i)
    {
        // 왼쪽으로 감소해야 함
        if (arr[startIndex] > arr[i])
        {
            lastLongest = MAX(lastLongest, 1 + longestRight(i, N, arr));
        }
    }

    DPRight[startIndex] = lastLongest;
    return lastLongest;
}

int longestBiotic(int midIndex, int N, int *arr)
{
    // 왼쪽 오른쪽 셀 때, mid도 세게 되는데, 이 때 같은 값이 두 번 더해지기 때문에, 양쪽 longest 더하고 하나 빼줌.
    int l = longestLeft(midIndex, N, arr);
    int r = longestRight(midIndex, N, arr);
    int b = l + r - 1;
    return b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 1001; ++i)
    {
        DPLeft[i] = -1;
        DPRight[i] = -1;
    }

    int N;

    cin >> N;

    int arr[N];

    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    int longest = 0;

    for (int i = 0; i < N; ++i)
    {
        int a = longestBiotic(i, N, arr);
        longest = MAX(a, longest);
    }

    cout << longest;
}