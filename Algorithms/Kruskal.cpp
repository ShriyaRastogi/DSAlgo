#include<bits/stdc++.h>
#define Loop(i,a,b) for(int i=a;i<b;++i)
#define NLoop(i,a,b) for(int i=a;i>=b;--i)
#define print(arr,n,m) for(int i=0;i<n;++i) { for(int j=0;j<m;++j) cout<<arr[i][j]<<" "; cout<<endl; }
#define print2(arr,n) for(int i=0;i<n;++i) { cout<<arr[i]<<" "; } cout<<endl;
#define mp(a,b) make_pair(a,b)
#define MOD 1000000007
#define pb(x) push_back(x)
#define ub(x,el) upper_bound(x.begin(),x.end(),el) - x.begin()
#define lb(x,el) lower_bound(x.begin(),x.end(),el) - x.begin();
#define bs(x,el) binary_search(x.begin(),x.end(),el)
using namespace std;
typedef long long int ll;
ll n;
vector< ll > arr,size;
struct edge
{
	ll u,v,w;
	edge() {}
	edge(ll a, ll b, ll c)
	{
		u = a;
		v = b;
		w = c;
	}
};
struct compare {
    bool operator() (const edge& lhs, const edge& rhs) const {
        if(lhs.w != rhs.w) return lhs.w < rhs.w;
        if(lhs.u != rhs.u) return lhs.u < rhs.u;
        return lhs.v < rhs.v;
    }
};
ll root(ll i)
{
	while(i!=arr[i])
	{
		arr[i] = arr[arr[i]];
		i = arr[i];
	}
	return i;
}
bool find(ll u, ll v)
{
	ll root_u = root(u);
	ll root_v = root(v);
	return root_u == root_v;
}
void uni(ll u, ll v)
{
	ll root_u = root(u);
	ll root_v = root(v);
	if(size[root_v] > size[root_u])
	{
		arr[root_u] = root_v;
		size[root_v] += size[root_u]; 
	}
	else
	{
		arr[root_v] = root_u;
		size[root_u] += size[root_v];
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll e;
	cin>>n>>e;
	arr.resize(n+1);
	size.resize(n+1,1);
	set<edge,compare> st;
	for(ll i=0;i<e;++i)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		st.insert(edge(a,b,c));
	}
	for(ll i=1;i<=n;++i) arr[i] = i;
	auto it = st.begin();
	ll co = 0;
	ll sum = 0;
	while(it!=st.end())
	{
		ll u = it->u;
		ll v = it->v;
		if(!find(u,v)) 
		{
			uni(u,v);
			++co;
			sum += it->w;
		}
		if(co == n-1) break;
		++it;
	}
	cout<<sum<<endl;
	
}
