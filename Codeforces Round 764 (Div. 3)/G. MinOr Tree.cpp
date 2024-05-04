/**
 * Source: t.ly/eODNJ
 * Date: 2024/5/4
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


const int MX = 2e5+2;

void solve() {
    ll n, m;
    ll res = 0;
    cin >> n >> m;
    ll edges[MX][4];
    for (int i = 0; i < m; i++) {
        edges[i][0] = 1;
        cin >> edges[i][1] >> edges[i][2] >> edges[i][3];
    }

    ll group[MX];

    function<ll(ll)> findGroup = [&](ll id) {
        if (group[id] != id) {
            group[id] = findGroup(group[id]);
        }
        return group[id];
    };

    function<void(ll, ll)> merge = [&](ll a, ll b) {
        ll groupA = findGroup(a);
        ll groupB = findGroup(b);
        if (groupA != groupB) {
            group[max(groupA, groupB)] = min(groupA, groupB);
        }
    };

    for (int i = 31; i >= 0; i--) {
        for (int j = 1; j <= n; j++) group[j] = j;
        for (int j = 0; j < m; j++) {
            if (!edges[j][0]) continue;
            if ((edges[j][3] >> i) & 1) continue;
            merge(edges[j][1], edges[j][2]);
        }
        bool check = true;
        for (int j = 2; j <= n; j++) {
            if (findGroup(j) != findGroup(j - 1)) {
                check = false;
                break;
            }
        }
        if (check) {
            for (int j = 0; j < m; j++) {
                if ((edges[j][3] >> i) & 1) {
                    edges[j][0] = 0;
                }
            }
        } else {
            res += (1ll << i);
        }
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