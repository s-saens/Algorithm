r,p,c,h,a=1,s[11],d[11]={1},g,i,w;main(){for(i=0;i<11;++i)scanf(w="%d",s+i),a*=s[i],i?d[i]=s[i-1]*d[i-1]:0;int t[a],q[a];for(i=0;i<a;++i)scanf(w,&g),t[i]=g,g>0?q[h++]=i:0,g<0?r++:0;while(c<h){g=q[c++];r++;p=t[g]-1;for(i=0;i<22;++i){int k=i/2,m=i%2?-1:1,n=g+m*d[k],v=d[k]*s[k];n>=0&&n<a&&n%v*m>g%v*m&&!t[n]?q[h++]=n,t[n]=t[g]+1:0;}}printf(w,r<a?-1:p);}