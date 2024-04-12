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

int lis (const vi & seq) {
    if (seq.empty()) return 0;
    vector<pii> res;
    rep(i,0,sz(seq)) {
        auto it = lower_bound(all(res), pii{seq[i], i});
        if (it == res.end()) res.emplace_back(), it = res.end()-1;
        *it = {seq[i], i};
    }
    return sz(res);
}
void solve() {
    vector<int> sequence;
    while (true) {
        int a;
        cin >> a;
        if (!a) break;
        sequence.push_back(a);
    }
    cout << lis(sequence) << endl;
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


