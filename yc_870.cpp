//https://yukicoder.me/problems/no/870
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
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
char B[11][11];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
    rep(y, 1, 10) rep(x, 1, 10) B[y][x] = '.';
    B[8][2] = 'A';
    B[9][3] = 'B';
    B[9][7] = 'C';

    rep(i, 0, N) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        swap(B[y1][x1], B[y2][x2]);
    }

    if(B[8][5] == 'A' and B[8][4] == 'B' and B[8][6] == 'C') cout << "YES" << endl;
    else cout << "NO" << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
シミュレーションしていこう。
A,B,Cの駒を動かしていって、最終的に指定の座標になるかを見ればいい。
駒毎に位置を持つのではなくて、盤面全体を管理すれば、操作はswapで実装でき、
ほんのちょっと楽。
///////////////////////// writeup2 end */
