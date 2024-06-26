/**
 * Source: is.gd/GCle9W
 * Date: 2024/4/17
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

const int MX = 20;

void solve() {
    int n;
    cin >> n;
    ll cnt[MX] = {0}, res = 0;
    for (int i = 0, j; i < n; i++) {
        cin >> j;
        for (int k = 0; k < MX; k++, j >>= 1) {
            if ((j & 1)) {
                cnt[k]++;
            }
        }
    }
    for (ll i = 0, tmp = 0; i < n; i++, tmp = 0) {
        for (int j = 0; j < MX; j++) {
            if (cnt[j]) {
                tmp += 1 << j;
                cnt[j]--;
            }
        }
        res += tmp * tmp;
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    for (t = 1; t--;) {
        solve();
    }
}