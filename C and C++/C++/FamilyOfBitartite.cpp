#include<stdio.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
const int mod=1e9+7;
inline int add(int a,int b){a+=b;if(a>=mod)a-=mod;return a;}
inline int sub(int a,int b){a-=b;if(a<0)a+=mod;return a;}
inline int mul(int a,int b){return (a*1ll*b)%mod;}

const int N=2500;
int dp[N+1][N+1],ncr[N+1][N+1],pows[N+1][N+1];
int main()
{
	for(int i=0;i<=N;i++){
		ncr[i][0]=1;
		pows[i][0]=1;
		for(int j=1;j<=i;j++)
			ncr[i][j]=add(ncr[i-1][j],ncr[i-1][j-1]);
		int a=add(ncr[i][2],i);
		for(int j=1;j<=N;j++)
			pows[i][j]=mul(pows[i][j-1],a);
	}
	for(int n=1;n<=N;n++){
		int M=N/n;
		dp[n][1]=1;
		for(int m=2;m<=M;m++){
			dp[n][m]=pows[m-1][n];
			for(int i=1;i<=n;i++)
				for(int j=1;j<m;j++)
					dp[n][m]=add(dp[n][m],mul(ncr[n][i],mul(dp[i][j],pows[m-j][n-i])));
			dp[n][m]=sub(pows[m][n],dp[n][m]);
		}
	}
	int t; 
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		printf("%d\n",dp[n][m]);
	}
}