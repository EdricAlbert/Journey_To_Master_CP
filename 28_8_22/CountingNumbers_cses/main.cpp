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

ll A, B;
ll dp[20][10][2][2];

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

ll solve(string num, int n, int x, bool leading_zero, bool smaller){
    if (n == 0){
        return 1;
    }

    if (x != -1 && dp[n][x][leading_zero][smaller] != -1){
        return dp[n][x][leading_zero][smaller];
    }

    int ln = 0;
    int hn = smaller ? (num[num.size() - n] - '0') : 9;

    ll ans = 0;

    for (int i = ln; i <= hn; i++){
        if (i == x && leading_zero == false){
            continue;
        }
        ans += solve(num, n - 1, i, (i == 0 && leading_zero == 1 ? 1 : 0), (smaller & (i == hn)));
    }
    dp[n][x][leading_zero][smaller] = ans;
    return ans;
}

int main(){
    setIO();
    cin >> A >> B;
    string a = to_string(A - 1);
    string b = to_string(B);
    memset(dp, -1, sizeof(dp));
    ll ans_for_b = solve(b, b.size(), -1, 1, 1);
    memset(dp, -1, sizeof(dp));
    ll ans_for_a = solve(a, a.size(), -1, 1, 1);
    cout << ans_for_b - ans_for_a;
}
