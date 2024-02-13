/**
 * Source: is.gd/PCfm9z
 * Date: 2024/2/13
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


void solve() {
    int n, k, num;
    cin >> n >> k;
    vector<vector<int>> a;
    vector<int> b(n), res(n);
    for (int i = 0; i < n; i++) {
        cin >> num;
        a.push_back({num, i});
    }
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(begin(a), end(a), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });
    sort(begin(b), end(b));
    for (int i = 0; i < n; i++) res[a[i][1]] = b[i];
    for (int i = 0; i < n; i++) cout << res[i] << " ";
    cout << endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    for (cin >> t; t--;) solve();
}