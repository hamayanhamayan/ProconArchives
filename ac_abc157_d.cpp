//https://atcoder.jp/contests/abc157/tasks/abc157_d
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
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, M, K, A[101010], B[101010], C[101010], D[101010];
int ans[101010];
set<int> friends[101010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M >> K;
	rep(i, 0, M) cin >> A[i] >> B[i], A[i]--, B[i]--;
	rep(i, 0, K) cin >> C[i] >> D[i], C[i]--, D[i]--;

	UnionFind uf(N);
	rep(i, 0, M) uf(A[i], B[i]);

	rep(i, 0, N) ans[i] = uf.getValues(i) - 1;
	rep(i, 0, M) {
		ans[A[i]]--;
		ans[B[i]]--;
		friends[A[i]].insert(B[i]);
		friends[B[i]].insert(A[i]);
	}
	rep(i, 0, K) if (!friends[C[i]].count(D[i]) && uf[C[i]] == uf[D[i]]) {
		ans[C[i]]--;
		ans[D[i]]--;
	}

	rep(i, 0, N) {
		if(i) printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
}





/* ///////////////////////// writeup1 start
# 前提知識
- [UnionFind](https://www.hamayanhamayan.com/entry/2017/10/04/101826)
///////////////////////// writeup2 start
実装が結構厳しい。
条件に番号を付けておこう。

条件1 aとbはブロック関係じゃない
条件2 aとbは直接交友関係じゃない
条件3 aとbは間接的に交友関係である

間接的に交友関係であるかを確かめるのには、UnionFindを用いる。
これがまず思いつかないと解くのは難しいだろう。

よって、交友関係でUnionFindをしていき、各成分の個数が答えに近いものになる。
「近いもの」と書いたのは、条件を満たさないものを含むためである。
交友関係でUnionFindをして個数を数えると、aとbが交友関係であるものの個数が得られる
（-1しているのは、自分を引くため）

まずは直接交友関係であるものを引いていこう。
全部の組に対してチェックするとN^2通りとなって、よくない。
交友関係はM通りしかないのだから、この交友関係について答えから引いていこう。
この時に、ある人の直接の友達リストを作成しておく。
friends[i] := iさんの直接の友達リスト

これで条件2と条件3を満たす人物は数えることができたが、条件1を満たさないものが混じっている。
引くべきは「!条件1 && 条件2 && 条件3」の組み合わせである。
!条件1はブロック関係であるということなので、与えられているブロック関係リストを全探索すれば、
その関係についてはすべて!条件1を満たす。
条件2は先ほど作ったfriends配列を使えば判定できるし、条件3はunionfindを使えば判定できる。
これで、条件を満たすものに対して答えを引くと、目標の答えが得られる。
///////////////////////// writeup2 end */
