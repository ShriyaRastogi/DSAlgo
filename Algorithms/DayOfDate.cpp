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
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		ll date,month,year;
		cin>>date>>month>>year;
		ll odd = 0;
		year = year%400;
		ll hund = year/100;
		if(hund==1) odd+=5;
		else if(hund==2) odd+=3;
		else if(hund==3) odd+=1;
		year = year%100;
		ll y = year-1;
		odd += (y/4)*2 + (y-(y/4))*1; // leap year has 2 odd days and normal year has 1
		vector<ll> mon = {31,28,31,30,31,30,31,31,30,31,30,31};
		// if leap year, remove add 1
		if((year%4==0 && year%100 != 0) || (year%400==0)) mon[1]++;
		
		for(ll i=0;i<12;++i) mon[i] = mon[i]%7;
		for(ll i=0;i<month-1;++i) odd+=mon[i];
		odd+=date;
		
		odd = odd %7;
		vector<string> ans = {"Sunday","Monday","Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
		cout<<ans[odd]<<endl;
	}
}