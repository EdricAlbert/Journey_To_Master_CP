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

ll dp[max_n];
int n, k;
int coins[max_n];

int main(){
    _io;
    // freopen("input.txt","r",stdin);
    // freopen("output.txt", "w", stdout);
    //  freopen(file".inp","r",stdin);
    //  freopen(file".out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> coins[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= k; i++){
        for (int j = 1; j <= n; j++){
            if (coins[j] <= i){
                dp[i] = (dp[i] + dp[i - coins[j]])%mod;
            }
        }
    }
    cout << dp[k] << '\n';
}
