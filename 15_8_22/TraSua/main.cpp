//   MASTER COMPETITIVE PROGRAMMING WITH
//               BUDDHA
//               _oo0oo_
//              o8888888o
//              88" . "88
//              (| -_- |)
//              0\  =  /0
//            ___/`---'\___
//          .' \\|     |// '.
//         / \\|||  :  |||// \
//        / _||||| -:- |||||- \
//       |   | \\\  -  /// |   |
//       | \_|  ''\---/''  |_/ |
//       \  .-\__  '-'  ___/-. /
//     ___'. .'  /--.--\  `. .'___
//  ."" '<  `.___\_<|>_/___.' >' "".
// | | :  `- \`.;`\ _ /`;.`/ - ` : | |
// \  \ `_.   \_ __\ /__ _/   .-` /  /
//=====`-.____`.___ \_____/___.-`___.-'=====
//               `=---='
/*

██████╗░██╗░░░░░███████╗░█████╗░░██████╗███████╗░░░░░░░░░░░░░█████╗░░█████╗░░█████╗░███████╗██████╗░████████╗
██╔══██╗██║░░░░░██╔════╝██╔══██╗██╔════╝██╔════╝░░░░░░░░░░░░██╔══██╗██╔══██╗██╔══██╗██╔════╝██╔══██╗╚══██╔══╝
██████╔╝██║░░░░░█████╗░░███████║╚█████╗░█████╗░░█████╗█████╗███████║██║░░╚═╝██║░░╚═╝█████╗░░██████╔╝░░░██║░░░
██╔═══╝░██║░░░░░██╔══╝░░██╔══██║░╚═══██╗██╔══╝░░╚════╝╚════╝██╔══██║██║░░██╗██║░░██╗██╔══╝░░██╔═══╝░░░░██║░░░
██║░░░░░███████╗███████╗██║░░██║██████╔╝███████╗░░░░░░░░░░░░██║░░██║╚█████╔╝╚█████╔╝███████╗██║░░░░░░░░██║░░░
╚═╝░░░░░╚══════╝╚══════╝╚═╝░░╚═╝╚═════╝░╚══════╝░░░░░░░░░░░░╚═╝░░╚═╝░╚════╝░░╚════╝░╚══════╝╚═╝░░░░░░░░╚═╝░░░

*/
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

int depth1[max_n], depth2[max_n], subtree1[max_n], subtree2[max_n];
ll value1[max_n], value2[max_n];
vector<int> edges;
int n;
vector<int> graph[max_n];

void dfs(int u, int p){
    depth1[u] = depth1[p] + 1;
    subtree1[u] = 1;
    value1[u] = depth1[u];
    for (int v: graph[u]){
        if (v != p){
            dfs(v, u);
            subtree1[u] += subtree1[v];
            value1[u] += value1[v];
        }
    }
    if (subtree1[u] == 1){
        edges.push_back(u);
    }
}

void dfs_secondtry(int u, int p){
    depth2[u] = depth2[p] + 1;
    subtree2[u] = 1;
    value2[u] = depth2[u];
    if (u == 1){
        return;
    }
    for (int v: graph[u]){
        if (v != p && subtree1[v] != 1){
            dfs_secondtry(v, u);
            subtree2[u] += subtree2[v];
            value2[u] += value2[v];
        }
    }
}

void bfs_secondtry(){
    for (int e, i = 0; i < edges.size(); i++){
        e = edges[i];
        depth2[n + 1] = -1;
        dfs_secondtry(e, n + 1);
    }
}

void solve(int x){
    ll res = 0;
    res += value1[x] -  (depth1[x])*(subtree1[x]);
    res += value2[x] - (depth2[x])*(subtree2[x]);
    for (int v: graph[1]){
        if (v != x)
        res += (depth1[x])*(subtree1[v]) + value1[v];
    }
    cout << res*2 << " ";
}

int main(){
    _io;
     freopen("input.txt","r",stdin);
     freopen("output.txt", "w", stdout);
    //  freopen(file".inp","r",stdin);
    //  freopen(file".out", "w", stdout);
    cin >> n;
    for (int u, v, i = 1; i < n; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    depth1[0] = -1;
    dfs(1, 0);
    bfs_secondtry();
    cout << value1[1]*2 << " ";
    for (int i = 2; i <= n; i++){
        solve(i);
    }
}
