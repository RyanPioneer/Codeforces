/**
 * Source: is.gd/W8OAjb
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
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto &i: nums) cin >> i;
    int res = 0;
    sort(begin(nums), end(nums));
    for (int left = 0, right = n - 1; left < right; left++, right--) {
        res += nums[right] - nums[left];
    }
    cout << res << endl;
}

int main() {
    int t;
    for (cin >> t; t--;) {
        solve();
    }
}