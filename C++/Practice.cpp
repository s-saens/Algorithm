#include <iostream>
#include <algorithm>

using namespace std;

string SumOfEachNumbers(string number)
{
    int sum = 0;
    int len = number.length();
    for (int i = 0; i < len; ++i)
    {
        sum += number[i] - '0';
    }
    return to_string(sum);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    string X;
    cin >> X;
    int len = X.length();

    int cnt = 0;

    while(X.length() > 1)
    {
        X = SumOfEachNumbers(X);
        cnt++;
    }

    int lastNumber = X[0] - '0';

    cout << cnt << "\n";
    if(lastNumber % 3 == 0)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO" ;
    }

    return 0;
}