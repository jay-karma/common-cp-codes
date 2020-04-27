#include <bits/stdc++.h>
using namespace std;
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
    cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args&&... args) {
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
using ll = long long;
using P = pair<int,int>;
const int inf = 2e9;
const int N = 2e6 + 15;
void solve() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<P> g[n+1];
	int a, b, c;
	for (int e = 1; e <= m; ++e) {
		scanf("%d%d%d", &a, &b, &c);
		g[a].push_back(P(b, c));
		g[b].push_back(P(a, c));
	}
	vector<int> vis(n+1, 0);
	vector<int> key(n+1, inf);
	priority_queue<P, vector<P>, greater<P>> q;
	q.push(P(0, 1));
	key[1] = 0;
	int mst = 0;
	while (!q.empty()) {
		P cur = q.top();
		q.pop();
		int u = cur.second;
		if (vis[u]) continue;
		vis[u] = 1;
		int cost = cur.first;
		mst += cost;
		for (P ne : g[u]) {
			int v = ne.first;
			int w = ne.second;
			if (!vis[v] && key[v] > w) {
				key[v] = w;
				q.push(P(key[v], v));
			}
		}
	}
	printf("%d\n", mst);
}
int main(){
	int T;
	scanf("%d", &T);
	while (T--) solve();
	return 0;
}
