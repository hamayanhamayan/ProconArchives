//https://yukicoder.me/problems/no/1016
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














int N; string S;
//---------------------------------------------------------------------------------------------------
#define ok "O"
#define ng "X"
string solve() {
	cin >> N >> S;

	vector<string> wins = {"ooo", "-oo", "oo-", "-o--", "--o-"};
	fore(win, wins) rep(i, 0, N) if (S.substr(i, win.size()) == win) return ok;

	vector<int> winvec;
	rep(i, 0, N) if (S[i] == 'o') winvec.push_back(i);

	int n = winvec.size();
	rep(i, 0, n - 1) {
		int st = winvec[i];
		int en = winvec[i + 1];
		int lose = 0, blank = 0;
		rep(j, st + 1, en) {
			if (S[j] == 'x') lose++;
			else blank++;
		}
		if (lose == 0 && blank % 2 == 1) return ok;
	}

	return ng;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	int T; cin >> T;
	rep(t, 0, T) cout << solve() << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
貪欲法で解けそう。
まずは自明な所から考えてみる。

既にoooがあるなら勝っているし、どこか1マスにoを入れれば勝てるなら勝ち。
複数手で勝てる手を考える。

3手詰めは？
`-o--`
この状況であれば3手詰めができる。
実はまだある。
`o---o`
これを思いつくのがきついが、詰めるためには毎回王手をかける必要がある。
それは`oo-`を作るか、`o-o`を作るしかないので、その辺から考えていく。

5手詰めは？
`o-----o`

7手詰めは？
`o-------o`

他にもあるかもしれないが、それっぽい規則性も見えたところで、出してみる。
以上の詰めパターンがあるならOが答え。
無ければX
///////////////////////// writeup2 end */
