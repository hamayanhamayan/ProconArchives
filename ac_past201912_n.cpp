//https://atcoder.jp/contests/past201912-open/tasks/past201912_n
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














int N, W, C, L[101010], R[101010], P[101010];
//---------------------------------------------------------------------------------------------------
vector<int> dic;
ll lft[201010], rht[201010], tot;
ll solve(int l, int r) {
	if (l < 0) return infl;
	if (W < r) return infl;

	ll res = tot;

	int lid = upper_bound(all(dic), l) - dic.begin() - 1;
	if (0 <= lid) res -= lft[lid];

	int rid = lower_bound(all(dic), r) - dic.begin();
	res -= rht[rid];

	return res;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> W >> C;
	rep(i, 0, N) cin >> L[i] >> R[i] >> P[i];

	rep(i, 0, N) {
		dic.push_back(L[i]);
		dic.push_back(R[i]);
	}
	sort(all(dic));
	dic.erase(unique(all(dic)), dic.end());
	int n = dic.size();

	rep(i, 0, N) {
		int l = lower_bound(all(dic), L[i]) - dic.begin();
		int r = lower_bound(all(dic), R[i]) - dic.begin();
		rht[l] += P[i];
		lft[r] += P[i];
		tot += P[i];
	}

	rep(i, 1, n + 1) lft[i] += lft[i - 1];
	rrep(i, n - 1, 0) rht[i] += rht[i + 1];
	
	ll ans = infl;
	rep(i, 0, n) chmin(ans, solve(dic[i], dic[i] + C));
	rep(i, 0, n) chmin(ans, solve(dic[i] - C, dic[i]));
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- 座標圧縮
- [累積和](https://www.hamayanhamayan.com/entry/2017/07/04/020117)
///////////////////////// writeup2 start
まずは、なにか全探索できる部分は無いだろうか。
門を設置する場所が分かれば、そこに存在する石の重さの総和を取ってきて、その最小値を取れば答えられる。
課題が、設置する場所が沢山あるということと、存在する石の重さの総和をどうやってとってくるかの2つである。

設置する場所が沢山ある問題だが、石の区間の端を門の端として採用すれば良さそう。
適当な場所に置いてもいいが、局面を全探索するにはそこだけ採用すれば問題ない。
石がN個あると、端点は2N個ある。
そして、その端点を門の左端とするか、右端とするかで更に2通りあるので、4N通り。
これは全探索できる。

これで、門の位置は固定できたので、存在する石の重さの総和を高速に求める方法を考えよう。
門の位置の区間にある石の総和を求めるのは若干難しいので、区間にない石の総和を求めて、全体の総和から引くことにしよう。
門の位置が[L,R]であるとすると、

- 右端≦Lである石の重さの総和
- R≦左端である石の重さの総和

これを求めればいい。
よって、あとは、箇条書きで書いた2つを高速に求めるだけ！
だいぶいい線まで来た。
これは累積和+座標圧縮で計算できる。
///////////////////////// writeup2 end */
