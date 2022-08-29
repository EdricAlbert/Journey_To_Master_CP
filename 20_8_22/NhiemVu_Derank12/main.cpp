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

struct info{
    int first, second;
    ll third;
};

bool cmp(const info& a, const info& b){
    return (a.third > b.third);
}

info quest[max_n];
int n, m;

int main(){
    _io;
     freopen("input.txt","r",stdin);
     freopen("output.txt", "w", stdout);
    //  freopen(file".inp","r",stdin);
    //  freopen(file".out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> quest[i].first;
    }
    for (int i = 1; i <= n; i++){
        cin >> quest[i].second;
        quest[i].third = abs(quest[i].first - quest[i].second);
    }
    sort(quest + 1, quest + 1 + n, cmp);
    ll res = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        if (cnt == m){
            res += quest[i].first;
        } else
        if (m - cnt == n - i + 1){
            res += quest[i].second;
            cnt++;
        } else {
            if (quest[i].first >= quest[i].second){
                res += quest[i].first;
            } else {
                res += quest[i].second;
                cnt++;
            }
        }
    }
    cout << res << '\n';
}
