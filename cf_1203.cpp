//https://codeforces.com/contest/1203/problem/E
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













int N, A[151010];
int cnt[151010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> A[i];

	rep(i, 0, N) cnt[A[i]]++;

	int ans = 0;
	rep(i, 1, 150002) {
		if (1 < i and 0 < cnt[i - 1]) ans++, cnt[i - 1]--;
		else if (0 < cnt[i]) ans++, cnt[i]--;
		else if (0 < cnt[i + 1]) ans++, cnt[i + 1]--;
	}
	cout << ans << endl; 
}






/* ///////////////////////// writeup1 start
N要素の配列Aがある。
各要素1だけ増減することができる（自然数の範囲で）とき、作ることのできる数の最大種類数は？
1≦N≦150000
///////////////////////// writeup2 start
貪欲に作ることができそう。
例えば、1を作りたいときは、2を使ってるのがいい。
2を作りたいときは、1が使えるときはなるべく1を使ってやるほうがいい。3は4でも使えそう。
そのため、小さい数から貪欲に作れるかどうか試していき、作っていく。
///////////////////////// writeup2 end */
