#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ld long double
#define ll long long
#define Friendy  ios_base::sync_with_stdio(false); cin.tie(0);
#define sz size

int main() {
    Friendy

    int n; cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    int f=1;
    sort(a.begin(),a.end());
    for(int i=n;i>=1;i--){
        if(a[i]-a[i-1]){
            if(!f) f=1;
            else if(a[i]-a[i-1]==1)f=0;
        }
    }
    cout<<(f==0?"Bobius":"Alicius")<<endl;
    return 0;
}

