//https://atcoder.jp/contests/past202004-open/tasks/past202004_c
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
string S[50];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> S[i];

	rrep(y, N - 2, 0) {
		rep(x, 1, 2 * N - 2) if(S[y][x] == '#') {
			bool ok = false;

			if (S[y + 1][x - 1] == 'X') ok = true;
			if (S[y + 1][x] == 'X') ok = true;
			if (S[y + 1][x + 1] == 'X') ok = true;

			if (ok) S[y][x] = 'X';
		}
	}

	rep(y, 0, N) cout << S[y] << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
文字列を扱う問題は慣れないと難しいかと思う。
問題で与えられている操作をシミュレーションしよう。

完全に自分の好みであるが、iをy, jをxを変換して実装をしている。
説明もそれに合わせる。
シミュレーションするだけであるが、
「(y+1,x-1),(y+1,x),(y+1,x+1)のどれかにXが書かれているとき」の判定がややこしいかもしれない。
逆を取って考えてもいいが、自分はこういう場合は「ok := 条件を満たすか」を使って、
ok=falseが初期値で、3つのifを作り、条件を満たせばok=trueとすることをしている。
こうすれば、3つのifのうち、どれかが条件を満たせばok=trueとなる。
あとは、順番にやっていくだけ。
///////////////////////// writeup2 end */
