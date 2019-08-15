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
bool compare(pair<ll,ll> a, pair<ll,ll> b)
{
	if(a.first != b.first) return a.first < b.first;
	return a.second > b.second;
}
void buildHeap(vector< pair<ll,ll> > &arr, ll start, ll end)
{
	for(ll i=start;i<=end;++i)
	{
		ll j = i;
		while(j>0)
		{
			ll par = (j-1)/2;
			if(compare(arr[par],arr[j]))
			{
				swap(arr[par],arr[j]);
				j = par;
			}
			else break;
		}
	}
}
void heapify(vector< pair<ll,ll> > &arr, ll start, ll end)
{
	ll j = start;
	while(j<end)
	{
		ll l = 2*j + 1;
		ll r = 2*j + 2;
		if(l<end && r<end)
		{
			if(compare(arr[j],arr[l]) && compare(arr[r],arr[l]))
			{
				swap(arr[j],arr[l]);
			//	cout<<"yo"<<endl;
				j = l;
				continue;
			}
			else if(compare(arr[j],arr[r]) && compare(arr[l],arr[r]))
			{
				swap(arr[j],arr[r]);
		//		cout<<"yo"<<endl;
				j = r;
				continue;
			}
			else break;
		//	cout<<"yo"<<endl;
		}
		else if(l<end)
		{
		//	cout<<"yo"<<" "<<j<<" "<<l<<endl;
			if(compare(arr[j],arr[l]))
			{
				swap(arr[j],arr[l]);
				j = l;
			}
			else break;
		}
		else break;
	}
	ll l = 2*j+1;
	if(l<end)
	{
		if(compare(arr[j],arr[l]))
		{
			swap(arr[j],arr[l]);
		}
	}
}
void heapSort(vector< pair<ll,ll> > &arr, ll start, ll end)
{
	buildHeap(arr,start,end);
	
	for(ll i=end;i>=start;--i)
	{
		
		swap(arr[start],arr[i]);
		heapify(arr,start,i);
		
	}
}
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
		vector< pair<ll, ll> > arr(n);
		for(ll i=0;i<n;++i)
		{
			ll a,b;
			cin>>a>>b;
			arr[i].first = a;
			arr[i].second = b;
		}
		heapSort(arr,0,n-1);
		cout<<"__"<<endl;
		for(ll i=0;i<n;++i)
		{
			cout<<arr[i].first<<" "<<arr[i].second<<endl;
		}
	}
}