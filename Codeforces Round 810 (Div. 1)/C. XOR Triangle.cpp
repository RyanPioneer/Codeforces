/**
 * Source: ibit.ly/3OK5D
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
#include<bits/stdc++.h>

using namespace std;
#define SZ(X) ((int)(X).size())
#define ll long long
typedef pair<int, int> PII;
typedef pair<ll, int> PLI;

const ll MOD = 998244353, MX = 2e5+10;

ll dp[MX][2][2][2][2][2][2];

void solve() {
    string s;
    cin >> s;
    ll n = s.length();
    memset(dp, -1, sizeof(dp));

    function<ll(ll, bool, bool, bool, bool, bool, bool)> dfs = [&](ll pos, bool a, bool b, bool c, bool x, bool y, bool z) {
        if (pos == n) {
            if (x && y && z) return 1ll;
            else return 0ll;
        }
        if (dp[pos][a][b][c][x][y][z] != -1) {
            return dp[pos][a][b][c][x][y][z];
        }
        ll res = 0;
        for (int i = 0; i <= 1; i++) {
            if (a && i > s[pos] - '0') {
                continue;
            }
            for (int j = 0; j <= 1; j++) {
                if (b && j > s[pos] - '0') {
                    continue;
                }
                for (int k = 0; k <= 1; k++) {
                    if (c && k > s[pos] - '0') {
                        continue;
                    }
                    res = (res + dfs(pos + 1, a & (s[pos] - '0' == i), b & (s[pos] - '0' == j), c & (s[pos] - '0' == k), x | ((i ^ j) & (j ^ k)), y | ((i ^ k) & (j ^ k)), z | ((i ^ k) & (j ^ i)))) % MOD;
                }
            }
        }
        return dp[pos][a][b][c][x][y][z] = res;
    };

    cout << dfs(0, true, true, true, false, false, false) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    for (t = 1; t; t--) {
        solve();
    }
}