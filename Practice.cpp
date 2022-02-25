#include <iostream>
#include <map>

using namespace std;

bool IsInteger(string s)
{
    if(s[0] >= 48 && s[0] <=57)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;

    cin >> N >> M;

    string pocketmonsList[N+1];
    map<string, int> pocketmonsMap;

    for(int i=1 ; i<=N ; ++i)
    {
        string input;
        cin >> input;

        pocketmonsMap[input] = i;
        pocketmonsList[i] = input;
    }

    string answers[M];

    for(int i=0 ; i<M ; ++i)
    {
        string p;
        cin >> p;
        

        if (IsInteger(p) == true) // 숫자면?
        {
            int n = stoi(p);

            answers[i] = pocketmonsList[n];
        }
        else // 이름이면?
        {
            answers[i] = to_string(pocketmonsMap[p]);
        }
    }

    for(int i=0 ; i<M ; ++i)
    {
        cout << answers[i] << "\n";
    }

}