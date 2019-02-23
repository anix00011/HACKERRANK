#include<iostream>
#include<string.h>
#include<vector>
#define ll long long
#define MOD 1000000007
using namespace std;
ll cnt[5025];
bool prime[9025];
vector<ll> v1;
ll px[2][8192];
void SOE(){//Sieve Of Eratosthenes
    memset(prime,true,sizeof(prime));
    prime[0]=false,prime[1]=false;
    for(int i=2;i*i<8200;i++){
        if(prime[i]==true)
            for(int j=i*i;j<8200;j+=i) prime[j]=false;
    }
}
int main(){
    SOE();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        v1.clear();
        memset(cnt,0,sizeof(cnt));
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            cnt[x]++;
        }
        for(int i=3500;i<4525;i++) if(cnt[i]>=1) v1.push_back(i);
        memset(px,0,sizeof(px));
        px[0][0]=1;
        int cx=1;
        for(int i=1;i<=v1.size();i++) {
            for(int j=0;j<8192;j++) {
                px[cx][j]=(px[cx^1][j]*(1+(cnt[v1[i-1]])/2)+px[cx^1][j^v1[i-1]]*((cnt[v1[i-1]]+1)/2))%MOD;
            }
            cx^=1;
        }
        ll res=0;
        for(int i=1;i<8192;i++) if(prime[i]) res+=px[cx^1][i]%=MOD;
        cout<<res%MOD<<"\n";
    }
}
//Questions
//how did you conclude this -> the XOR of any multiset must be in range [0, 8191] (8191==2^13-1)?
//ANS:-The xor-sum of an array can be at most 2^(log2(max(Ai)) + 1) - 1.
//Wow. That's a messy formula. Let's try to break it down. I'm assuming you know that taking log2(k) yields the number of bits used to represent k. We start with the largest element in an array call it Ai. If we xor elements that are less than Ai, the largest the xor-sum can be is when all of its bits are set. Example, Ai is the largest element in an array say 1010 (binary), since all other elements are less than or at most equivalient to Ai, we can only set or unset the bits of 1010 (we cannot add more bits since this would be a larger number but this is a contradiction since Ai max). In the max possible case, all bits of Ai are set (ex. 1010 ^ 0100 ^ 0001 = 1111) and it can never exceed that.
//So what is this number exactly? Well how do we set all bits in a binary string? Set the next most significant bit and subtract 1 from it. In our example 2^(log2(1010)+1) - 1 => 2^(4+1) - 1 = 1111 or in general 2^(log(2(k)+1) -1. That's how you derive the formula.
//Now in back to the problem, Ai will be at most 4500 stated in the constraints. Plug into formula 2^(log2(4500)+1) - 1 = 2^(12+1) - 1 = 2^13 - 1 = 8191. We won't need more than this many states to find the max xor-sum in any given array because it will never exceed this amount!
//**************************
//Explanation of Flag

//This is a standard approach to reduce memory usage when using dynamic programming.
//The idea is that often each row of a DP array only depends on the previous row. In this case, instead of storing the whole 2d DP[i][j] array, you can instead just use 2 rows of the array.
//In other words, DP[i][j] is stored in mem[0][j] if i is even, and in mem[1][j] if i is odd. The mem array is reused multiple times and after each iteration holds the most recent two rows of the full DP array.
//Explanation of recurrence

//Suppose we have 5 duplicates of a certain value v. There are 1+5/2 ways of making an xor of 0 (take either 0,2 or 4 copies). There are (1+5)/2 ways of making an xor of v (take either 1,3 or 5 copies).
//So to make the new value j, we can either start with j and add 0,2 or 4 copies of v, or start with j^v and add 1,3 or 5 copies.
//**************************
