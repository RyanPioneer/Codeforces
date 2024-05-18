/**
 * Source: t.ly/2HbIh
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

const int MX = 1e5+10;


void solve() {
    int n, a;
    cin >> n;
    unordered_map<int, vector<int>> cnt;
    For(i,0,n-1) {
        cin>>a;
        cnt[a].push_back(i);
    }
    ll res = 0;
    for (auto &i: cnt) {
        vector<int> &v = i.second;
        if (v.size() == 1) continue;
        ll right = 0;
        for (auto &j: v) {
            right += n - j;
        }
        for (auto &j: v) {
            right -= n - j;
            res += right * (j + 1);
        }
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