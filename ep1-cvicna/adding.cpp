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
    string a, b;
    cin >> a >> b;
    reverse(all(a));
    reverse(all(b));
    int a_num = stoll(a), b_num = stoll(b);
    string res = to_string(a_num+b_num);
    reverse(all(res));
    int res_num = stoll(res);
    cout << res_num << endl;
}
signed main() {
    std::istream::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(std::istream::failbit);

    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}


