/**
 * Source: is.gd/1bMc3o
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

const int MX = 32;


void solve() {
    int n, k, cnt[MX] = {0}, res = 0;
    cin >> n >> k;
    for (int i = 0, j; i < n; i++) {
        cin >> j;
        for (int l = 0; l < MX; l++, j >>= 1) {
            if ((j & 1) != 0) cnt[l]++;
        }
    }
    for (int i = MX - 1; i >= 0; i--) {
        if (cnt[i] + k <= n) {
            res += 1 << i;
            k -= n - cnt[i];
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