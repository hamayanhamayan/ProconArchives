//https://yukicoder.me/problems/no/927
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














string X;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> X;
	sort(all(X), greater<char>());

	string ans = X;

	int n = X.length();
	rrep(i, n - 2, 0) if (ans[i + 1] != ans[i]) {
		swap(ans[i], ans[i + 1]);
		break;
	}

	if (ans == X or ans[0] == '0') cout << -1 << endl;
	else cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
2番目に大きいものとあるが、最も大きいものを考えてみる。
与えられた文字を降順で並べると、最大の数が得られる。
サンプル1にもあるように、最大の321の下2桁をスワップすると、2番目が得られる。
問題は9911のような場合である。
この場合は9191とするのが2番目。
なので、基本的には降順で並べて、下の桁から数の境目を探して、そこだけswapすると答え。
スワップした結果、最大と同じになったり、0-leading（0から始まる）数になったら-1
///////////////////////// writeup2 end */
