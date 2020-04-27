#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vll vector<ll>
#define vvll vector<vll>
#define pb push_back
template<typename T, typename U>
static inline void amin(T &x, U y){
    if(x>y)
        x = y;
}
template<typename T, typename U>
static inline void amax(T &x, U y){
    if(x<y)
        x = y;
}
#define rep(i,n) for(int i = 0; i < n; ++i)
#define irep(i,k,n) for(int i = k; i <= n; ++i)
#define irepr(i,k,n) for(int i = k; i >= n; --i)

const ll mod = 1e9+7;
const int N = 1e5+50;
const ll INF = 1e18L;
vector <pii> g[N];

int main(){
    int n, m, u, v, w;
    cin>> n>> m;
    rep(i, m)
    {
        cin>> u>> v>> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    vll dist(N, INF);
    vi vis(N, 0);
    vi prev(N, 0);
    dist[1] = 0;
    prev[1] = 1;
    priority_queue <pii, vector<pii>, greater<pii> > minHeap; // distance, vertex
    minHeap.push({0, 1});
    while( ! minHeap.empty() ){
        u = (minHeap.top()).second;
        minHeap.pop();
        if(vis[u]){
            continue;
        }
        vis[u] = 1;
        for(pii ne : g[u]){
            v = ne.first;
            w = ne.second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                prev[v] = u;
                minHeap.push({dist[v], v});
            }
        }
    }
    if(dist[n] == INF){
        cout << "-1\n";
        return 0;
    }
    stack <int> path;
    u = n;
    while(prev[u] != u){
        path.push(u);
        u = prev[u];
    }
    path.push(1);
    while(! path.empty()){
        cout << path.top() << " ";
        path.pop();
    }
    cout << "\n";
    return 0;
}
