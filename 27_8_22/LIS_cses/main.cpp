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

int n;
int a[max_n];
int dp[max_n];
vector<int> nums;

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

int bs(int x){
    int l = 0;
    int r = nums.size() - 1;
    int res = nums.size();
    while (l <= r){
        int mid = (l + r)/2;
        if (nums[mid] >= x){
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return res;
}

int main(){
    setIO();
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int res = 0;
    for (int i = 1; i <= n; i++){
        int j = bs(a[i]);
        if (j == nums.size()){
            nums.push_back(j);
        }
        nums[j] = a[i];
        dp[i] = j + 1;
        res = max(res, dp[i]);
    }
    cout << res << '\n';
}
