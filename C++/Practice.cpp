#include <iostream>
#include <algorithm>
#define MIN -100000

using namespace std;

int N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    int number;
    cin >> number;

    int seqSum = number;
    int maxSum = seqSum;

    for(int i=1 ; i<N ; ++i)
    {
        cin >> number;
        if(seqSum + number < number) seqSum = number;
        else seqSum += number;
        maxSum = max(maxSum, seqSum);
    }

    cout << maxSum;

    return 0;
}