/**
 * Source: is.gd/W4jMQI
 * Date: 2024/2/11
 * Skill: bitset
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
const int N = 5002;
using bs = bitset<N>;


void solve() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> models(n, vector<int>(m + 1));
    for (int i = 0; i < n; i++) cin >> models[i][m];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> models[j][i];
        }
    }
    vector<bs> lower(n);
    for (int i = 0; i < n; i++) lower[i].set();
    sort(begin(models), end(models));
    vector<int> idxs(n);
    iota(begin(idxs), end(idxs), 0);
    for (int i = 0; i < m; i++) {
        sort(begin(idxs), end(idxs), [&](int a, int b) {
            return models[a][i] < models[b][i];
        });
        bs cur = 0;
        int pos = 0;
        for (int j = 0; j < n; j++) {
            while (models[idxs[j]][i] > models[idxs[pos]][i]) cur.set(idxs[pos++]);
            lower[idxs[j]] &= cur;
        }
    }
    vector<ll> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = models[i][m];
        for (int j = 0; j < n; j++) {
            if (lower[i][j]) dp[i] = max(dp[i], dp[j] + models[i][m]);
        }
    }
    cout << *max_element(begin(dp), end(dp)) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}