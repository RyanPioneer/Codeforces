/**
 * Source: is.gd/wxQVts
 * Date: 2024/4/17
 * Time:
 * Space:
 * Skill: 注意數據範圍
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

const int MX = 18;

void solve() {
    string s;
    cin >> s;
    int len = s.length(), res = 0, zeroNum = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == '0') {
            zeroNum++;
        } else {
            for (int j = 0, num = 0; j < MX; j++) {
                num = num * 2 + (s[i + j] == '1');
                if (j + 1 + zeroNum >= num) res++;
                if (i + j == len - 1) break;
            }
            zeroNum = 0;
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