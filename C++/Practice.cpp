#include <iostream>
#include <cmath>
#include <algorithm>
#define FOR(i, s, e) for(int i=s ; i<e ; ++i)

using namespace std;

string answer1 = "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
string answer2 = "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
string answer3 = "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
int N;

void PrintUnderline(int depth)
{
    FOR(i, 0, depth) cout << "____";
}

void Solve(int index)
{
    if(index > 0)
    {
        PrintUnderline(N - index);
        cout << "\"재귀함수가 뭔가요?\"\n";
        PrintUnderline(N - index);
        cout << answer1;
        PrintUnderline(N - index);
        cout << answer2;
        PrintUnderline(N - index);
        cout << answer3;
        Solve(index - 1);
    }
    else
    {
        PrintUnderline(N - index);
        cout << "\"재귀함수가 뭔가요?\"\n";
        PrintUnderline(N - index);
        cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
    }
    PrintUnderline(N - index);
    cout << "라고 답변하였지.\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";

    Solve(N);

    return 0;
}