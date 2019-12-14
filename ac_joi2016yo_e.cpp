//https://atcoder.jp/contests/joi2016yo/tasks/joi2016yo_e
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
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, M, K, S, P, Q;
vector<int> E[101010];
bool zombie[101010];
//---------------------------------------------------------------------------------------------------
bool danger[101010];
int dist[101010];
void bfs() {
	queue<int> que;

	rep(i, 0, N) {
		if (zombie[i]) {
			dist[i] = 0;
			que.push(i);
		}
		else dist[i] = -1;
	}

	while (!que.empty()) {
		int cu = que.front(); que.pop();

		fore(to, E[cu]) if (dist[to] < 0) {
			dist[to] = dist[cu] + 1;
			que.push(to);
		}
	}

	rep(i, 0, N) if (1 <= dist[i] and dist[i] <= S) danger[i] = true;
}
//---------------------------------------------------------------------------------------------------
bool vis[101010];
ll D[101010];
ll dijk() {
	rep(i, 0, N) D[i] = infl;
	rep(i, 0, N) vis[i] = false;

	min_priority_queue<pair<ll, int>> que;

	D[0] = 0;
	que.push({ 0, 0 });

	while (!que.empty()) {
		auto q = que.top(); que.pop();

		ll cst = q.first;
		int cu = q.second;

		if (cu == N - 1) {
			if (danger[cu]) return cst - Q;
			else return cst - P;
		}

		if (vis[cu]) continue;
		vis[cu] = 1;

		fore(to, E[cu]) {
			if (zombie[to]) continue;

			ll cst2 = cst;

			if (danger[to]) cst2 += Q;
			else cst2 += P;
			
			if (chmin(D[to], cst2)) que.push({ D[to], to });
		}
	}

	return -1;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M >> K >> S >> P >> Q;
	rep(i, 0, K) {
		int c; cin >> c; c--;
		zombie[c] = true;
	}
	rep(i, 0, M) {
		int a, b; cin >> a >> b; a--; b--;
		E[a].push_back(b);
		E[b].push_back(a);
	}

	bfs();
	cout << dijk() << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [複数始点BFS](https://www.hamayanhamayan.com/entry/2018/06/16/093035)
- [ダイクストラ](https://www.hamayanhamayan.com/entry/2017/05/14/134606)
///////////////////////// writeup2 start
まずは危険な街を特定しよう。
これはゾンビの街からKステップで到達可能な所であるが、到達可能性検証といえばBFSなので、
ゾンビの街の複数点を始点とするBFSでKステップ移動し、危険な街を特定しよう。

これで街を訪れたときのコストは特定できた。
後は宿泊費の合計の最小値だが、グラフで最短コストはダイクストラっぽいので、
ダイクストラできそうか考えるとできるので、ダイクストラやると答え。
頂点Nでは一泊する必要はないので、その分は引くこと。
///////////////////////// writeup2 end */
