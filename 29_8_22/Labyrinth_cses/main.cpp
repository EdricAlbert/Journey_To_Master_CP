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

bool visited[max_n][max_n];
char a[max_n][max_n];
pii last[max_n][max_n];
int s1, s2, e1, e2;
bool flag = false;
int n, m;
int row[4] = {0, 0, -1, 1};
int col[4] = {1, -1, 0, 0};

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

bool check(int u, int v){
    return (u >= 1 && v >= 1 && u <= n && v <= m);
}

void bfs(int x, int y){
    queue<pii> q;
    q.push({x, y});
    while (!q.empty()){
        pii tmp = q.front();
        q.pop();
        int u = tmp.first;
        int v = tmp.second;
        visited[u][v] = true;
        for (int i = 0; i < 4; i++){
            int wu = u + row[i];
            int wv = v + col[i];
            if (check(wu , wv)){
                if (a[wu][wv] == 'B'){
                    flag = true;
                    last[wu][wv] = {u, v};
                    return;
                } else
                if (!visited[wu][wv] && a[wu][wv] == '.'){
                    visited[wu][wv] = true;
                    q.push({wu, wv});
                    last[wu][wv] = {u, v};
                }
            }
        }
    }
}

void traceback()
{
    int u = e1;
    int v = e2;
    string ans;
    while (last[u][v].first != 0 && last[u][v].second != 0){
        int vu = last[u][v].first;
        int vv = last[u][v].second;
        if (vu != u){
            if (vu == u + 1){
                ans += 'U';
            } else {
                ans += 'D';
            }
        } else {
            if (vv == v + 1){
                ans += 'L';
            } else {
                ans += 'R';
            }
        }
        u = vu;
        v = vv;
    }
    cout << ans.size() << '\n';
    reverse(all(ans));
    cout << ans;
}

int main(){
    setIO();
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
            if (a[i][j] == 'A'){
                s1 = i;
                s2 = j;
            } else
            if (a[i][j] == 'B'){
                e1 = i;
                e2 = j;
            }
        }
    }
    bfs(s1, s2);
    if (flag){
        cout << "YES" << '\n';
        traceback();
    } else {
        cout << "NO" << '\n';
    }
    return 0;
}
