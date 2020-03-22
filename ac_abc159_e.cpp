//https://atcoder.jp/contests/abc159/tasks/abc159_e
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














int H, W, K;
string S[10];
//---------------------------------------------------------------------------------------------------
int cnt[11];
int solve(vector<int> grp) {
	int res = 0;
	int x = 0;

	while (x < W) {
		rep(c, 0, 11) cnt[c] = 0;

		int nxt = x;
		rep(xx, x, W) {
			bool ng = false;
			rep(y, 0, H) if (S[y][xx] == '1') {
				cnt[grp[y]]++;
				if (K < cnt[grp[y]]) ng = true;
			}
			if (ng) break;
			chmax(nxt, xx + 1);
		}

		if (nxt == x) return inf;
		x = nxt;

		res++;
	}

	return res - 1;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> H >> W >> K;
	rep(y, 0, H) cin >> S[y];

	int ans = inf;
	rep(div, 0, 1 << (H - 1)) {
		vector<int> grp;
		int g = 1, cnt = 0;
		rep(i, 0, H - 1) {
			grp.push_back(g);
			if (div & (1 << i)) g++, cnt++;
		}
		grp.push_back(g);

		chmin(ans, solve(grp) + cnt);
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
どう見てもHの制約の小ささが気になるので、2^Hを中心に考えてみる。
チョコレートを横に切る操作は2^(H-1)通りあるので、全探索できる。

横にどう切るかを確定させると、縦にどう切るかの最適戦略が存在する。
左から順番にどこから切るか考えていき、ホワイトチョコレートのマスがK個以下となるように
貪欲に切っていけば最適な切り方になる。

よって、横に切る操作を全探索して、それぞれについて、
貪欲に縦に切っていったときの操作の最小回数を取っていくと答えになる。

実装であるが、横に切る操作の全探索は、横に切る場所はH-1箇所で、ビット全探索を使ってやるといい。
切った箇所を境にしてグループに分かれるが、自分は各行について、番号をつけていった。
これで横から貪欲に個数を数えていくときに、配列のその番号の所に個数を足していけば、
グループ毎に個数集計が行える。

todo: 図
///////////////////////// writeup2 end */
