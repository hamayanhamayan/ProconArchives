//https://atcoder.jp/contests/nikkei2019-2-qual/tasks/nikkei2019_2_qual_a
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















int N;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	int ans = (N - 1) / 2;
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
組み合わせを全探索してもいいが、計算だけでも解ける。
N=1+(N-1)=2+(N-2)=...=(N-1)+1
と考えると(N-1)通りある。
だが、順番は考えないので、組み合わせ数は半分になり、(N-1)/2が答え。
Nが偶数のときに相異なるに反するパターンもあったりするが、切り捨てしとくとうまいこと消える。
///////////////////////// writeup2 end */
