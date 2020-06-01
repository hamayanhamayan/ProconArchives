//https://atcoder.jp/contests/abc169/tasks/abc169_c
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
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














ll A, B1, B2;
//---------------------------------------------------------------------------------------------------
void _main() {
	scanf("%lld %lld.%lld", &A, &B1, &B2);

	ll ans = A * (B1 * 100 + B2) / 100;
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
小数が絡む計算でやはり気になるのが誤差である。
普通に入力してもいいが、整数でできないかを考えてみる。
A×Bをするが、100倍をしてやると、整数になる。
100倍をした後に÷100をして、かつ、切り捨ててやると、A×Bの小数点以下切り捨てとなる。
この方針でやろう。

C++であれば、scanfを使うのがいい。
`scanf("%lld %lld.%lld", &A, &B1, &B2);`
便利。
これで、B1*100+B2をしてやると、Bを100倍したものが得られる。
あとは、Aとかけて100で切り捨てで割れば答え。
///////////////////////// writeup2 end */
