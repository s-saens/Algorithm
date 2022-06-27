#include <iostream>
#include <algorithm>
#define FOR(i,s,e) for(int i=s;i<e;++i)
#define MIN -2147483648
using namespace std;

int N;
string ex;
int answer;

int cal(int a, char op, int b)
{
    switch (op)
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
    }
}

void F(int i, int lastResult)
{
    if(i >= N-1)
    {
        answer = max(answer, lastResult);
        return;
    }
    if(i+4 < N) F(  i+4, cal( lastResult, ex[i+1], cal(ex[i+2]-'0', ex[i+3], ex[i+4]-'0') )  );
    if(i+2 < N) F(  i+2, cal( lastResult, ex[i+1], ex[i+2]-'0')  );
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    answer = MIN;
    cin >> N >> ex;
    F(0, ex[0]-'0');

    cout << answer;
}