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
const int max_e = 3;

using namespace std;

typedef pair<int, int> pii;

int n;

struct Node{
    int cnt;
    Node* child[max_e];
    Node() {
        cnt = 0;
        fill(child, child + max_e, nullptr);
    };
};

void add(Node* root, int x){
    Node* cur = root;
    for (int i = 30; i >= 0; i--){
        int c = (x >> i)&1;
        if (!cur -> child[c]){
            cur -> child[c] = new Node();
        }
        cur = cur -> child[c];
        cur -> cnt++;
    }
}

void getOut(Node* root, int x){
    Node* cur = root;
    for (int i = 30; i >= 0; i--){
        int c = (x >> i)&1;
        (cur -> child[c]) -> cnt--;
        if ((cur -> child[c]) -> cnt == 0){
            delete(cur -> child[c]);
            cur -> child[c] = nullptr;
            break;
        }
        cur = cur -> child[c];
    }
}

ll findVal(Node* root, int x){
    ll ans = 0;
    Node* cur = root;
    for (int i = 30; i >= 0; i--){
        int c = 1 - (x >> i)&1;
        if (cur -> child[c] != nullptr){
            cur = cur -> child[c];
            ans += (1 << i);
        } else {
            cur = cur -> child[1 - c];
            ans += (0 << i);
        }
    }

    return ans;
}

int main(){
    _io;
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);
    //  freopen(file".inp","r",stdin);
    //  freopen(file".out", "w", stdout);
    cin >> n;
    char s;
    int x;
    Node* root = new Node();
    add(root, 0);
    for (int i = 1; i <= n; i++){
        cin >> s >> x;
        if (s == '+'){
            add(root, x);
        } else
        if (s == '-'){
            getOut(root, x);
        } else {
            cout << findVal(root, x) << '\n';;
        }
    }
}
