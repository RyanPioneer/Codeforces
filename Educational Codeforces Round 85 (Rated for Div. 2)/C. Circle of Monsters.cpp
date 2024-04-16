/**
 * Source: is.gd/n0tVXb
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
    int n;
    cin >> n;
    vector<ll> health, damage;
    ll j, k;
    for (int i = 0; i < n; i++) {
        cin >> j >> k;
        health.push_back(j);
        damage.push_back(k);
    }
    ll total = 0, mi = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        if (damage[i] < health[(i + 1) % n]) {
            total += health[(i + 1) % n] - damage[i];
            mi = min(mi, damage[i]);
        } else {
            mi = min(mi, health[(i + 1) % n]);
        }
    }
    cout << total + mi << endl;
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