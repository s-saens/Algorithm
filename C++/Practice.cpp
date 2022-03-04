#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;

    vector<int> outputs;
    queue<int> q;

    for(int i=0 ; i<N ; ++i)
    {
        string op;
        cin >> op;

        switch (op[1])
        {
            case 'u': // push
                int element;
                cin >> element;
                q.push(element);
                break;
            case 'o': // pop
                if(q.empty()) outputs.push_back(-1);
                else
                {
                    outputs.push_back(q.front());
                    q.pop();
                }
                break;
            case 'i': // size
                outputs.push_back(q.size());
                break;
            case 'm': // empty
                outputs.push_back(q.empty());
                break;
            case 'r': // front
                if(q.empty()) outputs.push_back(-1);
                else outputs.push_back(q.front());
                break;
            case 'a': // back
                if(q.empty()) outputs.push_back(-1);
                else outputs.push_back(q.back());
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