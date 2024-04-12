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
    scanf("%jd ", &n);
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        size_t last_char_pos = line.find_last_not_of('\r');
        if (last_char_pos != std::string::npos) {
            line.erase(last_char_pos + 1);
        }
        unordered_set<char> relevant_symbols = {'(', ')', '{', '}', '[', ']', '<', '>'};
        stack<string> waiting_for;
        bool ok = true;
        for (size_t j = 0; j < line.size(); ++j) {
            if (!relevant_symbols.count(line[j])) continue;
            if (line[j] == '(') {
                if (j + 1 < line.size() && line[j+1] == '*') {
                    waiting_for.emplace("(*");
                } else {
                    waiting_for.emplace("(");
                }
            } else if (line[j] == '{' || line[j] == '<' || line[j] == '[') {
                waiting_for.emplace(1,line[j]);
            } else if (line[j] == '}') {
                if (waiting_for.empty() || waiting_for.top()[0] != '{') {
                    ok = false;
                    break;
                }
                waiting_for.pop();
            } else if(line[j] == '>') {
                if (waiting_for.empty() || waiting_for.top()[0] != '<') {
                    ok = false;
                    break;
                }
                waiting_for.pop();
            } else if (line[j] == ']') {
                if (waiting_for.empty() || waiting_for.top()[0] != '[') {
                    ok = false;
                    break;
                }
                waiting_for.pop();
            } else if (line[j] == ')') {
                if (j > 0 && line[j-1] == '*') {
                    if (waiting_for.empty() || waiting_for.top() != "(*" || (j > 1 && line[j-2] == '(')) {
                        ok = false;
                        break;
                    }
                    waiting_for.pop();
                } else {
                    if (waiting_for.empty() || waiting_for.top()[0] != '(' || waiting_for.top().size() > 1) {
                        ok = false;
                        break;
                    }
                    waiting_for.pop();
                }
            }
        }
        cout << ( waiting_for.empty() && ok ? "Plan je v poradku." : "V planu je chyba.") << endl;
    }
}
signed main() {
    //std::istream::sync_with_stdio(false); cin.tie(nullptr);
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


