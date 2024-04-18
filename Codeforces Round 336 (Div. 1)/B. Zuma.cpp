/**
 * Source: is.gd/rBo5wp
 * Date: 2024/4/18
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

const int MX = 510;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i: a) cin >> i;
    int dp[MX][MX];
    fill(dp[0], dp[MX - 1] + MX, MX);
    for (int i = 0; i < n; i++) dp[i][i] = 1;
    for (int i = 0; i < n - 1; i++) dp[i][i + 1] = a[i] == a[i + 1] ? 1 : 2;
    for (int len = 3; len <= MX; len++) {
        for (int left = 0; left + len <= n; left++) {
            int right = left + len - 1;
            if (a[left] == a[right]) {
                dp[left][right] = dp[left + 1][right - 1];
            }
            for (int mid = left; mid < right; mid++) {
                dp[left][right] = min(dp[left][right], dp[left][mid] + dp[mid + 1][right]);
            }
        }
    }
    cout << dp[0][n - 1] << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    for (t = 1; t--;) {
        solve();
    }
}