//https://yukicoder.me/problems/no/867
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
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { -1, 0, 1, 0 };
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int H, W, gx, gy, A[251][251], Q, X[501010], Y[501010], K[501010];
ll ans[1010101];
vector<int> query[1010101];
int threshold = 300;
//---------------------------------------------------------------------------------------------------
ll dst[251][251]; bool vis[251][251]; int idx[251][251];
void _main() {
	cin >> H >> W >> gy >> gx; gx--; gy--;
	rep(y, 0, H) rep(x, 0, W) cin >> A[y][x];
	cin >> Q;
	rep(i, 0, Q) cin >> Y[i] >> X[i] >> K[i], X[i]--, Y[i]--;

	rep(q, 0, Q) query[K[q]].push_back(q);

	// small pattern
	rep(k, 1, threshold) {
		if (query[k].size() == 0) continue;

		rep(y, 0, H) rep(x, 0, W) dst[y][x] = infl, vis[y][x] = false;
		min_priority_queue<pair<ll, int>> que;

		dst[gy][gx] = k * k + A[gy][gx];
		que.push({ dst[gy][gx], gy * W + gx });

		while (!que.empty()) {
			auto q = que.top(); que.pop();

			ll cst = q.first;
			int y = q.second / W;
			int x = q.second % W;

			if (vis[y][x]) continue;
			vis[y][x] = true;

			rep(d, 0, 4) {
				int xx = x + dx[d];
				int yy = y + dy[d];
				if (0 <= xx and xx < W and 0 <= yy and yy < H) {
					if (chmin(dst[yy][xx], cst + A[yy][xx] + k * k)) {
						que.push({ dst[yy][xx] , yy * W + xx});
					}
				}
			}
		}

		fore(q, query[k]) ans[q] = dst[Y[q]][X[q]];
	}

	queue<pair<int, int>> que;
	rep(y, 0, H) rep(x, 0, W) dst[y][x] = infl, vis[y][x] = false;

	que.push({ gx, gy });
	dst[gy][gx] = A[gy][gx]; vis[gy][gx] = true; idx[gy][gx] = 0;

	while (!que.empty()) {
		int x, y;
		tie(x, y) = que.front(); que.pop();

		rep(d, 0, 4) {
			int xx = x + dx[d];
			int yy = y + dy[d];
			if (0 <= xx and xx < W and 0 <= yy and yy < H) {
				if (!vis[yy][xx]) {
					que.push({ xx, yy });
					vis[yy][xx] = true;
					idx[yy][xx] = idx[y][x] + 1;
				}
				if(idx[y][x] + 1 == idx[yy][xx]) chmin(dst[yy][xx], dst[y][x] + A[yy][xx]);
			}
		}
	}

	// big pattern
	rep(k, threshold, 1010101) fore(q, query[k]) {
		int x = X[q], y = Y[q];
		ans[q] = dst[y][x] + 1LL * (abs(y - gy) + abs(x - gx) + 1) * k * k;
	}

	rep(i, 0, Q) printf("%lld\n", ans[i]);
}



















/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
まず、やはり気になるのは、制約である。
K^2がついているし、かつ、A[i][j]の値がとても小さい。
これはKが増えれば増えるほど、K^2による影響が増えていきそう。
なので、あるKを境に計算方法を変えるテクかもという感じ。

問題はKの境目をどのくらいにするかというところだが、これは計算量を考えて、決めよう。
俺は証明ができない。
あと、クエリ毎に始点が決まっているが、最短経路問題ではこれは厄介。
(gx, gy)を始点として、クエリ毎を終点とすれば、単一始点最短経路問題となり扱いやすい。
今後は始点終点を逆にして考えよう。

Kがある境目より小さい場合はどのようなアプローチがあるだろうか。
問題を典型的に考えると、無向グラフでの単一始点最短経路なので、ダイクストラが適用できそう。
Kが固定されていると、O(HWlog(HW))で解ける。
これは最大で3*10^5くらい。
10^7くらいを目指せばいいので、この操作は100回くらいならできそう。

Kがある境目より大きい場合は、K^2によるコストが支配的になる。
なので、ある頂点に向かうときは、移動回数が少ないほうが最良となる。
(sx,sy)から(gx,gy)へ最小回数で移動する経路のうちA[i][j]の総和の最小値を持っておけば、
K^2×移動回数を加えるだけで答えが得られる。
これは事前計算を1回しておけば答えることができる。
こっちは計算コストはそんなにかからない。

よって、Kがある境目より小さい場合が計算量が支配的であるので、なるべくKは大きくすることがいい。
ギリギリが10^8くらいであるので、300回くらいが限界そう。
境目は300としておこう。これで出すとWAで、800msくらいだった。
境界値1000くらいならいけそう。あれ、WA。通っているケースも増えてないし、TLEもある。
境目は300でいいのか。何かバグってた。
///////////////////////// writeup2 end */
