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
#define deb(x) cout<<#x<<" "<<x<<endl;
using namespace std;
typedef long long int ll;
ll gcd(ll a,ll b) { if (b == 0) return a; return gcd(b, a % b);  }
ll mod(ll x) { return x%MOD; }
ll power(ll x,ll y, ll p) { ll res = 1; x = x % p; while (y > 0) { if (y & 1) res = (res*x) % p; y = y>>1; x = (x*x) % p;   } return res; } 
//class compare { public: bool operator() (ll a,ll b) { return a>b;};
ll getLeap(ll y, ll m)
{
	if(m>2) return y/4 - y/100 + y/400;
	return (y-1)/4 - (y-1)/100 + (y-1)/400;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		ll d1,m1,y1;
		ll d2,m2,y2;
		d2 = 12;
		m2 = 8;
		y2 = 2019;
		cin>>d1>>m1>>y1;
		vector<ll> arr = {31,28,31,30,31,30,31,31,30,31,30,31};
		
		ll count1 = y1*365;
		for(ll i=0;i<m1-1;++i) count1+= arr[i];
		count1+= d1;
		count1+= getLeap(y1,m1); 
		
			
		ll count2 = y2*365;
		for(ll i=0;i<m2-1;++i) count2+= arr[i];
		count2+= d2;
		count2+= getLeap(y2,m2); 
		vector<string> arr2 = {"Sunday", "Monday", "Tuesday", "Wednesday","Thursday","Friday","Saturday"};
		if(count2 > count1)
		{
			ll temp = (count2-count1)%7;
			temp = (7-temp)%7;
			cout<<arr2[(temp+1)%7]<<endl;
		}
		else
		{
			ll temp = (count1-count2)%7;
			cout<<arr2[(temp+1)%7]<<endl;
		}
		
	}
}