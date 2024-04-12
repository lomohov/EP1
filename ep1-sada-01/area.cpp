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
    int n;
    cin >> n >> n;
    int y = 0;
    int S = 0;
    while(true) {
        char dir;
        cin >> dir;
        if (dir == '.') break;
        if (dir == 'N') y++;
        if (dir == 'S') y--;
        if (dir == 'W') S += y;
        if (dir == 'E') S -= y;
    }
    cout << "The area is " << abs(S) << " squares." << endl;
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


