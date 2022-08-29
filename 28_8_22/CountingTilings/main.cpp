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

ll f[1001][1 << 11];
int n, m;

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

void gen_masks(int row, int cur_mask, int n, int next_mask, vector<int>& future_masks){
    if (row == n + 1){
        future_masks.push_back(next_mask);
        return;
    }

    if (cur_mask & (1 << (row - 1))){
        if (row < n){
            if (!(cur_mask & (1 << row))){
                gen_masks(row + 1, cur_mask, n, next_mask, future_masks);
            }
        } else {
            gen_masks(row + 1, cur_mask, n, next_mask, future_masks);
        }
    }

    if (row < n){
        if (cur_mask & (1 << (row - 1)) && cur_mask & (1 << row)){
            gen_masks(row + 2, cur_mask, n, next_mask, future_masks);
        } else
        if (!(cur_mask & (1 << (row - 1))) && !(cur_mask & (1 << row))){
            gen_masks(row + 2, cur_mask, n, next_mask, future_masks);
        }
    }

    if (!(cur_mask & (1 << (row - 1)))){
        gen_masks(row + 1, cur_mask, n, next_mask ^ (1 << (row - 1)), future_masks);
    }
}

ll dp (int col, int mask, int n, int m){
    if (col == m + 1){
        if (mask == 0){
            return 1;
        } else {
            return 0;
        }
    }

    if (f[col][mask] != -1){
        return f[col][mask];
    }

    ll ans = 0;
    vector<int> future_masks;
    gen_masks(1, mask, n, 0, future_masks);

    for (int nextmask : future_masks){
        int tmp = nextmask;
        ans += (dp(col + 1, nextmask, n, m));
        ans%=mod;
    }

    f[col][mask] = ans;
    return ans;
}

int main(){
    setIO();
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        for (int j = 0; j < (1 << n); j++){
            f[i][j] = -1;
        }
    }
    cout << dp(1, 0, n, m);
}
