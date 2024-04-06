/**
 * Source: is.gd/2NmhNQ
 * Date: 2024/4/6
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
    int n, s;
    cin >> n >> s;
    vector<int> nums(n);
    for (auto &i: nums) cin >> i;
    int total = accumulate(begin(nums), end(nums), 0);
    if (total < s) {
        cout << -1 << endl;
        return;
    }
    int res = 0, right = 0, num = 0;
    for (int left = 0; left < n; left++) {
        while (right < n && num + nums[right] <= s) {
            num += nums[right++];
        }
        if (num < s) break;
        res = max(res, right - left);
        num -= nums[left];
    }
    cout << n - res << endl;
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