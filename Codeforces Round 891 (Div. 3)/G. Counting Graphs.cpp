/**
 * Source: t.ly/RfaPw
 * Date: 2024/5/5
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


using namespace std;
#define SZ(X) ((int)(X).size())
#define ll long long
typedef pair<int, int> PII;
typedef pair<ll, int> PLI;

const int MX = 2e5+2, MOD = 998244353;

struct edge {
    int n1, n2;
    ll w;
} e[MX];

bool cmp(const edge& a, const edge& b) {
    return a.w < b.w;
}

ll qpow(ll a, ll b) {
    if (b == 0) return 1;
    ll tmp = qpow(a, b / 2ll);
    if (b % 2) return tmp * tmp % MOD * a % MOD;
    else return tmp * tmp % MOD;
}

void solve() {
    ll n, s, res = 1;
    cin >> n >> s;
    for (int i = 1; i < n; i++) {
        cin >> e[i].n1 >> e[i].n2 >> e[i].w;
    }
    sort(e + 1, e + n, cmp);
    ll group[MX], sz[MX];
    for (int i = 1; i <= n; i++) {
        group[i] = i;
        sz[i] = 1;
    }

    function<ll(ll)> findGroup = [&](ll idx) {
        if (group[idx] != idx) {
            group[idx] = findGroup(group[idx]);
        }
        return group[idx];
    };

    function<void(ll, ll)> merge = [&](ll idx1, ll idx2) {
        ll g1 = findGroup(idx1), g2 = findGroup(idx2);
        if (g1 != g2) {
            sz[min(g1, g2)] += sz[max(g1, g2)];
            group[max(g1, g2)] = min(g1, g2);
        }
    };

    for (int i = 1; i < n; i++) {
        ll g1 = findGroup(e[i].n1), g2 = findGroup(e[i].n2), w = e[i].w;
        res = (res * qpow(s - w + 1, sz[g1] * sz[g2] - 1ll) % MOD);
        merge(e[i].n1, e[i].n2);
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    for (cin >> t; t; t--) {
        solve();
    }
}