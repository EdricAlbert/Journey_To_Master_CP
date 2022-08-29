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

const int max_n = 2e5 + 5;
const ll mod = 1e9 + 7;
const ll inf = 1e9;
const ld eps = 1e-9;

using namespace std;

typedef pair<int, int> pii;

struct info{
    ll start, finish, cost;
};

info project[max_n];
int n;
ll dp[max_n];

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

bool cmp(const info& a, const info& b){
    return (a.finish < b.finish);
}

int bs(int x){
    int l = 1;
    int r = n;
    int res = -1;
    while (l <= r){
        int mid = (l + r)/2;
        if (project[mid].finish < x){
            l = mid + 1;
            res = mid;
        } else {
            r = mid - 1;
        }
    }
    return res;
}

int main(){
    setIO();
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> project[i].start >> project[i].finish >> project[i].cost;
    }
    sort(project + 1, project + 1 + n, cmp);
    for (int i = 1; i <= n; i++){
        int j = bs(project[i].start);
        if (j == -1){
            dp[i] = max(dp[i - 1], project[i].cost);
        } else {
            dp[i] = max(dp[i - 1], project[i].cost + dp[j]);
        }
    }
    cout << dp[n];
}
