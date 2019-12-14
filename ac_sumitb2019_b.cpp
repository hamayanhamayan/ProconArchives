//https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_b
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
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(X, 1, N + 1) {
		double x = X;
		x = (int)(x * 1.08);
		if (x == N) {
			cout << X << endl;
			return;
		}
	}
	cout << ":(" << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
N/1.08をすれば答えが得られそうではあるが、小数点以下切り捨てになっているので、ちょっとやりにくい。
Nの上限が50000であるが、Xも50000を超えることがない。
よって、Xを1～Nまで全探索して、切り捨てがNになるものを答えればいい。
///////////////////////// writeup2 end */
