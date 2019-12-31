//https://atcoder.jp/contests/past201912-open/tasks/past201912_d
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
int cnt[201010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> A[i];

	rep(i, 0, N) cnt[A[i]]++;

	int x = -1, y = -1;
	rep(i, 1, N + 1) {
		if (cnt[i] == 0) x = i;
		if (cnt[i] == 2) y = i;
	}

	if (x < 0) cout << "Correct" << endl;
	else cout << y << " " << x << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
サンプル1の説明を見ると、個数が重要そうである。
書き換えが発生していなかった場合は、全て1個であるパターンである。
書き換えが発生している場合は、ほとんど1個であるが、2個が1つと0個が1つになるはずである。
よって、個数を数えて、どっちになっているかを見ればいい。
整数xが整数yに書き換えられているとすると、整数xの個数が0個で、整数yの個数が2個になっているはずなので、
それを答える。
///////////////////////// writeup2 end */
