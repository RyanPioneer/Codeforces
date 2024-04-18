/**
 * Source: is.gd/lZyx4T
 * Date: 2024/4/18
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
    ll r, g, b;
    cin >> r >> g >> b;
    if (b >= r && b >= g) {
        swap(r, b);
    } else if (g >= r && g >= b) {
        swap(r, g);
    }
    if (r > (g + b) * 2) cout << (g + b) << endl;
    else cout << (r + g + b) / 3 << endl;
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