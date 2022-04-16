#include <iostream>

#define ll long long int
using namespace std;

int** paper;

int cntm1 = 0;
int cntp1 = 0;
int cnt0 = 0;

void CountPapers(int sx, int sy, int len)
{
    int size = len * len;
    int cm1 = 0;
    int cp1 = 0;
    int c0 = 0;
    for(int y=sy ; y<sy+len ; ++y)
        for(int x=sx ; x<sx+len ; ++x)
        {
            if(paper[y][x] == -1) cm1++;
            else if(paper[y][x] == 0) c0++;
            else if(paper[y][x] == 1) cp1++;
        }
            
    
    if(cm1 == size) { cntm1++; return; }
    if(cp1 == size) { cntp1++; return; }
    if(c0 == size) { cnt0++; return; }

    int newLen = len/3;
    for(int y=0 ; y<3 ; ++y)
        for(int x=0 ; x<3 ; ++x)
            CountPapers(sx + x*newLen, sy + y*newLen, newLen);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    paper = new int*[N];
    for(int i=0 ; i<N ; ++i) paper[i] = new int[N];

    for(int y=0 ; y<N ; ++y)
        for(int x=0 ; x<N ; ++x)
            cin >> paper[y][x];

    CountPapers(0, 0, N);

    cout << cntm1 << "\n";
    cout << cnt0 << "\n";
    cout << cntp1 << "\n";

    return 0;
}