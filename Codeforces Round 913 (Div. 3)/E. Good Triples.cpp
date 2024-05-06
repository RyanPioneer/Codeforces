/**
 * Source: t.ly/4iz28
 * Date: 2024/5/6
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
    ll n, res = 0;
    cin >> n;
    while (n) {
        int d = n % 10;
        n /= 10;
        res *= (d + 2) * (d + 1) / 2;
    }
    cout << res << endl;
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