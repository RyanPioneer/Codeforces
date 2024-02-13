/**
 * Source: is.gd/yRm3fK
 * Date: 2024/2/13
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
    int n;
    cin >> n;
    vector<int> nums(n), ord(n);
    for (auto &i: nums) cin >> i;
    iota(begin(ord), end(ord), 0);
    sort(begin(ord), end(ord), [&](const int a, const int b) {
        return nums[a] < nums[b];
    });
    set<int> visited, unvisited;
    ll res = 0;
    for (int i = 1; i < n; i++) res += (ll)i * (n - i);
    for (int i = 0; i < n; i++) unvisited.insert(i);
    visited.insert(-1), visited.insert(n);
    unvisited.insert(-1), unvisited.insert(n);
    for (auto &i: ord) {
        visited.insert(i);
        unvisited.erase(i);
        auto next_bigger_or_equal = unvisited.lower_bound(i);
        int left_cnt = i - *prev(next_bigger_or_equal);
        int right_cnt = 0;
        if (*next_bigger_or_equal < n) {
            right_cnt = *visited.lower_bound(*next_bigger_or_equal) - *next_bigger_or_equal;
        }
        res -= (ll)left_cnt * right_cnt;
    }
    cout << res << endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    for (cin >> t; t--;) solve();
}