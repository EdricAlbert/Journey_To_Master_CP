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

const int max_n = 1e5 + 5;
const ll mod = 1e9 + 7;
const ll inf = 1e9;
const ld eps = 1e-9;

using namespace std;
using namespace std::chrono;

typedef pair<int, int> pii;

ll k;

ll check(ll x){
    ll kq = 0; // 1e6
    for (ll i = 1; i < sqrt(x); i++){
        kq += (ll) sqrt(x - i*i);
    }
    return kq;
}

int main(){
    _io;
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);
    //  freopen(file".inp","r",stdin);
    //  freopen(file".out", "w", stdout);
    auto start = high_resolution_clock::now();
    cin >> k;
    ll left = 0;
    ll right = 1e12;
    ll res = 0;
    while (left <= right){ //O(41)
        ll mid = left + (right - left)/2;
        if (check(mid) >= k){
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << res << '\n';
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << '\n';
}
