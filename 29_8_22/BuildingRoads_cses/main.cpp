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

const int max_n = 1e5 + 5;
const ll mod = 1e9 + 7;
const ll inf = 1e9;
const ld eps = 1e-9;

using namespace std;

typedef pair<int, int> pii;

int Rank[max_n];
int parent[max_n];
int n, m;
bool has[max_n];

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

int findSet(int u){
    if (parent[u] != u){
        return findSet(parent[u]);
    }
    return u;
}

void setup(){
    for (int i = 1; i <= n; i++){
        parent[i] = i;
    }
}

void unionSet(int u, int v){
    int pu = findSet(u);
    int pv = findSet(v);

    if (pu == pv){
        return;
    }

    if (Rank[pu] > Rank[pv]){
        parent[pv] = pu;
    } else
    if (Rank[pv] > Rank[pu]){
        parent[pu] = pv;
    } else {
        Rank[pu]++;
        parent[pv] = pu;
    }
}

int main(){
    setIO();
    cin >> n >> m;

    setup();

    for (int u, v, i = 1; i <= m; i++){
        cin >> u >> v;
        unionSet(u, v);
    }

    vector<int> q;

    for (int i = 1; i <= n; i++){
        int p = findSet(i);
        if (!has[p]){
            q.push_back(p);
            has[p] = true;
        }
    }
    cout << q.size() - 1 << '\n';
    for (int i = 1; i < q.size(); i++){
        cout << q[i] << " " << q[i - 1] << '\n';
    }
}
