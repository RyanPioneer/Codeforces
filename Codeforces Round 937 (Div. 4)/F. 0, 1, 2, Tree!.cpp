/**
 * Source: ibit.ly/pCYB4
 * Date: 2024/5/17
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


void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a * 2 + b != a + b - 1 + c) {
        cout << -1 << endl;
    } else {
        int log = a ? 32 - __builtin_clz(a) : 0;
        b -= min(b, (1 << log) - c);
        cout << log + (b + c - 1) / c << endl;
    }
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