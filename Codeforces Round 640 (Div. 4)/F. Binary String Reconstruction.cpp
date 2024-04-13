/**
 * Source: is.gd/OTnexM
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


void solve() {
    int n0, n1, n2;
    cin >> n0 >> n1 >> n2;
    string res;
    for (int i = 0; i < n0; i++) {
        if (res.empty()) res += "00";
        else res.push_back('0');
    }
    for (int i = 0; i < n1; i++) {
        if (res.empty()) res += "01";
        else if (res.back() == '1') res.push_back('0');
        else res.push_back('1');
    }
    for (int i = 0; i < n2; i++) {
        if (res.empty()) res += "11";
        else if (res.back() == '1') res.push_back('1');
        else {
            res.pop_back();
            res += "10";
        }
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    for (cin >> t; t--;) {
        solve();
    }
}