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
    while (true) {
        int r, s, c;
        cin >> r >> s >> c;
        if (!r || !s || !c) return;
        map<char, string> worm_mapper;
        unordered_map<char, int> eaten;
        for (int i = 0; i < c; ++i) {
            string worm;
            cin >> worm;
            worm_mapper[worm[0]] = worm;
        }
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < s; ++j) {
                char symbol;
                cin >> symbol;
                if (symbol == '*') continue;
                eaten[symbol]++;
            }
        }
        if (!eaten.empty()) {
            auto most_freq_symbol = max_element(all(eaten), [](const pair<char, int> & p1, const pair<char, int> & p2){
                return p1.second < p2.second;
            })->first;
            cout << "Nejzravejsi cervotoc je " << worm_mapper[most_freq_symbol] << "." << endl;
        } else {
            cout << "Nejzravejsi cervotoc je " << worm_mapper.begin()->second << "." << endl;
        }
    }
}
signed main() {
    std::istream::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(std::istream::failbit);
#undef int
    signal(SIGSEGV, [](int) {
        exit(0);
    });
#define int intmax_t
    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}


