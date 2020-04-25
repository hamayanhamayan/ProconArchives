//https://atcoder.jp/contests/abc163/tasks/abc163_e
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














int N; ll A[2010];
ll dp[2020][2020];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> A[i];

	vector<int> ord;
	rep(i, 0, N) ord.push_back(i);
	sort(all(ord), [&](int a, int b) { return A[a] > A[b]; });

	rep(tot, 0, N + 1) rep(lft, 0, N + 1) dp[tot][lft] = -inf;
	dp[0][0] = 0;

	rep(tot, 0, N) rep(lft, 0, tot + 1) if(0 <= dp[tot][lft]) {
		int i = ord[tot];

		if (0 <= i - lft) chmax(dp[tot + 1][lft + 1], dp[tot][lft] + A[i] * (i - lft));
		if (0 <= (N - 1 - (tot - lft) - i)) chmax(dp[tot + 1][lft], dp[tot][lft] + A[i] * (N - 1 - (tot - lft) - i));
	}

	ll ans = 0;
	rep(lft, 0, N + 1) chmax(ans, dp[N][lft]);
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [動的計画法](https://www.hamayanhamayan.com/entry/2017/02/27/021246)
///////////////////////// writeup2 start
うーむ、分からなかった。
一時間くらいは考えていたので、「数が大きいものから端に寄せてく」方針は出てきてはいたが、
この貪欲で行けそうという感覚は、センスが問われている気がする…
こういった流れも典型化していきなさいということでもあるかもしれない。

さて、気を取り直して解説を書くことにする。
本来は貪欲云々よりも先に、制約から2乗DPを検討し始める所が先だったかもしれない。
DPをしようと思うと何かしらの処理順序を決める必要がある。
先頭から確定させていこうとすると、間に要素が入ったりして、状態をまとめられない。
よって、数が大きいものから順に処理していくという順番を考える。
これは数が大きいものほど答えへの影響が大きいため、大きいものからの順番で考えてみる。

次は遷移だ。
例えば入力例3の「8 6 9 1 2 1」の最大値は9であるが、この9の遷移先を一番最初に確定させる。
遷移先は、「_ _ _ _ _ _」の6種類あるが、実は6通り考える必要はなく、最左か最右の2択だけでいい。
[公式解説](https://img.atcoder.jp/abc163/editorial.pdf)に理由は書いてあるが、コンテスト中の感覚に換言すると、
このくらいの制約がないと、とてもDPでは解けないとも言える。
（このくらいの制約がないと解けない思考テクは割と使える）
さて、遷移が端だけとなると、左右で何個確定しているかが分かれば、そこには数はおけないので、状態がまとめられる。
やっとDPらしくなってきた。

dp[tot][lft] := 大きい順でtot個選択済みで、左にlft個移動したときの嬉しさの最大値
これを更新していく。
各状態において、左に置くか右に置くかを考えるが、元々の位置と、選択済みの位置を見たときに、
左に移動できなかったら、左への遷移はできないし、右もまた然りである。

dp[N][0]～dp[N][N]の最大値が答えとなる。
///////////////////////// writeup2 end */
