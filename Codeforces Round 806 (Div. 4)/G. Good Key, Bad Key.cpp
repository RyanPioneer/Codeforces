/**
 * Source: is.gd/TCqmXx
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


const int MX = 1e9;

void solve() {
    int n, res = 0, time = 1;
    ll total = 0;
    vector<int> nums(n, 0);
    for (auto &i: nums) {
        cin >> i;
        total += i - i / 2;
    }
    for (auto &i: nums) {
        if (time > MX) break;
        if (total )
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