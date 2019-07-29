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
string add(string &s)
{
	string ans;
	ll sum = 0;
	ll carry = 1;
	for(ll i=s.size()-1;i>=0;--i)
	{
		ll num = s[i]-'0';
	//	cout<<num<<" "<<carry<<endl;
		num+=carry;
		carry = num/10;
		num = num%10;
		ans+=char(num+'0');
		
	}
	if(carry) ans+=(carry+'0');
	reverse(ans.begin(),ans.end());
	return ans;
}
string nextPal(string &s)
{
	ll n = s.size();
	if(n==1)
	{
		if(s[0] < '9') return add(s);
		return "11";
	}
	if(n%2==0)
	{
		string left = s.substr(0,n/2);
		string right = s.substr(n/2);
		ll l = left.size()-1;
		ll r = 0;
		bool ok = false;
		while(l>=0 && r<right.size())
		{
			if(left[l] > right[r]) 
			{
				ok = true;
				break;
			}
			else if(left[l] < right[r]) break;
			--l;
			++r;
		}
		if(ok)
		{
			string ans;
			ans += left;
			reverse(left.begin(),left.end());
			ans += left;
			return ans;
		}
		left = add(left);
	//	cout<<left<<endl;
		string ans;
		ans+=left;
		if(left.size()==(n/2))
		{
			reverse(left.begin(),left.end());
			ans+=left;
			return ans;
		}
		ll i = left.size()-2;
		while(i>=0)
		{
			ans+=left[i];
			--i;
		}
		return ans;
	}
	string left = s.substr(0,n/2 + 1);
	string right = s.substr(n/2 + 1);
	ll l = left.size()-2;
	ll r = 0;
	bool ok = false;
	while(l>=0 && r<right.size())
	{
		if(left[l] > right[r]) 
		{
			ok = true;
			break;
		}
		else if(left[l] < right[r]) break;
		--l;
		++r;
	}
	if(ok)
	{
		string ans;
		ans += left;
		reverse(left.begin(),left.end());
		for(ll i=1;i<left.size();++i) ans+=left[i];
		return ans;
	}
	ll prevs = left.size();
	left = add(left);
//	cout<<left<<endl;
	string ans;
	ans+=left;
	if(left.size()==prevs)
	{	
		reverse(left.begin(),left.end());
		for(ll i=1;i<left.size();++i) ans+=left[i];
		return ans;
	}
	ll i = left.size()-3;
	while(i>=0)
	{
		ans+=left[i];
		--i;
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		string ans = nextPal(s);
		cout<<ans<<endl;
	}
}