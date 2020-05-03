//https://atcoder.jp/contests/abc166/tasks/abc166_d
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














ll X;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> X;

	map<ll, ll> v;
	rep(x, -1000, 1001) v[1LL * x * x * x * x * x] = x;

	fore(bp, v) {
		ll B5 = bp.first;
		ll B = bp.second;

		if (v.count(X + B5)) {
			ll A = v[X + B5];
			printf("%lld %lld\n", A, B);
			return;
		}
	}
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
この問題を解くにあたって最も注目すべき部分はどこだろうか。
他の問題と著しく異なっている部分はやはり「5乗」の部分である。
この部分を中心に解法を考えていこう。

解法の基本は全探索である。Aを全探索して固定できればBも一意に定まるので答えられる。
よって、5乗であるということと、Aは全探索できるか？という所から解法を考える。

これ以降は、なんとなくレベルで解いてしまった。

5乗なので、10^2を5乗すると10^10となるので、Xを作るにはその範囲くらいで十分では？
Aを[-100,100]で全探索してみる。 -> WA

あれっ？
あっ、でもこのパターンだと、101^5-100^5がダメか。
適当に全探索範囲広げれば通るでしょ。[-1000,1000]にする -> AC

ratedだとこういう雰囲気で投げるのは怖い（コドフォとかだったらなおさら）ので、
ちゃんと公式解説を読んで全探索範囲の決め方を学びましょう。
（それか、計算量最大まで探索範囲を伸ばしておく戦略でもいいけど）
///////////////////////// writeup2 end */
