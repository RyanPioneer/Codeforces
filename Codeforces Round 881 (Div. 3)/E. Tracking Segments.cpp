/**
 * Source: t.ly/-kf5z
 * Date: 2024/2/9
 * Skill: binary search + prefix sum
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
const int MX = 1e5 + 2;


int intervals[MX][2];

void solve() {
    int n, m, q, x, changes[MX] = {0}, presum[MX];
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> intervals[i][0];
        cin >> intervals[i][1];
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> x;
        changes[x] = i;
    }

    function<bool(int time)> check = [&](int time) {
        fill (presum, presum + MX, 0);
        for (int i = 1; i <= n; i++) {
            presum[i] = presum[i - 1] + (0 < changes[i] && changes[i] <= time);
        }
        for (int i = 0; i < m; i++) {
            if ((presum[intervals[i][1]] - presum[intervals[i][0] - 1]) * 2 > intervals[i][1] - intervals[i][0] + 1) {
                return true;
            }
        }
        return false;
    };

    int left = 1, right = q;
    while (left < right) {
        int mid = (left + right) / 2;
        if (check(mid)) right = mid;
        else left = mid + 1;
    }
    cout << (check(left) ? left : -1) << endl;
}

int main() {
    int t;
    for (cin >> t; t--;) {
        solve();
    }
}