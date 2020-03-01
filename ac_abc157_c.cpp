//https://atcoder.jp/contests/abc157/tasks/abc157_c
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














int N, M, S[5], C[5];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M;
	rep(i, 0, M) cin >> S[i] >> C[i], S[i]--;

	rep(ans, 0, 1000) {
		string s = to_string(ans);
		if (s.length() != N) continue;

		bool ok = true;
		rep(i, 0, M) rep(j, 0, N) if (j == S[i] && (s[j] - '0') != C[i]) ok = false;
		if (ok) {
			cout << ans << endl;
			return;
		}
	}

	cout << -1 << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
答えとなる数は[0,999]の範囲に収まる。
なので、答えとなる数を小さい方から順番に確認していき、条件を満たすものがあれば答える。
判定の実装では、C++だとto_stringを使うと色々楽にできる。
intとstringにすると速度は犠牲になるが、実装（特に桁に対する実装）は楽になる。
今回は、制約も全部ちっちゃいので、多少無理しても問題ない。

ok := 条件を満たすか
というのを更新しながら判定する。
条件はすべて満たしている必要があるので、満たさないものがあればok = falseとするよう実装する。
判定問題では自分はよく使う記法だ。
///////////////////////// writeup2 end */
