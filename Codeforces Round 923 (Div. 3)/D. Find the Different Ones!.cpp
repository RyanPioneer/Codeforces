/**
 * Source: is.gd/p5ZHge
 * Date: 2024/4/7
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
    int n, q, l, r;
    cin >> n;
    vector<int> nums(n + 1, 0), presum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        presum[i] = presum[i - 1];
        if (i > 1 && nums[i] != nums[i - 1]) presum[i]++;
    }
    cin >> q;
    while (q--) {
        cin >> l >> r;
        if (l == r || presum[r] == presum[l]) {
            cout << -1 << " " << -1 << endl;
            continue;
        }
        int rl = l + 1, rr = r;
        while (rl < rr) {
            int mid = (rl + rr) / 2;
            if (presum[mid] == presum[l]) rl = mid + 1;
            else rr = mid;
        }
        cout << rl - 1 << " " << rr << endl;
    }
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