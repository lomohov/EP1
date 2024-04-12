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
        string expr;
        getline(cin, expr);
        //windows bullshit yet again
        size_t last_char_pos = expr.find_last_not_of('\r');
        if (last_char_pos != std::string::npos) {
            expr.erase(last_char_pos + 1);
        }
        expr.erase(remove_if(all(expr),[](unsigned char x) { return std::isspace(x); }), expr.end());
        if (expr == "0") break;
        stack<string> s;
        for (int i = sz(expr) - 1; i >= 0; i--) {
            if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
                auto op1 = s.top(); s.pop();
                auto op2 = s.top(); s.pop();
                s.emplace(op1 + op2 + expr[i]);
            } else {
                s.emplace(1, expr[i]);
            }
        }
        bool first = true;
        for (const auto item: s.top()) {
            if (first) {
                cout << item;
                first = false;
            } else {
                cout << " " << item;
            }
        }
        cout << '\n';
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


