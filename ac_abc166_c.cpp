//https://atcoder.jp/contests/abc166/tasks/abc166_c
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














int N, M, H[101010];
vector<int> E[101010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M;
	rep(i, 0, N) cin >> H[i];
	rep(i, 0, M) {
		int a, b; cin >> a >> b;
		a--; b--;
		E[a].push_back(b);
		E[b].push_back(a);
	}

	int ans = 0;
	rep(cu, 0, N) {
		bool ok = true;
		fore(to, E[cu]) if (H[cu] <= H[to]) ok = false;
		if (ok) ans++;
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
今回の問題が解けなかった場合は、この問題よりも競プロにおけるdfsの書き方を学ぶことをお勧めする。
そちらの方が資料が多いためだ。
そちらの解き方が分かっていれば、この問題を解くのは難しくない。

各頂点について、そこから遷移できる頂点について、標高の高さを比較する愚直解法を書けばいい。
教育的な部分があるとすると、無向グラフの辺表現であろう。
隣接行列での表現と、隣接リストでの表現の2種類がある。
dfsを学んだ人は、そもそも隣接行列についてはしらないように思うので、普通にdfsするように解法を作ればいい。
隣接グラフを使ってdfsをすると計算量はO(M)となるので、間に合う。
（ちなみに隣接行列でやると、O(N^2)となってしまう）
///////////////////////// writeup2 end */
