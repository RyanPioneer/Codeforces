/**
 * Source: t.ly/-rTdH
 * Date: 2024/5/18
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
#define ll long long
#define SZ(X) ((int)(X).size())
#define For(i, a, b) for (int i = (a); i <= (b); i++)
typedef pair<int, int> PII;
typedef pair<ll, int> PLI;


void solve() {
    ll res = 0;
    int n, a;
    map<int, ll> mp;
    cin>>n;
    For(i,1,n) {
        cin>>a;
        mp[a]++;
    }
    for (auto &i: mp) {
        For(j,2,1000) {
            if (!(i.first % (j * j))) {
                res += i.second * mp[i.first/j] * mp[i.first/j/j];
            }
        }
        res += i.second * (i.second - 1) * (i.second - 2);
    }
    cout << res << endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    for (cin>>t; t; t--) {
        solve();
    }
}