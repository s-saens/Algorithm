#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N;
    int A[N];

    for(int i=0 ; i <N ; ++i)
    {
        cin >> A[i];
    }
    cin >> M;
    int findings[M];

    for(int i=0 ; i<M ; ++i)
    {
        cin >> findings[i];
    }

    sort(A, A+N);

    for(int i=0 ; i<M ; ++i)
    {
        cout << binary_search(A, A+N, findings[i]) << "\n";
    }
    return 0;
}