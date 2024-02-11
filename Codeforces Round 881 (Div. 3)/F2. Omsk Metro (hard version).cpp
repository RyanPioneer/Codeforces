/**
 * Source: is.gd/J0yq92
 * Date: 2024/2/10
 * Skill: binary lifting, divide and conquer
 * Constraints:
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>
#include <bitset>
#include <functional>
#include <list>


#define SZ(X) ((int)(X).size())
#define ll long long
using namespace std;
const int K = 19;


struct Node {
    int total, mx_prev, mi_prev, mx_suf, mi_suf, max_seg_sum, min_seg_sum;
};

Node operator +(const Node& left, const Node& right) {
    return Node{
            left.total + right.total,
            max(left.mx_prev, left.total + right.mx_prev),
            min(left.mi_prev, left.total + right.mi_prev),
            max(right.mx_suf, left.mx_suf + right.total),
            min(right.mi_suf, left.mi_suf + right.total),
            max({left.max_seg_sum, right.max_seg_sum, left.mx_suf + right.mx_prev}),
            min({left.min_seg_sum, right.min_seg_sum, left.mi_suf + right.mi_prev}),
    };
};

Node make(int weight) {
    return Node{
            weight, max(0, weight), min(0, weight), max(0, weight),
            min(0, weight), max(0, weight), min(0, weight)
    };
};

Node reverse_node(const Node& node) {
    return Node{
            node.total, node.mx_suf, node.mi_suf, node.mx_prev,
            node.mi_prev, node.max_seg_sum, node.min_seg_sum
    };
};

void solve() {
    int n, v, x, u, k, total = 1;
    char c;
    cin >> n;
    vector<int> weights(1, 1), depth(1, 0);
    vector<array<int, K>> father(n + 1);
    vector<array<Node, K>> lift(n + 1);
    fill(begin(father[0]), end(father[0]), 0);
    lift[0] = {make(1)};
    while (n--) {
        cin >> c;
        if (c == '+') {
            cin >> v >> x;
            weights.push_back(x);
            depth.push_back(depth[--v] + 1);
            father[total++][0] = v;
            lift[total - 1][0] = make(x);
            for (int i = 1; i < K; i++) {
                father[total - 1][i] = father[father[total - 1][i - 1]][i - 1];
                lift[total - 1][i] = lift[total - 1][i - 1] + lift[father[total - 1][i - 1]][i - 1];
            }
        } else {
            cin >> u >> v >> k;
            if (depth[--u] < depth[--v]) swap(u, v);
            Node left = make(0), right = make(0);
            for (int i = K - 1; i >= 0; i--) {
                if (depth[u] - depth[v] >= 1<<i) {
                    left = left + lift[u][i];
                    u = father[u][i];
                }
            }
            for (int i = K - 1; i >= 0; i--) {
                if (father[u][i] != father[v][i]) {
                    left = left + lift[u][i];
                    u = father[u][i];
                    right = right + lift[v][i];
                    v = father[v][i];
                }
            }
            if (u != v) {
                left = left + lift[u][0];
                right = right + lift[v][0];
                u = father[u][0];
            }
            Node seg = left + make(weights[u]) + reverse_node(right);
            cout << (seg.min_seg_sum <= k && k <= seg.max_seg_sum ? "yes" : "no") << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    for (cin >> t; t--;) {
        solve();
    }
}