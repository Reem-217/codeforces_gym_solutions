#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ld long double
#define ll long long
#define Friendy  ios_base::sync_with_stdio(false); cin.tie(0);
#define sz size

int countBoxes(int L, int W, int H, int l, int w, int h) {
    int countL = L / l;
    int countW = W / w;
    int countH = H / h;
    return countL * countW * countH;
}
int main() {
    Friendy

    int L,W,H, l,w,h; cin>>L>>W>>H>>l>>w>>h;
    cout<<max({countBoxes(L,W,H,l,w,h),countBoxes(L,W,H,l,h,w),
               countBoxes(L,W,H,w,l,h),countBoxes(L,W,H,w,h,l),
               countBoxes(L,W,H,h,l,w),countBoxes(L,W,H,h,w,l)})<<endl;


    return 0;
}

