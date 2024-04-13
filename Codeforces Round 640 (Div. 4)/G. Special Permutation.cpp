/**
 * Source: is.gd/96gqHu
 * Date: 2024/4/13
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


void solve() {
    int n;
    cin >> n;
    if (n < 4) {
        cout << -1 << endl;
        return;
    }
    vector<int> res, mid = {3, 1, 4, 2};
    for (int i = n + n % 2 - 1; i > 3; i -= 2) res.push_back(i);
    res.insert(end(res), begin(mid), end(mid));
    for (int i = 6; i <= n; i += 2) res.push_back(i);
    for (auto &i: res) cout << i << " ";
    cout << endl;
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