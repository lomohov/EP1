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

/**
 * \brief Point ICPC template
 * \tparam T
 */
template<class T>
struct Point {
    typedef Point P;
    T x, y;

    explicit Point(T x = 0, T y = 0) : x(x), y(y) {
    }

    bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }
    bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }
    P operator+(P p) const { return P(x + p.x, y + p.y); }
    P operator-(P p) const { return P(x - p.x, y - p.y); }
    P operator*(T d) const { return P(x * d, y * d); }
    P operator/(T d) const { return P(x / d, y / d); }
    [[nodiscard]] T dot(P p) const { return x * p.x + y * p.y; }
    [[nodiscard]] T cross(P p) const { return x * p.y - y * p.x; }
    [[nodiscard]] T cross(P a, P b) const { return (a - *this).cross(b - *this); }
    [[nodiscard]] T dist2() const { return x * x + y * y; }
    [[nodiscard]] ld dist() const { return sqrt(static_cast<ld>(dist2())); }
    // angle to x−axis in interval [−pi , pi ]
    [[nodiscard]] ld angle() const { return atan2(y, x); }
    [[nodiscard]] P unit() const { return *this / dist(); } // makes dist()=1
    [[nodiscard]] P perp() const { return P(-y, x); } // rotates +90 degrees
    [[nodiscard]] P normal() const { return perp().unit(); }
    // returns point rotated ’a ’ radians ccw around the origin
    [[nodiscard]] P rotate(const ld a) const {
        return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
    }

    friend ostream& operator<<(ostream&os, P p) {
        return os << "(" << p.x << "," << p.y << ")";
    }
};

template<class T>
int sgn(T x, T eps = std::numeric_limits<T>::epsilon() * 100) {
    return (x > eps) - (x < -eps);
}

template<class P>
bool onSegment(P s, P e, P p) {
    return std::abs(p.cross(s, e)) <= 1e-12 && (s - p).dot(e - p) <= 1e-12;
}

template<class P>
vector<P> segIntersect(P a, P b, P c, P d) {
    auto oa = c.cross(d, a), ob = c.cross(d, b), oc = a.cross(b, c), od = a.cross(b, d);
    // Checks if intersection is single non−endpoint point.
    if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
        return {(a * ob - b * oa) / (ob - oa)};
    set<P> s;
    if (onSegment(c, d, a)) s.insert(a);
    if (onSegment(c, d, b)) s.insert(b);
    if (onSegment(a, b, c)) s.insert(c);
    if (onSegment(a, b, d)) s.insert(d);
    return {all(s)};
}

void solve() {
    int x1_line, y1_line, x2_line, y2_line;
    int x1_rect, y1_rect, x2_rect, y2_rect;
    cin >> x1_line >> y1_line >> x2_line >> y2_line;
    cin >> x1_rect >> y1_rect >> x2_rect >> y2_rect;

    const Point<ld> line_start(x1_line, y1_line), line_end(x2_line, y2_line);
    const Point<ld> rect_1(x1_rect, y1_rect), rect_2(x2_rect, y1_rect),
                    rect_3(x2_rect, y2_rect), rect_4(x1_rect, y2_rect);

    auto am = (line_start - rect_1);
    auto ab = (rect_2-rect_1);
    auto ad = (rect_4-rect_1);

    auto fpLessEq = [](const ld x, const ld y) {
        return x < y + numeric_limits<ld>::epsilon()*1000;
    };

    if (fpLessEq(0.0, am.dot(ab)) && fpLessEq(am.dot(ab),ab.dot(ab)) && fpLessEq(0.0, am.dot(ad)) && fpLessEq(am.dot(ad), ad.dot(ad))) {
        cout << "T\n";
        return;
    }

    const auto a = segIntersect(line_start, line_end, rect_1, rect_2);
    const auto b = segIntersect(line_start, line_end, rect_2, rect_3);
    const auto c = segIntersect(line_start, line_end, rect_3, rect_4);
    const auto d = segIntersect(line_start, line_end, rect_4, rect_1);

    cout << (a.empty() && b.empty() && c.empty() && d.empty() ? "F\n" : "T\n");
}

signed main() {
    std::istream::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}
