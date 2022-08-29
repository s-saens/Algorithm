#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#define FOR(i,e)for(int i=0;i<e;++i)
using namespace std;

struct Number
{
    char c = 'A';
    int w = 0;
    Number() {}
    Number(char _c, int _w)
    {
        c = _c, w = _w;
    }
};

bool CompareNumber (const Number& n1, const Number& n2)
{
    return n1.w > n2.w;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    Number numbers[26]; // numbers[0] = A

    FOR(i, N)
    {
        string s; cin >> s;
        int len = s.length();
        int k = pow(10, len-1);
        FOR(j, len)
        {
            numbers[s[j]-'A'].c = s[j];
            numbers[s[j]-'A'].w += k;
            k /= 10;
        }
    }
    sort(numbers, numbers + 26, CompareNumber);

    int answer = 0;
    int mul = 9;
    FOR(i, 26)
    {
        if(numbers[i].w <= 0) continue;
        answer += numbers[i].w * mul;
        mul--;
    }

    cout << answer;

    return 0;
}