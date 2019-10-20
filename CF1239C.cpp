#pragma GCC optimize("2,Ofast,inline")
#pragma GCC diagnostic error "-std=c++11"
#include<bits/stdc++.h>
#define LL long long
#define P pair<int,int>
#define int LL
#define fi first
#define se second
const LL N=1e6+10;
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
P s[N];
set<LL>Set;
set<LL>::iterator it;
LL ans[N];
deque<int> de;
signed main()
{
	LL n,p,t,minn=0;
	read(n),read(p);
	for(int i=1;i<=n;i++) 
		read(t), s[i]=P(t,i);
	sort(s+1,s+n+1);
	LL x=1, T=0;
	while(1)
	{
		while(x<=n&&s[x].fi<=T) 
		{
			if(minn>s[x].se) de.push_back(s[x].se),minn=s[x].se;
			else Set.insert(s[x].se);
			x++;
		}
		if(de.empty()&&!Set.empty())
		{
			it=Set.begin();
			de.push_back(*it); 
			minn=*it;
			Set.erase(it);
		}
		if(x<=n&&de.empty()&&Set.empty())
		{
			T=s[x].fi;de.push_back(s[x].se);minn=s[x].se; x++;
			while(x<=n&&s[x].fi<=T) 
			{
				if(minn>s[x].se) de.push_back(s[x].se),minn=s[x].se;
				else Set.insert(s[x].se);
				x++;
			}
		}
		if(de.empty()) break;
		T+=p; ans[de.front()]=T;
		de.pop_front();
	}
	for(int i=1;i<=n;i++)
		printf("%lld ",ans[i]);
	printf("\n");
	return 0;
}
