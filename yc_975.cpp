//https://yukicoder.me/problems/no/975
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














int X, N, M, A[101010], B[101010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> X >> N >> M;
	rep(i, 0, N) cin >> A[i];
	rep(i, 0, N) cin >> B[i];

	bool existMax = false;
	rep(i, 0, N) if (A[i] == X) existMax = true;

	bool existValue = false;
	rep(i, 0, N) if (B[i] == X) existValue = true;

	if (existMax && existValue) cout << "MrMaxValu" << endl;
	else if (existMax) cout << "MrMax" << endl;
	else if (existValue) cout << "MaxValu" << endl;
	else cout << -1 << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
あるかどうかをそれぞれ判定して、booleanの変数として保持しておこう。
あとは、それを使って、4択の回答方法で答える。
///////////////////////// writeup2 end */
