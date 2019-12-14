//https://yukicoder.me/problems/no/892
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

int A[3], B[3];
//---------------------------------------------------------------------------------------------------
void _main() {
    rep(i, 0, 3) cin >> A[i] >> B[i];

    int tot = 0;
    rep(i, 0, 3) tot += A[i] % 2;

    if(tot % 2 == 0) cout << ":-)" << endl;
    else cout << ":-(" << endl;
}

/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
2等分にするためには全体を足したときに偶数であればいい。
なので、A^Bそれぞれあるが、それぞれが偶数であるか奇数であるかのみ興味がある。
Aが奇数ならば、それをどれだけかけても奇数なのでA^Bは奇数。
同様にAが偶数ならば、A^Bも偶数。
奇数なら1, 偶数なら0とすれば、その総和をとったときに偶数であれば、A^Bの総和も偶数となる。
よって、それで判定する。
///////////////////////// writeup2 end */
