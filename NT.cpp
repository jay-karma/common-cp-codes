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
const ll mod = 1e9+7;
const int N = 2e6 + 15;
ll fact[N], ifact[N];
template<typename T> T gcd(T a, T b) {
    if(b==0) return a;
    return gcd(b,a%b);
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
ll nCr(int n, int r) {
	ll ans = fact[n];
	ans = (ans * ifact[n-r]) % mod;
	ans = (ans * ifact[r]) % mod;
	return ans;
}
int main(){
	fact[0] = 1;
	ifact[0] = mod_inv(fact[0], mod);
	for (int i = 1; i < N; ++i) {
		fact[i] = (i*fact[i-1])%mod;
		ifact[i] = mod_inv(fact[i], mod);
	}
	
	return 0;
}
