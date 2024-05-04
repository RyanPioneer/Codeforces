/**
 * Source: t.ly/Xdqhy
 * Date: 2024/5/2
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
typedef pair<int, int> PII;
typedef pair<ll, int> PLI;


const int MX = 1e3+10;

void solve() {
    int n;
    cin >> n;
    vector<ll> nums(n);

    for (auto &i : nums) cin >> i;

    function<ll()> helper = [&]() {
        ll num = 0;
        priority_queue<ll> q;
        for (auto &i: nums) {
            if (!q.empty() && q.top() > i) {
                num += q.top() - i;
                q.pop();
                q.push(i);
            }
            q.push(i);
        }
        return num;
    };

    ll res = helper();
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    for (t = 1; t--;) {
        solve();
    }
}