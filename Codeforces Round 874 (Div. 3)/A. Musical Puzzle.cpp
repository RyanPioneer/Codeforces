/**
 * Source: is.gd/0XDhpz
 * Date: 2024/2/13
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

const int carry = 7;

void solve() {
    int n;
    ll res = 0;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 1; i < n; ++i) {
        int hash = (s[i] - 'a') * carry + s[i - 1] - 'a';
        res |= 1ll<<hash;
    }
    cout << __builtin_popcountll(res) << endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    for (cin >> t; t--;) solve();
}