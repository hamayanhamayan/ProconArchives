//https://yukicoder.me/problems/no/987
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














int N, M;
char op;
ll B[101], A[101];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M >> op;
	rep(i, 0, M) cin >> B[i];
	rep(i, 0, N) cin >> A[i];

	rep(y, 0, N) {
		rep(x, 0, M) {
			if(x) printf(" ");
			
			if (op == '+') printf("%lld", A[y] + B[x]);
			else printf("%lld", A[y] * B[x]);
		}
		printf("\n");
	}
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
すべての要素を愚直に計算しても、10^4通りなので行っても問題ない。
注意点としては、積の場合はlong longでやらないと、オーバーフローする。
///////////////////////// writeup2 end */
