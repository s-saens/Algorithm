#include <iostream>
#include <deque>
using namespace std;

deque<int> StringToDeque(string s)
{
    deque<int> dq;
    string temp = "";

    for(int i=0 ; i<s.length() ; ++i)
    {
        if(s[i] == '[') continue;

        if(temp.length() > 0 && (s[i] == ',' || s[i] == ']'))
        {
            dq.push_back(stoi(temp));
            temp = "";
            continue;
        }

        temp += s[i];
    }

    return dq;
}

void PrintDeque(deque<int>* dq, bool atFirst)
{
    int len = dq->size();
    cout << '[';
    if(atFirst)
    {
        for(int i=0 ; i<len-1 ; ++i) cout << dq->at(i) << ',';
        if(len > 0) cout << dq->at(len - 1);
        cout << "]\n";
    }
    else
    {
        for(int i=len-1 ; i>0 ; --i) cout << dq->at(i) << ',';
        if(len > 0) cout << dq->at(0);
        cout << "]\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    for(int t=0 ; t<T ; ++t)
    {
        string operation;
        cin >> operation;
        int opLen = operation.length();

        int arrLenTemp;
        cin >> arrLenTemp;

        string arr;
        cin >> arr;
        int arrLen = arr.length();
        
        deque<int> dq = StringToDeque(arr);
        bool atFirst = true;
        bool err = false;

        for(int i=0 ; i<opLen ; ++i)
        {
            if(operation[i] == 'R')
            {
                atFirst = !atFirst;
            }
            else // 'D'
            {
                if(dq.size() <= 0)
                {
                    cout << "error" << "\n";
                    err = true;
                    break;
                }
                if(atFirst) dq.pop_front();
                else dq.pop_back();
            }
        }

        if(!err) PrintDeque(&dq, atFirst);
    }

    return 0;
}

/*

4
RDD
4
[1,2,3,4]
DD
1
[42]
RRD
6
[1,1,2,3,5,8]
D
0
[]

*/