//https://atcoder.jp/contests/joi2017yo/tasks/joi2017yo_e
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
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int H, W, A[1010][1010];
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { -1, 0, 1, 0 };
set<int> ponds[1010][1010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> H >> W;
	rep(y, 0, H) rep(x, 0, W) cin >> A[y][x];

	rep(y, 0, H) rep(x, 0, W) {
		bool ok = true;
		rep(d, 0, 4) {
			int xx = x + dx[d];
			int yy = y + dy[d];
			if (0 <= xx and xx < W and 0 <= yy and yy < H) {
				if (A[y][x] > A[yy][xx]) ok = false;
			}
		}
		if (ok) ponds[y][x].insert(y * W + x);
	}

	vector<pair<int, int>> ord;
	rep(y, 0, H) rep(x, 0, W) ord.push_back({ A[y][x], y * W + x });
	sort(all(ord));

	fore(p, ord) {
		int x = p.second % W;
		int y = p.second / W;

		rep(d, 0, 4) {
			int xx = x + dx[d];
			int yy = y + dy[d];
			if (0 <= xx and xx < W and 0 <= yy and yy < H) {
				if (A[y][x] < A[yy][xx]) {
					fore(pond, ponds[y][x]) ponds[yy][xx].insert(pond);
					while (2 < ponds[yy][xx].size()) {
						ponds[yy][xx].erase(ponds[yy][xx].begin());
					}
				}
			}
		}
	}

	int ans = 0;
	rep(y, 0, H) rep(x, 0, W) if (2 <= ponds[y][x].size()) ans++;
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
まず、順当に考えると、座標を全探索して、シミュレーションをして、その座標が尾根であるかを判定する。
どのようにシミュレーションするかであるが、雨水が通過するというのは、その座標から到達可能であるとも言える。
到達可能性解析といえば、幅優先探索。
幅優先探索をして、雨水が溜まる部分に複数箇所到達可能なら尾根である。
これをやるとO(H^2W^2)なので厳しい。

ありがちな方針ではあるが、始点は尾根であるかは事前に分からないが、終点が溜まる場所であることは事前にわかる。
つまり、溜まる場所を始点として考えてみると考えやすいのではないか。
幅優先探索を逆に行ってみる。
標高が低い所から高い所へ逆流させよう。
このときに、どの溜まる場所から逆流してきたかを保存しておこう。
もし、3つ以上の場所から逆流してきた場合は、尾根判別をしたいだけなので、2つだけ保持しておけばいい。
これで、全ての場所について、溜まる場所について特定ができるので、2つ以上溜まる場所があるなら尾根として計上する。

幅優先するときは、逆順にやるのが面倒なので、全て異なる数であることを利用して、小さい数から順番に操作を行えばいい。
///////////////////////// writeup2 end */
