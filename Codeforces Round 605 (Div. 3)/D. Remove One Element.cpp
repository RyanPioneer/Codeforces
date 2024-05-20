/**
 * Source: t.ly/TQizC
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

int front[MX]={0}, back[MX]={0}, arr[MX];

void solve() {
    int n, res=0, num;
    cin >> n;
    For(i,1,n) {
        cin>>arr[i];
    }
    arr[0]=INT32_MAX;
    int a=1, b=1;
    For(i,1,n) {
        if (arr[i]>arr[i-1]) {
            a++;
        } else {
            a=1;
        }
        back[i]=a;
        if (arr[n+1-i]<arr[n+2-i]) {
            b++;
        } else {
            b=1;
        }
        front[n+1-i]=b;
    }
    For(i,1,n) {
        res = max(res, front[i]);
        if (arr[i-1]<arr[i+1]) {
            res = max(res, back[i-1]+front[i+1]);
        }
    }
    cout << res << endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    for (t=1; t; t--) {
        solve();
    }
}