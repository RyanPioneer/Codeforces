/**
 * Source: is.gd/3OU1N8
 * Date: 2024/4/3
 * Time: TLE
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
    int n, res = 0, left = 1, right = 1, num;
    cin >> n;
    vector<int> nums(n);
    for (auto &i: nums) cin >> i;
    unordered_map<int, int> num2res, num2idx, num2left;
    for (int i = 0; i < n; i++) {
        int a = nums[i];
        if (num2res.find(nums[i]) != num2res.end() && 1 + num2res[a] - (i - num2idx[a] - 1) > 1) {
            num2res[a] = 1 + num2res[a] - (i - num2idx[a] - 1);
            num2idx[a] = i;
        } else {
            num2res[a] = 1;
            num2idx[a] = i;
            num2left[a] = i;
        }
        if (num2res[a] > res) {
            res = num2res[a];
            left = num2left[a] + 1;
            right = i + 1;
            num = a;
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