/**
 * Source: is.gd/9AH8Cs
 * Date: 2024/2/24
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
    vector<int> nums(n), dp(n + 1, 0);
    for (auto &i: nums) cin >> i;
    dp[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        dp[i] = dp[i + 1] + 1;
        if (i + nums[i] < n) dp[i] = min(dp[i], dp[i + nums[i] + 1]);
    }
    cout << dp[0] << endl;
}

int main() {
    int t;
    for (cin >> t; t--;) {
        solve();
    }
}