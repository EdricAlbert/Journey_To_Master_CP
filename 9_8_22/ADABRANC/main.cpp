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

const int max_n = 3e5 + 5;
const ll mod = 1e9 + 7;
const ll inf = 1e9;
const ld eps = 1e-9;

using namespace std;

typedef pair<int, int> pii;

struct info{
    int u, v, w;
};

struct query{
    int id, start, kg;
};

vector<info> Edges;
vector<query> Q;
int ans[max_n];
int parent[max_n], have[max_n], Rank[max_n];
int n, m, q;

bool cmp1(info& a, info& b){
    return (a.w > b.w);
}

bool cmp2(query& a, query& b){
    return (a.kg > b.kg);
}

int findSet(int u){
    if (u == parent[u]){
        return u;
    }
    return findSet(parent[u]);
}

void unionSet(int u, int v){
    int pu = findSet(u);
    int pv = findSet(v);

    if (pu == pv){
        return;
    }

    if (Rank[pu] > Rank[pv]){
        parent[pv] = pu;
        have[pu] += have[pv];
    } else
    if (Rank[pv] > Rank[pu]){
        parent[pu] = pv;
        have[pv] += have[pu];
    } else {
        Rank[pu]++;
        parent[pv] = pu;
        have[pu] += have[pv];
    }
}

void setup(){
    for (int i = 0; i <= n; i++){
        Rank[i] = 1;
        parent[i] = i;
        have[i] = 1;
    }
}

int main(){
    _io;
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);
    //  freopen(file".inp","r",stdin);
    //  freopen(file".out", "w", stdout);
    cin >> n >> m >> q;
    setup();
    for (int u, v, w, i = 1; i <= m; i++){
        cin >> u >> v >> w;
        Edges.push_back({u, v, w});
    }
    sort(all(Edges), cmp1);
    for (int s, w, i = 1; i <= q; i++){
        cin >> s >> w;
        Q.push_back({i, s, w});
    }
    sort(all(Q), cmp2);
    int j = 0;
    for (int i = 0; i < Edges.size(); i++){
        int u = Edges[i].u;
        int v = Edges[i].v;
        int w = Edges[i].w;
        while (Q[j].kg > w && j < Q.size()){
            ans[Q[j].id] = have[findSet(Q[j].start)];
            j++;
        }
        if (j == Q.size()){
            break;
        }
        unionSet(u, v);
    }
    if (j < Q.size()){
        while (j < Q.size()){
            ans[Q[j].id] = have[findSet(Q[j].start)];
            j++;
        }
    }
    for (int i = 1; i <= q; i++){
        cout << ans[i] << '\n';
    }
}
