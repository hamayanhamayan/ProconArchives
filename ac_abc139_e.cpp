//https://atcoder.jp/contests/abc139/tasks/abc139_e
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

int N;
queue<int> Q[1010];
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    rep(i, 0, N) rep(j, 0, N - 1) {
        int a;
        cin >> a;
        a--;
        Q[i].push(a);
    }

    set<pair<int, int>> buf;
    rep(cu, 0, N) {
        int to = Q[cu].front();
        if (Q[to].front() == cu)
            buf.insert({min(cu, to), max(cu, to)});
    }

    int ans = 0;
    while(!buf.empty()) {
        ans++;
        set<pair<int, int>> buf2;
        fore(p, buf) {
            int a = p.first;
            int b = p.second;

            Q[a].pop();
            Q[b].pop();

            if(!Q[a].empty()) {
                int cu = Q[a].front();
                if(!Q[cu].empty()) {
                    if(Q[cu].front() == a)
                        buf2.insert({min(a, cu), max(a, cu)});
                }
            }

            if(!Q[b].empty()) {
                int cu = Q[b].front();
                if(!Q[cu].empty()) {
                    if(Q[cu].front() == b)
                        buf2.insert({min(b, cu), max(b, cu)});
                }
            }
        }
        swap(buf, buf2);
    }

    rep(i, 0, N) if(!Q[i].empty()) {
        cout << -1 << endl;
        return;
    }
    cout << ans << endl;
}

/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
全くいい方針が思いつかない。
AtCoderなので、貪欲法かもしれない。
先頭から順番にペアでとってこれる場合はとってくる動作を繰り返せばいい。
簡単すぎる気がするが、そのまま実装するとO(N^3)になる。
これを高速化するのが本質か？
queueなどで、とりあえず配列Aは置き換えておこう。
貪欲にペアをとっていくには、取れるペアをどっかにとっておけばいい。
これは、ペアをとった場合に2つ取れるが、逆に言えば、選択可能な数が2つ増えるということ。
そのため、その差分について、追加していけばいい。
ダブルでカウントするのを防ぐために、{a,b}をsetに入れておけばいい。
a<bとなるように入れることに注意しよう。
///////////////////////// writeup2 end */
