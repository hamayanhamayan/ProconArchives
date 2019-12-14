//https://yukicoder.me/problems/no/915
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













int A, B, C;
//---------------------------------------------------------------------------------------------------
void solve() {
	cin >> A >> B >> C;

	if (C == 1) {
		cout << -1 << endl;
		return;
	}

	ll ans = 0;
	while (0 < A) {
		if (A < C) {
			ans += B;
			break;
		}

		if (A <= 2LL * (C - 1)) {
			ans += 2LL * B;
			break;
		}

		if (A % C != 0) {
			A = A - (A % C);
			ans += B;
		}
		else {
			A /= C;
			ans += B;
		}
	}
	cout << ans << endl;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	int Q; cin >> Q;
	rep(q, 0, Q) solve();
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
よーく見ると、C進数っぽく見える。
なので、C進数っぽく考えて最小コストを作ろう。
と思ったら合わない！
最後の12 2 3は(2 + 2) * 3の3手が最短。
★2だしなぁと思って方針を探すと、Cの倍数じゃないなら、Cの倍数になるよう減らして、
Cで割るのを繰り返す。
(C-1)*2あたりがコーナーケースになりそう。
これ以下になっていれば2回か。

C = 1がコーナーケース。クッキーを作れないので-1
///////////////////////// writeup2 end */
