#include <bits/stdc++.h>
using namespace std;
#define int intmax_t
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
vii read_coins () {
    vii coins;
    while (true) {
        ld value;
        string q;
        cin >> value;
        if (value == -1) break;
        cin >> q;
        stringstream q_stream(q);
        int quantity;
        q_stream >> quantity;
        coins.emplace_back(static_cast<int>(round(value*100)), quantity);
    }
    return coins;
}
void solve() {
    while (true) {
        ld wanted_num_ld;
        cin >> wanted_num_ld;
        if (wanted_num_ld == -1) return;
        int wanted = static_cast<int>(round(wanted_num_ld*100));
        auto customer_coins = read_coins();
        auto shop_coins = read_coins();

    }
}

signed main() {
    std::istream::sync_with_stdio(false); cin.tie(nullptr);
//#undef int
//    signal(SIGSEGV, [](int) {
//        exit(0);
//    });
//#define int intmax_t
    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}


