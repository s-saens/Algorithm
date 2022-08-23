#include <iostream>
#include <queue>
#define F(i,e)for(int i=0;i<e;++i)
using namespace std;struct T{int i=0,s=0,w=0;};
int main(){int r=0,e=0,a=1,p=0,s[11],d[11]={1};F(i,11){cin>>s[i];a*=s[i];}F(i,11)if(i)d[i]=s[i-1]*d[i-1];T t[a];queue<T> q;F(i,a){cin>>t[i].s;t[i].i=i;if(t[i].s>0)q.push(t[i]);else if(t[i].s<0)e++;}while (!q.empty()){T f=q.front();q.pop();r++;p=f.w;F(i,22){int k=i/2,m=1-2*(i%2),n=f.i+m*d[k],v=d[k]*s[k],x=f.i%v,y=n%v;if(n>=0&&n<a&&m*(y-x)>0&&!t[n].s){t[n]={n,1,f.w+1};q.push(t[n]);}}}if(r+e-a||r<=0)p=-1;cout<<p;}