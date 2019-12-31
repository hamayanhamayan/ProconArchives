//https://atcoder.jp/contests/past201912-open/tasks/past201912_k
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














int N, Q;
vector<int> E[151010];
//---------------------------------------------------------------------------------------------------
int L[401010], R[401010];
int idx = 0;
void euler(int cu, int pa = -1) { // [L[v],R[v])
	L[cu] = idx; idx++;
	for (int to : E[cu]) if (to != pa) euler(to, cu);
	R[cu] = idx;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	int root = -1;
	rep(i, 0, N) {
		int p; cin >> p;
		p--;

		if (p < 0) root = i;
		else {
			E[p].push_back(i);
			E[i].push_back(p);
		}
	}
	euler(root);

	cin >> Q;
	rep(_, 0, Q) {
		int a, b; cin >> a >> b; a--; b--;

		if(L[b] <= L[a] and R[a] <= R[b]) printf("Yes\n");
		else printf("No\n");
	}
}





/* ///////////////////////// writeup1 start
# 前提知識
- [オイラーツアー](https://www.hamayanhamayan.com/entry/2017/04/10/163548)
///////////////////////// writeup2 start
この問題はN頂点の木に帰着させることができる。
まずは、この帰着が見えないと、解くのは難しいかもしれない。
木であることを考えると、根をどこにするかを考える必要があるが、根としてふさわしそうな頂点を探すと、
特徴があるのは社長だけで、上司を持たないということもあり、これを根として採用すれば良さそう。
すると、社員aが社員bの部下であるかを判定するには、頂点bの部分木に頂点aが含まれるかを判定すればいい。
これを判定する方法は色々あるが、一番いい感じなのが、オイラーツアーである。
他にも、「クエリを先読みしておいて、setで頂点を保存しながら答えを求める」とか
「LCAと頂点間距離を上手く使って答える」とか色々ある。
///////////////////////// writeup2 end */
