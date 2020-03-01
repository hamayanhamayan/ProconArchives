//https://www.hackerrank.com/contests/yfkpo3-1/challenges/digit-sum-multiple
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
//---------------------------------------------------------------------------------------------------
/*---------------------------------------------------------------------------------------------------
                      Welcome to My Coding Space!       @hamayanhamayan0
---------------------------------------------------------------------------------------------------*/













//---------------------------------------------------------------------------------------------------
void _main() {
    int cnt = 0;
    rep(x, 10000, 100000) {
        string s = to_string(x);
        bool ok = true;
        rep(i, 0, 4) if (s[i] == '0') ok = false;
        if (ok) {
            int sn = 0;
            rep(i, 0, 4) sn += s[i] - '0';
            if (x % sn == 0) {
                printf("%d [%d]\n", x, sn);
                cnt++;
                if (cnt == 10) return;
            }
        }
    }
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
///////////////////////// writeup2 end */
