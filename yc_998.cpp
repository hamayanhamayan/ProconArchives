//https://yukicoder.me/problems/no/998
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














int v[4];
//---------------------------------------------------------------------------------------------------
void _main() {
	rep(i, 0, 4) cin >> v[i];
	sort(v, v + 4);

	if (v[0] + 1 == v[1] && v[1] + 1 == v[2] && v[2] + 1 == v[3]) cout << "Yes" << endl;
	else cout << "No" << endl;
	
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
連続する4つの整数にできるか判定することを、以下のように行う。
ABCDを昇順ソートしたときに、A+1=B, B+1=C, C+1=Dとなっていればいい。
昇順ソートするので、配列で受け取っておくのがいいだろう。
///////////////////////// writeup2 end */
