/**
 * Source: t.ly/amBZ7
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
    int a,b,c;
    cin>>a>>b>>c;
    int total=a+b+c, res=INT32_MAX;

    function<void(int, int, int)> check = [&](int f, int s, int t) {
        vector<int> v(3, 0);
        v[2]=s;
        int i,j;
        if (f==1) {
            v[0]=v[1]=1,t--;
        } else {
            v[0]=f/2,v[1]=f/2+f%2;
        }
        sort(begin(v), end(v));
        if (2*v[2]-v[1]-v[0]>=t) res = min(res,v[2]);
        else res = min(res,total/3+(total%3!=0));
    };

    check(a,c,b);
    check(c,a,b);
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