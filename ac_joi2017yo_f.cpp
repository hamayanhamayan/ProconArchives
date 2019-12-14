//https://atcoder.jp/contests/joi2017yo/tasks/joi2017yo_f
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












int N, M, X;
int T[10101];
vector<pair<int, int>> E[10101];
int dist[10101][3][201];
bool vis[10101][3][201];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M >> X;
	rep(i, 0, N) cin >> T[i];
	rep(i, 0, M) {
		int a, b, c; cin >> a >> b >> c;
		a--; b--;
		E[a].push_back({ b, c });
		E[b].push_back({ a, c });
	}

	rep(i, 0, N) rep(lst, 0, 3) rep(x, 0, X + 1) dist[i][lst][x] = inf;
	min_priority_queue<pair<int, pair<int,int>>> que;

	que.push({ 0, {0, 0} });
	dist[0][0][0] = 0;

	while (!que.empty()) {
		auto q = que.top(); que.pop();

		int cst = q.first;
		int cu = q.second.first / 10;
		int lst = q.second.first % 10;
		int x = q.second.second;

		if (vis[cu][lst][x]) continue;
		vis[cu][lst][x] = true;

		fore(p, E[cu]) {
			int to = p.first;
			int len = p.second;

			if (T[to] == 0) {
				if (lst == 2 and x + len < X) continue;
				if (chmin(dist[to][0][0], dist[cu][lst][x] + len)) {
					que.push({ dist[to][0][0], {to * 10 + 0, 0} });
				}
			}
			else if (T[to] == 1) {
				int x2 = min(X, x + len);
				if (chmin(dist[to][lst][x2], dist[cu][lst][x] + len)) {
					que.push({ dist[to][lst][x2], {to * 10 + lst, x2} });
				}
			}
			else {
				if (lst == 0 and x + len < X) continue;
				if (chmin(dist[to][2][0], dist[cu][lst][x] + len)) {
					que.push({ dist[to][2][0], {to * 10 + 2, 0} });
				}
			}
		}
	}

	int ans = inf;
	rep(lst, 0, 3) rep(x, 0, X + 1) chmin(ans, dist[N - 1][lst][x]);
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
パット見てダイクストラ感はある。
状態を考えると、(どの部屋にいるか, 寒すぎる・暑すぎるのどっちが最後か, 寒すぎる・暑すぎるを出てから何分)が状態となりそう。
これは4*10^6であり、ダイクストラするにはちょっと危なそう。
だが、AtCoderの実行時間制限を見ると10sなので、ちょっとの無茶はできる。
実装してみる価値はありそうだ。

注意点としては、状態の何分かはX分より大きい時間は意味を持たないので、その場合は上限のXとしてまとめる。
///////////////////////// writeup2 end */
