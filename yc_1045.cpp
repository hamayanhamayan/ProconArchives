//https://yukicoder.me/problems/no/1045
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














int N, ABC[16][3];
int dp[1 << 16][16][3];
bool ok[16][3][16][3];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) rep(j, 0, 3) cin >> ABC[i][j];

	rep(lst, 0, N) rep(hei, 0, 3) rep(nxt, 0, N) rep(hei2, 0, 3) {
		vector<int> v1;
		rep(j, 0, 3) if (hei != j) v1.push_back(ABC[lst][j]);
		sort(all(v1));

		vector<int> v2;
		rep(j, 0, 3) if (hei2 != j) v2.push_back(ABC[nxt][j]);
		sort(all(v2));

		if (v2[0] <= v1[0] && v2[1] <= v1[1]) ok[lst][hei][nxt][hei2] = true;
		if (v2[1] <= v1[0] && v2[0] <= v1[1]) ok[lst][hei][nxt][hei2] = true;
	}

	rep(msk, 0, 1 << N) rep(lst, 0, N) rep(hei, 0, 3) dp[msk][lst][hei] = -1;
	rep(lst, 0, N) rep(hei, 0, 3) dp[1 << lst][lst][hei] = ABC[lst][hei];

	rep(msk, 0, 1 << N) rep(lst, 0, N) rep(hei, 0, 3) if (0 <= dp[msk][lst][hei]) {
		rep(nxt, 0, N) if (!(msk & (1 << nxt))) rep(hei2, 0, 3) {
			if (ok[lst][hei][nxt][hei2]) {
				int msk2 = msk | (1 << nxt);
				chmax(dp[msk2][nxt][hei2], dp[msk][lst][hei] + ABC[nxt][hei2]);
			}
		}
	}

	int ans = -1;
	rep(msk, 0, 1 << N) rep(lst, 0, N) rep(hei, 0, 3) chmax(ans, dp[msk][lst][hei]);
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [bitDP](https://www.hamayanhamayan.com/entry/2017/07/16/130151)
///////////////////////// writeup2 start
制約からbitDPを感じるので、その方針で考えるとできる。
遷移込みで状態を考えると、以下のようにすればいいと分かる。
dp[msk][lst][hei] := 使用済みの直方体の集合がmskで、一番上に置いてあるのがlst番目で、高さがhei番目の辺になっているときの高さの最大値
入力のA,B,Cを0番目,1番目,2番目として取り込んでおく。
このようにDPを作成すると、DPの遷移先は、mskに入っていない直方体を置くことになる。
どの辺を縦にするかの置き方で更に3通りの遷移先となる。

ここで、「一番上に置いてあるlst番目の直方体が縦にhei番目の辺が使われていて、その上にnxt番目の直方体が縦にhei2番目の辺を使うように置けるか」というのが知りたくなる。
DPの中身でこれを判定したらTLEしちゃったので、前計算しておこう。
ok[lst][hei][nxt][hei2] := 一番上に置いてあるlst番目の直方体が縦にhei番目の辺が使われていて、その上にnxt番目の直方体が縦にhei2番目の辺を使うように置けるか
どんなふうにやってもいいのだが、lst番目のhei以外の辺2つとnxt番目のhei2以外の辺2つを取ってきて、どっちの辺もnxt≦heiになるようなパターンがあるかを判定すればいい。
///////////////////////// writeup2 end */
