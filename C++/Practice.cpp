#include <iostream>
#include <stdio.h>

using namespace std;

int mDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isYoonYear(int year) // 2월29일이 추가됨.
{
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

int DaysOfYear(int year)
{
    if (isYoonYear(year))
    {
        mDays[2] = 29;
        return 366;
    }
    else
    {
        mDays[2] = 28;
        return 365;
    }
}

int MonthToDays(int month)
{
    int sum = 0;
    for (int i = 1; i < month; ++i)
    {
        sum += mDays[i];
    }
    return sum;
}

int MonthStringToInt(string s)
{
    if (s == "January")
        return 1;
    if (s == "February")
        return 2;
    if (s == "March")
        return 3;
    if (s == "April")
        return 4;
    if (s == "May")
        return 5;
    if (s == "June")
        return 6;
    if (s == "July")
        return 7;
    if (s == "August")
        return 8;
    if (s == "September")
        return 9;
    if (s == "October")
        return 10;
    if (s == "November")
        return 11;
    if (s == "December")
        return 12;
    return -1;
}

int TimeMinutes(int h, int m)
{
    return (h * 60) + m;
}

int DaysToMinutes(int days)
{
    return days * 60 * 24;
}

int main()
{
    // ios::sync_with_stdio(false);
    // ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << fixed;
    cout.precision(15);

    // inputs
    string M;
    cin >> M;
    int months = MonthStringToInt(M);

    int D;
    scanf("%02d,", &D);

    int year;
    cin >> year;
    int daysOfYear = DaysOfYear(year);

    int h, m;
    scanf("%02d:%02d", &h, &m);
    // input end

    // 모두 분으로 환산
    int days = MonthToDays(months) + D;

    int minutes = TimeMinutes(h, m) + DaysToMinutes(days - 1);

    int minutesOfYear = DaysToMinutes(daysOfYear);

    cout << (minutes * 100.0) / minutesOfYear << "\n";

    return 0;
}