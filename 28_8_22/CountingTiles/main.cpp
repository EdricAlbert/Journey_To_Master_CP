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

ll f[11][1001];
int n, m;

void setIO(string name = ""){
    _io;
    bool yes = true;
    if (name.size()){
        freopen((name + "inp").c_str(), "r", stdin);
        freopen((name + "out").c_str(), "w", stdin);
    } else
    if (yes == 1){ // Change to 1 if input/output -> txt.
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    }
}

int main(){
    setIO();
    cin >> n >> m;
    f[1][2] = 1;
    f[2][1] = 1;
    f[2][2] = 2;
    for (int i = 4; i <= n; i++){
        f[i][1] += f[i - 2][1];
    }
    for (int i = 3; i <= n; i++){
        f[i][2] = f[i - 2][2] + f[i - 1][2];
    }
    for (int i = 3; i <= m; i++){
        f[n][i] = f[n][i - 2] + f[n][i - 1];
    }
    cout << f[n][m];
}
