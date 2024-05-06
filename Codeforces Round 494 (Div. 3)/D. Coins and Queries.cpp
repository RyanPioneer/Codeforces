/**
 * Source: t.ly/MEhpn
 * Date: 2024/5/6
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
    ll n, q;
    cin >> n >> q;
    ll cnt[32] = {0}, cnt2[32];
    for (ll i = 0, num; i < n; i++) {
        cin >> num;
        for (int j = 0; j < 32; j++) {
            if ((num >> j) & 1) {
                cnt[j]++;
                break;
            }
        }
    }
    for (ll i = 0, num; i < q; i++) {
        cin >> num;
        for (int j = 0; j < 32; j++) {
            cnt2[j] = cnt[j];
        }
        bool check = true;
        int res = 0;
        for (int j = 0; j < 32; j++) {
            if ((num >> j) & 1) {
                ll k = 1 << j;
                int pos = j;
                while (pos >= 0 && k) {
                    if (cnt2[pos] * (1 << pos) >= k && k >= (1 << pos)) {
                        int l = k / (1 << pos);
                        res += l;
                        cnt2[pos] -= l;
                        k = 0;
                    } else if (k >= (1 << pos)) {
                        res += cnt2[pos];
                        k -= (1 << pos) * cnt2[pos];
                        cnt2[pos] = 0;
                    }
                    pos--;
                }
                if (k) {
                    check = false;
                    break;
                }
            }
        }
        if (check) cout << res << endl;
        else cout << -1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    for (t = 1; t; t--) {
        solve();
    }
}