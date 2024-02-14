/**
 * Source: is.gd/BDiLPz
 * Date: 2024/2/14
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

const int MOD = 1e9+7;

ll inv(int x) {
    ll s = 1;
    for (; x > 1; x = MOD % x) s = s * (MOD - MOD / x) % MOD;
    return s;
}

void solve() {
    int n, m, num;
    cin >> n >> m;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> num;
        mp[num]++;
    }
    num = 0;
    ll mul = 1, res = 0;
    for (auto start = begin(mp), tail = begin(mp); start != end(mp); start = next(start)) {
        while (tail != end(mp) && tail->first - start->first < m) {
            mul = mul * tail->second % MOD;
            tail = next(tail);
            num++;
        }
        if (num >= m) res = (res + mul) % MOD;
        num--;
        mul = mul * inv(start->second) % MOD;
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    for (cin >> t; t--;) solve();
}