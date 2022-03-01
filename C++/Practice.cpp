#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

int BinarySearch(int num) // This function returns the first index of the number. If num is not in the container, it returns -1.
{
    int len = arr.size();
    int l = 0;
    int r = len - 1;

    while(l < r)
    {
        int m = (l+r)/2;
        if(arr[m] >= num)
        {
            r = m;
        }
        else
        {
            l = m+1;
        }
    }
    if(arr[l] == num)
    {
        return l;
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cout << "Array size : ";
    cin >> N;

    cout << "Array members(in sorted order) : ";
    for (int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    int S;
    cout << "Number to search : ";
    cin >> S;

    int index = BinarySearch(S);

    cout << "\nIndex : " << index;
    if(index > -1)
    {
        cout << "\nNumber : " << arr[index];
    }
    else
    {
        cout << "\nNumber is not in the array\n";
    }
}