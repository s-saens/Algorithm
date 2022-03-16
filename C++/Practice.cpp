#include <iostream>
#include <algorithm>
#define ull unsigned long long int

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int N;
    cin >> N;

    int maximumNumber = 0;
    int winIndex;

    for(int i=0 ; i<N ; ++i)
    {
        int number[5];
        for(int j=0 ; j<5 ; ++j)
        {
            cin >> number[j];
        }

        for(int j=0 ; j<3 ; ++j)
        {
            for(int k=j+1 ; k<4 ; ++k)
            {
                for(int l=k+1 ; l<5 ; ++l)
                {
                    int sum = number[j] + number[k] + number[l];
                    if(maximumNumber <= sum%10)
                    {
                        maximumNumber = sum%10;
                        winIndex = i+1;
                    }
                }
            }
        }
    }

    cout << winIndex;

    return 0;
}