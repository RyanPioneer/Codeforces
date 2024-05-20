/**
 * Source: t.ly/_lJiH
 * Date: 2024/5/20
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
#include <cstdint>


using namespace std;
#define ll long long
#define SZ(X) ((int)(X).size())
#define For(i, a, b) for (int i = (a); i <= (b); i++)
#define Rep(i, a, b) for (int i = (a); i >= (b); i--)
typedef pair<int, int> PII;
typedef pair<ll, int> PLI;


const int MX = 2e5+10;
int dp[MX][2] = {0};

void solve() {
    string s;
    cin>>s;
    int res = 0, num = 0;
    vector<int> v;
    for (auto &c: s) {
        if (c == 'A')num++;
        else {
            v.push_back(num);
            num = 0;
        }
    }
    v.push_back(num);
    for (int i = 1; i < v.size(); i++) {
        dp[i][0] = v[i-1] + dp[i-1][0];
        dp[i][1] = v[i] + max(dp[i-1][0],dp[i-1][1]);
    }
    cout << max(dp[v.size()-1][0], dp[v.size()-1][1]) << endl;
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