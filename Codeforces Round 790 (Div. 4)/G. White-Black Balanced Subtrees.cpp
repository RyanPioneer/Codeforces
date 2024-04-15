/**
 * Source: is.gd/8Tm4jd
 * Date: 2024/4/15
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

const int MX = 2e5+10;


void solve() {
    int n, j, res = 0;
    cin >> n;
    vector<vector<int>> children(n + 1);
    for (int i = 2; i <= n; i++) {
        cin >> j;
        children[j].push_back(i);
    }

    string s;
    cin >> s;

    function<int(int)> dfs = [&](int cur) {
        int num = s[cur - 1] == 'W' ? 1 : -1;
        for (auto &i: children[cur]) {
            num += dfs(i);
        }
        if (num == 0) res++;
        return num;
    };

    dfs(1);
    cout << res << endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    for (cin >> t; t--;) {
        solve();
    }
}