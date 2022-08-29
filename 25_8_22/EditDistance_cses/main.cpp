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

int n, m;
string s1, s2;
ll dp[max_n][max_n];

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
    bool yes = false;
    int tmp = 0;
    for (int i = 1; i <= n; i++){
        if (!yes){
            if (s1[i] != s2[1]){
                tmp++;
                dp[1][i] = tmp;
            } else {
                dp[1][i] = tmp;
                yes = true;
            }
        } else {
            dp[1][i] = ++tmp;
        }
    }
    for (int i = 1; i <= m; i++){
        dp[i][0] = i;
    }
}

int main(){
    setIO();
    cin >> s1 >> s2;
    if (s2.size() > s1.size()){
        swap(s1, s2);
    }
    n = s1.size();
    m = s2.size();
    s1 = " " + s1;
    s2 = " " + s2;
    setup();
    for (int i = 2; i <= m; i++){
        for (int j = 1; j <= n; j++){
            if (s1[j] != s2[i]){
                dp[i][j] = min(dp[i - 1][j - 1],min(dp[i - 1][j], dp[i][j - 1])) + 1;
            } else {
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }
    cout << dp[m][n];
}
