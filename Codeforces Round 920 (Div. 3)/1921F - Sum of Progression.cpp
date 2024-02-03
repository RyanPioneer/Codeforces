/**
 * Source: jpeg.ly/54wK_
 * Date: 2024/1/30
 * Skill: Math
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


const int MX_N = 100000, D = 300;
ll pre[D][MX_N + D], sum[D][MX_N + D];

void solve() {
    int n, q, s, d, k, r;
    cin >> n >> q;
    vector<ll> nums(n);
    for (auto &i: nums) cin >> i;

    for (d = 1; d < D; d++) {
        for (int i = 0; i < n; i++) {
            pre[d][i + d] = pre[d][i] + nums[i];
            sum[d][i + d] = sum[d][i] + (i / d + 1) * nums[i];
        }
    }

    while (q--) {
        cin >> s >> d >> k;
        s--;
        r = s + d * k;
        if (d < D) {
            cout << sum[d][r] - sum[d][s] - (pre[d][r] - pre[d][s]) * (s / d) << " ";
        } else {
            ll res = 0;
            for (int i = 0; i < k; i++) res += nums[s + i * d] * (i + 1);
            cout << res << " ";
        }
    }
    cout << endl;
}

int main() {
    int t;
    for (cin >> t; t--;) {
        solve();
    }
}