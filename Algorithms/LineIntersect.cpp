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
struct point
{
	ll x,y;
	point() { }
	point(ll a, ll b)
	{
		x = a;
		y = b;
	}
};
ll direction(point p1, point p2, point p3)
{
	ll x1 = p2.x-p1.x;
	ll x2 = p3.x-p1.x;
	ll y1 = p2.y-p1.y;
	ll y2 = p3.y-p1.y;
	return (x1*y2) - (x2*y1);
}
bool onseg(point p1, point p2, point p3)
{
	if(min(p1.x,p2.x) <= p3.x && max(p1.x,p2.x) >= p3.x && min(p1.y,p2.y) <= p3.y && max(p1.y,p2.y) >= p3.y ) return true;
	return false;
}
bool intersect(point p1, point p2, point p3, point p4)
{
	ll d1 = direction(p1,p2,p3);
	ll d2 = direction(p1,p2,p4);
	ll d3 = direction(p3,p4,p1);
	ll d4 = direction(p3,p4,p2);
	//cout<<d1<<" "<<d2<<" "<<d3<<" "<<d4<<endl;
	
	if(d1*d2<0 && d3*d4<0) return true;
	else if(d1==0 && onseg(p1,p2,p3)) return true;
	else if(d2==0 && onseg(p1,p2,p4)) return true;
	else if(d3==0 && onseg(p3,p4,p1)) return true;
	else if(d4==0 && onseg(p3,p4,p2)) return true;
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		ll x1,y1,x2,y2,x3,y3,x4,y4;
		cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
		point p1(x1,y1);
		point p2(x2,y2);
		point p3(x3,y3);
		point p4(x4,y4);
		cout<<intersect(p1,p2,p3,p4)<<endl;		
	}
}