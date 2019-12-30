//https://codeforces.com/contest/1283/problem/D
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














int N, M, A[201010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M;
	rep(i, 0, N) cin >> A[i];

	set<int> vis;
	map<int, int> dist;
	queue<int> que;

	rep(i, 0, N) {
		vis.insert(A[i]);
		dist[A[i]] = 0;
		que.push(A[i]);
	}

	ll ans1 = 0;
	vector<int> ans2;
	while (!que.empty()) {
		int cu = que.front(); que.pop();

		if (0 < dist[cu]) {
			ans1 += dist[cu];
			ans2.push_back(cu);
			M--;
			if (M == 0) break;
		}

		rep(d, -1, 2) if (d != 0) {
			int nxt = cu + d;
			if (vis.count(nxt)) continue;
			vis.insert(nxt);
			dist[nxt] = dist[cu] + 1;
			que.push(nxt);
		}
	}

	printf("%lld\n", ans1);
	M = ans2.size();
	rep(i, 0, M) {
		if (i) printf(" ");
		printf("%d", ans2[i]);
	}
	printf("\n");
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
人を適切に配置する問題であるが、最適解を考えると、木の周りに順番に人を配置していくのがいいだろう。
木を始点にしてBFSをしていくのがいい。
木の座標が大きいので、setとmapで適当にやっていくと通る。

vis[i] := 座標iに到達済み
dist[i] := 座標iでの木からの最短距離

あとは、queueを使ってBFSをする要領で最短距離であるものを選んで行く。
///////////////////////// writeup2 end */
