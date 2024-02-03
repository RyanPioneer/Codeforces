/**
 * Source: jpeg.ly/tTiUQ
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


const int MOD = 998244353;


void solve() {
    int n;
    cin >> n;
    vector<int> nums(n), presum(n + 1), f(n);
    stack<int> st;
    for (auto &i: nums) cin >> i;
    ll res = 0;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[i] < nums[st.top()]) {
            res -= f[st.top()];
            st.pop();
        }
        int left = st.empty() ? 0 : st.top() + 1;
        f[i] = (res + presum[i] - presum[left] + st.empty()) % MOD;
        presum[i + 1] = (presum[i] + f[i]) % MOD;
        res = (res + f[i]) % MOD;
        st.push(i);
    }
    cout << (res + MOD) % MOD << endl;
}

int main() {
    int t;
    for (cin >> t; t--;) {
        solve();
    }
}