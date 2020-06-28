//https://atcoder.jp/contests/abc172/tasks/abc172_f
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














int N; ll A[301];
//---------------------------------------------------------------------------------------------------
ll dp[51][2][2];
ll opt(ll A0, ll A1, ll other) {
	rep(d, 0, 51) rep(debt, 0, 2) rep(prof, 0, 2) dp[d][debt][prof] = infl;
	dp[0][0][0] = 0;

	rep(d, 0, 50) rep(debt, 0, 2) rep(prof, 0, 2) {
		ll a0 = ((A0 & (1LL << d)) != 0);
		ll a1 = ((A1 & (1LL << d)) != 0);
		ll b = ((other & (1LL << d)) != 0);

		int debt2 = 0, prof2 = 0;
		if (debt) a0--;
		if (a0 < 0) a0 = 1, debt2 = 1;
		if (prof) a1++;
		if (a1 == 2) a1 = 0, prof2 = 1;

		// 何もしない
		if ((a0 ^ a1) == b) chmin(dp[d + 1][debt2][prof2], dp[d][debt][prof]);

		// 1つ渡す
		a0--;
		if (a0 < 0) debt2 = 1, a0 = 1;
		a1++;
		if (a1 == 2) prof2 = 1, a1 = 0;
		if ((a0 ^ a1) == b) chmin(dp[d + 1][debt2][prof2], dp[d][debt][prof] + (1LL << d));
	}

	ll ans = dp[50][0][0];
	if (ans == infl) ans = -1;
	if (ans == A0) ans = -1;
	return ans;
}
//---------------------------------------------------------------------------------------------------
ll naive(ll A0, ll A1, ll other) {	
	rep(move, 0, A0) if ((other ^ (A0 - move) ^ (A1 + move)) == 0) return move;
	return -1;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> A[i];

	ll other = 0;
	rep(i, 2, N) other ^= A[i];

	//cout << naive(A[0], A[1], other) << endl;
	cout << opt(A[0], A[1], other) << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [Nim](https://www.hamayanhamayan.com/entry/2017/02/27/025050)
- [XOR系の知識](https://www.hamayanhamayan.com/entry/2017/05/20/145021)
- [桁DP](https://www.hamayanhamayan.com/entry/2017/04/23/212728)
///////////////////////// writeup2 start
今回の問題はNimを知っていないと解くのは不可能である。
問題の前半部分で説明している、山を1つ選んで任意個数取り除くというゲームはNimと呼ばれていて、
xorで先手必勝か後手必勝かが分かるという話がある。
これを本番で生成するのはだいぶきつい。

## Nim

Nimでは、全部の石の山の個数のxor和を取ったときに0であれば後手必勝で、そうでないなら先手必勝である。
よって、今回の問題はA[0]からA[1]にいくつか数を移したときに数列Aのxor和が0になるような最小個数を求める問題となる。
この操作にA[2]移行は関係ないので、もう少し限定的に考えると、
「A[0]からA[1]にいくつか数を移したときに移動後のA[0] xor A[1]がA[2]以降のxor和と等しくなる最小個数は？」
という問題に帰着できる。
自分の実装では、それを愚直に計算するnaive関数を作っておいた。
naive(A0, A1, other) := A0からA1にいくつか数を移動させた後A0 xor A1がotherになる最小移動数

## XORテク「ビット毎に考える」

このnaive関数を高速に求めることを考える。
xor問題に対するよくあるテクとして「ビット毎に考える」というのがある。
これは、XOR計算はビット毎に独立という所から来ている。
どうビット毎に考えるかという話だが、A0からA1への数移動も1毎ではなく、ビット毎に考えることにする。
つまり、1,2,4,8,16,...の単位で移動するかを考えることにする。
ここで4を移すことを試しに考えてみると、3ビット目が変化することになるが「それ以前のビットは変化しない」
なので、それ以前のビットのXORがotherと合っているように操作を行っていけば、それ以前のビットは考える必要がなくなる。
つまり抽象化できる。
DPへ持って行けそうなネタができた。

## 桁DP

後は、抽象化に必要な条件をまとめて桁DPする。
dp[d][debt][prof] := dビット目まで確定していて、A0で繰り下がりが発生しているか（debt）でA1で繰り上がりが発生しているか(prof)の状態を作るための最小移動数
A0からA1に数を移しているので、A0では繰り下がりが発生している場合がある。
同様にA1は数をもらうので、繰り上がりが発生している場合がある。
その情報は抽象化に含める必要がある。
遷移は、移す・移さないの二通りで、あとは頑張る。
50ビットくらいやれば10^15くらいまで行くので十分。
dp[50][0][0]が答えになる。

## 注意

dp[50][0][0] = A0の場合は全部移していることになるので、それはダメなので-1を返すこと
///////////////////////// writeup2 end */
