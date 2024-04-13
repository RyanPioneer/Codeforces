/**
 * Source: is.gd/TCqmXx
 * Date: 2024/4/6
 * Time:
 * Space:
 * Skill: 由于减半操作将向下舍入到每个切半的最接近的整数，硬币最多10^9个，
 *        所以大概经历30次会变为0，此时后面的箱子都不需要再计算了。
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
    ll total = 0, res = 0;
    vector<int> nums(n, 0);
    for (auto &i: nums) {
        cin >> i;
    }
    for (int i = 0; i < n; i++) {
        ll num = total;
        for (int j = i, shift = 2; j < min(n, i + 31); j++, shift *= 2) {
            num += nums[j] / shift;
        }
        res = max(res, num);
        total += nums[i] - k;
    }
    res = max(res, total);
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