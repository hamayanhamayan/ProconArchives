//https://atcoder.jp/contests/abc155/tasks/abc155_c
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
	map<string, int> cnt;
	rep(i, 0, N) {
		string s; cin >> s;
		cnt[s]++;
	}

	int ma = -1;
	fore(p, cnt) chmax(ma, p.second);
	fore(p, cnt) if (p.second == ma) printf("%s\n", p.first.c_str());
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
文字列をそれぞれ数えて、一番頻度の高いやつをまとめて答えるという問題。
指示されていることを実装するのだが、c++であればmapを使うのが最も簡単。
map<string,int>で使い、intで数えていく。
valueの最大値miを計算し、value=miであるkeyを答えればいい。
mapはkeyでソートされているため、順番に答えれば自然と辞書順で小さい順に出力できる。
///////////////////////// writeup2 end */
