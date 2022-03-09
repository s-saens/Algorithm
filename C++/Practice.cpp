#include <iostream>

using namespace std;

struct Point
{
    int column;
    short row;
};

bool visited[6][6];

int main()
{
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            visited[i][j] = false;
        }
    }

    Point firstPoint, lastPoint;

    string input;
    cin >> input;

    lastPoint.column = (int)input[0] - (int)'A';
    lastPoint.row = (int)input[1] - (int)'1';

    visited[lastPoint.column][lastPoint.row] = true;

    firstPoint.column = lastPoint.column;
    firstPoint.row = lastPoint.row;

    bool valid = true;

    for (int i = 1; i < 36; ++i)
    {
        Point p;
        cin >> input;
        p.column = (int)input[0] - (int)'A';
        p.row = (int)input[1] - (int)'1';

        // cout << p.column << ", " << p.row << "\n";

        if (visited[p.column][p.row])
        {
            valid = false;
        }

        int deltaColumn = abs(p.column - lastPoint.column);
        int deltaRow = abs(p.row - lastPoint.row);

        if (deltaRow + deltaColumn != 3 || deltaRow * deltaColumn != 2)
        {
            valid = false;
        }

        lastPoint.column = p.column;
        lastPoint.row = p.row;
        
        visited[p.column][p.row] = true;
    }

    int dC = abs(lastPoint.column - firstPoint.column);
    int dR = abs(lastPoint.row - firstPoint.row);

        if (dC + dR != 3 || dC * dR != 2)
    {
        valid = false;
    }


    if (valid)
    {
        cout << "Valid";
    }
    else
    {
        cout << "Invalid";
    }

    return 0;
}