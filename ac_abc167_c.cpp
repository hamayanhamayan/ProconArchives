//https://atcoder.jp/contests/abc167/tasks/abc167_c
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














int N, M, X;
int C[12], A[12][12];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M >> X;
	rep(i, 0, N) {
		cin >> C[i];
		rep(j, 0, M) cin >> A[i][j];
	}

	int ans = inf;
	rep(msk, 0, 1 << N) {
		int cst = 0;
		vector<int> rikai(M, 0);

		rep(i, 0, N) if (msk & (1 << i)) {
			cst += C[i];
			rep(j, 0, M) rikai[j] += A[i][j];
		}

		bool ok = true;
		rep(i, 0, M) if (rikai[i] < X) ok = false;
		if (ok) chmin(ans, cst);
	}

	if (ans == inf) ans = -1;
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
bit全探索というのが分かっていないと、難しいと思う。
bit全探索については各所でやり方が紹介されているので、ググって勉強してみてほしい。
今回のような、N個のものから任意個を取り出すという組合せを全探索する手法である。
N=22くらいがギリギリ限界くらいの全探索方法である。
今回は、参考書の買い方は最大2^12通りであり、これは全探索できる。

買う参考書の組が固定されてしまえば、必要な金額は計算できるし、各アルゴリズムの理解度も計算できる。
よって、すべての組について、金額と理解度を計算して、理解度がすべてXを超えている金額の最小値を答えると答え。
///////////////////////// writeup2 end */
