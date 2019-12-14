//https://atcoder.jp/contests/abc138/tasks/abc138_e
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
struct StringMaster {
    string S; int N; StringMaster() {}StringMaster(string s) { init(s); }
    void init(string s) { S = s; N = S.length(); initgo(); }

    // get the nearest index for the char
    vector<int> hidari[26], migi[26];
    inline void initgo() {
        rep(c, 0, 26) { migi[c].resize(N); migi[c][N - 1] = inf; }
        rrep(i, N - 2, 0) { rep(c, 0, 26) migi[c][i] = migi[c][i + 1]; migi[S[i + 1]][i] = i + 1; }
        rep(c, 0, 26) { hidari[c].resize(N); hidari[c][0] = -1; }
        rep(i, 1, N) { rep(c, 0, 26) hidari[c][i] = hidari[c][i - 1]; hidari[S[i - 1]][i] = i - 1; }
    }
    inline int gomigi(int cu, int c) { 
		if (cu < 0) {
			if (S[0] == c) return 0;
			cu = 0;
		}
		return migi[c][cu];
	}
    inline int gohidari(int cu, int c) { return hidari[c][cu]; }
};
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














string S, T;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> S >> T;
	fore(c, S) c -= 'a';
	fore(c, T) c -= 'a';
	StringMaster sm(S);

	ll ans = 0;
	int cu = -1;
	rep(i, 0, T.size()) {
		int c = T[i];
		int to = sm.gomigi(cu, c);
		if (cu < 0 and to == inf) {
			cout << -1 << endl;
			return;
		}

		if (to == inf) {
			ans += S.length() - cu - 1;
			cu = -1;
			i--;
			continue;
		}

		ans += to - cu;
		cu = to;
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
文字列tを先頭から貪欲にs'からとっていく。
貪欲にとるためには、文字列sのある場所から一番近いどころにある、とある文字の座標を取ってくる操作が必要である。
これは累積和を使えば実現可能。
具体的には、`migi[cu][c] := cu文字目より右にある文字cの座標`を作る。
これはA[i] = cであるとき、`migi[i - 1][c] = i`が言える。
これをすべての文字について行い、chmin(migi[i][c], migi[i - 1][c])として累積和的に更新していけばいい。
自分はStringMasterとしてライブラリ整備してるので、これを使って貪欲にとっていった。
///////////////////////// writeup2 end */
