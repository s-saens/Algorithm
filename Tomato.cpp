#include <iostream>
#include <queue>
#define FOR(x,n) for(int x=0 ; x<n ; ++x)

using namespace std;

int dirM[22] = {1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int dirN[22] = {0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int dirO[22] = {0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int dirP[22] = {0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int dirQ[22] = {0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int dirR[22] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int dirS[22] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0};
int dirT[22] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0};
int dirU[22] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0};
int dirV[22] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0};
int dirW[22] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1};

struct Vector11
{
    int m, n, o, p, q, r, s, t, u, v, w;
    int days = 0;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M,N,O,P,Q,R,S,T,U,V,W;
    cin>>M>>N>>O>>P>>Q>>R>>S>>T>>U>>V>>W;
    int tomatos[W][V][U][T][S][R][Q][P][O][N][M];
    int total = M*N*O*P*Q*R*S*T*U*V*W;

    queue<Vector11> qu;

    FOR(w, W)FOR(v, V)FOR(u, U)FOR(t, T)FOR(s, S)FOR(r, R)FOR(q, Q)FOR(p, P)FOR(o, O)FOR(n, N)FOR(m, M)
    {
        cin >> tomatos[w][v][u][t][s][r][q][p][o][n][m];
        Vector11 vec;
        vec.w = w; vec.v = v; vec.u = u; vec.t = t; vec.s = s; vec.r = r; vec.q = q; vec.p = p; vec.o = o; vec.n = n; vec.m = m;

        if (tomatos[w][v][u][t][s][r][q][p][o][n][m] == 1) qu.push(vec);
        else if (tomatos[w][v][u][t][s][r][q][p][o][n][m] == -1) total--;
    }

    int days = 0;
    int rippedCnt = 0;

    while (!qu.empty())
    {
        Vector11 f = qu.front();
        qu.pop();
        rippedCnt++;
        days = f.days;

        for (int i = 0; i < 6; ++i)
        {
            int newIndexM = f.m + dirM[i];
            int newIndexN = f.n + dirN[i];
            int newIndexO = f.o + dirO[i];
            int newIndexP = f.p + dirP[i];
            int newIndexQ = f.q + dirQ[i];
            int newIndexR = f.r + dirR[i];
            int newIndexS = f.s + dirS[i];
            int newIndexT = f.t + dirT[i];
            int newIndexU = f.u + dirU[i];
            int newIndexV = f.v + dirV[i];
            int newIndexW = f.w + dirW[i];

            if (newIndexM >= M || newIndexM < 0
             || newIndexN >= N || newIndexN < 0
             || newIndexO >= O || newIndexO < 0
             || newIndexP >= P || newIndexP < 0
             || newIndexQ >= Q || newIndexQ < 0
             || newIndexR >= R || newIndexR < 0
             || newIndexS >= S || newIndexS < 0
             || newIndexT >= T || newIndexT < 0
             || newIndexU >= U || newIndexU < 0
             || newIndexV >= V || newIndexV < 0
             || newIndexW >= W || newIndexW < 0)
            {
                continue;
            }

            int *state = &tomatos[newIndexW][newIndexV]
                        [newIndexU][newIndexT][newIndexS]
                        [newIndexR][newIndexQ][newIndexP]
                        [newIndexO][newIndexN][newIndexM];

            if (*state == 0)
            {
                *state = 1;
                Vector11 vec;
                vec.w = newIndexW;
                vec.v = newIndexV;
                vec.u = newIndexU;
                vec.t = newIndexT;
                vec.s = newIndexS;
                vec.r = newIndexR;
                vec.q = newIndexQ;
                vec.p = newIndexP;
                vec.o = newIndexO;
                vec.n = newIndexN;
                vec.m = newIndexM;
                vec.days = f.days + 1;
                qu.push(vec);
            }
        }
    }

    if (rippedCnt == total)
    {
        cout << days;
    }
    else
    {
        cout << -1;
    }

    return 0;
}