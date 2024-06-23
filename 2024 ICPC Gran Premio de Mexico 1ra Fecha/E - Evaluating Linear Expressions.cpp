#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ld long double
#define ll long long
#define Friendy  ios_base::sync_with_stdio(false); cin.tie(0);
#define sz size
int main() {
    Friendy

    int a,b,k; cin>>a>>b>>k;
    for(int i=1;i<=k;i++){
        if(i==k) cout<<a*i+b<<"\n";
        else
            cout<<a*i+b<<" ";
    }
    return 0;
}

