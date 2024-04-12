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
    int map_count = 1;
    while (true) {
        long double cur_x = 0.0, cur_y = 0.0;
        string line;
        getline(cin, line);

        // Windows bullshit
        size_t last_char_pos = line.find_last_not_of('\r');
        if (last_char_pos != std::string::npos) {
            line.erase(last_char_pos + 1);
        }
        if (line == "END") break;
        stringstream is(line);
        string direction;
        while (getline(is, direction, ',')) {
            stringstream direction_stream(direction);
            int count;
            string dir;
            direction_stream >> count >> dir;
            if (dir.size() == 1 || (dir.size() == 2 && dir[1] == '.')) {
                switch (dir[0]) {
                    case 'N':
                        cur_y += 1 * count;
                        break;
                    case 'W':
                        cur_x -= 1 * count;
                        break;
                    case 'E':
                        cur_x += 1 * count;
                        break;
                    case 'S':
                        cur_y -= 1 * count;
                        break;
                }
            }
            else {
                dir[0] == 'N' ? cur_y += (long double) sqrt(2)/2 * count
                              : cur_y -= (long double) sqrt(2)/2 * count;

                dir[1] == 'E' ? cur_x += (long double) sqrt(2)/2 * count
                              : cur_x -= (long double) sqrt(2)/2 * count;
            }
            if (dir.back() == '.') break;
        }
        cout << "Map #" << map_count++ << endl;
        cout << "The treasure is located at (" << setprecision(3)  << fixed << cur_x << "," << cur_y << ")." << endl;
        cout << "The distance to the treasure is " << setprecision(3) << fixed << (sqrt(cur_x*cur_x + cur_y*cur_y)) << "." << endl << endl;

    }
}

signed main() {
    std::istream::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(std::istream::failbit);

    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}


