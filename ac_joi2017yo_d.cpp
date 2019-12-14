//https://atcoder.jp/contests/joi2017yo/tasks/joi2017yo_d
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














int N, M, A[101010];
int cnt[20];
int dp[1 << 20];
int rui[20][101010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M;
	rep(i, 0, N) {
		cin >> A[i];
		A[i]--;
		cnt[A[i]]++;
		rui[A[i]][i] = 1;
	}

	rep(a, 0, M) rep(i, 1, N) rui[a][i] += rui[a][i - 1];

	rep(msk, 0, 1 << M) dp[msk] = inf;
	dp[0] = 0;
	rep(msk, 0, 1 << M) {
		int done = 0;
		rep(i, 0, M) if (msk & (1 << i)) done += cnt[i];
		rep(nxt, 0, M) if (!(msk & (1 << nxt))) {
			int tot = dp[msk];

			//rep(i, done, done + cnt[nxt]) if (A[i] != nxt) tot++;
			int nxt_cnt = rui[nxt][done + cnt[nxt] - 1];
			if (0 < done) nxt_cnt -= rui[nxt][done - 1];
			tot += cnt[nxt] - nxt_cnt;
			
			chmin(dp[msk + (1 << nxt)], tot);
		}
	}

	cout << dp[(1<<M) - 1] << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
何から始めようかという感じになるかもしれないが、M≦20というところがまずはヒントになりそうだ。
種類について何かうまくやることで、2^20の計算に持ち込めるに違いないという想像ができる。
種類について決めると結果に影響しそうなものとして、順番がある。
例えば、「1 3 2 1 3」というぬいぐるみを同じ種類が連続するようにするには、
種類の順番を123とすると結果は「1 1 2 3 3」であり、順番を321とすると結果は「3 3 2 1 1」となる。
結果が固定されていれば、取り出す必要のあるぬいぐるみの個数は、初期状態とあっていないものの個数となる。
つまり、初期状態「1 3 2 1 3」で結果が「1 1 2 3 3」であれば、あっていない2箇所（2番目と4番目）が答え。
種類の順番は最大20!あって、不可能だが、bitDPではN!を2^Nに変換して解決するのに最適な方針である。

bitDPでN!を2^Nで解決できるのは経験が無いと難しいだろう。
以下のようなDPを構築する。
dp[msk] := 既に順番が決まった種類の集合をmskとしたときに、取り出す必要のある個数の最小値
順番が12であろうと、21であろうと、その時点で結果として決まっている個数は一緒なので、
順番の3つ目以降には影響しないため、状態をまとめられるというのがモチベーション。

mskによって既に順番が決まっている結果の個数をdoneとして数える。
今回新たに種類nxtを選んだとすると、[done, done+cnt[nxt])の部分が結果として確定するので、
初期状態と照らし合わせて、違えば取り出す個数をインクリメントする。
結果をdpテーブルに最小値ならば格納する。
これを繰り返す。

と思ったらTLEした。
[done, done+cnt[nxt])について初期状態がnxtでない個数をカウントしているが、これをループでやるとTLEする。
累積和にしておこう。
///////////////////////// writeup2 end */
