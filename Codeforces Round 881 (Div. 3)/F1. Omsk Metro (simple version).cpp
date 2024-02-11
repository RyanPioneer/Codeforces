/**
 * Source: is.gd/cpePkH
 * Date: 2024/2/10
 * Skill: 用dp求最大跟最小連續區間和
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
const int MX = 2e5 + 2;

class Node {
public:
    int pre_mx, pre_mi, mx, mi;
} nodes[MX];

void addNode(int idx, int father, int weight) {
    nodes[idx].mx = weight + max(0, nodes[father].mx);
    nodes[idx].mi = weight + min(0, nodes[father].mi);
    nodes[idx].pre_mx = max(nodes[father].pre_mx, nodes[idx].mx);
    nodes[idx].pre_mi = min(nodes[father].pre_mi, nodes[idx].mi);
}

void solve() {
    int n, v, x, u, k, total = 1;
    nodes[1].pre_mx = nodes[1].mx = nodes[1].mi = 1;
    nodes[1].pre_mi = 0;
    cin >> n;
    char op;
    while (n--) {
        cin >> op;
        if (op == '+') {
            cin >> v >> x;
            addNode(++total, v, x);
        } else {
            cin >> u >> v >> k;
            cout << (nodes[v].pre_mx >= k && nodes[v].pre_mi <= k ? "yes" : "no") << endl;
        }
    }
}

int main() {
    int t;
    for (cin >> t; t--;) {
        solve();
    }
}