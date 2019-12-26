//https://atcoder.jp/contests/pakencamp-2019-day3/tasks/pakencamp_2019_day3_c
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














int N, M, A[101][101];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M;
	rep(i, 0, N) rep(j, 0, M) cin >> A[i][j];

	ll ans = 0;
	rep(t1, 0, M) rep(t2, t1 + 1, M) {
		ll tot = 0;
		rep(i, 0, N) tot += max(A[i][t1], A[i][t2]);
		chmax(ans, tot);
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
難しい問題に直面したときは、まずは全探索ができないか考えてみよう。
何を全探索するかであるが、なるべく、それが決まれば他が全て決まるというものがふさわしい。
今回だと、M個から曲を2つ選べばシミュレートすることで全体の得点が分かるので、これを全探索しよう。

曲の選び方がM^2通りくらいあって、それで歌ったときの得点をシミュレートするのにO(N)かかるので、
全体でO(NM^2)で間に合う。
自分は実装でchmaxというマクロを使っている。
chmax(a, b)と書くと、a=max(a,b)と同様の働きをする。
参照渡しで関数に与えているので更新ができるということ。
///////////////////////// writeup2 end */
