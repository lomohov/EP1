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

auto countMoves (const vi & positions) -> int {
    int index = positions.back();
    int ret = 0;
    for(int i = sz(positions) - 1; i; i--) {
        if (positions[i-1] != index) {
            ret += 1 << i-1;
            index = 2*(index + positions[i-1])%3;
        }
    }
    return ret;
}

void solve() {
    int x;
    cin >> x;
    if (!x) {
        cout << "Je treba 0 presunu." << '\n';
        return;
    }
    vi endPos(x);
    for (int i = 0; i < x; ++i) {
        cin >> endPos[i];
    }
    std::reverse(all(endPos));
    int res = 0;
    res = countMoves(endPos);

    cout << "Je treba " << res << " presunu." << '\n';
}
signed main() {
    std::istream::sync_with_stdio(false); cin.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}
