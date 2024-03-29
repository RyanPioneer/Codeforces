/**
 * Source: is.gd/zN3Jxg
 * Date: 2024/2/14
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

using namespace std;

#define SZ(X) ((int)(X).size())
#define ll long long
typedef pair<int, int> PII;

const int MX = 2e5+2;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj_list(n);
    unordered_map<ll, int> edge2idx;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
        ll hash = (ll) a * MX + b;
        edge2idx[hash] = i;
    }

    vector<int> visited(n, 0);
    function<void(int, int)> dfs = [&](int cur, int par) {

    };
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    for (cin >> t; t--;) solve();
}