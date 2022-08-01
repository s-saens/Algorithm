#include<iostream>
#define k(i)t[n].c[i]
using namespace std;struct P{int c[2];};int main(){long long N,K,n=1;P t[200001];cin>>N;for(int n=1;n<=N;++n){cin>>k(0)>>k(1);}cin>>K;while(k(0)>-1||k(1)>-1)if(k(0)==-1)n=k(1);else if(k(1)==-1)n=k(0);else n=k(1-K&1),K=K&1?K/2+1:K/2;cout<<n;}