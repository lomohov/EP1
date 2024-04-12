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
    int r, s;
    cin >> r >> s;
    vvi prefix_sum (r, vi(s+1, 0));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < s; ++j) {
            int num;
            cin >> num;
            prefix_sum[i][j+1] = num + prefix_sum[i][j];
        }
    }
    int d;
    cin >> d;
    for (int i = 0; i < d; ++i) {
        int r1, s1, r2, s2;
        cin >> r1 >> s1 >> r2 >> s2;
        int sum = 0;
        for (int j = r1-1; j < r2; ++j) {
            sum += prefix_sum[j][s2] - prefix_sum[j][s1-1];
        }
        cout << "Absolutni hodnota pohodlnosti je " << sum << " bodu." << endl;
    }
    cout << endl;
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


