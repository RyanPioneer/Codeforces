/**
 * Source: is.gd/S229aM
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


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i: a) cin >> i;
    int total = accumulate(begin(a), end(a), 0);
    for (auto &i: a) {
        if (i * 2 > total) {
            cout << "T" << endl;
            return;
        }
    }
    cout << (total % 2 ? "T" : "HL") << endl;
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