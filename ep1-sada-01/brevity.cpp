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

char shootCoordinates(int i, int j) {
    char symbol = (char)('a' + i);
    cout << symbol << j << endl;
    string res;
    cin >> res;
    if (res == "miss") {
        return '.';
    }
    return res == "hit" ? 'x' : 'd';
}
void solve() {
    vector<vector<char>> board (10, vector<char>(10,'e'));
    int shipsLeft = 6;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (board[i][j] != 'e') continue;
            auto shot = shootCoordinates(i, j);
            if (shot != 'd') {
                board[i][j] = 1;
            }
            else {
                if (!--shipsLeft) return;
                array<pair<int, int>, 5> directions = {make_pair(1, 1),
                                                       make_pair(1, 0),
                                                       make_pair(1, -1),
                                                       make_pair(0, 1),
                                                       make_pair(0, -1)};
                for (const auto &[x, y]: directions) {
                    if (i+x < 10 && j+y < 10) {
                        if (board[i+x][j+y] == 'e') board[i+x][j+y] = '.';
                    }
                }
            }
        }
    }

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
    //cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}


