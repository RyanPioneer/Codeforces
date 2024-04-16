/**
 * Source: is.gd/2Z4h2b
 * Date: 2024/4/16
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

const int MX = 512;

void solve() {
    int n, res = 0;
    cin >> n;
    int dp[MX];
    fill(dp, dp + MX, MX);
    dp[0] = -1;
    for (int i = 0, j; i < n; i++) {
        cin >> j;
        for (int k = 1; k < MX; k++) {
            if (dp[k ^ j] < j) {
                dp[k] = min(dp[k], j);
            }
        }
    }
    for (int i = 0; i < MX; i++) {
        if (dp[i] != MX) res++;
    }
    cout << res << endl;
    for (int i = 0; i < MX; i++) {
        if (dp[i] != MX) cout << i << " ";
    }
    cout << endl;
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