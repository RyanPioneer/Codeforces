/**
 * Source: is.gd/4Z1H7R
 * Date: 2024/4/18
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


void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> edges(n + 1);
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    ll res = 0;

    function<vector<int>(int, int)> dfs = [&](int cur, int par) {
        vector<int> dis(k + 1, 0);
        for (auto &i: edges[cur]) {
            if (i == par) continue;
            vector<int> d = dfs(i, cur);
            for (int j = 1; j < k; j++) {
                res += dis[j + 1] * d[k - j];
            }
            res += d[k];
            for (int j = 1; j < k; j++) {
                dis[j + 1] += d[j];
            }
        }
        dis[1]++;
        return dis;
    };

    dfs(1, 0);
    cout << res << endl;
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