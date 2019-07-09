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

ll power(ll x,ll y, ll p) { ll res = 1; x = x % p; while (y > 0) { if (y & 1) res = (res*x) % p; y = y>>1; x = (x*x) % p;   } return res; } 
ll mod(ll x)
{
	return x%MOD;
}
//class compare { public: bool operator() (ll a,ll b) { return a>b;};
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		ll x,y,z;
		cin>>x>>y>>z;
		vector< vector< vector<ll> > > dp(x+1, vector< vector<ll> >(y+1, vector<ll>(z+1)));
		vector< vector< vector<ll> > > terms(x+1, vector< vector<ll> >(y+1, vector<ll>(z+1)));
		if(x>0)terms[1][0][0] = 1;
		if(y>0)terms[0][1][0] = 1;
		if(z>0)terms[0][0][1] = 1;
		if(x>0)dp[1][0][0] = 4;
		if(y>0)dp[0][1][0] = 5;
		if(z>0)dp[0][0][1] = 6;
		ll sum = 0;
		for(ll i=0;i<=x;++i)
		{
			for(ll j=0;j<=y;++j)
			{
				for(ll k=0;k<=z;++k)
				{
					if(i-1>=0) 
					{
						dp[i][j][k] = mod(mod(dp[i][j][k]) +   mod(mod(dp[i-1][j][k]*10) + mod(4*terms[i-1][j][k])));
						terms[i][j][k] = mod(terms[i][j][k] + terms[i-1][j][k]);
					}
					if(j-1>=0) 
					{

						dp[i][j][k] = mod(mod(dp[i][j][k]) +   mod(mod(dp[i][j-1][k]*10) + mod(5*terms[i][j-1][k])));
						terms[i][j][k] = mod(terms[i][j][k] + terms[i][j-1][k]);
				
					}
					if(k-1>=0) 
					{

						dp[i][j][k] = mod(mod(dp[i][j][k]) +   mod(mod(dp[i][j][k-1]*10) + mod(6*terms[i][j][k-1])));
						terms[i][j][k] = mod(terms[i][j][k] + terms[i][j][k-1]);
						
					}
					sum+=dp[i][j][k];
				}
			}
		}
		cout<<sum<<endl;
	}
}