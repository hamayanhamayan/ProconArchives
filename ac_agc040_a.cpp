//https://atcoder.jp/contests/agc040/tasks/agc040_a
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














string S;
int N;
ll A[501010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> S;
	N = S.length() + 1;

	rep(i, 0, N) A[i] = -1;

	queue<int> q;

}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
小さい所から順番に埋めていこう。  
>?<となっている所があれば、?は0にしてしまって問題ない。これをまずやろう。
>?>となっている所は右の値の+1が入る。
<?>となっている所は、左右の値の最大値+1が入る。
これを順番にやっていく。
///////////////////////// writeup2 end */
