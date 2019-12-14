//https://atcoder.jp/contests/nikkei2019-2-qual/tasks/nikkei2019_2_qual_c
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
struct UnionFind {
	vector<int> par; // uf(x,y)->y
	UnionFind() {}
	UnionFind(int NV) { init(NV); }
	void init(int NV) { par.clear(); rep(i, 0, NV) par.push_back(i); }
	void reset() { rep(i, 0, par.size()) par[i] = i; }
	int operator[](int x) { return par[x] == x ? x : par[x] = operator[](par[x]); }
	void operator()(int x, int y) { x = operator[](x); y = operator[](y); if (x != y) par[x] = y; }
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














int N, A[101010], B[101010];
//---------------------------------------------------------------------------------------------------
#define yes "Yes"
#define no "No"
pair<int, int> A2[101010], B2[101010];
string solve() {
	rep(i, 0, N) A2[i] = { A[i], i };
	sort(A2, A2 + N);
	rep(i, 0, N) B2[i] = { B[i], i };
	sort(B2, B2 + N);

	// 前提条件チェック
	rep(i, 0, N) if (A2[i].first > B2[i].first) return no;

	// ループが2つ以上ならyes
	UnionFind uf(N);
	rep(i, 0, N) uf(A2[i].second, B2[i].second);
	int cnt = 0;
	rep(i, 0, N) if (uf[i] == i) cnt++;
	if (1 < cnt) return yes;
	
	// ラストコーナー対策
	rep(i, 0, N - 1) if (A2[i].first <= B2[i + 1].first and A2[i + 1].first <= B2[i].first) return yes;

	return no;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> A[i];
	rep(i, 0, N) cin >> B[i];
	cout << solve() << endl;
}




/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
TLで見つけたスーパーコーナーケース

```
4
2 1 4 3
1 2 3 4
```

なるほど、という言葉しか出てこない。
解説に移ろう。

まずは、自明な所から攻めていく。
AとBをソートしたものをA2,B2とする。
このとき、A2[i]≦B2[i]が満たされている必要がある。
そうでないならNo
swapを使ってのソートはN-1回swapが必要である。
しかし今回はN-2回までしかswapが使えないので、どうしようかとなる。
そのため、自分は本番では、A[i]≦B[i]を満たすA[i],B[i]以外のA,Bをソートして、
A2[i]≦B2[i]が全て満たされているかを判定すればいいと考えた。
この方針ではスーパーコーナーケースに阻まれる。

スーパーコーナーケースから知見を得ることにする。
A = {2 1 4 3}であり、A2 = {1 2 3 4}であるが、これはA[0]がA2[1]へ、A[1]がA2[0]へ移動している。
これを遷移と考えると、なもりグラフになる。
実際はもっと違う性質を持っていて、入次辺と出次辺が全て1なので、ループのみの連結成分が1つ以上あるグラフになっている。
ループが1つであれば、N-1回のswapが必要であるが、スーパーコーナーケースのようにループが2つなら、
swapを1回減らすことができる。
よって、Aをswapして、A[i]=A2[j]であるiからjに有向辺を引いてループの個数を調べよう。
ループが2つ以上あればyesである。
ループ検出はdfsでもUnionFindでもいい。
知見としてはei1333さんが言っていた「N-1回交換が必要→閉路グラフ」これに集約されそう。

これでもまだ通らない。
```
4
2 3 4 1
5 6 6 7
```
これがNoになっちゃうはず。
A={2,3,4,1}でA2が{1,2,3,4}なので、1->2->3->4->1で1つのループになる。
だが、今回はA2として{2,1,3,4}のようにしても問題ない。
つまり、ソート済み+1回のswapでもOKなら、ループが1つであってもswapにより2つになるので、yesとなる。
これは一番可能性が高いのは隣り合う要素となるので、隣合う要素を確認して、swapしても問題ないならyesとなる。
ここまでやって、やっとAC
///////////////////////// writeup2 end */
