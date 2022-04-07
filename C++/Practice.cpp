#include <iostream>
#include <algorithm>

using namespace std;

struct Number
{
    int index = 0;
    int number = 0;
    int compressedNumber = 0;
};

bool cmp1(Number& n1, Number& n2)
{
    return n1.number < n2.number;
}

bool cmp2(Number& n1, Number& n2)
{
    return n1.index < n2.index;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    Number numbers[N];

    for(int i=0 ; i<N ; ++i)
    {
        cin >> numbers[i].number;
        numbers[i].index = i;
    }

    sort(numbers, numbers+N, cmp1);

    for(int i=1 ; i<N ; ++i)
    {
        if(numbers[i].number > numbers[i-1].number)
        {
            numbers[i].compressedNumber = numbers[i-1].compressedNumber + 1;
        }
        else if(numbers[i].number == numbers[i-1].number)
        {
            numbers[i].compressedNumber = numbers[i - 1].compressedNumber;
        }
    }

    sort(numbers, numbers+N, cmp2);

    for(int i=0 ; i<N ; ++i)
    {
        cout << numbers[i].compressedNumber << ' ';
    }

    return 0;
}