#include <iostream>

#define ull unsigned long long int

using namespace std;

bool isPowerOf10(ull a)
{
    while (a > 1)
    {
        if (a % 10 > 0)
        {
            return false;
        }
        a /= 10;
    }
    return true;
}

ull GetLargestCoin(ull price)
{
    if(price <= 0)
    {
        return 0;
    }
    if(price < 10)
    {
        return 1;
    }

    ull divider = 10;
    while(true)
    {
        if(price / divider == 0)
        {
            return divider / 4;
        }
        divider = divider * 25 / 10;
        if(price / divider == 0)
        {
            return divider * 10 / 25;
        }
        divider = divider * 4;
    }

    return -1; // -1이 출력되면 문제 있음.
}

ull GetCoinCount(ull price, ull largestCoin)
{
    if(price < 10)
    {
        return price;
    }

    if (price == 10)
    {
        return 1;
    }

    ull nextLargestCoin;

    bool flag = isPowerOf10(largestCoin);
    
    if(flag == true) // 10의 제곱수
    {
        nextLargestCoin = largestCoin / 4;
    }
    else // 25포함
    {
        nextLargestCoin = largestCoin / 25 * 10;
    }

    ull cc = price / largestCoin + GetCoinCount(price % largestCoin, nextLargestCoin);
    return cc;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ull T;
    cin >> T;

    for(int i=0 ; i<T ; ++i)
    {
        ull price;
        cin >> price;

        cout << GetCoinCount(price, GetLargestCoin(price));
    }

}