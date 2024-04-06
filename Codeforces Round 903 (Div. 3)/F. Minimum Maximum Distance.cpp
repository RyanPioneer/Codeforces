/**
 * Source: is.gd/CR1rDF
 * Date: 2024/3/3
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
    int n, k, l, m, res = INT32_MAX;
    cin >> n >> k;
    vector<vector<int>> adj_list(n), dp(n, vector<int>(4, -2));
    vector<int> marked(n, 0);
    for (int i = 0; i < k; i++) {
        cin >> l;
        marked[l - 1]++;
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> l >> m;
        adj_list[l - 1].push_back(m - 1);
        adj_list[m - 1].push_back(l - 1);
    }

    function<int(int cur, int par)> find_bottom = [&](int cur, int par) {
        if (marked[cur] > 0) {
            dp[cur][0] = 0, dp[cur][1] = cur;
        }
        for (auto &i: adj_list[cur]) {
            if (i == par) continue;
            int d = find_bottom(i, cur);
            if (d >= 0) {
                if (d >= dp[cur][0]) {
                    dp[cur][2] = dp[cur][0], dp[cur][3] = dp[cur][1];
                    dp[cur][0] = d + 1, dp[cur][1] = i;
                } else if (d >= dp[cur][2]) {
                    dp[cur][2] = d + 1, dp[cur][3] = i;
                }
            }
        }
        return dp[cur][0];
    };

    function<void(int cur, int par, int top_dis)> find_par = [&](int cur, int par, int top_dis) {
        if (top_dis >= 0) top_dis++;
        if (marked[cur] != 0) top_dis = max(top_dis, 0);
        for (auto &i: adj_list[cur]) {
            if (i == par) continue;
            if (dp[cur][1] != i && dp[cur][0] > top_dis) {
                find_par(i, cur, dp[cur][0]);
            } else if (dp[cur][3] != i && dp[cur][2] > top_dis) {
                find_par(i, cur, dp[cur][2]);
            } else {
                find_par(i, cur, top_dis);
            }
        }
        top_dis = max({top_dis, dp[cur][0], dp[cur][2]});
        res = min(res, top_dis);
    };

    find_bottom(0, -1);
    find_par(0, -1, -1);
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    for (cin >> t; t--;) {
        solve();
    }
}