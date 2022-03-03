#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> v;

    for (int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;

        int l, r, m;
        l = 0;
        r = i;

        if (v.empty() == true)
        {
            v.push_back(num);
            continue;
        }

        while (r > l)
        {
            m = (l + r) / 2;
            if (v[m] < num)
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }
        v.insert(v.begin() + l, num);
    }

    for (int i = 0; i < N; ++i)
    {
        cout << v[i] << "\n";
    }
}