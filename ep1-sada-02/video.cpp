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
    while (true) {
        int floorCounter = 1;
        int n;
        cin >> n;
        if (!n) break;
        vector<pair<pii, pii>> edges(n+1);
        int startX, startY;
        cin >> startX >> startY;
        int prevX = startX, prevY = startY;
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            edges[i] = {{prevX, prevY},{x, y}};
            prevX = x, prevY = y;
        }
        edges[n] = {{prevX, prevY}, {startX, startY}};
        for (int i = 0; i < (n + 1); ++i) {
            auto [startPoint, endPoint] = edges[i];
            if (endPoint.first)
        }
        cout << "Floor #" << floorCounter++ << '\n';

    }
}
signed main() {
    std::istream::sync_with_stdio(false); cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}


