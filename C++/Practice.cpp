#include <iostream>

using namespace std;

bool isYoonYear(int year) // 2월29일이 추가됨.
{
    bool ret = true;
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

int YearToDays(int year)
{
    int sum = 0;
    for (int i = 1; i < year; ++i)
    {
        if (isYoonYear(i))
        {
            sum += 366;
        }
        else
        {
            sum += 365;
        }
    }
    return sum;
}

int mDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int MonthToDays(int month, int year)
{
    int sum = 0;
    for(int i=1 ; i<month ; ++i)
    {
        if (i == 2 && isYoonYear(year))
        {
            sum += 29;
        }
        else
        {
            sum += mDays[i];
        }
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int Y1, M1, D1;
    int Y2, M2, D2;
    cin >> Y1 >> M1 >> D1;
    cin >> Y2 >> M2 >> D2;

    if(Y2-Y1 > 1000)
    {
        cout << "gg";
        return 0;
    }
    else if(Y2 - Y1 == 1000)
    {
        if(M2 > M1)
        {
            cout << "gg";
            return 0;
        }
        else if(M2 == M1)
        {
            if(D2 >= D1)
            {
                cout << "gg";
                return 0;
            }
        }
    }

    int days1 = YearToDays(Y1) + MonthToDays(M1, Y1) + D1;
    int days2 = YearToDays(Y2) + MonthToDays(M2, Y2) + D2;

    cout << "D-" << days2 - days1;

    return 0;
}