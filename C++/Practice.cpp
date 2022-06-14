#include <iostream>
#include <queue>
#define FOR(i,s,e) for(int i=s;i<e;++i)
using namespace std;struct T{int i=0,s=0,w=0;};int main(){int r=0,e=0,a=1,p=0,s[11],d[11]={1};FOR(i,0,11){cin>>s[i];a*=s[i];}FOR(i,1,11)d[i]=s[i-1]*d[i-1];T t[a];queue<T> q;FOR(i,0,a){cin>>t[i].s;t[i].i=i;if(t[i].s==1)q.push(t[i]);else if(t[i].s==-1)e++;}while(!q.empty()){T f=q.front();q.pop();r++;p=f.w;FOR(i,0,22){int m=i%2,n=f.i+d[i/2]*(1-m*2),v=d[i/2]*s[i/2],x=f.i%v,y=n%v;if(n<0||n>=a||m&&y>=x||!m&&y<=x)continue;if(t[n].s==0){t[n].s=1;t[n].w=f.w+1;q.push(t[n]);}}}if(r==a-e&&r>0)cout<<p;else cout<<-1;return 0;}