#include <bits/stdc++.h>
#define _io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI 3.1415926535897932384626433832795l
#define all(a) (a).begin(), (a).end()
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())

#define BITMASK_SET(x, mask) ((x) |= (mask))
#define BITMASK_CLEAR(x, mask) ((x) &= (~(mask)))
#define BITMASK_FLIP(x, mask) ((x) ^= (mask))
#define BITMASK_CHECK_ALL(x, mask) (!(~(x) & (mask)))
#define BITMASK_CHECK_ANY(x, mask) ((x) & (mask))
#define file "input"

const int max_n = 2e5 + 5;
const ll mod = 1e9 + 7;
const ll inf = 1e9;
const ld eps = 1e-9;

using namespace std;

typedef pair<int, int> pii;

int n;
vector<int> graph[max_n];
int v1, res;

void setIO(string name = ""){
    _io;
    bool yes = true;
    if (name.size()){
        freopen((name + "inp").c_str(), "r", stdin);
        freopen((name + "out").c_str(), "w", stdin);
    } else
    if (yes == 0){ // Change to 1 if input/output -> txt.
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    }
}

void dfs1(int u, int p, int cnt){
    bool yes = false;
    for (int v: graph[u]){
        if (v != p){
            dfs1(v, u, cnt + 1);
            yes = true;
        }
    }
    if (!yes){
        if (res < cnt){
            res = cnt;
            v1 = u;
        }
    }
}

void dfs2(int u, int p, int cnt){
    bool yes = false;
    for (int v: graph[u]){
        if (v != p){
            dfs2(v, u, cnt + 1);
            yes = true;
        }
    }
    if (!yes){
        if (res < cnt){
            res = cnt;
        }
    }
}

int main(){
    setIO();
    cin >> n;
    for (int u, v, i = 1; i < n; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs1(1, 0, 1);
    res = 0;
    dfs2(v1, 0, 1);
    cout << res - 1 << '\n';
}
