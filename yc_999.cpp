//https://yukicoder.me/problems/no/999
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














int N, A[201010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N * 2) cin >> A[i];

	ll ans = -infl;
	ll tot = 0;
	rep(i, 0, N * 2) {
		if (i % 2 == 0) tot -= A[i];
		else tot += A[i];
	}
	chmax(ans, tot);
	rep(i, 0, N) {
		int first = A[i * 2];
		int second = A[i * 2 + 1];

		tot = tot + first - second; // 打消し
		tot = tot + first - second; // ほてにする
		chmax(ans, tot);
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
ルールを整理してみると、最終的な選択は以下のようになる。
「ほ」はほむらちゃん、「て」はてんぷらくん。
`ほてほてほて てほてほ`
このように、左をとると`ほて`と取れて、右をとると`てほ`ととれる。
つまり、`ほて`の連続 + `てほ`の連続のような選択になる。
ほむらちゃんが選択すれば、てんぷらくんの選択は一意に定まるので、ほむらちゃんの操作回数のみを考える。
左をk回とると、右はN-k回とることになる。
これをうまく全探索することで答えを導こう。

差分を計算することで、うまく計算する。
まずは、`てほてほてほ…`で合計値を計算しよう。
先頭から`てほ`になっている所を打ち消して、`ほて`と選択を変えながら、全体のコストを差分を使って計算しよう。
累積和を使うことで、左を何回とるかを全探索して、計算することもできる。
///////////////////////// writeup2 end */
