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
const int max_m = 1e3 + 5;
const ll mod = 1e9 + 7;
const ll inf = 1e9;
const ld eps = 1e-9;

using namespace std;

typedef pair<int, int> pii;

ll dp[max_n][max_m];
int n, m;
int a[max_n];

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

int main(){
    setIO();
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if (a[1] == 0){
        for (int i = 1; i <= m; i++){
            dp[1][i] = 1;
        }
    } else {
        dp[1][a[1]] = 1;
    }
    for (int i = 2; i <= n; i++){
        if (a[i] == 0){
            for (int j = 1; j <= m; j++){
                dp[i][j] += dp[i - 1][j];
                if (j + 1 <= m) dp[i][j] += dp[i - 1][j + 1];
                if (j - 1 > 0) dp[i][j] += dp[i - 1][j - 1];
                dp[i][j] %= mod;
            }
        } else {
            dp[i][a[i]] += dp[i - 1][a[i]];
            if (a[i] + 1 <= m) dp[i][a[i]] += dp[i - 1][a[i] + 1];
            if (a[i] - 1 > 0) dp[i][a[i]] += dp[i - 1][a[i] - 1];
            dp[i][a[i]]%=mod;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= m; i++){
        ans += dp[n][i];
        ans%=mod;
    }
    cout << ans << '\n';
}
