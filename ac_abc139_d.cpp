//https://atcoder.jp/contests/abc139/tasks/abc139_d
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

ll N;
//---------------------------------------------------------------------------------------------------
void labo(int n) {
    vector<int> v;
    rep(i, 0, n) v.push_back(i + 1);
    do {
        int tot = 0;
        rep(i, 0, n) tot += (i + 1) % v[i];
        printf("%d", tot);
        rep(i, 0, n) printf(" %d", v[i]);
        printf("\n");
    } while (next_permutation(all(v)));
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    ll ans = (N - 1) * N / 2;
    cout << ans << endl;
}

/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
Nの上限が10^9なので、Nに起因するアルゴリズムではなさそう。
それで400点ということもあり、特殊な解法が存在するっぽい。

という訳で実験してみよう。
```
N     ans    P
1     0      1
2     1      2 1
3     3      1 3 2
             2 3 1
4     6      2 3 4 1
5     10     1 3 4 5 2
             2 1 4 5 3
             2 3 4 5 1
```
2 3 4 ... N 1のようにしていけばいいっぽい。
こうすると、1+2+3+...+(N-1)が得られる。
つまり、(N-1)*N/2が答え。
///////////////////////// writeup2 end */
