/**
 * Source: is.gd/CaIOD2
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
    int n, total = 0;
    cin >> n;
    vector<int> nums;
    for (int i = 1; i <= n - 2; i++) {
        nums.push_back(i);
        total ^= i;
    }
    if (total == 0) {
        nums[0] = 0;
        total ^= 1;
    }
    nums.push_back(2 << 20);
    nums.push_back((2 << 20) ^ total);
    for (auto &i: nums) cout << i << " ";
    cout << endl;
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