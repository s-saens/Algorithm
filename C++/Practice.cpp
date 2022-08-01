#include <iostream>
#define F(i, e) for (int i = 0; i < e; ++i)
#define k(i) t[n].c[i]
using namespace std;
struct P{int c[2];};
int main()
{
    long long N,K,n=0;
    P t[200001];
    cin>>N;
    F(n, N)F(j, 2){cin >> k(j);k(j)--;}
    cin>>K;K--;
    while(k(0)>-2||k(1)>-2)
        if(k(0)==-2)n=k(1);
        else if(k(1)==-2)n=k(0);
        else n=k(K%2),K=K&1?K/2:K-K/2;
    cout<<n+1;
}