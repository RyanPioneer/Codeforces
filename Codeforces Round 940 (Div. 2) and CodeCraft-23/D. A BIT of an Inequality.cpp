/**
 * Source: t.ly/uI8IY
 * Date: 2024/5/4
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


const int MX = 1e5+10;

void solve() {
    int n;
    cin >> n;
    int arr[MX], sum[MX], hb[MX];
    ll total[MX][31][2];
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum[i] = sum[i - 1] ^ arr[i];
        for (int j = 0; j < 31; j++) {
            total[i][j][1] = total[i - 1][j][1] + (1 & (sum[i] >> j));
            total[i][j][0] = total[i - 1][j][0] + (!(1 & (sum[i] >> j)));
            if (1 & (arr[i] >> j)) hb[i] = j;
        }
    }

    ll res = 0;
    for (int i = 1; i <= n; i++) {
        res += (total[i - 1][hb[i]][0] + 1) * (total[n][hb[i]][0] - total[i - 1][hb[i]][0]);
        res += (total[i - 1][hb[i]][1]) * (total[n][hb[i]][1] - total[i - 1][hb[i]][1]);
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