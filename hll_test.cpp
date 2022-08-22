#include <bits/stdc++.h>
#include <functional>
using namespace std;

int b = 4;
//Const for b = 4
double am = 0.697;
//stdl hash struct
hash<string> h;
//Total buckets
int m = 16;
//Return an int that cointains only the first b bytes
int first_bb(int x){
    return (x >> (32-b));
}
//Return an int equal to x minus the first b bytes
int resto(int x){
    return (x << b);
}

int hll(multiset<string> M){
    //Buckets
    vector<int> v1(m,0);
    //Traverse the multiset
    for(auto i : M){
        //Apply the hash function to the string i
        int x = h(i);
        //Index
        int j = first_bb(x);
        //x - j bytes
        int w = resto(x);
        //Save the maximum in the bucket j
        v1[j] = max(v1[j],__builtin_clz(w)+1); 
    }
    //Raw Estimate
    double E = am*(m*m);
    double summ = 0;
    for(int i = 0; i < m; ++i){
        summ+=pow(2,-v1[i]);
    }
    summ = pow(summ,-1);
    //Final Raw Estimate
    E = E * summ;
    double Eaux;
    //Small range correction
    if(E <= (5.0/2.0)*m){
        double V = 0;
        for(int i = 0; i < m; ++i)
            if(v1[i] == 0)V++;
        if(V != 0)
            Eaux = m*log2f((double)m/V);
        else
            Eaux = E;
    }
    //Intermediate range => no correction
    if(E <= (1.0/30.0)*pow(2,32))
        Eaux = E;
    //Large range correction
    if(E > (1.0/30.0)*pow(2,32)){
        Eaux = -pow(2,32)*log2f(1.0 - E/pow(2,32));
    }
    //Return the estimate cardinality
    return Eaux;
}


