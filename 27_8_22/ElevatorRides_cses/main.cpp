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

const int max_n = 21;
const ll mod = 1e9 + 7;
const ll inf = 1e9;
const ld eps = 1e-9;

using namespace std;

typedef pair<int, int> pii;

pii dp[1 << max_n];
int a[max_n];
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

int main(){
    setIO();
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    dp[0] = {1, 0};
    for (int s = 1; s < (1 << n); s++){
        dp[s] = {n + 1, 0};
        for (int i = 1; i <= n; i++){
            if (s & (1 << (i - 1))){
                auto tmp = dp[s ^ (1 << (i - 1))];
                if (tmp.second + a[i] <= m){
                    tmp.second += a[i];
                } else {
                    tmp.first += 1;
                    tmp.second = a[i];
                }
                dp[s] = min(dp[s], tmp);
            }
        }
    }
    cout << dp[(1 << n) - 1].first;
}
