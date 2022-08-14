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
const int max_q = 1e5 + 5;
const ll mod = 1e9 + 7;
const ll inf = 1e9;
const ld eps = 1e-9;

using namespace std;

typedef pair<int, int> pii;

struct info{
    int first, second;
    // Optional for type 2
    char c;
};

string st;
int q;
info query[max_q];
int have[max_n], parent[max_n], Rank[max_n];
vector<int> ans;

void setup(){
    for (int i = 0; i < st.size(); i++){
        have[i] = 1;
        parent[i] = i;
        Rank[i] = 1;
    }
}

int findSet(int u){
    if (parent[u] == u){
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

int main(){
    _io;
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);
    //  freopen(file".inp","r",stdin);
    //  freopen(file".out", "w", stdout);
    int t;
    cin >> t;
    for (int test = 1; test <= t; test++){
        cout << "Case " << test << ": " << '\n';
        cin >> st;
        cin >> q;
        ans.clear();
        setup();
        for (int x, i = 1; i <= q; i++){
            cin >> query[i].first >> query[i].second;
            if (query[i].first == 2){
                query[i].c = st[query[i].second];
                st[query[i].second] = '#';
            }
        }
        for (int i = 1; i < st.size(); i++){
            if (st[i] == st[i - 1] && st[i] != '#'){
                unionSet(i, i - 1);
            }
        }
        for (int i = q; i >= 1; i--){
            if (query[i].first == 1){
                ans.push_back(have[findSet(query[i].second)]);
            } else {
                st[query[i].second] = query[i].c;
                int pos = query[i].second;
                if (pos - 1 != -1 && st[pos] == st[pos - 1]){
                    unionSet(pos - 1, pos);
                }
                if (pos + 1 != st.size() && st[pos] == st[pos + 1]){
                    unionSet(pos + 1, pos);
                }
            }
        }
        reverse(all(ans));
        for (int i = 0; i < ans.size(); i++){
            cout << ans[i] << '\n';
        }
    }
}
