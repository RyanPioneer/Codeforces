/**
 * Source: is.gd/xTuFC7
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
    int n, k, res = 0;
    cin >> n >> k;
    vector<int> nums(n);
    for (auto &i: nums) cin >> i;
    vector<int> comp = {0};
    for (int i = 1; i < n; i++) {
        comp.push_back(comp.back());
        if (nums[i] * 2 > nums[i - 1]) comp.back()++;
    }
    for (int i = k; i < n; i++) {
        if (comp[i] - comp[i - k] == k) res++;
    }
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