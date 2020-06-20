//https://yukicoder.me/problems/no/1082
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














int N, A[201010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> A[i];

	int ans = -1;
	rep(a, 0, N) rep(b, a + 1, N) chmax(ans, A[a] ^ A[b]);
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
配列Aが固定されている場面でまずは考えてみよう。
すると、
Xは
B1 xor B2 xor B3 xor ... xor BN-1
(A1 xor A2) xor (A2 xor A3) xor (A3 xor A4) xor ... xor (AN-1 xor AN)
A1 xor A2 xor A2 xor A3 xor A3 xor A4 xor ... xor AN-1 xor AN
A1 xor (A2 xor A2) xor (A3 xor A3) xor (A4 xor ... xor AN-1) xor AN
A1 xor AN
となる。
x xor x = 0がなりたつため、最初と最後のxorだけが残る。
なので、最終的な結果はA[i] xor A[j]の値になる。
これは配列Aから2つを抜き出しているので、制約を見ると全探索できる。
///////////////////////// writeup2 end */
