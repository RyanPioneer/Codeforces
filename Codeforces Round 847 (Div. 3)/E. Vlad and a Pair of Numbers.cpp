/**
 * Source: is.gd/yJSrnx
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


const int MX = 30;

void solve() {
    ll x, a = 0, b = 0;
    cin >> x;
    for (int i = MX; i > 0; i--) {
        if (((x >> i) & 1) != 0) {
            if (a == 0) a += (1 << i);
            else b += (1 << i);
        }
    }
    for (int i = MX; i > 0; i--) {
        if (((x >> i) & 1) == 0 && a + b + (1ll << (i + 1)) <= 2 * x) {
            a += (1ll << i);
            b += (1ll << i);
        }
    }
    if (a + b != 2 * x) {
        a++;
        b++;
    }
    if (x % 2 == 1 || a == 0 || b == 0 || a + b != 2 * x) {
        cout << -1 << endl;
    } else {
        cout << a << " " << b << endl;
    }
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