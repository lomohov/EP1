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

struct Less {
    bool operator ()(const ld a , const ld b) const {
        return (abs(a - b) / abs(a + b) >= 100*DBL_EPSILON && a < b);
    }
};
void solve() {
    while (true) {
        int n;
        cin >> n;
        if (!n) return;
        map<ld, int, Less> lengths;
        for (int i = 0; i < n; ++i) {
            ld x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            ld length = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
            lengths[length]++;
        }
        auto longest = max_element(all(lengths), [](const pair<ld, int> & p1, const pair<ld, int> & p2){
            return p1.first < p2.first;
        });
        cout << longest->second << " usecek ma delku " << setprecision(2) << fixed << sqrt(longest->first) << "." << endl;

    }
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
    //cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}


