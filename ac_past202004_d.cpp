//https://atcoder.jp/contests/past202004-open/tasks/past202004_d
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














string S;
//---------------------------------------------------------------------------------------------------
bool check(string s, string t) {
	int ns = s.length();
	int nt = t.length();

	rep(i, 0, ns - nt + 1) {
		bool ok = true;
		rep(j, 0, nt) {
			if (t[j] == '.') continue;
			if (s[i + j] != t[j]) ok = false;
		}
		if (ok) return true;
	}

	return false;
}
//---------------------------------------------------------------------------------------------------
vector<string> Ts;
void dfs(int cu, string s) {
	if (0 < cu) Ts.push_back(s);
	if (cu == 3) return;

	rep(i, 0, 26) dfs(cu + 1, s + char('a' + i));
	dfs(cu + 1, s + ".");
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> S;

	dfs(0, "");

	int ans = 0;
	fore(T, Ts) if (check(S, T)) ans++;
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
競技プログラミングの基本は全探索である。
文字列Tは全部で27^3+27^2+27通りある。
これはだいたい20000通りくらいであり、一般に10^5くらいまでは全探索余裕なので、これは全探索できる。
なので、文字列Tの全探索が必要となる。
基本的には重複順列の全列挙と同じなので、dfsが典型としてよく使われるので、dfsを使うといい。
他にもキューでBFSをしたり、色々な方法がある。

すべてのTが全列挙できたら、あとは、Sにマッチするものをカウントすればいい。
check(S, T) := TがSにマッチするか
これもSの先頭からTに合うかどうかマッチングを試していく。
Tが.であればチェックをスキップして、そうでないなら、SとTが合うかどうかをチェックしていく。
///////////////////////// writeup2 end */
