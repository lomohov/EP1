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
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;

void solve() {
    vector<int> sequence;
    while (true) {
        int a;
        cin >> a;
        if (!a) break;
        sequence.push_back(a);
    }
    int res = 0;
    int curMax = 0;
    int prev = 0;
    for (const auto item: sequence) {
        if (item >= prev) {
            curMax++;
        } else {
            res = max(curMax, res);
            curMax = 1;
        }
        prev = item;
    }
    cout << max(res, curMax) << endl;
}
signed main() {
    std::istream::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(std::istream::failbit);
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