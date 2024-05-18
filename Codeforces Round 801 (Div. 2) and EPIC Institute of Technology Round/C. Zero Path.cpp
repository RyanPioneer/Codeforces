/**
 * Source: ibit.ly/ZP-wc
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

const int MX = 1e3+10;

int arr[MX][MX], mi[MX][MX], mx[MX][MX];

void solve() {
    int n, m;
    cin >> n >> m;
    For(i, 1, n)
        For(j, 1, m)
            cin >> arr[i][j];
    if ((n + m - 1) & 1) {
        puts("NO");
        return;
    }
    int h = (n + m - 1) / 2;
    For(i, 1, n)
        For(j, 1, m)
            mx[i][j] = max(mx[i][j-1], mx[i-1][j]) + (arr[i][j] == 1 ? 1 : 0);

    For(i, 2, n) mi[i][0] = 0x3f3f3f3f;
    For(i, 2, m) mi[0][i] = 0x3f3f3f3f;
    For(i, 1, n)
        For(j, 1, m)
            mi[i][j] = min(mi[i][j-1], mi[i-1][j]) + (arr[i][j] == 1 ? 1 : 0);

    if (mi[n][m] <= h && h <= mx[n][m]) puts("YES");
    else puts("NO");
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