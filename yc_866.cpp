//https://yukicoder.me/problems/no/866
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
#pragma GCC optimize ("-O3")
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










int H, W, K;
string C[2010];
//---------------------------------------------------------------------------------------------------
int buf[2010][2010][26];
void init() {
	rep(y, 0, H) rep(x, 0, W) buf[y + 1][x + 1][C[y][x] - 'a']++;
	rep(c, 0, 26) rep(y, 1, H + 2) rep(x, 1, W + 2) {
		buf[y][x][c] += buf[y - 1][x][c] + buf[y][x - 1][c] - buf[y - 1][x - 1][c];
	}
}
//---------------------------------------------------------------------------------------------------
inline int binarySearch(int x, int y, int l, int r, int limit) { //[l,r)
	int ng = l - 1, ok = r;
	while (ng + 1 != ok) {
		int md = (ng + ok) / 2;

		int res = 0;
		rep(c, 0, 26) if (0 < buf[y + md][x + md][c] - buf[y + md][x][c] - buf[y][x + md][c] + buf[y][x][c]) res++;

		if (limit <= res) ok = md;
		else ng = md;
	}

	return ok;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> H >> W >> K;
	rep(y, 0, H) cin >> C[y];

	init();

	ll ans = 0;
	rep(y, 0, H) rep(x, 0, W) {
		int maxlen = min(W - x, H - y);
		ans += binarySearch(x, y, 1, maxlen + 1, K + 1) - binarySearch(x, y, 1, maxlen + 1, K);
	}
	cout << ans << endl;
}






/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
結構計算量が厳しいらしいので、ゴリゴリ計算系であろうと思う。
全探索で考えると、左上をHW通り試し、正方形の一片を試してmin(W,H)通り試す。
これだと間に合わない。
間に合わないが、正方形の一片をどんどん大きくしていくと、種類数はどんどん増えていく。
二分探索すればちょうどP種類の時が見つけられる。
あとは、区間にある種類数を高速に求めたい。
26種類を二次元累積和で管理して、何種類あるか求めよう。
これで計算量はO(HWlog(H+W)26)という感じで、間に合うかだいぶ怪しい。
実際出しても間に合わない。
間に合わないが、二次元累積和の添え字を入れ替えて、メモリのキャッシュ効率を良くすると通る。
///////////////////////// writeup2 end */	