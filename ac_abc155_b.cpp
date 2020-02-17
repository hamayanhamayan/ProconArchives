//https://atcoder.jp/contests/abc155/tasks/abc155_b
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














int N, A[101];
//---------------------------------------------------------------------------------------------------
string solve() {
	rep(i, 0, N) if (A[i] % 2 == 0) if(A[i] % 3 != 0 && A[i] % 5 != 0) return "DENIED";
	return "APPROVED";
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> A[i];
	cout << solve() << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
全部の整数のうち、条件を満たさないものがあるかを判定する。
条件を満たさないものは、偶数であるが、3でも5でも割り切れないことになる。
なので、配列Aを全部みて、偶数であり、3でも5でも割り切れないものがあれば、"DENIED"を返す。
全部大丈夫なら"APPROVED"を返す。
///////////////////////// writeup2 end */
