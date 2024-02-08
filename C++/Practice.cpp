#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> rotate(vector<vector<int>> shape) // left, 90 degree
{
    vector<vector<int>> newShape;

    int X = shape[0].size();
    int Y = shape.size();

    for (int x = 0; x < X; ++x)
    {
        vector<int> v;

        for (int y = 0; y < Y; ++y)
        {
            v.push_back(shape[y][X - 1 - x]);
        }

        newShape.push_back(v);
    }

    return newShape;
}

void print_shape(vector<vector<int>> shape)
{
    int X = shape[0].size();
    int Y = shape.size();

    for (int y = 0; y < Y; ++y)
    {
        for (int x = 0; x < X; ++x)
        {
            cout << shape[y][x] << ' ';
        }
        cout << '\n';
    }
}

bool equals_raw(vector<vector<int>> s1, vector<vector<int>> s2)
{
    int X1 = s1[0].size();
    int Y1 = s1.size();

    int X2 = s2[0].size();
    int Y2 = s2.size();

    if (X1 == X2 && Y1 == Y2)
    {
        for (int y = 0; y < Y1; ++y)
        {
            for (int x = 0; x < X1; ++x)
            {
                if (s1[y][x] != s2[y][x])
                    return false;
            }
        }
    }
    else
        return false;

    return true;
}

bool equals(vector<vector<int>> s1, vector<vector<int>> s2)
{
    vector<vector<int>> r;

    if (equals_raw(s1, s2))
        return true;

    for (int i = 0; i < 3; ++i)
    {
        r = rotate(s2);
        if (equals_raw(s1, r))
            return true;
    }

    return false;
}

unordered_set

    int
    solution(vector<vector<int>> game_board, vector<vector<int>> table)
{
    int answer = -1;

    return answer;
}