/**
 * Source: is.gd/td3jAr
 * Date: 2024/4/7
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
    int n, a, b;
    cin >> n >> a >> b;
    a--, b--;
    vector<vector<array<int, 2>>> edges(n);
    for (int i = 1, x, y, w; i < n; i++) {
        cin >> x >> y >> w;
        x--, y--;
        array<int, 2> c = {x, w}, d = {y, w};
        edges[x].push_back(d);
        edges[y].push_back(c);
    }

    function<void(int, int, int, int, set<int>&)> dfs = [&](int cur, int par, int w, int d, set<int> &nums) {
        for (auto &e: edges[cur]) {
            if (e[0] == par || e[0] == d) continue;
            int w1 = w ^ e[1];
            nums.insert(w1);
            dfs(e[0], cur, w1, d, nums);
        }
    };

    bool check = false;
    set<int> nums1;
    nums1.insert(0);
    dfs(a, -1, 0, b, nums1);

    function<void(int, int, int)> dfs2 = [&](int cur, int par, int w) {
        for (auto &e: edges[cur]) {
            if (e[0] == par) continue;
            int w1 = w ^ e[1];
            if (nums1.count(w1)) {
                check = true;
                return;
            }
            dfs2(e[0], cur, w1);
        }
    };

    dfs2(b, -1, 0);
    cout << (check ? "YES" : "NO") << endl;
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