//https://atcoder.jp/contests/abc139/tasks/abc139_c
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

int N, H[101010];
bool checked[101010];
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    rep(i, 0, N) cin >> H[i];

    int ans = 0;
    rep(i, 0, N) if(!checked[i]) {
        checked[i] = true;
        rep(j, i + 1, N) {
            if(H[j - 1] < H[j])
                break;
            checked[j] = true;
            chmax(ans, j - i);
        }
    }
    cout << ans << endl;
}

/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
全探索を考える。
始点を全探索して、右側にどれだけ移動できるかを確かめると、O(N^2)で解が求まる。
例えば、「6 5 4 9」
となっていて、6を始点とすると、6 5 4が最長であると分かる。
この時、5を始点としたチェックは6 5 4に含まれ、最適ではないので、チェックする必要はない。
つまり、始点を全探索するが、チェック済みの部分については、再度チェックしなくていい。
///////////////////////// writeup2 end */
