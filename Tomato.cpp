#include <iostream>
#include <queue>
#define FOR(x,n) for(int x=0 ; x<n ; ++x)

using namespace std;

int d1[22] = {1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int d2[22] = {0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int d3[22] = {0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int d4[22] = {0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int d5[22] = {0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int d6[22] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int d7[22] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0};
int d8[22] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0};
int d9[22] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0};
int d10[22] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0};
int d11[22] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1};

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
        cout << f.m + f.n*M + f.o*M*N + f.p*M*N*O + f.q*M*N*O*P + f.r*M*N*O*P*Q + f.s*M*N*O*P*Q*R + f.t*M*N*O*P*Q*R*S
                + f.u*M*N*O*P*Q*R*S*T + f.v*M*N*O*P*Q*R*S*T*U + f.w*M*N*O*P*Q*R*S*T*U*V << ' ';

        for (int i = 0; i < 22; ++i)
        {
            int newIndexM = f.m + d1[i];
            int newIndexN = f.n + d2[i];
            int newIndexO = f.o + d3[i];
            int newIndexP = f.p + d4[i];
            int newIndexQ = f.q + d5[i];
            int newIndexR = f.r + d6[i];
            int newIndexS = f.s + d7[i];
            int newIndexT = f.t + d8[i];
            int newIndexU = f.u + d9[i];
            int newIndexV = f.v + d10[i];
            int newIndexW = f.w + d11[i];

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

    cout << "\n";

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