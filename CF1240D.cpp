#include<bits/stdc++.h>
#define LL long long
#define int LL
#define P pair<int,int>
#define fi first
#define se second
const LL N=3e5+10;
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
int n,T,a[N],nxt[N],F[N],ans;
map<int,int> Map[N];
signed main()
{
	read(T);
	while(T--)
	{
		read(n),ans=0;
		for(int i=1;i<=n;i++) read(a[i]);
		for(int i=1;i<=n+10;i++)
			nxt[i]=F[i]=0,Map[i].clear();
		nxt[n]=n;
		for(int i=n-1;i>=1;i--)
		{
			if(a[i]==a[i+1]) nxt[i]=i+1;
			else 
			{
				if(Map[i+1].count(a[i]))
					nxt[i]=Map[i+1][a[i]];
				else nxt[i]=i;
			}
			if(nxt[i]!=i) swap(Map[i],Map[nxt[i]+1]);
			if(nxt[i]+1<=n&&nxt[i]!=i)
				Map[i][a[nxt[i]+1]]=nxt[i]+1;
		}
		for(int i=n;i>=1;i--)
			if(nxt[i]!=i)
				F[i]=F[nxt[i]+1]+1;
		for(int i=1;i<=n;i++)
			ans+=F[i];
		printf("%lld\n",ans);
	}
	return 0;
}
