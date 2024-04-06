/**
 * Source: is.gd/cDtLNj
 * Date: 2024/3/2
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
    int first = nums[0];
    nums.erase(begin(nums));
    sort(nums.begin(), nums.end());
    for (auto &i: nums) {
        if (i > first) first = (i + first) / 2 + (i + first) % 2;
    }
    cout << first << endl;
}

int main() {
    int t;
    for (cin >> t; t--;) {
        solve();
    }
}