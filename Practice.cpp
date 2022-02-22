#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int lastNatural = 1;
    stack<int> stack1234; // 1부터 순차적으로 쌓아올릴 친구
    queue<int> seq;

    string history;

    for(int i=0 ; i<n ; ++i)
    {
        int number;
        cin >> number;
        seq.push(number);
    }

    int whileCount = 0;
    while(seq.empty() == false)
    {
        whileCount++;
        int popped = seq.front();
        seq.pop();

        while(lastNatural <= popped)
        {
            stack1234.push(lastNatural);
            history += "+\n";
            lastNatural++;
        }

        int popped1234 = stack1234.top();

        stack1234.pop();
        history += "-\n";


        if (popped1234 > popped)
        {
            cout << "NO";
            return 0;
        }
    }

    cout << history;

}