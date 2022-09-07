#include <bits/stdc++.h>
int M=32;
using namespace std;

vector<int> sketch(M,0);
long R(long x){
    return ~x &(x+1);
}
void Update(string s){
    hash<string> h;
    hash <long> h2;
    long x= h(s);
    int k = h2(x)%M;
    sketch[k]=sketch[k]|R(x);
    //cout<<sketch[k]<<endl;
} 
long estimacion(){
    int k=M;
    int sum=0;
    for(int i=0;i<k;i++){
        sum+=R(sketch[i]);
    }
    double media=1.0*sum/M;
    return M*pow(2,media)/0.77351;    
}
void kmers(vector<string> &v1,string seg,int k) {
  int size=seg.size();
  int kmer_size=size-k+1;
  for (int i=0;i<kmer_size;++i) {
    int posi=i,posf=i+k;
    if (posf<size)
      v1.push_back(seg.substr(posi, k));
  }
}
int main() {
  srand(time(NULL));
  int j=0;
  cout <<"Ingrese nombre del archivo: " <<endl;
  string filename, line;
  cin>>filename;
  int S=0,x=31;
  ifstream newFile(filename);
  vector<string> k1;
  set<string> set1;
  multiset<string> m;
  set<string> Real;
  if (newFile.is_open()) {
    while (newFile.peek()!=EOF) {
      getline(newFile,line);
      if (line.size()>=x)
        x=line.size();
      if (line!="")
        kmers(k1,line,31);
        for( auto i:k1){
            Update(i);
            m.insert(i);
            Real.insert(i);
        }
      S++;
    }
    newFile.close();
  }

  cout<<"Cantidad real: "<<Real.size()<<endl;
  for(int i=0;i<=10;i++){
    long r=estimacion();
    cout<<"respuesta: "<<r<<endl;
  }

  return 0;
}