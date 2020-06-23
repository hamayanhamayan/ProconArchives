//https://atcoder.jp/contests/abc171/tasks/abc171_e
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














int N, a[201010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> a[i];

	int tot = 0;
	rep(i, 0, N) tot ^= a[i];
	
	rep(i, 0, N) {
		if(i) printf(" ");
		printf("%d", tot ^ a[i]);
	}
	printf("\n");
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
XORの性質を知っておく必要がある。
x ^ x = 0
x ^ 0 = x
このルールから、全ての数のxorを取ったときに同じ数が複数個あった場合は2個セットで消すことができる
ことが分かる。
1 xor 1 xor 2 xor 2 xor 2 xor 3となっていれば、2 xor 3と変換することができる。

突拍子も無い発想だが、数列aの全部のxorを取る。
例えば、元々{1, 2, 3, 4}が答えであり、
a={2 xor 3 xor 4, 1 xor 3 xor 4, 1 xor 2 xor 4, 1 xor 2 xor 3}
であったとする。
これで全部のxorを取ると、
2 xor 3 xor 4 xor 1 xor 3 xor 4 xor 1 xor 2 xor 4 xor 1 xor 2 xor 3
= (1 xor 1 xor 1) xor (2 xor 2 xor 2) xor (3 xor 3 xor 3) xor (4 xor 4 xor 4)
= 1 xor 2 xor 3 xor 4
のように答えの数列の全部のxor和が得られる。
なぜかというと、i番目の答えがxor和として含まれる配列aの要素はi番目以外なのでN-1個となる。
N-1は奇数なので、全体でxorを取ると丁度残る。
これが全てにおいて言えるので、答えの数列が全部残り、答えの数列のxor和が得られることが分かる。

あとは、i番目の答えは(全体のxor和) xor a[i]で求めることができるので、これを答えていく。
///////////////////////// writeup2 end */
