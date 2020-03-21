//https://www.hackerrank.com/contests/oyamac/challenges/sumsumsum
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












int A, B, C, D;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> A >> B >> C >> D;

    int ans = 0;
    rep(x, 0, D + 1) rep(y, 0, D + 1) if ((D - A * x - B * y) % C == 0) {
        int z = (D - A * x - B * y) / C;
        if (0 <= z) ans++;
    }
    cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
まずは全探索を考えてみよう。
ABCDxyzは全部整数でなので、等式になるためにはxyzも最大はDまで考えればいい。
よって、xyzの全探索は10^9通りとなる。
これは間に合わない。

少し工夫をしよう。

```
Ax + By + Cz = D
Cz = D - Ax - By
z = (D - Ax - By) / C
```

このように変換してみると、xyが決まればzは一意に定まることが分かる。
なので、等式を満たすxyzを全探索するにはxyの全探索で10^6通りを考えればいい。
これは間に合う。

よって、xyを全探索し、zが整数で0以上のものを答えとしてカウントしていくと答え。
///////////////////////// writeup2 end */
//　