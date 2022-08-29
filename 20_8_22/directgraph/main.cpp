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
#define file "direct-graph"

const int max_n = 3e5 + 5;
const int max_e = 3e5 + 5;
const ll mod = 1e9 + 7;
const ll inf = 1e9;
const ld eps = 1e-9;

using namespace std;

typedef pair<int, int> pii;

vector<int> graph[max_e];
vector<int> tree[max_n];
int low[max_e], num[max_e];
stack<int> st;
int counter = 0;
bool found1[max_e];
bool found2[max_e];
int up[max_n], down[max_n];
int d = 0;
int has[max_n], cnt[max_n];
int n, m;

void dfs1(int u, int p){
    st.push(u);
    counter++;
    low[u] = num[u] = counter;
    for (int v: graph[u]){
        if (v == p){
            continue;
        }
        if (!found1[v]){
            if (num[v] > 0){
                low[u] = min(low[u], num[v]);
            } else {
                dfs1(v, u);
                low[u] = min(low[u], low[v]);
            }
        }
    }

    if (num[u] == low[u]){
        d++;
        int v;
        do {
            v = st.top();
            st.pop();
            has[v] = d;
            cnt[d]++;
            found1[v] = true;
        } while (v != u);
    }
}

void tarjan(int x){
    dfs1(x, 0);
}

void createTree(int u, int p){
    found2[u] = true;
    for (int v: graph[u]){
            if (!found2[v]){
                if (has[v] != has[u]){
                    tree[has[u]].push_back(has[v]);
                    tree[has[v]].push_back(has[u]);
                }
                createTree(v, u);
            }
    }
}

void dfs2(int u, int p){
    down[u] = 0;
    for (int v: tree[u]){
        if (v != p){
            dfs2(v, u);
            down[u] = max(down[u], down[v]);
        }
    }
    down[u] += cnt[u];
    return;
}

void calculate(int u, int p){
    int longest1 = 0;
    int longest2 = 0;
    for (int v: tree[u]){
        if (v != p){
            if (down[v] >= longest1){
                longest2 = longest1;
                longest1 = down[v];
            } else
            if (down[v] > longest2){
                longest2 = down[v];
            }
        }
    }

    for (int v: tree[u]){
        if (v != p){
            if (longest1 == down[v]){
                up[v] = cnt[v] + max(cnt[u] + longest2, up[u]);
            } else {
                up[v] = cnt[v] + max(cnt[u] + longest1, up[u]);
            }
            calculate(v, u);
        }
    }
}

int main(){
    _io;
     freopen("input.txt","r",stdin);
     freopen("output.txt", "w", stdout);
    //  freopen(file".inp","r",stdin);
    //  freopen(file".out", "w", stdout);
    cin >> n >> m;
    for (int u, v, i = 1; i <= m; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 1; i <= n; i++){
        if (!found1[i]){
            tarjan(i);
        }
    }
    for (int i = 1; i <= n; i++){
        if (!found2[i]){
            createTree(i, 0);
            dfs2(has[i], 0);
            calculate(has[i], 0);
        }
    }
    for (int i = 1; i <= n; i++){
        cout << max(up[has[i]], down[has[i]])<< " ";
    }
}
