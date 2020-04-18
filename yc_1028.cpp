//https://yukicoder.me/problems/no/1028
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
template<typename Func>
int findMin(int L, int R, Func f) { //[L, R)
	int lo = L - 1, hi = R - 1;
	while (lo + 1 != hi) {
		int mi = (lo + hi) / 2;
		if (f(mi) <= f(mi + 1)) hi = mi;
		else lo = mi;
	}
	return hi;
}
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, A[1010][1010];
//---------------------------------------------------------------------------------------------------
vector<pair<int, int>> houses[1010];
int employee;
int f(int x) {
	int tot = 0;
	fore(p, houses[employee]) tot += max(abs(x - p.first), p.second);
	return tot;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(x, 0, N) rep(y, 0, N) cin >> A[x][y];
	rep(x, 0, N) rep(y, 0, N) houses[A[x][y]].push_back({ x, y });

	int ans = 0;
	rep(e, 1, N + 1) {
		employee = e;
		int optx = findMin(0, N, f);
		ans += f(optx);
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [三分探索](https://www.hamayanhamayan.com/entry/2017/07/05/160236)
///////////////////////// writeup2 start
難しい問題。三分探索で解く。

三分探索で解くというのに気づくのが一番難しい。
（二分探索系は大体そう）
方針は「各社員の家について、(1,1)～(N,1)のどこで襲撃するのが最適かを高速に見つける」。
(1,1)～(N,1)のそれぞれで襲撃にかかる移動回数を計算してみると、凸性を持つことが分かる。
よって、どこが最適であるかは、三分探索で求めることが可能。

あとは、それぞれの社員について、最適な移動回数の総和を求めれば答え。
計算量O(N^2logN)
///////////////////////// writeup2 end */
