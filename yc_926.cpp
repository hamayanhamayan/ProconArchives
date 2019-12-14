//https://yukicoder.me/problems/no/926
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














int A, B, C;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> A >> B >> C;

	int tot = 0;
	rep(top, 0, B) {
		rep(d, 0, A) {
			int td = (top + d) % B;
			if (td < C) tot++;
		}
	}
	double ans = 1.0 * tot / B;
	printf("%.8f\n", ans);
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
最後の「一週間の内の休日の位置が変わった場合でも平均の休日数は変わらないことが証明できます。」が
あるおかげで簡単に解けそうだ。
一週間の先頭C日間が休日として問題なさそう。
平均を取る必要があり、パターンを考える。
一年の最初の日が、一週間の何日目かを考えれば良さそう。
///////////////////////// writeup2 end */
