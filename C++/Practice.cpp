#include <iostream>

using namespace std;

bool Has666(int number)
{
    string numberString = to_string(number);
    size_t t = numberString.find("666");
    if(t == string::npos)
    {
        return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int cnt = 0;
    int number = 666;
    while(cnt < N)
    {
        if(Has666(number))
        {
            cnt++;
        }
        number++;
    }

    cout << number-1;


    return 0;
}