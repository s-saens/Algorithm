#include <iostream>
#include <algorithm>

using namespace std;

struct Person
{
    int index;
    int time;
};

bool cmp(Person &p1, Person &p2)
{
    if(p1.time > p2.time)
    {
        return true;
    }
    return false;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int N;
    cin >> N;

    int time[N];

    for(int i=0 ; i<N ; ++i)
    {
        cin >> time[i];
    }

    sort(time, time + N);

    int sum=0;

    for(int i=0 ; i < N ; ++i)
    {
        sum += time[i] * (N-i);
    }

    cout << sum;

    return 0;
}