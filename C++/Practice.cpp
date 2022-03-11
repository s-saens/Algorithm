#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    queue<int> q;
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
                cin >> X;
                q.push(X);
                break;
            case 'o': // pop
                if(!q.empty())
                {
                    answers.push_back(q.front());
                    q.pop();
                }
                else
                {
                    answers.push_back(-1);
                }
                
                break;
            case 'i': // size
                answers.push_back(q.size());
                break;
            case 'm': // empty
                answers.push_back(q.empty());
                break;
            case 'r': // front
                answers.push_back(q.empty() ? -1 : q.front());
                break;
            case 'a': // back
                answers.push_back(q.empty() ? -1 : q.back());
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