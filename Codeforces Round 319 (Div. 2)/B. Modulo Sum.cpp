/**
 * Source: is.gd/EkOvpM
 * Date: 2024/4/18
 * Time:
 * Space:
 * Skill:   把多于n个的物体放到n个抽屉里，则至少有一个抽屉里的东西不少于两件。
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

const int MX = 1e3+10;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &i: a) {
        cin >> i;
        i %= m;
    }
    if (n > m) {
        cout << "YES" << endl;
        return;
    }
    bool dp[MX][MX];
    fill(dp[0], dp[MX - 1] + MX, false);
    for (int i = 1; i <= n; i++) {
        dp[i][a[i - 1]] = true;
        for (int j = 0; j < m; j++) {
            dp[i][(a[i - 1] + j) % m] |= dp[i - 1][(a[i - 1] + j) % m];
            dp[i][(a[i - 1] + j) % m] |= dp[i - 1][j];
        }
    }
    cout << (dp[n][0] ? "YES" : "NO") << endl;
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