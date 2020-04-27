#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
const int MAXN=1e5+50;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

vll lazy(4*MAXN),tree(4*MAXN);
vll s(4*MAXN),e(4*MAXN),arr(MAXN+1,0);
ll calculate(int node){
	return tree[node]+lazy[node]*(e[node]-s[node]+1);
}
void lazyPropagation(int node){
	lazy[2*node]+=lazy[node];
	lazy[2*node+1]+=lazy[node];
	lazy[node]=0;
}
void build(int node,int l,int r){
	s[node]=l;
	e[node]=r;
	if(l==r){
		tree[node]=arr[l];
		return;
	}
	int mid=(l+r)/2;
	build(2*node,l,mid);
	build(2*node+1,mid+1,r);
	tree[node]=tree[2*node]+tree[2*node+1];
	return;
}
void update(int node,int l,int r,int x){
	if(s[node]>r || e[node]<l)
	return;
	if(l<=s[node] && e[node]<=r){
		lazy[node]+=x;
		return;
	}
	lazyPropagation(node);
	update(2*node,l,r,x);
	update(2*node+1,l,r,x);
	tree[node]=calculate(2*node)+calculate(2*node+1);
}
ll query(int node,int l,int r){
	if(s[node]>r || e[node]<l)
	return 0ll;
	if(l<=s[node] && e[node]<=r){
		return calculate(node);
	}
	lazyPropagation(node);
	ll left=query(2*node,l,r);
	ll right=query(2*node+1,l,r);
	tree[node]=calculate(2*node)+calculate(2*node+1);
	return left+right;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		lazy.assign(4*MAXN,0);
		cin>>n >>c;
		build(1,1,n);
		int x,p,q,val;
		while(c--){
			cin>>x;
			if(x){
				cin>>p >>q;
				cout<<query(1,p,q)<<"\n";
			}else{
				cin>>p >>q >>val;
				update(1,p,q,val);
			}
		}	
	}
    return 0;
}
