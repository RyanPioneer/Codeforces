/**
 * Source: t.ly/YgeEb
 * Date: 2024/5/18
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
#define ll long long
#define SZ(X) ((int)(X).size())
#define For(i, a, b) for (int i = (a); i <= (b); i++)
typedef pair<int, int> PII;
typedef pair<ll, int> PLI;

const int MX = 5010;
ll arr1[MX], arr2[MX];
ll presum[MX] = {0}, dp[MX][MX];

void solve() {
    int n;
    cin>>n;
    For(i,1,n) cin>>arr1[i];
    For(i,1,n) cin>>arr2[i];
    For(i,1,n) presum[i] = presum[i - 1] + arr1[i] * arr2[i];
    ll res = presum[n];
    For(i,1,n) dp[i][i] = res;
    For(i,1,n-1) {
        dp[i][i+1] = dp[i][i] + arr1[i] * arr2[i+1] + arr1[i+1] * arr2[i] - arr1[i] * arr2[i] - arr1[i+1] * arr2[i+1];
        res = max(res, dp[i][i+1]);
    }
    For(len,3,n) {
        for (int start = 1; start + len <= n + 1; start++) {
            int tail = start + len - 1;
            dp[start][tail] = dp[start+1][tail-1] + arr1[start] * arr2[tail] + arr1[tail] * arr2[start] - arr1[start] * arr2[start] - arr1[tail] * arr2[tail];
            res = max(res, dp[start][tail]);
        }
    }
    cout << res << endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    for (t=1; t; t--) {
        solve();
    }
}