/**
 * Source: is.gd/sjGZdN
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

const int MX = 63;


void solve() {
    ll a, b, r, x = 0;
    cin >> a >> b >> r;
    bool found = false, is_a;
    for (ll i = MX - 1; i >= 0; i--) {
        if (((a >> i) & 1) != ((b >> i) & 1)) {
            if (!found) {
                is_a = ((a >> i) & 1) != 0;
                found = true;
            } else if (is_a && ((a >> i) & 1) != 0 && x + (1ll << i) <= r) {
                x += 1ll << i;
            } else if (!is_a && ((b >> i) & 1) != 0 && x + (1ll << i) <= r) {
                x += 1ll << i;
            }
        }
    }
    ll res = abs((a ^ x) - (b ^ x));
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    for (cin>>t; t--;) {
        solve();
    }
}