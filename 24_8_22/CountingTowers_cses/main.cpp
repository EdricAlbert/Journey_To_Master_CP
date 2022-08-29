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

const int max_n = 1e6 + 5;
const ll mod = 1e9 + 7;
const ll inf = 1e9;
const ld eps = 1e-9;

using namespace std;

typedef pair<int, int> pii;

ll dp[max_n][2];

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
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 1; i < 1000000; i++){
        dp[i][0] %= mod;
        dp[i][1] %= mod;
        dp[i + 1][0] += 2*dp[i][0];
        dp[i + 1][0] += dp[i][1];
        dp[i + 1][1] += dp[i][0];
        dp[i + 1][1] += 4*dp[i][1];
    }
    int t;
    int n;
    cin >> t;
    ll ans = 0;
    while (t--){
        cin >> n;
        ans = dp[n][0] + dp[n][1];
        ans%=mod;
        cout << ans << '\n';
    }
}
