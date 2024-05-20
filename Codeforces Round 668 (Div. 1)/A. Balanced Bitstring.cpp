/**
 * Source: t.ly/FqVvL
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


void solve() {
    int n,k;
    string s;
    cin>>n>>k>>s;

    vector<int> num(k, -1);
    For(i,0,k-1) {
        int idx = i;
        while (idx<n) {
            if (s[idx]=='1') {
                if (num[i]==0) {
                    cout << "NO" << endl;
                    return;
                }
                num[i]=1;
            }
            if (s[idx]=='0') {
                if (num[i]==1) {
                    cout << "NO" << endl;
                    return;
                }
                num[i]=0;
            }
            idx += k;
        }
    }

    int diff=0, free=0;
    For(i,0,k-1) {
        if (num[i]==1) diff++;
        else if (num[i]==0) diff--;
        else free++;
    }
    int d = (free-abs(diff));
    if (d<0 || d%2) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
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