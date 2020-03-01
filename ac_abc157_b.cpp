//https://atcoder.jp/contests/abc157/tasks/abc157_b
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














int A[3][3], N;
bool punched[3][3];
//---------------------------------------------------------------------------------------------------
void _main() {
	rep(y, 0, 3) rep(x, 0, 3) cin >> A[y][x];
	cin >> N;
	rep(i, 0, N) {
		int b; cin >> b;
		rep(y, 0, 3) rep(x, 0, 3) if (A[y][x] == b) punched[y][x] = true;
	}

	bool ans = false;

	// 横
	rep(y, 0, 3) {
		int cnt = 0;
		rep(x, 0, 3) if (punched[y][x]) cnt++;
		if (cnt == 3) ans = true;
	}

	// 縦
	rep(x, 0, 3) {
		int cnt = 0;
		rep(y, 0, 3) if (punched[y][x]) cnt++;
		if (cnt == 3) ans = true;
	}

	// ななめ
	if (punched[0][0] && punched[1][1] && punched[2][2]) ans = true;
	if (punched[2][0] && punched[1][1] && punched[0][2]) ans = true;

	if (ans) cout << "Yes" << endl;
	else cout << "No" << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
実装問題。
まずは、punched[y][x] := (x,y)に印がついているか
をN個の選ばれた数を見ながら作成しよう。

あとは、これがビンゴになっているかの確認である。
縦、横については、印がついている個数を行ごと、列ごとに考えて、3つあればビンゴとする。
ななめは直書きしたが、ループでもそんなにたいしたことない。
（なんなら、横も縦も直で書けばよかったかも）
///////////////////////// writeup2 end */
