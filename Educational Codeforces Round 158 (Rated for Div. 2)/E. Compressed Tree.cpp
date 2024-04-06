/**
 * Source: is.gd/fA7NYi
 * Date: 2024/3/2
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

const int MX = 5e5+10;

int nums[MX], n;
ll dp[MX], res;
vector<int> adj_list[MX];


void dfs(int cur, int par) {
    dp[cur] = nums[cur], res = max(res, dp[cur]);
    vector<ll> n;
    for (auto &i: adj_list[cur]) {
        if (i == par) continue;
        dfs(i, cur);
        res = max(res, nums[cur] + dp[i]);
        dp[cur] = max(dp[cur], dp[i]);
        n.push_back(dp[i]);
    }
    sort(begin(n), end(n), greater<ll>());
    if (n.size() >= 2) {
        ll a = n[0] + n[1];
        res = max(res, a);
        for (int i = 2; i < (int)n.size() && n[i] > 0; i++) {
            a += n[i];
        }
        dp[cur] = max(dp[cur], a + nums[cur]);
    }
    if (n.size() >= 3) {
        ll a = n[0] + n[1] + n[2];
        for (int i = 3; i < (int)n.size() && n[i] > 0; i++) {
            a += n[i];
        }
        res = max(res, a + nums[cur]);
    }
};

void solve() {
    int a, b;
    res = 0;
    cin >> n;
    for (int i = 0; i < n; i++) adj_list[i].clear();
    for (int i = 0; i < n; i++) cin >> nums[i];
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        adj_list[a - 1].push_back(b - 1);
        adj_list[b - 1].push_back(a - 1);
    }

    dfs(0, -1);
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