//https://codeforces.com/contest/1286/problem/B
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














int N;
vector<int> E[2010];
int C[2010];
//---------------------------------------------------------------------------------------------------
int ans[2010];
void dfs2(int cu, int lim) {
	if (lim <= ans[cu]) ans[cu]++;
	fore(to, E[cu]) dfs2(to, lim);
}
int dfs(int cu, int base = 0) {
	int cnt = 0;
	fore(to, E[cu]) cnt += dfs(to, base + cnt);
	if (cnt < C[cu]) {
		cout << "NO" << endl;
		exit(0);
	}
	fore(to, E[cu]) dfs2(to, base + C[cu] + 1);
	ans[cu] = base + C[cu] + 1;
	return cnt + 1;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	int root;

	cin >> N;
	rep(i, 0, N) {
		int p; cin >> p >> C[i];
		p--;
		if (p < 0) root = i;
		else E[p].push_back(i);
	}

	dfs(root);

	printf("YES\n");
	rep(i, 0, N) {
		if(i) printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
手がつかない問題は何かを仮定して考えていくしか無い。
まず、構築可能そうな場合は構築可能であるという仮定である。
子の個数<C[i]であることはありえない。
これは自明で構築不可能。
だが、逆はどうだろう。逆はよくわからないが、構築可能であると仮定しよう。
これは構築する仮定で必ず構築できるという確信ができてくるのだが、凡人はこうやっていくしかない。

さて、木構造の問題であるため、きっとDFSで作っていくんだろうと考える。
そして、木の葉は必ずC[i]=0であり、そこが真っ先に確定していきそうな感じがする。
ここから、DFSをしていって深いところから順に作っていくんだろうなと仮定して考えていく。
すると、ある頂点iの数を確定する時は既に部分木がすべて確定していることになる。
順に作っていくときに1から順に割り当てていくが、ある頂点iを確定する時は、
ある数xよりも小さい数が部分木に割り当てられている。
ある頂点iに割り当てる数は、その中でC[i]+1番目になればいいので、C[i]+1番目以上の数を1つずつずらす。
部分木のある値以上の数をインクリメントするにはO(N)でできるので、木の探索O(N)でインクリメントO(N)なので、
O(N^2)で間に合う。
///////////////////////// writeup2 end */
