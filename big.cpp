#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;
const int N = 2e6+5;
int label[N], rk[N];
ll bit[N];
vector <int> g[N];
int dp[N][30];
int dep[N];
typedef vector<ll> vll;
typedef vector<int> vi; 
vll lazy(4*N),tree(4*N);
vll s(4*N),e(4*N),arr(N+1,0);
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
int lca(int u, int v) {
	if(u == v) return u;
	if (dep[u] < dep[v]) swap(u, v);
	for(int i = 29; i >= 0; --i) {
		if (dep[dp[u][i]] >= dep[v])
			u = dp[u][i];
	}
	if (u == v) return u;
	for(int i = 29; i >= 0; --i) {
		if(dp[u][i] != dp[v][i]) {
			u = dp[u][i];
			v = dp[v][i];
		}
	}
	return dp[u][0];
}
void dfs(int u, int par) {
	dep[u] = 1+dep[par];
	dp[u][0] = par;
	for(int i = 1; i < 19; ++i) {
		dp[u][i] = dp[dp[u][i-1]][i-1];
	}
	for(int ch : g[u]) {
		if(ch != par) dfs(ch, u);
	}
}
void update(int idx, ll x){
	while(idx < N){
		bit[idx] += x;
		idx += idx&-idx;
	}
}
ll query(int idx){
	ll sum = 0;
	while(idx){
		sum += bit[idx];
		idx -= idx&-idx;
	}
	return sum;
}
template<typename T> T gcd(T a, T b) {
    if(b==0) return a;
    return gcd(b,a%b);
}
int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}
vector<int> phi_1_to_n(int n){
	vector<int> phi(n+1);
	phi[0] = 0;
	phi[1] = 1;
	for(int i = 2; i <= n; ++i) phi[i] = i;
	for(int i = 2; i <= n; ++i){
		if(phi[i] == i){
			for(int j = i; j <= n; j += i){
				phi[j] -= phi[j]/i;
			}
		}
	}
	return phi;
}
template <typename T> T mod_pow(T a, T b, T m) {
	T ans = 1;
	while(b) {
        if(b&1)ans=(ans*a)%m;
        a=(a*a)%m;
        b=b/2;
    }
    return ans;
}
template <typename T> T mod_inv (T a, T m) {
	return mod_pow(a, m - 2, m);
}
template <typename T> T mod_div (T a, T b, T m) {
	return a * mod_inv(b, m) % m;
}
int find(int x){
	return (x == label[x] ? x : (label[x] = find(label[x])));
}
void union1(int u, int v){
	u = find(u);
	v = find(v);
	if(u == v) return;
	if(rk[u] < rk[v]) swap(u, v);
	label[v] = u;
	if(rk[u] == rk[v]) rk[u]++;
}
int main(){
	
    return 0;
}
