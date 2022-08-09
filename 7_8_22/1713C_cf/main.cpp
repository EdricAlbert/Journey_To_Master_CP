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

    typedef pair<int, int> pii;

    bool f[max_n][448];
    bool check[max_n];
    pii has[max_n];
    int ans[max_n];
    int n;

    void setup(){
        for (int i = 0; i <= 447; i++){
            for (int j = 0; j <= n; j++){
                f[j][i] = false;
            }
        }
        for (int i = 0; i <= n; i++){
            has[i].first = 0;
            has[i].second = i;
            check[i] = false;
        }
    }

    bool cmp(const pii& a, const pii& b){
        return (a.first < b.first) || (a.first == b.first && a.second > b.second);
    }

    int main(){
        _io;
        //freopen("input.txt","r",stdin);
        //freopen("output.txt", "w", stdout);
        //  freopen(file".inp","r",stdin);
        //  freopen(file".out", "w", stdout);
        int t;
        cin >> t;
        while (t--){
            cin >> n;
            setup();
            for (int i = 0; i*i <= 2*n; i++){
                for (int j = 0; j <= i*i && j <= n - 1; j++){
                    if (i*i - j <= n - 1 && i*i - j >= 0){
                        f[j][i] = true;
                        has[j].first++;
                    }
                }
            }
            sort(has, has + n, cmp);
            bool done = true;
            for (int i = 0; i <= n - 1; i++){
                int pos = has[i].second;
                bool flag = false;
                for (int j = sqrt(2*n - 2); j >= 0; j--){
                    if (f[pos][j] == true && j*j - pos >= 0 && check[j*j - pos] == false){
                        check[j*j - pos] = true;
                        ans[j*j - pos] = pos;
                        flag = true;
                        break;
                    }
                }
                if (!flag){
                    cout << "-1";
                    done = false;
                    break;
                }
            }
            if (done == true){
                for (int i = 0; i <= n - 1; i++){
                    cout << ans[i] << " ";
                }
            }
            cout << '\n';
        }
    }
