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

const int max_n = 1e5 + 5;
const ll mod = 1e9 + 7;
const ll inf = 1e9;
const ld eps = 1e-9;

using namespace std;

typedef pair<int, int> pii;

int depth[max_n];
vector<int> graph[max_n];
int tin[max_n], tout[max_n];
int counter, l;
int n, m;
int parent[max_n][20];

void dfs(int u, int p){
    depth[u] = depth[p] + 1;
    tin[u] = ++counter;

    parent[u][0] = p;
    for (int v: graph[u]){
        if (v!=p){
            dfs(v, u);
        }
    }
    tout[u] = ++counter;
}

void preprocess(){
    counter = 0;
    depth[1] = -1;
    l = ceil(log2(n));

    dfs(1, 1);

    for (int k = 1; k <= l; k++){
        for (int i = 1; i <= n; i++){
            parent[i][k] = parent[parent[i][k - 1]][k - 1];
        }
    }
}

int isAncestor(int u, int v){
    return (tin[u] <= tin[v] && tin[v] <= tout[u]);
}

int lca(int u, int v){
    if (isAncestor(u, v)){
        return u;
    }
    if (isAncestor(v, u)){
        return v;
    }
    for (int k = l; k >= 0; k--){
        if (!isAncestor(parent[u][k], v))
            u = parent[u][k];
    }
    return parent[u][0];
}

int case1(int a, int b, int c){
    int A, B, C;
    int kqA = 0;
    int kqB = 0;
    A = a;
    // B = b, C == c
    B = b, C = c;
    if (isAncestor(C, A) == 1)
    B = c, C = b;
    if (isAncestor(A, C) == 1 && isAncestor(C, B) == 1){
        kqB--;
    }
    k = lca(A, C);
    kqB += depth[k] + depth[B] - 2*depth[lca(k, B)] + 1;
    return max(kqA, kqB);
}

int case2(int a, int b, int c){
    int A, B, C;
    int kqA = 0;
    int kqB = 0;
    A = b;
    // B = b, C == c
    B = a, C = c;
    if (isAncestor(A, C) == 1 && isAncestor(C, B) == 1){
        kqA--;
    }
    int k = lca(A, C);
    kqA += depth[k] + depth[B] - 2*depth[lca(k, B)] + 1;

    B = c, C = a;
    if (isAncestor(A, C) == 1 && isAncestor(C, B) == 1){
        kqB--;
    }
    k = lca(A, C);
    kqB += depth[k] + depth[B] - 2*depth[lca(k, B)] + 1;
    return max(kqA, kqB);
}

int case3(int a, int b, int c){
    int A, B, C;
    int kqA = 0;
    int kqB = 0;
    A = c;
    // B = b, C == c
    B = a, C = b;
    if (isAncestor(A, C) == 1 && isAncestor(C, B) == 1){
        kqA--;
    }
    int k = lca(A, C);
    kqA += depth[k] + depth[B] - 2*depth[lca(k, B)] + 1;

    B = b, C = a;
    if (isAncestor(A, C) == 1 && isAncestor(C, B) == 1){
        kqB--;
    }
    k = lca(A, C);
    kqB += depth[k] + depth[B] - 2*depth[lca(k, B)] + 1;
    return max(kqA, kqB);
}

int main(){
    _io;
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);
    //  freopen(file".inp","r",stdin);
    //  freopen(file".out", "w", stdout);
    cin >> n >> m;
    for (int x, i = 2; i <= n; i++){
        cin >> x;
        graph[i].push_back(x);
        graph[x].push_back(i);
    }
    preprocess();
    int res = 0;
    for (int a, b, c, i = 1; i <= m; i++){
        res = 0;
        cin >> a >> b >> c;
        res = max(res, case1(a, b, c));
        res = max(res, case2(a, b, c));
        res = max(res, case3(a, b, c));
        cout << res << '\n';
    }
}
