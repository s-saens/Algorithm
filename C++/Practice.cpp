#include <iostream>
#include <map>

using namespace std;

int F()
{
    int N;
    cin >> N;

    map<string, int> clothes;

    for (int i = 0; i < N; ++i)
    {
        string cloth, cate;
        cin >> cloth >> cate;
        if(clothes.count(cate) == 0)
        {
            clothes[cate] = 2;
        }
        else
        {
            clothes[cate]++;
        }
    }

    int sum = 1;
    for (map<string, int>::iterator it = clothes.begin() ; it != clothes.end() ; ++it)
    {
        sum *= (*it).second;
    }
    return sum-1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    

    int T;
    cin >> T;

    int answers[T];

    for(int i=0 ; i<T ; ++i)
    {
        answers[i] = F();
    }

    for(int i=0 ; i<T ; ++i)
    {
        cout << answers[i] << "\n";
    }


    return 0;
}