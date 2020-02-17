//https://atcoder.jp/contests/abc155/tasks/abc155_d
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














int N; ll K; ll A[201010];
//---------------------------------------------------------------------------------------------------
ll getMinus(ll lim) {
	vector<ll> mi, pl;
	rep(i, 0, N) {
		if (A[i] < 0) mi.push_back(A[i]);
		if (0 < A[i]) pl.push_back(A[i]);
	}

	int j = 0;
	ll res = 0;
	fore(m, mi) {
		// m * p <= lim
		while (j < pl.size() && lim < m * pl[j]) j++;
		res += pl.size() - j;
	}
	return res;
}
//---------------------------------------------------------------------------------------------------
ll getZeros() {
	int zero = 0;
	rep(i, 0, N) if (A[i] == 0) zero++;
	return 1LL * zero * (N - zero) + 1LL * zero * (zero - 1) / 2;
}
//---------------------------------------------------------------------------------------------------
ll getPlus(ll lim) {
	vector<ll> mi, pl;
	rep(i, 0, N) if (0 < A[i]) pl.push_back(A[i]);
	rrep(i, N - 1, 0) if (A[i] < 0) mi.push_back(-A[i]);

	ll res = 0;

	int n = mi.size();
	int j = n - 1;
	rep(i, 0, n) {
		while (i < j && lim < mi[i] * mi[j]) j--;
		res += max(0, j - i);
	}

	n = pl.size();
	j = n - 1;
	rep(i, 0, n) {
		while (i < j && lim < pl[i] * pl[j]) j--;
		res += max(0, j - i);
	}

	return res;
}
//---------------------------------------------------------------------------------------------------
ll getCount(ll lim) {
	ll res = getMinus(min(lim, -1LL));
	if (0 <= lim) res += getZeros();
	if (0 < lim) res += getPlus(lim);
	return res;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> K;
	rep(i, 0, N) cin >> A[i];
	sort(A, A + N);

	ll ng = -infl, ok = infl;
	while (ng + 1 != ok) {
		ll md = (ok + ng) / 2;
		if (K <= getCount(md)) ok = md;
		else ng = md;
	}
	cout << ok << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [二分探索](https://www.hamayanhamayan.com/entry/2017/07/05/160236)
- [尺取り法](https://www.hamayanhamayan.com/entry/2017/09/09/220426)
///////////////////////// writeup2 start
競技プログラミングに慣れている人は、全通りのK番目を答えよと言われたら真っ先に二分探索かなと思う。
getCount(lim) := A[i]*A[j]≦limである(i,j)ペアの組み合わせ
これを用意して、[-10^18,-10^18]で二分探索する。
K≦getCount(md)であるかというのを考えると単調性があるのが分かるだろう。
この形は「全通りのK番目を答えよ」という問題では典型テクなので覚えておくとよい。
あと、Aはソート可能で、このテクではよくソートが必要なのでソートしておく。

問題はgetCountの実装である。
制約も2秒でlong longも使う必要があるので、O(NlogN)で作りたい。
順位表を見ていると、WAが多く見られたのでO(N(lonN)^2)は落とすような制約だったのだろう。
自分は場合分けをして実装した。

getMinus(lim) := A[i]*A[j]≦lim<0である(i,j)の組合せ
getZeros(lim) := A[i]*A[j]=0である(i,j)の組合せ
getPlus(lim) := 0 < A[i]*A[j]≦limである(i,j)の組合せ

getZerosは0の個数を数えておき、0とそれ以外の積と、0同士の積を数えればいい。O(N)

getMinusは、負×正を考えればいいので、負の数を小さいほうから全探索して、かけてlim以下となる正の個数を足し合わせていく。
どちらも先頭から正負でわけてくとソート済みを保てる。
負の数を固定すると、条件を満たす正の数は後半のある区間になって、負の数を順番に見ていくと区間が縮小していくので、
尺取り法で数え上げていく。
これで全体O(N)

getPlusは、負×負、正×正で考える。
基本的にはgetMinusと同じ。
負×負もマイナスを付けて正×正にしてしまえば同じコードで実装可能（コピペしちゃったけど、あと順番注意）。
こちらも尺取り法が使えて全体O(N)

ソートとかを不用意に使うとすぐO(logN)がつく。
丁寧にやると全体O(NlogN)で間に合う。
///////////////////////// writeup2 end */
