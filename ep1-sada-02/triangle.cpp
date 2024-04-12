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
    int triangleCounter = 1;
    while (true) {
        int n;
        cin >> n;
        if (!n) break;
        vector<vector<char>> triangle (n, vector<char>(2*n, ' '));
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < 2*n - 1 - i; ++j) {
                cin >> triangle[i][j];
            }
            cin >> ws;
        }
        int maxArea = 0;
        vector<vii> intervals(n);
        for (int i = 0; i < n; ++i) {
            int lastStartIndex = 0, currEndIndex = 0;
            for (int j = 0; j < 2*n - 1 - i; ++j, ++currEndIndex) {
                if (triangle[i][j] != '-') {
                    if (lastStartIndex != currEndIndex) {
                        intervals[i].emplace_back(lastStartIndex, currEndIndex);
                    }
                    lastStartIndex = j + 1;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (const auto &[left, right]: intervals[i]) {

            }
        }
        cout << "Triangle #" << triangleCounter << "\n";
        cout << "The largest triangle area is " << maxArea << ".\n\n";
        triangleCounter++;
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


