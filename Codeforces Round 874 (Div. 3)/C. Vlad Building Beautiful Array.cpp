/**
 * Source: is.gd/FFd7gK
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


using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto &i: nums) cin >> i;
    bool odd_feasible = true, even_feasible = true;
    int odd = INT32_MAX;
    sort(begin(nums), end(nums));
    for (auto &i: nums) {
        if (i % 2) {
            if (i <= odd) even_feasible = false;
            odd = i;
        } else {
            if (i <= odd) odd_feasible = false;
        }
    }
    cout << (even_feasible || odd_feasible ? "YES" : "NO") << endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    for (cin >> t; t--;) solve();
}