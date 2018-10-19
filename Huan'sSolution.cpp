#include<bits/stdc++.h>
using namespace std;
#define maxn 501
#define maxc 1000000000
#define huan autodeptrai
long c[maxn],d[maxn][maxn],n,P,a[maxn][maxn],ans[maxn],vt=1;
void visit(long u)
{   
	d[u][1]=c[u];
	for(long v=1;v<=n;v++)
	if(a[u][v]==1){
	    a[v][u]=0;
	    visit(v);
	    for(long i=P;i>=1;i--)
	      	for(long j=1;j<=i-1;j++)
	        	if(d[u][i]<d[u][j]+d[v][i-j]){
		        	d[u][i]=d[u][j]+d[v][i-j];
	        	}
	}
}
void xuli(){
	long u;
	visit(1);
	for(u=2;u<=n;u++)
	  	if(d[u][P]>d[vt][P])
	    	vt=u;
}
void init(){
	for(long u=1;u<=n;u++)
	  	for(long k=1;k<=n;k++)
	    	 d[u][k]=-maxc;
} 
void enter()
{
	long i,u,v;
	cin>>n>>P;
	for(i=1;i<=n;i++)
	  	cin>>c[i];
	for(i=1;i<=n-1;i++){
		cin>>u>>v;
		a[u][v]=1;
		a[v][u]=1;
	}
}  
void xuat(){
	// huan da xuat sai yeu cau
	cout<<d[vt][P]<<endl;
}       
int main(){
	enter();
	init();
	xuli();
	xuat();
}    
