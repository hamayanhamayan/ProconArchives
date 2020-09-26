//https://atcoder.jp/contests/abl/tasks/abl_c
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














int N, M;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M;

	dsu uf(N);
	rep(i, 0, M) {
		int a, b; cin >> a >> b;
		a--; b--;
		uf.merge(a, b);
	}

	int ans = uf.groups().size() - 1;
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [UnionFind, DSU](https://www.hamayanhamayan.com/entry/2017/10/04/101826)
///////////////////////// writeup2 start
この問題設定をパッと見てUnionFindが真っ先に思い浮かんだので、途中考察がしにくいのだが、

- 都市と道路を頂点と無向辺と捉えると、無向グラフとして考えられる
- 「条件のどの都市からどの都市へも到達可能」が連結であるということに言い換えられる

みたいなところから思い浮かんでほしい。
既に存在する無向辺で連結成分に分けたとする。
全体を連結にするには、その連結成分をつないでやる必要があるが、ある2つの連結成分をつなぐのに必要な辺は1つで十分。
よって、連結成分数がgrp個であれば、それを1つにするにはgrp-1個の辺を追加すればいい。
無向グラフから連結成分数を抜き取るにはUnionFindを使うといい。
AtCoder LibraryではDSUとして実装されているので、それを使うとスムーズ。
///////////////////////// writeup2 end */
