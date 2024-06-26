/**
 * Source: is.gd/lLHxYl
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
    ll n, k;
    cin >> n >> k;
    ll left = 0, right = LLONG_MAX;
    while (left < right) {
        ll mid = (left + right) / 2;
        ll rank = mid - mid / n;
        if (rank < k) left = mid + 1;
        else right = mid;
    }
    cout << left << endl;
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