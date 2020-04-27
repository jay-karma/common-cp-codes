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
const int MAXN = 1e5+5;
int sa[MAXN], rk[MAXN], tmp[MAXN], lcp[MAXN];
int gap, N;
string S;
bool suffCmp(int x, int y) {
	if (rk[x] != rk[y]) return rk[x] < rk[y];
	x += gap;
	y += gap;
	return (x < N && y < N) ? rk[x] < rk[y] : x > y;
}
void buildSA() {
	N = S.size();
	for (int i = 0; i < N; ++i) rk[i] = S[i], sa[i] = i;
	for (gap = 1; ; gap *= 2) {
		sort(sa, sa+N, suffCmp);
		for (int i = 0; i < N-1; ++i) 
			tmp[i+1] = tmp[i] + suffCmp(sa[i], sa[i + 1]);
		for (int i = 0; i < N; ++i) rk[sa[i]] = tmp[i];
		if (tmp[N-1] == N-1) break;
	}
}
void buildLCP() {
	N = S.size();
	for (int i = 0, k = 0; i < N; ++i) {
		if (rk[i] != N-1) {
			for (int j = sa[rk[i] + 1]; S[i+k] == S[j+k]; )
				++k;
			lcp[rk[i]] = k;
			if (k) --k;
		}
	} 
}
int main(){
	
	return 0;
}
