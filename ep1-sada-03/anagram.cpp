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
void permutations(const string& inputString, int k, const string& current, unordered_map<char, int>& charCount, set<string>& result) {
    if (k == 0) {
        result.emplace(current);
        return;
    }

    for (auto& [ch, count] : charCount) {
        if (count > 0) {
            count--;
            permutations(inputString, k - 1, current + ch, charCount, result);
            count++;
        }
    }
}
void solve() {
    while (true) {
        int k;
        cin >> k;
        if (!k) break;
        string word;
        cin >> word;
        unordered_map<char, int> charCount;
        for (auto ch : word) {
            charCount[ch]++;
        }

        set<string> perms;
        permutations(word, k, "", charCount, perms);
        for (const auto & perm : perms) {
            cout << perm << '\n';
        }
        cout << perms.size() << '\n';
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


