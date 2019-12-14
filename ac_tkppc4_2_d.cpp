//https://atcoder.jp/contests/tkppc4-2/tasks/tkppc4_2_d
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
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, P, Q, A[101010];
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> P >> Q;
    rep(i, 0, N) cin >> A[i];

    if((P + Q) % 2 != 0) {
        cout << 0 << endl;
        return;
    }

    int R = P - (P + Q) / 2;

    ll ans = 0;
    ll lft = 0;
    map<int,ll> cnt;
    rep(i, 0, N) cnt[A[i]]++;

    rep(y, 0, N) {
        cnt[A[y]]--;

        ans += lft * cnt[R - A[y]];

        if(A[y] == (P + Q) / 2) lft++;
    }

    cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
さて、何かを全探索することから考え始めるわけだが、xを固定してみよう。
すると、A[y], A[z]をどうするかという話になるが、まずは式変形。
```
A[x] + A[y] + A[z] = P
A[y] + A[z] = P - A[x]
```
これで
```
A[x] - A[y] - A[z] = Q
- A[y] - A[z] = Q - A[x]
A[y] + A[z] = A[x] - Q
```
となるので、`P - A[x] = A[x] - Q`を満たす必要がある。
`R = P - A[x]`とすると、`x < y < z`かつ、`A[y] + A[z] = R`を満たすy,zの組を
求める問題となる。
これはだいぶ計算しやすそうに見える。
計算量は余り残っていない。xを全探索するので、O(1)かO(logN)でやる必要がある。
だが、全然思いつかない。

満たすべき条件`P - A[x] = A[x] - Q`はよくよく見ると、
```
P - A[x] = A[x] - Q
P + Q = 2 A[x]
A[x] = (P + Q) / 2
```
となるので、実はA[x]が一意に定まる。
よって、Rも一意に定まる。
`x < y < z`かつ`A[x] = (P + Q) / 2`であるとき、(`A[y] + A[z] = R`を満たすy,zの組)×(A[x]の個数)の総和が答え。
これもちょっとやりにくいので、ここで典型を使おう。
「3つ並んでいるものの全探索は真ん中を使うのがいい。」
yを全探索すると、「yより左で`A[x] = (P + Q) / 2`の組み合わせ×yより左で`A[z] = R - A[y]`の組み合わせ」の総和を取れば良くなる。
これは計算できる。
///////////////////////// writeup2 end */
