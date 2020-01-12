//https://atcoder.jp/contests/abc151/tasks/abc151_b
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














int N, K, M;
int A[101];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> K >> M;
	rep(i, 0, N - 1) cin >> A[i];

	int tot = 0;
	rep(i, 0, N - 1) tot += A[i];

	rep(lst, 0, K + 1) {
		if (M * N <= lst + tot) {
			cout << lst << endl;
			return;
		}
	}

	cout << -1 << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
計算することで最適な点数を求めることもできそうだが、
今回は点数は最大100点満点なので、全探索で求めていこう。
最後の点数を全探索して、平均点がM点以上であるものの最小点数を答える。
平均点の比較では、分数をあまり使いたくないので、両辺を個数でかけることで整数比較にしておこう。
///////////////////////// writeup2 end */
