#include <bits/stdc++.h>
int M=1024;
using namespace std;
set<string> Real;
vector<int> sketch(M);
long R(long x){
    return ~x &(x+1);
}
int countZeros(int x){
  int cont=0;
  while(x&1){
    cont++;
    x=x>>1;
  }
  return cont;
}
void Update(string s){
    hash<string> h;
    hash <long> h2;
    long x= h(s);
    int k = h2(x)%(M-1);
    sketch[k]=sketch[k]|R(x);
} 
long estimacion(){
    double sum=0.0;
    for(int i=0;i<M;i++){
      sum+=countZeros(sketch[i]);
      //  cout<<countZeros(sketch[i])<<endl;
    }
    //cout<<sum<<endl;
    double media=1.0*sum/M;
   // cout<<"media: "<<media<<endl;
    return (M*pow(2,media))/0.77351;    
}
void kmers(std::string seg, int k) {
  int size = seg.size();
  int kmer_size = size - k + 1;
  if(seg[0]=='>') return;
  for (int i = 0; i < kmer_size; ++i) {
    int posi = i, posf = i + k;
    // Inserting the kmer directly in to the sketch
    Update(seg.substr(posi, k));
    Real.insert(seg.substr(posi, k));
  }
}

int main() {
  int j = 0;
  std::cout << "Ingrese nombre del archivo: " << std::endl;

  std::string filename, line;
  std::cin >> filename;
  // Cardinalidad del conjunto de Genomas
  int S = 0, x = 31;
  std::ifstream newFile(filename);
  std::vector<std::string> k1;
  std::set<std::string> set1;
  std::multiset<std::string> M;
  if (newFile.is_open()) {
    while (newFile.peek() != EOF) {
      getline(newFile, line);
      if (line.size() >= x)
        x = line.size();
      if (line != "")
        kmers(line, 31);
      k1.clear();
      S++;
    }
    newFile.close();
  }
  cout << "respuesta: " << estimacion() << endl;
  cout << "Real: " << Real.size() << endl;
  set1.clear();
  return 0;
}