/**
 * Source: is.gd/3OU1N8
 * Date: 2024/4/3
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
    int n, res = 0, left = 1, right = 1, num;
    cin >> n;
    vector<int> nums(n);
    for (auto &i: nums) cin >> i;
    unordered_map<int, int> num2res, num2idx, num2left;
    for (int i = 0; i < n; i++) {
        if (num2res.find(nums[i]) != num2res.end() && 1 + num2res[nums[i]] - (i - num2idx[nums[i]] - 1) > 1) {
            num2res[nums[i]] = 1 + num2res[nums[i]] - (i - num2idx[nums[i]] - 1);
            num2idx[nums[i]] = i;
        } else {
            num2res[nums[i]] = 1;
            num2idx[nums[i]] = i;
            num2left[nums[i]] = i;
        }
        if (num2res[nums[i]] > res) {
            res = num2res[nums[i]];
            left = num2left[nums[i]] + 1;
            right = i + 1;
            num = nums[i];
        }
    }
    cout << num << " " << left << " " << right << endl;
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