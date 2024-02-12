/**
 * Source: is.gd/UYqFUa
 * Date: 2024/2/12
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
    int ans = 0, zero_cnt = 0;
    for (int i = n / 2; i >= 1; i >>= 1) {
        vector<int> t(n);
        for (int j = 0; j < n; j++) t[j] = nums[j] ^ nums[(j + i) % n];
        zero_cnt = ranges::count(t, 0);
        if (zero_cnt != n) {
            ans += i;
            nums = t;
        }
    }
    cout << ans + (ranges::count(nums, 0) != n) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}