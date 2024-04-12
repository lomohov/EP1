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

struct Node {
    int val = 0;
    Node *left = nullptr;
    Node *right = nullptr;
};

Node *createNode(int x) {
    Node *node = new Node;
    node->val = x;
    node->left = nullptr;
    node->right = nullptr;

    return node;
}

void bstInsert(Node *&root, int x) {
    if (root == nullptr) {
        root = createNode(x);
        return;
    }

    if (x < root->val) {
        if (root->left == nullptr) {
            root->left = createNode(x);
            return;
        } else {
            bstInsert(root->left, x);
        }
    }

    if (x > root->val) {
        if (root->right == nullptr) {
            root->right = createNode(x);
            return;
        } else {
            bstInsert(root->right, x);
        }
    }
}

bool dfsSame(Node *a, Node *b) {
    if (!a && !b) {
        return true;
    }

    if (!a || !b) {
        return false;
    }

    return dfsSame(a->left, b->left) && dfsSame(a->right, b->right);
}

void solve() {
    int n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    vector<Node *> trees;
    for (int i = 0; i < n; ++i) {
        Node *root = nullptr;
        for (int j = 0; j < k; ++j) {
            int value;
            cin >> value;
            bstInsert(root, value);
        }
        trees.push_back(root);
    }

    vector isUnique(sz(trees), true);

    for (int i = 0; i < sz(trees); ++i) {
        for (int j = i + 1; j < sz(trees); ++j) {
            if (isUnique[j] && dfsSame(trees[i], trees[j])) {
                isUnique[j] = false;
            }
        }
    }

    cout << count(isUnique.begin(), isUnique.end(), true) << endl;
}

signed main() {
    std::istream::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}


