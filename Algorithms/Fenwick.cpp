#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
class NumArray {

public:
    vector<ll> bit_arr;
    vector<ll> arr;
    NumArray(vector<ll> nums) {
        arr = nums;
        ll n = nums.size();
        bit_arr.clear();
        bit_arr.resize(n+1);
        for(ll i=0;i<nums.size();++i) add(i+1, nums[i]);
    }
    
    void update(ll i, ll val) {
        ll diff = val - arr[i];
        arr[i] = val;
        add(i+1,diff);
    }
    
    ll sumRange(ll i, ll j) {
        ll b = sum(j+1);
        ll a = sum(i);
        return b-a;
        
    }
    void add(ll idx, ll val)
    {
	    while(idx<bit_arr.size())
	    {
	    	bit_arr[idx] += val;
	    	idx += (idx & -idx);
	    }
    }
    ll sum(ll idx)
    {
    	ll result = 0;
    	while(idx)
    	{
    		result+= bit_arr[idx];
    		idx -= idx & -idx;
    	}
    	return result;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * ll param_2 = obj.sumRange(i,j);
 */
 int main()
 {
 	ll t;
 	cin>>t;
 	while(t--)
 	{
 		ll n;
		cin>>n;
		vector<ll> arr(n);
		for(ll i=0;i<n;++i) cin>>arr[i];
		ll ma = INT_MIN;
		for(ll i=0;i<n;++i) ma = max(ma, arr[i]);
		vector<ll> temp(ma+2);
		NumArray* obj = new NumArray(temp);
		ll co = 0;
		for(ll i=0;i<n;++i)
		{
			co += obj->sumRange(arr[i],ma);
			obj->add(arr[i],1);	
		}	
		cout<<co<<endl;
	}
 }
 
