/**
 * Source: is.gd/KRRWNq
 * Date: 2024/4/19
 * Time:
 * Space:
 * Skill:
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
typedef pair<int, int> PII;
typedef pair<ll, int> PLI;


const int MX = 1e3+10;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<PII>> edges(n + 1);
    vector<int> par(n + 1, 0);
    vector<bool> visited(n + 1, false);
    for (int i = 0, j, k, l; i < m; i++) {
        cin >> j >> k >> l;
        if (j == k) continue;
        edges[j].push_back({k, l});
        edges[k].push_back({j, l});
    }

    priority_queue<PLI, vector<PLI>, greater<>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();
        if (visited[node]) continue;
        visited[node] = true;
        for (auto &e: edges[node]) {
            ll i = d + e.second;
            if (dis[e.first] > i) {
                par[e.first] = node;
                pq.push({i, e.first});
                dis[e.first] = i;
            }
        }
    }

    if (par[n] == 0) {
        cout << -1 << endl;
        return;
    }
    vector<int> res;
    while (n != 0) {
        res.push_back(n);
        n = par[n];
    }
    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    for (t = 1; t--;) {
        solve();
    }
}