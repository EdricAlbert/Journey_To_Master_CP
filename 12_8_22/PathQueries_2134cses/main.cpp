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

int n, q;
int tin[max_n], tout[max_n];
int depth[max_n], parent[max_n][20], value[max_n][20];
vector<int> graph[max_n];
int counter, l;
int log_2[max_n];

void dfs(int u, int p){
    tin[u] = ++counter;
    depth[u] = depth[p] + 1;
    parent[u][0] = p;
    for (int v: graph[u]){
        if (v != p){
            dfs(v, u);
        }
    }

    tout[u] = ++counter;
}

void setup(){
    log_2[1] = 0;
    for (int i = 2; i <= n; i++){
        log_2[i] = log_2[i/2] + 1;
    }

    counter = 0;
    l = ceil(log2(n));

    dfs(1, 1);

    for (int j = 1; j <= l; j++){
        for (int i = 1; i <= n; i++){
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }

    for (int j = 1; j <= l; j++){
        for (int i = 1; i <= n; i++){
            value[i][j] = max(value[i][j - 1], value[parent[i][j - 1]][j - 1]);
        }
    }
}

bool isAncestor(int u, int v){
    return (tin[u] <= tin[v] && tin[v] <= tout[u]);
}

int lca(int u, int v){
    if (isAncestor(u, v)){
        return u;
    }
    if (isAncestor(v, u)){
        return v;
    }
    for (int k = ceil(log2(n)); k >= 0; k--){
        if (!isAncestor(parent[u][k], v)){
            u = parent[u][k];
        }
    }
    return parent[u][0];
}

ll findVal(int u, int v){
    int k = log_2[depth[u] - depth[v] + 1];
    return max(value[u][k - 1], value[parent[u][k - 1]][k - 1]);
}

ll findPath(int b, int c){
    for (int k = 1; k <= l; k++){
        value[b][k] = max(value[b][k - 1], value[parent[b][k - 1]][k - 1]);
    }

    for (int k = 1; k <= l; k++){
        value[c][k] = max(value[c][k - 1], value[parent[c][k - 1]][k - 1]);
    }

    int giaodiem = lca(b, c);
    int res1 = findVal(b, giaodiem);
    int res2 = findVal(c, giaodiem);
    return max(res1, res2);
}

int main(){
    _io;
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);
    //  freopen(file".inp","r",stdin);
    //  freopen(file".out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> value[i][0];
    }
    for (int u, v, i = 1; i < n; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    setup();
    for (int a, b, c, i = 1; i <= q; i++){
        cin >> a >> b >> c;
        if (a == 1){
            value[b][0] = c;
            for (int k = 1; k <= l; k++){
                value[b][k] = max(value[parent[b][k - 1]][k - 1], value[b][k - 1]);
            }
        } else {
            cout << findPath(b, c) << " ";
        }
    }
}
