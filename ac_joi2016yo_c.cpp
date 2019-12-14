//https://atcoder.jp/contests/joi2016yo/tasks/joi2016yo_c
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












int N, M;
string B[50];
//---------------------------------------------------------------------------------------------------
int count(int sy, int ty, char c) { // [sy, ty)
	int res = 0;
	rep(y, sy, ty) rep(x, 0, M) if (B[y][x] == c) res++;
	return res;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M;
	rep(i, 0, N) cin >> B[i];

	int ans = inf;
	rep(white, 1, N) rep(blue, 1, N) {
		int red = N - white - blue;
		if (0 < red) {
			int tot = 0;
			tot += white * M - count(0, white, 'W');
			tot += blue * M - count(white, white + blue, 'B');
			tot += red * M - count(white + blue, white + blue + red, 'R');
			chmin(ans, tot);
		}
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
どこから考えようかという話だが、全探索できそうな所が無いか探そう。
ゴールの形はそんなに状態が無い。
上からwhite行が白で、そこから更にblue行が青であるという風に考えると、
状態空間はO(N^2)くらいで、余裕。
あとは、適切にマスを書き換えるが、これは色があってない所を数えると、その個数が最適な書き換え回数となる。
この書き換え回数の最小値が答え。

count(sy, ty, c) := [sy,ty)行の矩形領域にある種類cのマスの個数
この関数は二次元累積和を使ってもいいが、愚直にループでやっても間に合う。
///////////////////////// writeup2 end */
