#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    deque<int> dq;
    vector<int> answers;

    int N;
    cin >> N;
    
    for(int i=0 ; i<N ; ++i)
    {
        string op;
        cin >> op;
        int X = 0;

        switch (op[1])
        {
            case 'u': // push
                if(op[5] == 'f') // push front
                {
                    cin >> X;
                    dq.push_front(X);
                }
                else if(op[5] == 'b') // push back
                {
                    cin >> X;
                    dq.push_back(X);
                }
                break;
            case 'o': // pop
                if(dq.empty())
                {
                    answers.push_back(-1);
                }
                else
                {
                    if(op[4] == 'f')
                    {
                        answers.push_back(dq.front());
                        dq.pop_front();
                    }
                    else if(op[4] == 'b')
                    {
                        answers.push_back(dq.back());
                        dq.pop_back();
                    }
                }
                break;
            case 'i': // size
                answers.push_back(dq.size());
                break;
            case 'm': // empty
                answers.push_back(dq.empty());
                break;
            case 'r': // front
                answers.push_back(dq.empty() ? -1 : dq.front());
                break;
            case 'a': // back
                answers.push_back(dq.empty() ? -1 : dq.back());
                break;
            default:
                break;
        }
    }

    for(unsigned int i=0 ; i<answers.size() ; ++i)
    {
        cout << answers[i] << "\n";
    }

    return 0;
}