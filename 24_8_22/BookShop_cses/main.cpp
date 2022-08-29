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

const int max_n = 1e3 + 1;
const int max_m = 1e6 + 1;
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const ld eps = 1e-9;

using namespace std;

typedef pair<int, int> pii;

struct info{
    int price, pages;
};

int n, m;
info cost[max_n];
ll dp[max_m];

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

void setup(){
    for (int j = 1; j <=m; j++){
        dp[j] = -inf;
    }
    dp[0] = 0;
}

int main(){
    setIO();
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> cost[i].price;
    }
    for (int i = 1; i <= n; i++){
        cin >> cost[i].pages;
    }
    setup();
    for (int i = 1; i <= n; i++){
        for (int j = m; j >= 1; j--){
            if (cost[i].price <= j){
                dp[j] = max(dp[j], dp[j - cost[i].price] + cost[i].pages);
            }
        }
    }
    ll res = 0;
    for (int i = 1; i <= m; i++){
        res = max(res, dp[i]);
    }
    cout << res;
}
