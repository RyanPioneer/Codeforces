/**
 * Source: is.gd/oR1gW0
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


const int MX = 2e5+10;
ll nums[MX];


void solve() {
    int n;
    cin >> n;
    bool found = false;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        if (i % 2) nums[i] *= -1;
    }
    set<ll> visited;
    visited.insert(0);
    for (int i = 1; i <= n; i++) {
        nums[i] += nums[i - 1];
        if (visited.count(nums[i])) {
            found = true;
            break;
        }
        visited.insert(nums[i]);
    }
    cout << (found ? "yes" : "no") << endl;
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