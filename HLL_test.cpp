#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <set>
#include <vector>
#include <bits/stdc++.h>
#include <functional>
using namespace std;

void kmers(std::vector<std::string> &v1, std::string seg, int k);
int b = 4;
//Const for b = 4
double am = 0.673;
//stdl hash struct
hash<string> h;
//Total buckets
int m = 16;
//Return an int that cointains only the first b bytes
unsigned long long first_bb(unsigned long long x){
    return (x >> (64-b));
}
//Return an int equal to x minus the first b bytes
unsigned long long resto(unsigned long long x){
    return (x << b);
}

double hll(multiset<string> M){
    //Buckets
    vector<int> v1(m,0);
    //Traverse the multiset
    for(auto i : M){
        //Apply the hash function to the string i
        unsigned long long x = h(i);
        //Index
        unsigned long long j = first_bb(x);
        //x - j bytes
        unsigned long long w = resto(x);
        //Save the maximum in the bucket j
        v1[j] = max(v1[j],__builtin_clz(w)+1); 

    }
    //Raw Estimate
    double E;

    double sum = 0.0;

    for (int i = 0; i < m; ++i) {
    const double max = (double)v1[i];
    const double term = pow(2.0, -max);
    sum += term;
    }
    const double harmonic_mean = m * (1.0 / sum);
    const double estimate = am * m * harmonic_mean;
    assert(estimate >= 0.0);
    E=estimate;

    double Eaux;
    //Small range correction
    if(E <= (5.0/2.0)*m){
        
        double V = 0;
        for(int i = 0; i < m; ++i)
            if(v1[i] == 0)V++;
        if(V != 0){
            Eaux = m*log2f((double)m/V);
        }
        else
            Eaux = E;
    }else if(E <= (1.0/30.0)*pow(2,32)){//Intermediate range => no correction
        Eaux = E;
    }
    //Large range correction
    if(E > (1.0/30.0)*pow(2,32)){
        Eaux = -pow(2,32)*log2f(1.0 - E/pow(2,32));
    }
    //Return the estimate cardinality
    return Eaux;
}

int main() {
  int j=0;
  std::cout << "Ingrese nombre del archivo: " << std::endl;

  std::string filename, line;
  std::cin >> filename;
  // Cardinalidad del conjunto de Genomas
  int S = 0, x = 31;
  std::ifstream newFile(filename);
  std::vector<std::string> k1;
  std::set<std::string> set1;
  std::multiset<std::string> M;
  std::set<std::string> Real;
  if (newFile.is_open()) {
    while (newFile.peek() != EOF) {
      getline(newFile, line);
      if (line.size() >= x)
        x = line.size();
      if (line != "")
        kmers(k1, line, 31);
        for( auto i: k1){
            j++;
            M.insert(i);
            Real.insert(i);
            //cout<<"Kmer numero: "<<j<<" -"<<i<<endl;
        }
      S++;
    }
    newFile.close();
  }

  cout<<"Cantidad real: "<<Real.size()<<endl;
  for(int i=0; i<=10; i++){
    cout<<"respuesta: "<<hll(M)<<endl;
  }

  return 0;
}

void kmers(std::vector<std::string> &v1, std::string seg, int k) {
  int size = seg.size();
  int kmer_size = size - k + 1;
  for (int i = 0; i < kmer_size; ++i) {
    int posi = i, posf = i + k;
    if (posf < size)
      v1.push_back(seg.substr(posi, k));
  }
}