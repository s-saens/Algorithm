#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    int answers[T];

    for(int i=0 ; i<T ; ++i)
    {
        answers[i] = 1;

        int number[2];
        cin >> number[0] >> number[1];

        sort(number, number+2);

        for(int j=2 ; j<=number[0] ; ++j)
        {
            if(number[0]%j == 0 && number[1]%j == 0)
            {
                answers[i] *= j;
                number[0] /= j;
                number[1] /= j;
                j--;
            }
        }

        answers[i] *= number[0] * number[1];
    }

    for(int i=0 ; i<T ; ++i)
    {
        cout << answers[i] << "\n";
    }

    return 0;
}