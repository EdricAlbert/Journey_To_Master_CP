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

const int max_n = 5e3 + 5;
const ll mod = 1e9 + 7;
const ll inf = 1e9;
const ld eps = 1e-9;

using namespace std;

typedef pair<int, int> pii;

int a[max_n];
ll dp[max_n][max_n];
int n;

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
    cin >> n;
    ll total = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        total += a[i];
    }
    for (int i = 1; i <= n; i++){
        for (int j = i; j >= 1; j--){
            if (i == j){
                dp[j][i] = a[j];
            } else {
                dp[j][i] = max(a[j] - dp[j + 1][i], a[i] - dp[j][i - 1]);
            }
        }
    }
    cout << (dp[1][n] + total)/2;
}
