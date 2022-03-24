#include <iostream>

using namespace std;

/* 연습장

     o     
    o o    
   ooooo   
  o     o  
 o o   o o 
ooooo ooooo

s1 = GetStars()

*/

string* map;

void F(int x, int y, int length)
{
    if(length == 3)
    {
        for(int i=y ; i>y-3 ; --i)
        {
            for(int j=x ; j<=x+4 ; ++j)
            {
                if(i % 3 == 2)
                {
                    map[i][j] = '*';
                }
                else if(i % 3 == 1 && (j == x+1 || j == x+3))
                {
                    map[i][j] = '*';
                }
                else if(i % 3 == 0 && j == x+2)
                {
                    map[i][j] = '*';
                }
            }
        }
        return;
    }

    F(x, y, length/2); // 왼쪽 아래
    F(x + length, y, length/2); // 오른쪽 아래
    F(x + (length/2), y - (length/2), length/2); // 위
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    string m[N];
    map = m;

    for(int i=0 ; i<N ; ++i)
    {
        for(int j=0 ; j<N*2-1 ; ++j)
        {
            map[i] += ' ';
        }
    }

    F(0, N-1, N);

    for(int i=0 ; i<N ; ++i)
    {
        cout << m[i] << "\n";
    }


    return 0;
}