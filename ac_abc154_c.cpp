//https://atcoder.jp/contests/abc154/tasks/abc154_c
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
	sort(A, A + N);

	rep(i, 0, N - 1) if (A[i] == A[i + 1]) {
		cout << "NO" << endl;
		return;
	}

	cout << "YES" << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
ある数列が全て異なる数であることを判別するには色々方法がある。
データ構造を使うやり方であれば、setを使うのがいいだろう。
setに全部入れて、サイズを見た時にN個であれば全て異なる。

自分は、ソートを使った手法を使った。
同じ数があった場合は、ソートをした後に隣接しているはずである。
なので、ソートを行い、全ての隣接する数について同じであるかを確認する。
同じな物があればNO, 全てそうでないならYES
///////////////////////// writeup2 end */
