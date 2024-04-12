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

void solve() {
    int e, f;
    cin >> e >> f;
    int n;
    cin >> n;
    vi dp (f-e+1, INT_MAX);
    dp[0] = 0;
    vii value_weight(n);
    for (int i = 0; i < n; ++i) {
        int value, weight;
        cin >> value >> weight;
        value_weight[i] = {value, weight};
    }
    for (int i = 0; i <= f-e; ++i) {
        if (dp[i] == INT_MAX) continue;
        for (auto [value, weight] : value_weight) {
            if (i+weight > f-e) continue;
            if (dp[i] + value < dp[i+weight]) dp[i+weight] = dp[i] + value;
        }
    }
    if (dp[f-e] == INT_MAX) {
        cout << "This is impossible.\n";
    }
    else {
        cout << "The minimum amount of money in the piggy-bank is " << dp[f-e] << ".\n";
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
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}


