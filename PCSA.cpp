#include <bits/stdc++.h>
using namespace std;

long[] sketch() = new long[M];
long R(long x){
    return ~x &(x+1);
}
void Update(x){
    long x= hash(s);
    int k = hash(x,M);
    sketch[k]=sketch[k]|R(x);
} 
long estimacion(){
    int sum=0;
    for(int i=0;i<k;i++){
        sum+=R(sketch[k]);
        
    }
    double media=1.0*sum/M;
    return M*2^(media)/0.77351;    
}