//https://atcoder.jp/contests/agc046/tasks/agc046_a
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














int X;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> X;

	int K = 1;
	while (K * X % 360 != 0) K++;
	cout << K << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
まず自明な所から考えてみると、
X=180, X=90, X=60みたいな正多角形で内角が整数であるものは360/Xが答えになっている。
X=100のような、360/Xが整数にならない場合が問題。
場合分けするのも大変なので、一旦全部まとめて考えられるような式が立てられないか考えると、
角度は360でも720でも変わらないみたいな性質を使うと、
「XKが360の倍数であるようなKで戻ってくるのでは？」
という仮定ができる。
なので、XKが360の倍数となるKの最小値が答えっぽい。
普通のコンテストならこの仮定でつっこんでもいいが、AGCなので、
かつ、Xも179通りしかないので、実験コードで確認してから出すと確実かもしれない。
（ランキングをチラ見して、爆速でみんな通しているので、つっこむ戦略もいいかも）
///////////////////////// writeup2 end */
