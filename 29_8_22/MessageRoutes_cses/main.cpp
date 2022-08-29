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

vector<int> graph[max_n];
int n, m;
bool visited[max_n];
bool flag = false;
int last[max_n];

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

void bfs(int s){
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int v: graph[u]){
            if (v == n){
                last[v] = u;
                flag = true;
                return;
            } else
            if (!visited[v]){
                q.push(v);
                visited[v] = true;
                last[v] = u;
            }
        }
    }
}

void traceback(){
    int u = n;
    vector<int> order;
    order.push_back(u);
    while (u != 1){
        order.push_back(last[u]);
        u = last[u];
    }
    cout << order.size() << '\n';
    reverse(all(order));
    for (int i = 0; i < order.size(); i++){
        cout << order[i] << " ";
    }
}

int main(){
    setIO();
    cin >> n >> m;
    for (int u, v, i = 1; i <= m; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bfs(1);

    if (flag){
        traceback();
    } else {
        cout << "IMPOSSIBLE" << '\n';
    }
}
