/**
 * Source: is.gd/Ti0U2q
 * Date: 2024/2/3
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
    ll n, res = 0;
    cin >> n;
    while (n > 0) {
        res += n;
        n /= 2;
    }
    cout << res << endl;
}

int main() {
    int t;
    for (cin >> t; t--;) {
        solve();
    }
}