#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int N;
    cin >> N;

    int arr[N];

    int sum = 0;
    int maximum = -40000;
    int minimum = 40000;

    int cntPositive[4001];
    int cntNegative[4001];
    int cnt0 = 0;

    for (int i = 0; i < 4001; ++i) // 배열 초기화
    {
        cntPositive[i] = 0;
        cntNegative[i] = 0;
    }

    // input
    for(int i=0 ; i<N ; ++i)
    {
        int input;
        cin >> input;
        arr[i] = input;

        sum += input;

        maximum = max(maximum, input);
        minimum = min(minimum, input);

        if(input > 0)
        {
            cntPositive[input]++;
        }
        else if(input < 0)
        {
            cntNegative[-input]++;
        }
        else
        {
            cnt0++;
        }
    }

    // 산술 평균 구하기
    double average = 1.0 * sum / N;

    // 중앙값 구하기
    sort(arr, arr+N);
    int midNumber = arr[N/2];

    // 최빈값 구하기
    int maxCnt = max(0, cnt0); // 최빈값의 빈도 찾기
    for(int i=1 ; i<4001 ; ++i) // 최빈값의 빈도 찾기
    {
        maxCnt = max(max(maxCnt, cntPositive[i]), cntNegative[i]);
    }

    int mostFrequentsCnt = 0; // 최빈값의 개수
    int mostFrequent = 0;
    for(int i=-4000 ; i<=4000 ; ++i) // 최고 빈도를 가진 수, 즉 최빈값 찾기. 오름차순으로 탐색. 두 개 이상인 경우 
    {
        if(i>0)
        {
            if (cntPositive[i] == maxCnt)
            {
                mostFrequent = i;
                mostFrequentsCnt++;
            }
        }
        else if(i<0)
        {
            if(cntNegative[-i] == maxCnt)
            {
                mostFrequent = i;
                mostFrequentsCnt++;
            }
        }
        else // i == 0
        {
            if(cnt0 == maxCnt)
            {
                mostFrequent = i;
                mostFrequentsCnt++;
            }
        }
        if(mostFrequentsCnt >= 2)
        {
            break;
        }
    }

    cout << fixed;
    cout.precision(0);

    cout << "\n";

    // 산술평균
    cout << (int)round(average) << "\n";

    // 중앙값
    cout << midNumber << "\n";

    // 최빈값
    cout << mostFrequent << "\n";

    // 범위
    cout << maximum - minimum << "\n";

    return 0;
}