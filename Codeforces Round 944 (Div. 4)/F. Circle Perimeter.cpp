/**
 * Source: ibit.ly/nyj1F
 * Date: 2024/5/16
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
#define SZ(X) ((int)(X).size())
#define ll long long
typedef pair<int, int> PII;
typedef pair<ll, int> PLI;

const int MX = 2e5+2;


void solve() {
    ll r;
    cin >> r;
    ll num = 0;
    for (ll x = 1; x <= r; x++) {
        ll left = 0, right = r;
        while (left < right) {
            ll mid = (left + right + 1) / 2;
            if (mid * mid + x * x < (r + 1) * (r + 1)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        ll left1 = 0, right1 = r;
        while (left1 < right1) {
            ll mid = (left1 + right1) / 2;
            if (mid * mid + x * x >= r * r) {
                right1 = mid;
            } else {
                left1 = mid + 1;
            }
        }
        num += (left - left1 + 1) * 4;
    }
    cout << num << endl;
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