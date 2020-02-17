//https://atcoder.jp/contests/abc155/tasks/abc155_f
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
	using T = int;
	const T def = 0;
	T f(T a, T b) { return a + b; }
	//==========================================
    vector<int> par; 
	vector<T> value;
    UnionFind() {}
    UnionFind(int NV) { init(NV); }
	void init(int NV) { par.clear(); rep(i, 0, NV) par.push_back(i); value.resize(NV, 1); }
    void reset() { rep(i, 0, par.size()) par[i] = i; }
	int operator[](int x) {
		if (par[x] == x) return x;
		else {
			int res = operator[](par[x]);
			if (res != par[x]) {
				value[res] = f(value[res], value[par[x]]);
				value[par[x]] = def;
			}
			return par[x] = res;
		}
	}
	// uf(x,y)->y
    void operator()(int x, int y) {
		x = operator[](x); y = operator[](y); 
		if (x != y) {
			value[y] += value[par[x]];
			value[par[x]] = def;
			par[x] = y;
		}
	}
	T getValues(int x) { return value[operator[](x)]; };
};
vector<int> compress1(int* v, int n) {
	vector<int> dic;
	rep(i, 0, n) dic.push_back(v[i]);
	sort(all(dic));
	dic.erase(unique(all(dic)), dic.end());
	rep(i, 0, n) v[i] = lower_bound(all(dic), v[i]) - dic.begin();
	return dic;
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














int N, M, A[101010], B[101010], L[201010], R[201010];
int bombs[101010], diff[101010];
//---------------------------------------------------------------------------------------------------
UnionFind uf2;
set<int> E[101010];
vector<int> solve(vector<int> ps, vector<int> es) {
	vector<int> res;
	fore(i, es) {
		int l = L[i];
		int r = R[i];
		if (uf2[l] == uf2[r]) continue;

		uf2(l, r);
		E[l].insert(i);
		E[r].insert(i);
	}

	queue<int> que;
	fore(p, ps) if (E[p].size() == 1) que.push(p);

	while (!que.empty()) {
		int cu = que.front(); que.pop();
		if (E[cu].size() == 0) continue;
		int i = *E[cu].begin();
		int to = (L[i] == cu) ? R[i] : L[i];

		if (diff[cu] == 1) {
			diff[cu] ^= 1;
			diff[to] ^= 1;
			res.push_back(i);
		}

		E[cu].erase(i);
		E[to].erase(i);

		if (E[to].size() == 1) que.push(to);
	}

	return res;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M;
	rep(i, 0, N) cin >> A[i] >> B[i];
	rep(i, 0, M) cin >> L[i] >> R[i];

	// 座標圧縮して、[L,R]をそれに合わせて変換する
	auto dic = compress1(A, N);
	rep(i, 0, M) {
		L[i] = lower_bound(all(dic), L[i]) - dic.begin();
		R[i] = upper_bound(all(dic), R[i]) - dic.begin();
	}

	// XOR差をとる
	rep(i, 0, N) if (B[i] == 1) bombs[A[i]] = 1;
	diff[0] = bombs[0];
	rep(i, 1, N) diff[i] = bombs[i - 1] ^ bombs[i];

	// 連結成分ごとに分ける
	UnionFind uf(N + 1);
	uf2.init(N + 1);
	rep(i, 0, N) if (diff[i] == 0) uf.value[i] = 0;
	rep(i, 0, M) if(L[i] != R[i]) if(R[i] != N) uf(L[i], R[i]);

	// diffのN番目はなんでも大丈夫なので、ONの個数調整のためにメモる
	map<int, vector<int>> lasts;
	rep(i, 0, M) if (L[i] != R[i]) if (R[i] == N) lasts[uf[L[i]]].push_back(i);

	// 連結成分ごとに頂点集合を作る
	map<int, vector<int>> ps;
	rep(i, 0, N) ps[uf[i]].push_back(i);

	// 連結成分ごとに辺集合を作る
	map<int, vector<int>> es;
	rep(i, 0, M) if (L[i] != R[i]) if(uf[L[i]] == uf[R[i]]) es[uf[L[i]]].push_back(i);

	// 連結成分ごとにONの個数が偶数個か確認
	vector<int> ans;
	rep(i, 0, N) if(uf[i] == i) {
		if (uf.getValues(i) % 2 == 1) {
			if (lasts[i].size() == 0) {
				printf("-1\n");
				return;
			}
			ans.push_back(*lasts[i].begin());
			diff[L[*lasts[i].begin()]] ^= 1;
		}
		auto res = solve(ps[i], es[i]);
		fore(x, res) ans.push_back(x);
	}
	
	// 答える
	sort(all(ans));
	int n = ans.size();
	printf("%d\n", n);
	rep(i, 0, n) {
		if(i) printf(" ");
		printf("%d", ans[i] + 1);
	}
	printf("\n");
}





/* ///////////////////////// writeup1 start
# 前提知識
- 座標圧縮
- [UnionFind](https://www.hamayanhamayan.com/entry/2017/10/04/101826)
///////////////////////// writeup2 start
やっとAC。実装がきつい。

[公式解説](https://www.youtube.com/watch?v=SG60Cp9pSog&feature=youtu.be)の副読解説です。
まずは、動画解説見ることをお勧めします。
最初にテクニックを抽出しておく。

- 座標圧縮や区間の簡略化のような前処理は先に済ませて問題を簡単にしておこう
- 区間に対する操作は隣り合う要素の差をとることで、始点と終点の2点操作にできる

基本の解説は公式解説を見ましょう読みましょう…
たぶん考察過程としては、「区間に対する操作は隣り合う要素の差をとることで、始点と終点の2点操作にできる」
が出てこないと厳しいかもしれない。
imos法が理解できてると、このテクもすんなり受け入れることができるかと思う。

コードに埋め込みでコメントを入れてあるので、それを見ながら実装を追って行ってほしい。
注意点は以下の通り。

- L[i],R[i]が座標圧縮後のものになっているが、[ L[i], R[i] )になってる
- diff[N]は1である必要はないので、そのあたりで色々処理を追加している
- 隣接リストを作っているが、`E[cu] := 頂点cuから伸びる辺のインデックス`のようになっているので注意

最後のsolve関数であるが、解説にあるように次数が1になったものからqueueでとってきている。
だが、実際はdfsでも作ることができ、そっちのほうがはるかに簡単。
気持ち的にはlowlinkの時に無向グラフ上を木みたいにdfsすると思うが、そんな感じで探索していって、
葉に到達したら、操作を行いながら、根に戻っていく感じ。
[kmjpさんの解説](http://kmjp.hatenablog.jp/entry/2020/02/17/0930)がそのようになっている。
さすがだ…
///////////////////////// writeup2 end */
