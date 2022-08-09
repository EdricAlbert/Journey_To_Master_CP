//   MASTER COMPETITIVE PROGRAMMING WITH
//               BUDDHA
//               _oo0oo_
//              o8888888o
//              88" . "88
//              (| -_- |)
//              0\  =  /0
//            ___/`---'\___
//          .' \\|     |// '.
//         / \\|||  :  |||// \
//        / _||||| -:- |||||- \
//       |   | \\\  -  /// |   |
//       | \_|  ''\---/''  |_/ |
//       \  .-\__  '-'  ___/-. /
//     ___'. .'  /--.--\  `. .'___
//  ."" '<  `.___\_<|>_/___.' >' "".
// | | :  `- \`.;`\ _ /`;.`/ - ` : | |
// \  \ `_.   \_ __\ /__ _/   .-` /  /
//=====`-.____`.___ \_____/___.-`___.-'=====
//               `=---='
/*

██████╗░██╗░░░░░███████╗░█████╗░░██████╗███████╗░░░░░░░░░░░░░█████╗░░█████╗░░█████╗░███████╗██████╗░████████╗
██╔══██╗██║░░░░░██╔════╝██╔══██╗██╔════╝██╔════╝░░░░░░░░░░░░██╔══██╗██╔══██╗██╔══██╗██╔════╝██╔══██╗╚══██╔══╝
██████╔╝██║░░░░░█████╗░░███████║╚█████╗░█████╗░░█████╗█████╗███████║██║░░╚═╝██║░░╚═╝█████╗░░██████╔╝░░░██║░░░
██╔═══╝░██║░░░░░██╔══╝░░██╔══██║░╚═══██╗██╔══╝░░╚════╝╚════╝██╔══██║██║░░██╗██║░░██╗██╔══╝░░██╔═══╝░░░░██║░░░
██║░░░░░███████╗███████╗██║░░██║██████╔╝███████╗░░░░░░░░░░░░██║░░██║╚█████╔╝╚█████╔╝███████╗██║░░░░░░░░██║░░░
╚═╝░░░░░╚══════╝╚══════╝╚═╝░░╚═╝╚═════╝░╚══════╝░░░░░░░░░░░░╚═╝░░╚═╝░╚════╝░░╚════╝░╚══════╝╚═╝░░░░░░░░╚═╝░░░

*/
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

const int max_n = 8001;
const ll mod = 1e9 + 7;
const ll inf = 1e9;
const ld eps = 1e-9;

using namespace std;

typedef pair<int, int> pii;

int dp[max_n];
string st;

void setup(){
    for (int i = 0; i < st.size(); i++){
        dp[i + 1] = (i + 2);
    }
}

vector<int> zFunction(string s){
    int n = (int)s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++){
        if (i <= r){
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]){
            z[i]++;
        }
        if (i + z[i] - 1 > r){
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int calculate(int x){
    if ((x/1000) > 0){
        return 4;
    } else
    if ((x/100) > 0){
        return 3;
    } else
    if ((x/10) > 0){
        return 2;
    } else {
        return 1;
    }
}

int main(){
    _io;
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);
    //  freopen(file".inp","r",stdin);
    //  freopen(file".out", "w", stdout);
    cin >> st;
    setup();
    string tmp;
    vector<int> z;
    st = " " + st;
    for (int i = 1; i < st.size(); i++){
        tmp = st.substr(i, st.size() - i);
        z = zFunction(tmp);
        dp[i] = min(dp[i], dp[i - 1] + 2);
        for (int j = i + 1; j < st.size(); j++){
            if (st[j] == st[i]){
                int step = (j - i + 1);
                dp[j] = min(dp[j], dp[i - 1] + step + 1);
            }
        }
        for (int j = 1; j < z.size(); j++){
            int t = z[j];
            if (j <= z[j]){
                int step = calculate((j + z[j])/j);
                dp[i + j + z[j] - 1] = min(dp[i + j + z[j] - 1], dp[i - 1] + step + j);
            } else {
                dp[i + j] = min(dp[i + j], dp[i - 1] + 2 + j);
            }
        }
    }
    cout << dp[st.size() - 1];
}
