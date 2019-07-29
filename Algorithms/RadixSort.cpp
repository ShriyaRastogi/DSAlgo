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
ll gcd(ll a,ll b) { if (b == 0) return a; return gcd(b, a % b);  }
ll mod(ll x) { return x%MOD; }
ll power(ll x,ll y, ll p) { ll res = 1; x = x % p; while (y > 0) { if (y & 1) res = (res*x) % p; y = y>>1; x = (x*x) % p;   } return res; } 
//class compare { public: bool operator() (ll a,ll b) { return a>b;};
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vector<ll> arr(n);
		for(ll i=0;i<n;++i) cin>>arr[i];
		ll po = 1;
		for(ll i=0;i<n;++i)
		{
			ll temp = floor(log(arr[i])/log(10))+1;
			po = max(po,temp);
		}
		for(ll p=1;p<=po;++p)
		{
			ll ten = pow(10,p);
			vector< vector<ll> > buc(10);
			for(ll i=0;i<n;++i) 
			{
				ll pr = (arr[i]/ten)%10;
				buc[pr].push_back(arr[i]);
			}
			ll co = 0;
			for(auto i:buc)
			{
				for(auto j:i)
				{
					arr[co] = j;
					++co;
				}
			}	
		}	
		print2(arr,arr.size());
	}
}