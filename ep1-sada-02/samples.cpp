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

int findAvgCount (vii & samples, const string & comp, int interval, int n) {
    int res = 0;
    const auto [first_t, first_v] = samples[0];
    int sum = first_v, start = 0, end = 1, timeOfStart = first_t, k = 1;

    while ( end < n) {
        auto [t, v] = samples[end];
        while (t-timeOfStart > interval) {
            sum -= samples[start].second;
            k--;
            timeOfStart = samples[++start].first;
        }
        if (comp == "gt") {
            if (v > (long double)(sum)/(long double)(k)) res++;

        } else {
            if (v < (long double)(sum)/(long double)(k)) res++;
        }
        sum += v;
        k++;
        end++;
    }

    return res;
}
int findMinMaxCount(vii & samples, const string & comp, const string & operation, int interval, int n) {
    multiset<int> sortedSamples;
    int res = 0;
    const auto [first_t, first_v] = samples[0];
    int start = 0, end = 1, timeOfStart = first_t;
    sortedSamples.emplace(first_v);
    while (end < n) {
        auto [t, v] = samples[end];
        while (t-timeOfStart > interval) {
            sortedSamples.erase(sortedSamples.find(samples[start].second));
            timeOfStart = samples[++start].first;
        }
        if (!sortedSamples.empty()) {
            if (comp == "gt") {
                if (operation == "min") {
                    if (v > *sortedSamples.begin()) res++;
                } else {
                    if (v > *sortedSamples.rbegin()) res++;
                }
            } else {
                if (operation == "min") {
                    if (v < *sortedSamples.begin()) res++;
                } else {
                    if (v < *sortedSamples.rbegin()) res++;
                }
            }
        }
        sortedSamples.emplace(v);
        end++;
    }
    return res;
}
void solve() {
    int n;
    while (cin >> n && n) {
        vii samples(n);
        for (int i = 0; i < n; ++i) {
            int t, v;
            cin >> t >> v;
            samples[i] = {t, v};
        }
        int q;
        cin >> q;
        for (int i = 0; i < q; ++i) {
            string comp, operation;
            int interval;
            cin >> comp >> operation >> interval;
            if (operation == "avg") {
                cout << findAvgCount(samples, comp, interval, n) << endl;
            }
            else {
                cout << findMinMaxCount(samples, comp, operation, interval, n) << endl;
            }
        }
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


