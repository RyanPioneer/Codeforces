/**
 * Source: is.gd/tgdqBv
 * Date: 2024/4/6
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


class BIT {
public:
    vector<int> nums;
    int n;

    BIT(int n) {
        this->n = n;
        nums = vector<int>(n, 0);
    }

    void update(int idx) {
        while (idx < n) {
            nums[idx] += 1;
            idx += idx & -idx;
        }
    }

    int query_presum(int idx) {
        int presum = 0;
        while (idx > 0) {
            presum += nums[idx];
            idx -= idx & -idx;
        }
        return presum;
    }
};


void solve() {
    int n;
    ll res = 0;
    cin >> n;
    BIT *tree = new BIT(n + 1);
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        if (i > a) {
            res += tree->query_presum(a - 1);
            tree->update(i);
        }
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