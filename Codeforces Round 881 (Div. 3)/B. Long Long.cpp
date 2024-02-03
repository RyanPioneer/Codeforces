/**
 * Source: is.gd/nFFo3E
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
    int n, res = 0;
    ll total = 0;
    cin >> n;
    vector<int> nums(n);
    for (auto &i: nums) cin >> i;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (nums[i] < 0 && !flag) {
            flag = true;
            res++;
        } else if (nums[i] > 0) {
            flag = false;
        }
        total += abs(nums[i]);
    }
    cout << total << " " << res << endl;
}

int main() {
    int t;
    for (cin >> t; t--;) {
        solve();
    }
}