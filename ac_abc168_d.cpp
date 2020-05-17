//https://atcoder.jp/contests/abc168/tasks/abc168_d
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














int N, M;
vector<int> E[101010];
int ans[101010];
bool vis[101010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M;
	rep(i, 0, M) {
		int a, b; cin >> a >> b;
		a--; b--;
		E[a].push_back(b);
		E[b].push_back(a);
	}

	queue<int> que;
	que.push(0);
	vis[0] = true;

	while (!que.empty()) {
		int cu = que.front(); que.pop();
		fore(to, E[cu]) if (!vis[to]) {
			ans[to] = cu;
			vis[to] = true;
			que.push(to);
		}
	}

	printf("Yes\n");
	rep(i, 1, N) printf("%d\n", ans[i] + 1);
}





/* ///////////////////////// writeup1 start
# 前提知識
- [BFS](https://www.hamayanhamayan.com/entry/2018/06/16/093035)
///////////////////////// writeup2 start
競プロの考察方針の一つとして、典型問題に似ていないかという糸口がある。
今回は、今いる部屋から最短距離で部屋1にたどり着くという条件があるが、最短距離はどのくらいになるだろう。
全ての部屋から部屋1にたどりつくための最短距離を考えたいが、移動が双方向に可能なことから、
部屋1から各部屋にたどりつくための最短距離を考えるのと実質同じであることが言える。
このある始点から移動コスト1で移動したときの最短距離を求めるのは、典型問題であり、
BFSで解けることが知られている。
まず、今回の問題はBFSで最短経路問題を解く方法を知っていると解法が分かりやすい。
これを知らない場合は、まず学習してきてほしい。

これが分かっていれば、今回の答えを導くのはそう難しくない。
BFSで最短距離を計算するときに、遷移元を記憶しておく。
BFSでの最短距離は一般に
dist[i] := 頂点iへの最短距離
visited[i] := 頂点iを既に訪れたか（queueに入れたか）
を計算しながら更新していくが、ここに
pre[i] := 頂点iを更新したときの遷移元
も加えて更新していく。
こうすると、例えば頂点Aに最短距離5で到達していれば、pre[A]は最短距離4で到達することになる。
preをどんどんたどっていけば、頂点1からの最短パスになっているという寸法になる。
これは「DPの復元」という操作でも使えるテクである。
今回は丁度このpreが答えになっているので、BFSをしながら、
ans[i] = pre[i] := 頂点iへの最短距離への遷移元
を作れば答え。
///////////////////////// writeup2 end */
