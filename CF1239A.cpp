#pragma GCC optimize("2,Ofast,inline")
#pragma GCC diagnostic error "-std=c++11"
#include<bits/stdc++.h>
#define LL long long
#define int LL
#define P pair<int,int>
#define fi first
#define se second
const LL N=1e5+10;
const LL mod=1e9+7;
const LL inf=0x3f3f3f;
const double eps=1e-9;
using namespace std;
template<typename tp> inline void read(tp &x)
{
    x=0;char c=getchar();
    bool f=0; for(; c<'0'||c>'9'; f|=(c=='-'),c = getchar());
    for(; c>='0'&&c<='9'; x=(x<<3)+(x<<1)+c-'0',c = getchar());
    if(f) x=-x;
}
int n,m;
int dp[N][3];
int dp2[N][3];
signed main()
{
	read(n),read(m);
	dp[1][0]=2;
	for(int i=2;i<=m;i++)
	{
		dp[i][0]=(dp[i-1][0]+dp[i-1][1])%mod;
		dp[i][1]=dp[i-1][0]%mod;
	}
//	cout<<dp[m][0]<<" "<<dp[m][1]<<endl;
	dp2[1][0]=2;
	for(int i=2;i<=n;i++)
	{
		dp2[i][1]=dp2[i-1][0]%mod;
		dp2[i][0]=(dp2[i-1][1]+dp2[i-1][0])%mod;
	}
//	cout<<dp2[2][1]+dp2[2][0]<<endl;
	printf("%lld\n",(dp[m][1]+dp[m][0]+dp2[n][1]+dp2[n][0]-2)%mod);
	return 0;
}
