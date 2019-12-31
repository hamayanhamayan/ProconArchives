//https://atcoder.jp/contests/past201912-open/tasks/past201912_o
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














int N, A[30101][6];
double ma = 0;
double tot[30101];
double dp[181010];
vector<int> que[181010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) rep(j, 0, 6) cin >> A[i][j];

	vector<int> dic;
	dic.push_back(0);
	rep(i, 0, N) rep(j, 0, 6) dic.push_back(A[i][j]);
	sort(all(dic));
	dic.erase(unique(all(dic)), dic.end());

	int n = dic.size();
	rep(i, 0, N) rep(j, 0, 6) {
		int id = lower_bound(all(dic), A[i][j]) - dic.begin();
		que[id].push_back(i);
	}

	rrep(i, n - 1, 0) {
		dp[i] = ma + 1;
		fore(q, que[i]) {
			tot[q] += dp[i] / 6;
			chmax(ma, tot[q]);
		}
	}

	printf("%0.14f\n", dp[0]);
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
サイコロを振って出た目を並べると、単調増加になっている。
出た目がiである状態からサイコロを振ったときの遷移先である出た目がjである状態は、
必ずi<jを満たす。
このことから、なんとなく期待値DPな雰囲気がある。
dp[i] := 出目がiである状態からサイコロを適切に振ったときのサイコロを振る回数の期待値の最大

iは大きくなるので、座標圧縮して入れとく必要がある。
dp[0]が答えになるので、降順でDPテーブルを埋めていく。
dp[i]を更新したいときに、N通りのサイコロを振る必要がある。
この時、j番目のサイコロを振るとしたときに
i<A[j][k]である全てのkについて、dp[A[j][k]] / 6の総和が期待値となる。
これの最大値を取ってきて+1したものがdp[i]となる。
普通にN通りのサイコロを振ったときの最大値を確認していると、TLEしてしまう。
この辺を効率よく計算する。

dp[i]の計算が終わったとする。
これで、次にdp[i-1]を計算しようと考える。
その場合、今のN通りのサイコロを振ったときの最大値を計算すると、ほぼほぼ前と同じになることが分かる。
違う部分はA[j][k]=iである部分である。
つまり、A[j][k]=iであるサイコロについてだけ、期待値を更新してやる。
期待値の更新に伴って、全体の最大値も更新されるので、こっちも更新する。
これで、DPの更新がならしO(N)でできて間に合う。
ならし計算量は難しいかもしれないが、全体でその部分を処理する回数が1回だけという保証があると、
全体を通してみると間に合うことが分かるだろう。
///////////////////////// writeup2 end */
