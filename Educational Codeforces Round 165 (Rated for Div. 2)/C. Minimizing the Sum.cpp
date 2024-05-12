/**
 * Source: ibit.ly/KXmvz
 * Date: 2024/5/12
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

const int MX = 3e5+2;
ll arr[MX], dp[MX][11];


void solve() {
    ll n, k, res = LLONG_MAX;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    fill(dp[0], dp[n] + 11, LLONG_MAX / 8);
    dp[0][0] = 0ll;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + arr[i - 1];
    }
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= min(i - 1, k); j++) {
            if (i - 1 > j) dp[i][j] = dp[i - 1][j] + arr[i - 1];
            for (ll l = 1; l <= j; l++) {
                dp[i][j] = min(dp[i][j], dp[i - l][j - l] + arr[i - l - 1] * l);
                dp[i][j] = min(dp[i][j], dp[i - l - 1][j - l] + arr[i - 1] * (l + 1));
            }
        }
    }
    for (int i = 0; i <= k; i++) {
        res = min(res, dp[n][i]);
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