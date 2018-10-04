//In this problem values are stored as either 1 or 0 for getting values
#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        int ks[k+1];
        memset(ks, 0, sizeof(ks));
        ks[0] = 1;
        for(int i=0; i<n; i++)
            for(int j=a[i]; j<=k; j++){
                if(ks[j]!=1) ks[j] += ks[j-a[i]];
            }
        for(int i=k;i>=0;i--)
        if(ks[i]!=0){
            cout<<i<<"\n";
            break;
        }
    }
}
