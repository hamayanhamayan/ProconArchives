//https://yukicoder.me/problems/no/935
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














int N; string S;
int A[2010], Q;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> S;
	rep(i, 0, N) cin >> A[i];
	cin >> Q;
	rep(_, 0, Q) {
		int K; cin >> K;

		int tot = 0, L = 0, ans = 0, enemy = 0;
		rep(R, 0, N) {
			tot += A[R];
			if (S[R] == 'E') enemy++;

			while (K < tot) {
				tot -= A[L];
				if (S[L] == 'E') enemy--;
				L++;
			}

			chmax(ans, enemy);
		}

		printf("%d\n", ans);
	}
}





/* ///////////////////////// writeup1 start
- [尺取法](https://www.hamayanhamayan.com/entry/2017/09/09/220426)
///////////////////////// writeup2 start
んーと思って見てると制約が弱めなことに気がつく。
よって、O(NQ)はまずできそう。
つまり、ビームの始点は全探索可能。
始点からビームでどこまで伸ばせるかを考えていくが、これは尺取法でうまいことやれる。
尺取法がわからないと少し厳しいかもしれない。
ビームの始点終点は特に逆になってても関係ないので、最大区間を考えていけばいい。
///////////////////////// writeup2 end */
