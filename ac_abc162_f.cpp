//https://atcoder.jp/contests/abc162/tasks/abc162_f
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
ll dp[201010][2][4][3];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> A[i];

	rep(i, 0, N + 1) rep(top, 0, 2) rep(two, 0, 3) rep(three, 0, 2) dp[i][top][two][three] = -infl;

	dp[0][0][0][0] = 0;

	dp[1][1][0][0] = A[0];
	dp[2][0][0][0] = A[1];
	dp[3][0][1][0] = A[2];

	rep(i, 0, N) rep(top, 0, 2) rep(two, 0, 3) rep(three, 0, 2) if(-infl < dp[i][top][two][three]) {
		chmax(dp[i + 2][top][two][three], dp[i][top][two][three] + A[i + 1]);
		chmax(dp[i + 3][top][two + 1][three], dp[i][top][two][three] + A[i + 2]);
		chmax(dp[i + 4][top][two][three + 1], dp[i][top][two][three] + A[i + 3]);
	}

	ll ans = -infl;
	rep(i, 1, N + 1) rep(top, 0, 2) rep(two, 0, 3) rep(three, 0, 2) if (-infl < dp[i][top][two][three]) {
		int cnt = 0;
		int tot = i;
		if (top == 1) cnt++, tot--;

		tot -= two;
		tot -= three * 2;

		cnt += tot / 2;

		if (cnt == N / 2) chmax(ans, dp[i][top][two][three]);
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [動的計画法](https://www.hamayanhamayan.com/entry/2017/02/27/021246)
///////////////////////// writeup2 start
まず、どこから始めようかという感じであるが、とりあえず実験してみる。
色々実験してみると、空白について以下のことがわかる。

- 2連続空白となっている箇所は2箇所以下
- 3連続空白となっている箇所は1箇所以下

これは比較的見つけやすいかもしれない（2連続空白が1箇所かと思ってWA出したけど）
ここからちょっと発想の転換が必要であるが、動的計画法を行う。

dp[i][top][two][three] := 以下の条件を満たす組み合わせ
- i: 最後に選択した箇所がi番目である
- top: 配列の先頭を選択しているか（top=1なら選択している）
- two: 2連続する空白の個数
- three: 3連続する空白の個数

dp[i][top][two][three]を更新するには、i番目は選択済みなので、i+2,i+3,i+4を選択するしかない。
間の長さによって、two+1となったり、three+1となる。
これの更新はそこまで難しくない。
選択した個数が添え字に入っていないのが気になるかもしれないが、実はこれだけの要素があれば、
何個選択したかは計算で求めることができる。

dp[i][top][two][three]の状態のときに、何個選択されているかは以下のように計算する。
全部で長さはtotとして、選択されている個数をcntとする。
tot=i, cnt=0で初期化しておこう。
top=1であれば最初は選択されているので、cnt++する。
このとき、tot--としておくと、残っている部分はすべて「空白+選択」の連続になる。
ここから、tot -= two + three*2をすることで、すべての「空白+選択」を「1つの空白+選択」とできる。
つまり、これで残った長さの半分が残りの選択個数であるので、cnt += tot/2をすることで選択個数が得られる。

なので、作成済みDPに対して、以上の計算をして、選択個数がN/2であるものの最大値を求めると答え。
///////////////////////// writeup2 end */
