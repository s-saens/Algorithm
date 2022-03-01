#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

void AddNumber(int num)
{
    int len = arr.size();
    int l = 0;
    int r = len - 1;

    if(len <= 0 || arr[len-1] < num)
    {
        arr.push_back(num);
        return;
    }
    
    while(r > l)
    {
        int m = (l + r) / 2;
        if (arr[m] >= num)
        {
            r = m;
        }
        else
        {
            l = m+1;
        }
    }

    arr[l] = num;

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;
        AddNumber(num);
    }

    cout << arr.size();
}