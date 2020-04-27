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
#define ll long long
const int N = 2e6 + 15;
int label[N], rk[N];
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
