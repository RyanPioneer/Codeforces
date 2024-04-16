/**
 * Source: is.gd/khWimt
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
typedef pair<int,int> PII;

const int MX = 2e5+10;

void solve() {
    ll res = 0;
    int boys[MX] = {0}, girls[MX] = {0};
    int a, b, k;
    cin >> a >> b >> k;
    vector<PII> couples(k);
    for (int i = 0; i < k; i++) {
        cin >> couples[i].first;
        boys[couples[i].first]++;
    }
    for (int i = 0; i < k; i++) {
        cin >> couples[i].second;
        girls[couples[i].second]++;
    }
    for (int i = 0; i < k; i++) {
        res += k - boys[couples[i].first] - girls[couples[i].second] + 1;
    }
    cout << res / 2 << endl;
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