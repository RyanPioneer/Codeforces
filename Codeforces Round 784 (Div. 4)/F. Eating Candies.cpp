/**
 * Source: is.gd/3zsPrB
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
    int n, res = 0;
    cin >> n;
    vector<int> w(n);
    map<int, int> mp;
    for (int i = 0, total = 0; i < n; i++) {
        cin >> w[i];
        total += w[i];
        mp[total] = i;
    }
    for (int i = n - 1, total = 0; i >= 0; i--) {
        total += w[i];
        if (mp.find(total) != mp.end() && mp[total] < i) {
            res = mp[total] + 1 + n - i;
        }
    }
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