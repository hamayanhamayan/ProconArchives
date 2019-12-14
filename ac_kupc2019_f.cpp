//https://atcoder.jp/contests/kupc2019/tasks/kupc2019_f
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
template<int VW, int VH> struct Ruisekiwa2D {
	using T = ll;
	T v[VH][VW];
	Ruisekiwa2D() { rep(y, 0, VH) rep(x, 0, VW) v[y][x] = 0; }
	void set(int x, int y, T c) { v[y][x] = c; }
	void add(int x, int y, T c) { v[y][x] += c; }
	void build() {
		rep(y, 0, VH) rep(x, 0, VW) {
			if (0 < y) v[y][x] += v[y - 1][x];
			if (0 < x) v[y][x] += v[y][x - 1];
			if (0 < y && 0 < x) v[y][x] -= v[y - 1][x - 1];
		}
	}
	T get(int sx, int tx, int sy, int ty) { // [sx,sy]～[tx,ty]
		if (tx < sx or ty < sy) return 0;
		T rs = v[ty][tx];
		if (0 < sx) rs -= v[ty][sx - 1];
		if (0 < sy) rs -= v[sy - 1][tx];
		if (0 < sx && 0 < sy) rs += v[sy - 1][sx - 1];
		return rs;
	}
};
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, A[3010], M;
ll dp[3010];
Ruisekiwa2D<3010, 3010> r2d;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> A[i];
	cin >> M;
	rep(i, 0, M) {
		int l, r, b; cin >> l >> r >> b;
		r2d.add(l, r, b);
	}
	r2d.build();

	rep(i, 0, N) {
		rep(j, i + 1, N + 1) {
			chmax(dp[j], dp[i] + r2d.get(i + 1, j, j, N) - A[j - 1]);
		}
	}

	ll ans = 0;
	rep(i, 0, N + 1) chmax(ans, dp[i]);
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
最適方針として、なるべく1人の勇者に攻撃を集中させるのが得策。
なんとなくDP感がするので、DPで考えてみる。
dp[i] := 最後に勇者iに集中攻撃をした時のダメージ最大値
このように最後にどの勇者に集中攻撃したかが分かれば、勇者iを区間に持つ拠点とR[j]<iである拠点は使用済みとなる。
最後に集中攻撃をした勇者だけ覚えておけばよさそうだ。
するとN通りなので、ちょっと余裕がある。
遷移は普通にO(N)にしてみようか。
dp[i]→dp[i2]を考えると、i2は区間に入るが、iは区間に入らない拠点が総攻撃をする拠点になる。
これはi < L[j] ≦ i2、かつ、i2 ≦ R[j]を満たす拠点のモンスター総数が高速に求まればいい。
これは二次元累積和でいけるじゃん。
『かつおぶし』が脳裏をよぎるので、メモリを確認して出すと通る。
///////////////////////// writeup2 end */
