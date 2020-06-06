//https://atcoder.jp/contests/past202005-open/tasks/past202005_d
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












int N;
string S[5];
string test[5] = {
	".###..#..###.###.#.#.###.###.###.###.###.",
	".#.#.##....#...#.#.#.#...#.....#.#.#.#.#.",
	".#.#..#..###.###.###.###.###...#.###.###.",
	".#.#..#..#.....#...#...#.#.#...#.#.#...#.",
	".###.###.###.###...#.###.###...#.###.###."
};
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, 5) cin >> S[i];

	string ans = "";
	rep(j, 0, N) {
		int L = j * 4;
		rep(c, 0, 10) {
			bool ok = true;
			rep(y, 0, 4) rep(x, 0, 5) if (S[x][j * 4 + y] != test[x][c * 4 + y]) ok = false;
			if (ok) ans += char('0' + c);
		}
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
パターンマッチングを頑張る問題。
パターンマッチングなので、数と対応した文字列を紐づける必要があるが、
丁度入力例1で0から順に整備されたやつがあるので、使おう。

それベースで見ると、横4縦5で数字が表現されている。
なので、マッチングするかは、このサイズで比較すればいいだろう。
後は、頑張ってマッチングしていくだけなのだが、何とも説明しようがない。
ok := マッチングしているか
ok変数をtrueにしといて、長方形をクロールして違っている所があればok=falseにしている。
全部あってればokがtrueのはずなので、そうなったら答えにその数を入れ込む。
///////////////////////// writeup2 end */
