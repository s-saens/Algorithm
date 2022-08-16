#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;

    int multiplier = 9, d = 1;
    while(N-multiplier > 0)
    {
        N -= multiplier;
        d++;
        multiplier = (int)pow(10, d-1) * 9 * d;
    }

    N--;
    int l = (int)pow(10, d-1);
    int k = l + N/d;

    string number = to_string(k);
    int index = N%d;

    cout << number[index];

    return 0;
}

/*

한자리수 : 1부터 9까지 : 9개 * 1
두자리수 : 10부터 99까지 : 90개 * 2
세자리수 : 100부터 999까지 : 900개 * 3
d자리수 : 10^(d-1)부터 10^d까지 : 9 * 10^(d-1)개 * d
  -> multiplier = 9 * 10^(n-1) * d

N이 0에 가장 가까워질때까지 multiplier만큼 값을 빼면서 d값, 즉 몇자리 수인지 알아낸다.
나중N은, 처음N보다 작은, 처음N에서 가장 가까운 경곗값(l = 10^(d))으로부터 몇 번째의 인덱스를 더 가야하는지를 나타내는 값이다.
단, 이때 1번째가 아니라 0번째부터 세어야 하므로 N에 1을 빼준다. (10을 생각해보면, 나중N이 1인데, 이 때 더 가야하는 인덱스 수는 0개이다.)
d자리 수에 대해서, l부터 시작해서 인덱스가 d번 증가할 때마다 수는 1씩 증가하므로 나중N을 d로 나눈 값은, l에서 인덱스에 도착했을 때의 전체 수(k)까지 몇이 증가했는지를 의미한다.
즉, k = l + N/d이다.
또한 N%d는 d자리 숫자 k에서 몇번째를 탐색해야 할지를 알려준다. (index)
따라서 k를 string으로 변환한 후 index로 접근하면 도달한 숫자를 알 수 있다.

*/