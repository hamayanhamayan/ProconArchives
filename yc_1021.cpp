//https://yukicoder.me/problems/no/1021
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














int N, M, A[201010]; string S;
int buf[601010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M;
	rep(i, 0, N) cin >> A[i];
	cin >> S;

	int L = M, R = M + N - 1;
	rep(i, 0, N) buf[M + i] = A[i];

	fore(c, S) {
		if (c == 'L') {
			L++; R++;
			buf[L] += buf[L - 1];
			buf[L - 1] = 0;
		}
		else {
			L--; R--;
			buf[R] += buf[R + 1];
			buf[R + 1] = 0;
		}
	}

	rep(i, L, R + 1) {
		if(i != L) printf(" ");
		printf("%d", buf[i]);
	}
	printf("\n");
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
さて、初めてこういう問題に取り組む人は、どういう所から考え始めればいいかわからないかもしれない。
こういう操作を行う問題の方針の1つである「差分だけ計算する」という方針で考えてみる。

タイプLを考えてみると、ほぼ左に移るが、最左の要素ははみ出すが、左から二番目の要素に足される。
はみ出した部分を二番目の要素に足すこと以外を見てみると、シフト操作になっている。
シフト操作は全部を移動させるのではなく、オフセットを移すというやり方がある。
つまりは、以下のような感じ。

todo

なので、今の状況のL,Rを持っておき、タイプLであればL++,R++、タイプRであればL--,R--してやればシフトはできる。
はみ出した分だけ、別途足し合わせてやれば操作はO(1)で行えるので、M回やっても問題ない。
注意点として、L,Rは負の数になる可能性があるので、L=0,R=N-1スタートとせずに、
L=M,R=M+N-1のような配列の真ん中ぐらいに配置してスタートするといい。
///////////////////////// writeup2 end */
