/**
 * Source: t.ly/_dLNN
 * Date: 2024/5/5
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


using namespace std;
#define SZ(X) ((int)(X).size())
#define ll long long
typedef pair<int, int> PII;
typedef pair<ll, int> PLI;


const int MX = 2e5+2;

void solve() {
    ll n, k, x, res = 0;
    cin >> n >> k >> x;
    ll dp[MX][21], arr[MX];

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (ll i = 1; i <= n; i++) {
        for (int j = 0; j <= min(k, i); j++) {
            ll x1 = arr[i] + x, x2 = arr[i] - x;
            if ((j < i) && j) dp[i][j] = max(max(0ll, dp[i - 1][j - 1]) + x1, max(0ll, dp[i - 1][j]) + x2);
            else if (j < i) dp[i][j] = max(dp[i - 1][j], 0ll) + x2;
            else if (j) dp[i][j] = max(dp[i - 1][j - 1], 0ll) + x1;
            if (n - i >= k - j) res = max(res, dp[i][j]);
        }
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    for (cin >> t; t; t--) {
        solve();
    }
}