/**
 * Source: is.gd/XB0wLd
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


void solve() {
    int n, k;
    cin >> n >> k;
    if ((n - 2 * (k - 1)) > 0 && (n - 2 * (k - 1)) % 2 == 0) {
        cout << "YES" << endl;
        for (int i = 1; i < k; i++) cout << 2 << " ";
        cout << (n - 2 * (k - 1)) << endl;
    } else if ((n - (k - 1)) > 0 && (n - (k - 1)) % 2 == 1) {
        cout << "YES" << endl;
        for (int i = 1; i < k; i++) cout << 1 << " ";
        cout << (n - (k - 1)) << endl;
    } else {
        cout << "NO" << endl;
    }
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