//https://yukicoder.me/problems/no/887
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

int n0;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> n0;

    int i1 = -1, nmax = n0;
    int n = n0;
    rep(i, 0, 400)
    {
        if (n == 1 and i1 < 0) {
            i1 = i;
            break;
        }

        chmax(nmax, n);

        if (n % 2 == 0)
            n = n / 2;
        else
            n = 3 * n + 1;
    }
    cout << i1 << endl;
    cout << nmax << endl;
}

/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
制約を見てみると、シミュレートできそうな雰囲気がある。
400回までが上限なので、ぶん回す。
///////////////////////// writeup2 end */
