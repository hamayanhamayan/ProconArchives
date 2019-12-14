//https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_d
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
		if (cu == inf) return inf;
		if (cu < 0) {
			if (S[0] == c) return 0;
			cu = 0;
		}
		return migi[c][cu];
	}
    inline int gohidari(int cu, int c) {
		if (cu < 0) return cu;
		return hidari[c][cu];
	}
};
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
void _main() {
	cin >> N >> S;

	fore(c, S) c -= '0';
	StringMaster sm(S);

	int ans = 0;
	rep(x0, 0, 10) rep(x1, 0, 10) rep(x2, 0, 10) {
		int cu = -1;
		cu = sm.gomigi(cu, x0);
		cu = sm.gomigi(cu, x1);
		cu = sm.gomigi(cu, x2);
		if (cu < inf) ans++;
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
3桁を指定するのはO(N^3)かかってしまう。
だが、答えの組み合わせに注目してみると、10^3通りある。
これなら全探索できるので、10^3通りで作れるかどうか試してみる。
全ての文字について、次にある文字が出てくる最近の添字を覚えておく。
すると、先頭から3つの数を貪欲に探していくのをO(1)できる。
自分はこのへんはライブラリにしてるので、貼るだけ。
///////////////////////// writeup2 end */
