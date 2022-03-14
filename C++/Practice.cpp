#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    int K;
    cin >> K;

    int sum = 0;
    stack<int> numbers;

    for(int i=0 ; i<K ; ++i)
    {
        int input;
        cin >> input;

        if(input == 0)
        {
            sum -= numbers.top();
            numbers.pop();
        }
        else
        {
            sum += input;
            numbers.push(input);
        }
    }

    cout << sum;

    return 0;
}