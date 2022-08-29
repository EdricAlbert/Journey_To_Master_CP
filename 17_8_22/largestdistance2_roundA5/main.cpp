#include <bits/stdc++.h>
#define _io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI 3.1415926535897932384626433832795l
#define all(a) (a).begin(), (a).end()
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())

#define BITMASK_SET(x, mask) ((x) |= (m ask))
#define BITMASK_CLEAR(x, mask) ((x) &= (~(mask)))
#define BITMASK_FLIP(x, mask) ((x) ^= (mask))
#define BITMASK_CHECK_ALL(x, mask) (!(~(x) & (mask)))
#define BITMASK_CHECK_ANY(x, mask) ((x) & (mask))
#define file "largest-distance-2"

const int max_n = 2e5 + 5;
const ll mod = 1e9 + 7;
const ll inf = 1e9;
const ld eps = 1e-9;

using namespace std;

typedef pair<int, int> pii;

int n;
int res = 0;
vector<int> graph[max_n];
int a[max_n];
bool yes[max_n];
vector<int> primes;
bool rightt[max_n];
vector<int> P;
bool visited1[max_n];
bool visited2[max_n];
bool has[max_n];

void analysis(int x){
    int i = 0;
    while (x != 1){
        if (i == P.size()){
            break;
        }
        if (x % P[i] == 0){
            while (x % P[i] == 0){
                x /= P[i];
            }
            if (!has[P[i]]){
                primes.push_back(P[i]);
                has[P[i]] = true;
            }
        }
        i++;
    }
}

int bfs(int s, int x){
    int kq = 0;
    int vertice = 0;
    queue<pii> q;
    q.push({s, 1});
    while (!q.empty()){
        int u = q.front().first;
        int w = q.front().second;
        q.pop();
        visited1[u] = true;
        int r = 0;
        for (int v: graph[u]){
            if (!visited1[v] && a[v] % x == 0){
                q.push({v, w + 1});
                r++;
            }
        }
        if (r == 0){
            if (kq < w){
                kq = w;
                vertice = u;
            }
        }
    }
    return vertice;
}

int bfs_for_ans(int s, int x){
    int kq = 0;
    queue<pii> q;
    q.push({s, 1});
    while (!q.empty()){
        int u = q.front().first;
        int w = q.front().second;
        visited2[u] = true;
        q.pop();
        int r = 0;
        for (int v: graph[u]){
            if (!visited2[v] && a[v] % x == 0){
                q.push({v, w + 1});
                r++;
            }
        }
        if (r == 0){
            if (kq < w){
                kq = w;
            }
        }
    }
    return kq;
}

void solve(int val){
    for (int i = 1; i <= n; i++){
        if (!visited1[i] && a[i] % val == 0){
            res = max(res, bfs_for_ans(bfs(i, val), val));
            yes[i] = true;
        }
    }
}

void sieve(){
    for (ll i = 2; i <= 200000; i++){
        if (rightt[i] == false)
        for (ll j = i * i; j <= 200000; j+=i){
            rightt[j] = true;
        }
    }
    for (int i = 2; i <= 600; i++){
        if (rightt[i] == false){
            P.push_back(i);
        }
    }
}

int main(){
    _io;
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);
    //  freopen(file".inp","r",stdin);
    //  freopen(file".out", "w", stdout);
    sieve();
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        analysis(a[i]); // 19000000
    }
    for (int u, v, i = 1; i < n; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int j = 0; j < primes.size(); j++){ // 95
        int val = primes[j];
        solve(val);
        for (int i = 1; i <= n; i++){ // 2e5
            visited1[i] = false;
            visited2[i] = false;
        }
    }
    for (int i = 1; i <= n; i++){
        if (yes[i] == false && a[i] != 1){
            res = max(res, bfs_for_ans(bfs(i, a[i]), a[i]));
        }
    }
    cout << res << '\n';
}
