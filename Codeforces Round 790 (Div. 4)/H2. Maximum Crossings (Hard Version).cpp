/**
 * Source: is.gd/V6zCej
 * Date: 2024/4/15
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

const int MX = 2e5+10;

class BIT {
public:
    int n;
    vector<ll> arr;

    BIT(int n) : n(n){
        arr = vector<ll>(n, 0);
    }

    void add(int idx) {
        while (idx < n) {
            arr[idx]++;
            idx += idx & -idx;
        }
    }

    int queryPreSum(int idx) {
        ll res = 0;
        while (idx > 0) {
            res += arr[idx];
            idx -= idx & -idx;
        }
        return res;
    }
};

void solve() {
    int n;
    ll res = 0;
    cin >> n;
    BIT *tree = new BIT(n + 1);
    for (int i = 0, j; i < n; i++) {
        cin >> j;
        res += tree->queryPreSum(n - j + 1);
        tree->add(n - j + 1);
    }
    cout << res << endl;
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