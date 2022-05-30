#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
#define F(i,N) for(int i=0;i<N;++i)
struct T{int l=0,s=0,d=0;};
int main(){int p=11,r=0,e=0,t=1,d=0,s[p];F(i,p){cin>>s[i];t*=s[i];}int w[p * 2];F(i,p){int m=1;F(j,i)m*=s[j];w[i*2]=m;w[i*2+1]=-m;}T y[t];queue<T> q;F(i,t){cin >> y[i].s;y[i].l=i;if(y[i].s==1) q.push(y[i]);else if(y[i].s == -1)e++;}while(!q.empty()){T f=q.front();q.pop();r++;d=f.d;F(i,p*2){bool n=i%2;int c=f.l+w[i],v=abs(w[i]),b=v*s[i/2],x=f.l%b,z=c%b;if(c<0||c>=t||abs(x-z)!=v||n&&z>x||!n&&z<x)continue;if(y[c].s == 0){y[c].s = 1;y[c].d = f.d + 1;q.push(y[c]);}}}if(r==t-e&&r>0)cout<<d;else cout<<-1;return 0;}