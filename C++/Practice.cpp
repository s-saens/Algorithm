#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


short len = 21;

void Clear(short* arr)
{
    for(int i=0 ; i<len ; ++i)
    {
        arr[i] = -1;
    }
}
void Fill(short* arr)
{
    for(int i=0 ; i<len ; ++i)
    {
        arr[i] = i;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;

    short arr[21];
    vector<bool> outputs;

    Clear(arr);

    for (int i = 0; i < N; ++i)
    {
        short x;
        string op;
        cin >> op;

        switch (op[1])
        {
        case 'd': // add
            cin >> x;
            if(arr[x] == -1)
            {
                arr[x] = x;
            }
            break;
        case 'e': // remove
            cin >> x;
            if(arr[x] != -1)
            {
                arr[x] = -1;
            }
            break;
        case 'h': // check
            cin >> x;
            outputs.push_back(arr[x] == x);
            break;
        case 'o': // toggle
            cin >> x;
            if (arr[x] == -1)
            {
                arr[x] = x;
            }
            else
            {
                arr[x] = -1;
            }
            break;
        case 'l': // all
            Fill(arr);
            break;
        case 'm': // empty
            Clear(arr);
            break;
        default:
            break;
        }
    }

    for(int i=0 ; i<outputs.size() ; ++i)
    {
        cout << outputs[i] << "\n";
    }

    return 0;
}