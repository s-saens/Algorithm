#include <iostream>

using namespace std;

struct Person
{
    int weight;
    int height;
    int rank;
};

short Sign(int x)
{
    if(x > 0)
    {
        return 1;
    }
    else if(x < 0)
    {
        return -1;
    }
    return 0;
}

int Dungchi(Person p1, Person p2) // 0이면 덩치 판정 불가, 2이면 p1이 덩치 큼, -2이면 p2가 덩치 큼
{
    int deltaW = p1.weight - p2.weight;
    int deltaH = p1.height - p2.height;
    int signDW = Sign(deltaW);
    int signDH = Sign(deltaH);
    return signDW + signDH;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int N;
    cin >> N;

    Person people[N];

    for (int i = 0; i < N; ++i)
    {
        cin >> people[i].weight >> people[i].height;
        people[i].rank = 1;
    }

    for (int i = 0; i < N; ++i)
    {
        for(int j=0 ; j<N ; ++j)
        {
            if( Dungchi(people[i], people[j]) == -2 )
            {
                people[i].rank += 1;
            }
        }
    }

    for(int i=0 ; i<N ; ++i)
    {
        cout << people[i].rank << "\n";
    }

    return 0;
}