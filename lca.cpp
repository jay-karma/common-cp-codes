#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;
const int N = 1e5+5;
vector <int> g[N];
int dp[N][30];
int dep[N];
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
	for(int i = 1; i < 30; ++i) {
		dp[u][i] = dp[dp[u][i-1]][i-1];
	}
	for(int ch : g[u]) {
		if(ch != par) dfs(ch, u);
	}
}
int main(){
	
    return 0;
}
