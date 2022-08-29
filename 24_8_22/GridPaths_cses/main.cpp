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

const int max_n = 1e3 + 5;
const ll mod = 1e9 + 7;
const ll inf = 1e9;
const ld eps = 1e-9;

using namespace std;

typedef pair<int, int> pii;

char a[max_n][max_n];
ll dp[max_n][max_n];
int n;
int col[2] = {0, 1};
int row[2] = {1, 0};
bool visited[max_n][max_n];

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

bool check(int& x, int& y){
    return (x >= 1 && y >= 1 && x <= n && y <= n && a[x][y] != '*');
}

void bfs_loang(){
    queue<pii> pq;
    pq.push({1, 1});
    dp[1][1] = 1;
    if (a[1][1] == '*'){
        dp[1][1] = 0;
        return;
    }
    while (!pq.empty()){
        int u = pq.front().first;
        int v = pq.front().second;
        pq.pop();
        for (int k = 0; k < 2; k++){
            int vu = u + col[k];
            int vv = v + row[k];
            if (!check(vv, vu)){
                continue;
            }
            dp[vu][vv] += dp[u][v];
            dp[vu][vv]%=mod;
            if (!visited[vu][vv]){
                visited[vu][vv] = true;
                pq.push({vu, vv});
            }
        }
    }
}

int main(){
    setIO();
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    bfs_loang();
    cout << dp[n][n] << '\n';
}
