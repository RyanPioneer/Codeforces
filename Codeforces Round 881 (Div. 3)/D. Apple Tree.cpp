/**
 * Source: is.gd/ypeQ9W
 * Date: 2024/2/3
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
    int a, b, n, q, res = 0;

    cin >> n;
    vector<vector<int>> edges(n + 1);
    vector<int> nums(n + 1, 0);
    for (int i = 1; i < n; ++i) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    function<int(int, int)> dfs = [&](int cur, int par) {
        if (edges[cur].size() == 1 && edges[cur][0] == par) {
            nums[cur] = 1;
            return 1;
        }
        int num = 0;
        for (auto &c: edges[cur]) {
            if (c == par) continue;
            num += dfs(c, cur);
        }
        return nums[cur] = num;
    };
    dfs(1, 0);
    cin >> q;
    while (q--) {
        cin >> a >> b;
        cout << (ll)nums[a] * nums[b] << endl;
    }
}

int main() {
    int t;
    for (cin >> t; t--;) {
        solve();
    }
}