/**
 * Source: ibit.ly/319tR
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

const int MX = 3e5+10;

void solve() {
    int n, res = 0;
    cin >> n;
    vector<vector<int>> graph(n + 1);
    For(i, 1, n-1) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    function<int(int, int)> dfs = [&](int cur, int par) {
        int mx = -1, mi = -1;
        for (auto i: graph[cur]) {
            if (i == par) continue;
            int num = dfs(i, cur);
            if (num > mx) {
                mi = mx;
                mx = num;
            } else if (num > mi) {
                mi = num;
            }
        }
        if (mx == -1) return 1;
        else if (mi == -1) return 2;
        else return mi + 2;
    };

    int num = dfs(1, -1);
    cout << n - num << endl;
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