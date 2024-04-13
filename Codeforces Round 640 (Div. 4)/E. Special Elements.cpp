/**
 * Source: is.gd/9y6uQu
 * Date: 2024/4/13
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

const int MX = 63;


void solve() {
    int n, total = 0, res = 0;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    mp[0] = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
        mp[total] = i;
    }
    for (auto &i: a) {
        total = 0;
        for (int j = 0; j < n; j++) {
            total += a[j];
            if (mp.find(total - i) != mp.end() && mp[total - i] < j - 1) {
                res++;
                break;
            }
        }
    }
    cout << res << endl;
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