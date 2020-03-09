//https://atcoder.jp/contests/hitachi2020/tasks/hitachi2020_d
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














int N, T, A[201010], B[201010];
ll dp[201010][40];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> T;
	rep(i, 0, N) cin >> A[i] >> B[i], B[i]++;

	vector<int> one;
	rep(i, 0, N) if (1 <= A[i]) one.push_back(i);
	sort(all(one), [&](int x, int y) { // aybx < axby
		return 1LL * A[y] * B[x] < 1LL * A[x] * B[y];
	});
	int M = one.size();
	rep(i, 0, M + 1) rep(j, 0, 35) dp[i][j] = inf;
	dp[0][0] = 1;
	rep(i, 0, M) rep(j, 0, 35) if (dp[i][j] != inf) {
		int id = one[i];
		chmin(dp[i + 1][j], dp[i][j]);
		chmin(dp[i + 1][j + 1], dp[i][j] + 1LL * A[id] * dp[i][j] + B[id]);
	}

	vector<ll> zeros;
	rep(i, 0, N) if (A[i] == 0) zeros.push_back(B[i]);
	sort(all(zeros));
	int mm = zeros.size();
	rep(i, 1, mm) zeros[i] += zeros[i - 1];
	zeros.push_back(infl);

	int ans = 0;
	rep(cn, 0, 35) if (dp[M][cn] - 1 <= T) {
		ll t = dp[M][cn] - 1;
		int cnt = cn;
		ll rest = T - t;
		int zero = upper_bound(all(zeros), rest) - zeros.begin();
		chmax(ans, cn + zero);
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
お店への移動時に+1の時間がかかるので、b[i]はあらかじめ+1しておく。
こういう問題では、x->yと移動するのと、y->xと移動するのとで、比較をして、順番を確定してしまうのがいい。
ay(axt + bx + t) + by + axt + bx + t < ax(ayt + by + t) + bx + ayt + by + t
axayt + aybx + ayt + by + axt + bx + t < axayt + axby + axt + bx + ayt + by + t
aybx < axby
この条件が満たされるようにソートすれば最適な順番になる。

この問題で気づくべき重要な性質が、1≦A[i]であれば、時間は必ず2倍になるということ。
なので、1≦A[i]を選択した場合は、最大32個ぐらいしか取れないということ。
よって、dpをして32個ぐらい取ったときの時間の最小値を求めておこう。
dp[i][j] := i番目の街まで使ったときに、j個の街を音連れたときの時間最小値
これは普通のDPで書ける。
あとは、0～32個を取ったとして、残っているA[i]=0を何個とれるかを考えればいい。
A[i]=0はB[i]が小さい方から選択していくのが、最適なので、ソートしておき、累積和を取っておけば、upper_boundで何個まで取れるかを素早く計算できる。
これで、1≦A[i]で取った個数とA[i]=0を取れるだけとった個数の和の最大値が答えとなる。
///////////////////////// writeup2 end */
