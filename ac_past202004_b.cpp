//https://atcoder.jp/contests/past202004-open/tasks/past202004_b
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














string S;
int cnt[3];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> S;
	fore(c, S) cnt[c - 'a']++;

	int ma = -1;
	rep(i, 0, 3) chmax(ma, cnt[i]);
	rep(i, 0, 3) if (ma == cnt[i]) cout << char('a' + i) << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
まずは候補者ごとに票を集計する。
cnt[i] := 候補者abcのi番目に入った票の数
次に、最も多い票数maを探す。
最後に、その最も多い票数を獲得している人を探して、答える。
0,1,2をa,b,cに最後変換する必要があるが、char('a'+i)とやると変換できる。
///////////////////////// writeup2 end */
