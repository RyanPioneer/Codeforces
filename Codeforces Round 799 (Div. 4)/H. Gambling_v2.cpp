/**
 * Source: is.gd/3OU1N8
 * Date: 2024/4/5
 * Time: TLE
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


void solve() {
    int n, res = 1, left, right, num;
    cin >> n;
    map<int, vector<int>> M;
    for (int i = 1; i <= n; ++i) {
        cin >> num;
        M[num].push_back(i);
    }
    left = M[num].front(), right = M[num].front();
    for (map<int, vector<int>>:: iterator it = M.begin(); it != M.end(); ++it) {
        vector<int> &pos = it->second;
        int sz = pos.size();
        vector<int> dp(sz, 1), l(sz);
        l[0] = pos[0];
        for (int i = 1; i < sz; i++) {
            if (1 + dp[i - 1] - (pos[i] - pos[i - 1] - 1) > 1) {
                dp[i] = 1 + dp[i - 1] - (pos[i] - pos[i - 1] - 1);
                l[i] = l[i - 1];
            } else {
                l[i] = pos[i];
            }
            if (dp[i] > res) {
                res = dp[i];
                left = l[i];
                right = pos[i];
                num = it->first;
            }
        }
    }
    cout << num << " " << left << " " << right << endl;
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