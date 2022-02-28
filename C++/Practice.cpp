#include <iostream>
#include <algorithm>

using namespace std;

int minimum = 1000000000;
int maximum = -1000000000;
int N;
int numbers[12];

void TryAll(int index, int lastOperated, int op[4])
{
    if(index == N-1)
    {
        minimum = min(minimum, lastOperated);
        maximum = max(maximum, lastOperated);
        return;
    }
    for(int i=0 ; i<4 ; ++i)
    {
        if(op[i] <= 0 )
        {
            continue;
        }

        int operated;
        switch (i)
        {
        case 0:
            operated = lastOperated + numbers[index+1];
            break;

        case 1:
            operated = lastOperated - numbers[index + 1];
            break;

        case 2:
            operated = lastOperated * numbers[index + 1];
            break;

        case 3:
            operated = lastOperated / numbers[index + 1];
            break;
        
        default:
            cout << "Somthing's wrong";
            return;
            break;
        }

        int newOp[4];
        // Op 배열 복사
        for(int j=0 ; j<4 ; ++j)
        {
            newOp[j] = op[j];
        }
        newOp[i]--;

        TryAll(index + 1, operated, newOp);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i=0 ; i<N ; ++i)
    {
        cin >> numbers[i];
    }

    int operators[4];
    for (int i = 0 ; i<4 ; ++i)
    {
        cin >> operators[i];
    }

    TryAll(0, numbers[0], operators);

    cout << maximum << "\n" << minimum << "\n";

    return 0;
}