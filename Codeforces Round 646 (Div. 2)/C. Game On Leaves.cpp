/**
 * Source: is.gd/zbM4QQ
 * Date: 2024/4/16
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
    int n, x, deg = 0;
    cin >> n >> x;
    for (int i = 1, j, k; i < n; i++) {
        cin >> j >> k;
        if (j == x || k == x) deg++;
    }
    if (deg == 1 || n % 2 == 0 || n == 1) cout << "Ayush" << endl;
    else cout << "Ashish" << endl;
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