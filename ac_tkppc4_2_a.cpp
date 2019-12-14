//https://atcoder.jp/contests/tkppc4-2/tasks/tkppc4_2_a
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











int x, y;
//---------------------------------------------------------------------------------------------------
int solve() {
    if (y < 0) return -1;
    int ans = 0;
    int xx = 0, yy = 0;
    while(yy < y) {
        ans++;
        if(xx < x) xx++;
        else xx--;
        yy += 2;
    }
    if(xx != x or yy != y) return -1;
    return ans;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> x >> y;
    cout << solve() << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
操作を見ると、y座標は+2するしかないので、yが負の場合は達成できない。
目標のy座標の上限が10^5なので、多くても10^5/2回くらいしか操作できない。
よって、シミュレーションしてみよう。
x座標は-1か+1かどちらかであるが、目標のx座標により近い方に貪欲に選択していけばいい。
///////////////////////// writeup2 end */
