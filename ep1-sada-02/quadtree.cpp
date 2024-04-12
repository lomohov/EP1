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

void parse(vector<vector<int>> &out, stringstream &in, int N, int x0, int y0) {
    char symbol;
    in >> symbol;
    if(symbol == 'W' || symbol == 'B') {
        for(int y = 0; y < N; y++)
            for(int x = 0; x < N; x++)
                out[y0 + y][x0 + x] = symbol == 'B';
    }
    else {
        N /= 2;
        parse(out, in, N, x0, y0);
        parse(out, in, N, x0 + N, y0);
        parse(out, in, N, x0, y0 + N);
        parse(out, in, N, x0 + N, y0 + N);
    }
}

void solve() {
    int n;
    cin >> n;
    string line;
    cin >> line;
    cout << "#define quadtree_width " << n << "\n#define quadtree_height " << n << "\n";
    cout << "static char quadtree_bits[] = {\n";

    stringstream str (line);
    vector<vector<int>> picture (n, vector<int>(n, 0));

    parse(picture, str, n, 0, 0);

    for (int i = 0; i < n; ++i) {
        int byte = 0;
        for (int j = 0; j < n; ++j) {
            byte |= picture[i][j] << j%8;
            if (j%8 == 7) {
                cout << "0x" << hex << setfill('0') << setw(2)  << byte << ",";
                byte = 0;
            }
        }
        cout << "\n";
    }
    cout << "};\n";
}

signed main() {
    std::istream::sync_with_stdio(false); cin.tie(nullptr);
    int t = 1;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}


