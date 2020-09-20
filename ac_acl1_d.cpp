//https://atcoder.jp/contests/acl1/tasks/acl1_d
#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; using namespace atcoder;
void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
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














int N, K, X[201010];
int Q;
//---------------------------------------------------------------------------------------------------
int toRight[201010], toLeft[201010];
int toR[19][201010], toL[19][201010];
int totR[19][201010], totL[19][201010];
//---------------------------------------------------------------------------------------------------
int getTot(int L, int R) {
	int res = 1;
	int cu = L;
	rrep(p, 18, 0) {
		if (toR[p][cu] <= R) {
			res += 1 << p;
			cu = toR[p][cu];
		}
	}
	return res;
}
int getRight(int L, int R) {
	int cnt = getTot(L, R);

	ll tot = R; cnt--;
	int cu = R;
	rep(p, 0, 19) if (cnt & (1 << p)) {
		tot += totL[p][cu];
		cu = toL[p][cu];
	}

	return tot;
}
int getLeft(int L, int R) {
	int cnt = getTot(L, R);

	ll tot = L; cnt--;
	int cu = L;
	rep(p, 0, 19) if (cnt & (1 << p)) {
		tot += totR[p][cu];
		cu = toR[p][cu];
	}

	return tot;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> K;
	rep(i, 0, N) cin >> X[i];
	cin >> Q;

	rep(i, 0, N) toRight[i] = lower_bound(X, X + N, X[i] + K) - X;
	rep(i, 0, N) {
		int id = upper_bound(X, X + N, X[i] - K) - X;
		toLeft[i] = id - 1;
	}

	rep(p, 0, 19) toR[p][N] = N;
	rep(i, 0, N) toR[0][i] = toRight[i];
	rep(p, 1, 19) rep(i, 0, N) toR[p][i] = toR[p - 1][toR[p - 1][i]];

	rep(i, 0, N) totR[0][i] = toR[0][i];
	rep(p, 1, 19) rep(i, 0, N) totR[p][i] = totR[p - 1][i] + totR[p - 1][toR[p - 1][i]];

	rep(i, 0, N) toL[0][i] = toLeft[i];
	rep(p, 1, 19) rep(i, 0, N) {
		if (toL[p - 1][i] < 0) toL[p][i] = -1;
		else toL[p][i] = toL[p - 1][toL[p - 1][i]];
	}

	rep(i, 0, N) totL[0][i] = toL[0][i];
	rep(p, 1, 19) rep(i, 0, N) {
		if (toL[p - 1][i] < 0) totL[p][i] = totL[p - 1][i];
		else totL[p][i] = totL[p - 1][i] + totL[p - 1][toL[p - 1][i]];
	}

	rep(q, 0, Q) {
		int L, R; cin >> L >> R;
		L--; R--;
		ll ans = getRight(L, R) - getLeft(L, R) + getTot(L, R);
		printf("%lld\n", ans);
	}

}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
強実装問題。

## クエリ問題は1クエリではどう解くかを考えよう

まずは1つのクエリに対してどうやって解くかを考えていこう。
「よい集合の和集合のサイズ」という珍しい条件は一旦忘れて、
条件を満たす部分集合の個数を最大化する方法を考える。
これは先頭の点から貪欲に距離がK以上となるように選択していくことで、
取れる点の個数を最大化できる。
色々実験してみると、区間にある頂点で1番目として使用できる数、2番目として使用できる数は、
ちょうど区間になっていて、かつ、独立であることが分かる。
しかも、区間の先頭から貪欲に取ったときの数が各番目として使用できる区間の左端となっていて、
区間の末尾から貪欲に取ったときの数が各番目として使用できる区間の右端となっている。

## もう少し分割して考える

各クエリの答えは以下のようになる。
(右端から貪欲で取っていった座標の総和) - (左端から貪欲で取っていった座標の総和) + (集合の最大サイズ)
最初の2つはほぼ同じような計算をするので、まとめて考える。

## 集合の最大サイズ

ダブリングを使う。
toR[p][i] := 座標iから2^p回距離K以上を保ったまま貪欲に移動したときの移動先
これを構築していく。
これが分かれば、二分探索っぽい感じにすることで区間の左端から何回移動できるかを計算することができる。
こっちはダブリングの一般的な用法なので、これはいいだろう。

## 左端から貪欲で取っていった座標の総和

こっちもダブリングで計算しよう。
こっちの計算がだいぶ大変。
totR[p][i] := 座標iから2^p回距離K以上を保ったまま貪欲に移動したときの移動した座標の総和
これもダブリングと、toR配列を使えば計算可能。
クエリ計算で使用するときは、移動回数が分かっているので、その移動回数を2^0, 2^1, 2^2のように分割して、
この配列を使って数え上げていけばいい。
///////////////////////// writeup2 end */
