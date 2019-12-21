//https://codeforces.com/contest/1268/problem/A
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














int N, K;
string A;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> K >> A;
	
	string B = "";
	rep(i, 0, N) B += A[i % K];

	int bad = -1;
	rep(i, 0, N) {
		if (A[i] < B[i]) break;
		else if (A[i] > B[i]) {
			bad = i;
			break;
		}
	}
	if (0 <= bad) {
		bad %= K;
		rrep(k, K - 1, bad) {
			if (B[k] != '9') {
				int i = k;
				while (i < N) {
					B[i]++;
					i += K;
				}
				rep(kk, k + 1, K) {
					i = kk;
					while (i < N) {
						B[i] = '0';
						i += K;
					}
				}
				break;
			}
		}
	}

	printf("%d\n%s\n", N, B.c_str());
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
適当に解説を書いておく。
B[i] = A[i % K]としてまず置く。
先頭から大小関係を比較していく。
Bの方が既に大きいなら、答え。
Aの方が大きくなったら、その添字をメモっておく。
B[0]～B[K-1]はAと同じなので、その添字badは、K以上になる。
これを解消するにはB[bad % K]を+1すればいい。
だが、これが最適とは限らず、bad % K < badであることは確実なので、
bad % Kよりもbad % K + 1を+1する方が最適になる場合がある。
なので、後ろから順に+1できたらする。
より小さくするために、+1できた場合は、後ろを0埋めしておく。
///////////////////////// writeup2 end */
