#include<bits/stdc++.h>
using namespace std;
//int *arr;
//int *tree;
vector<int> arr,tree,lazy;
int n;
void build(int start,int end,int node)
{
	if(start==end) tree[node] = arr[start];
	else
	{
		int mid = (start+end)/2;
		build(start,mid,2*node + 1);
		build(mid+1,end,2*node + 2);
		tree[node] = tree[2*node + 1]+ tree[2*node + 2];
	}
}
int query(int start, int end, int node, int l, int r)
{
	if(lazy[node]!=0)
	{
		tree[node] += (end-start+1)*lazy[node];
		if(start!=end)
		{
			lazy[2*node+1] += lazy[node];
			lazy[2*node+2] += lazy[node];
			
		}
		lazy[node] = 0;
	}
	
	if(start>end || r < start || l > end) return 0;
	if(l <= start and r>= end) return tree[node];
	int mid = (start+end)/2;
	int p1 = query(start,mid,2*node + 1, l, r);
	int p2 = query(mid+1,end,2*node + 2, l, r);
	return p1+p2;
}
void updateRange(int start, int end, int node, int l, int r, int val)
{
	if(lazy[node]!=0) //first do the pending updates on the nodes and then go for the next updates
	{
		tree[node] += (end-start+1)*lazy[node];
		if(start!=end) //propagate the lazy thing to the children if not leaf node
		{
			lazy[2*node + 1] += lazy[node];
			lazy[2*node + 2] += lazy[node];
		}
		lazy[node] = 0; // khatam
	}
	if(start > end || r<start || l>end) return;//out of range
	if(l <= start and r >= end)//fully in range
	{
		tree[node] += (end-start+1)*val;
		if(start!=end) 
		{
			lazy[2*node + 1] += val;
			lazy[2*node + 2] += val;
		}
		return;
	}
	// if not completely in range
	int mid = (start+end)>>1;
	updateRange(start,mid, 2*node+1,l,r,val);
	updateRange(mid+1,end, 2*node+2,l,r,val);
	tree[node] = tree[2*node+1] + tree[2*node+2];
}
void update(int start, int end, int node, int idx, int val)
{
	if(start==end)
	{
		arr[idx]+=val;
		tree[node] = arr[idx];
	}
	else
	{
		int mid = (start+end)/2;
		if(start <= idx and mid >= idx) update(start,mid,2*node + 1, idx, val);
		else update(mid+1, end, 2*node + 2, idx, val);
		tree[node] = tree[2*node + 1] + tree[2*node + 2];
	}
}
int main()
{
	cin>>n;
	arr.clear();
	arr.resize(n);
	for(int i=0;i<n;++i) cin>>arr[i];
	tree.clear();
	tree.resize(4*n);
	lazy.clear();
	lazy.resize(4*n);
	
	
	build(0,n-1,0);
	int l,r;
	cin>>l>>r;
	cout<<query(0,n-1,0,l,r)<<endl;
	int idx,val;
	cin>>idx>>val;
	update(0,n-1,0,idx,val);
	cout<<query(0,n-1,0,l,r)<<endl;
}
