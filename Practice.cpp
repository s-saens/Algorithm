#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int min = 99999;

    string a, b;

    cin >> a >> b;

    string *longer;
    string *shorter;

    int aLen = a.length();
    int bLen = b.length();

    if (aLen > bLen)
    {
        longer = &a;
        shorter = &b;
    }
    else
    {
        longer = &b;
        shorter = &a;
    }

    int gap = (*longer).length() - (*shorter).length();

    string sum("");

    int buffer = 0;
    for (int i = (*shorter).length() - 1; i >= 0; --i)
    {
        int s = ((*shorter)[i] - 48) + ((*longer)[i + gap] - 48) + buffer;

        if(s>=10)
        {
            buffer = s / 10;
        }
        else
        {
            buffer = 0;
        }

        sum.insert(sum.begin(), (char)(s % 10 + 48));
    }

    for (int i = gap - 1; i >= 0; --i)
    {
        int s = ((*longer)[i] - 48) + buffer;
        buffer = s/10;
        sum.insert(sum.begin(), (char)(s % 10 + 48));
    }

    if (buffer > 0)
    {
        sum.insert(sum.begin(), (char)(buffer + 48));
    }
    
    cout << sum;
    
}