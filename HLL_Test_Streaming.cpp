#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <set>
#include <vector>
#include <bits/stdc++.h>
#include <functional>
using namespace std;

void kmers(std::string seg, int k);
int b = 8;
// Const for b = 4
double am = 0.7182;
// stdl hash struct
hash<string> h;
// Total buckets
int m = pow(2, b);
// Return an int that cointains only the first b bytes
unsigned long long first_bb(unsigned long long x) { return (x >> (64 - b)); }
// Return an int equal to x minus the first b bytes
unsigned long long resto(unsigned long long x) { return (x << b); }
vector<int> v1(m, 0);
std::set<std::string> Real;

void procesar(string M) {
  // Apply the hash function to the string i
  unsigned long long x = h(M);
  // Index
  unsigned long long j = first_bb(x);
  // x - j bytes
  unsigned long long w = resto(x);
  // Save the maximum in the bucket j
  v1[j] = max(v1[j], __builtin_clz(w) + 1);
}

int hll() {
  // Raw Estimate
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
  E = estimate;

  double Eaux;
  // Small range correction
  if (E <= (5.0 / 2.0) * m) {

    double V = 0;
    for (int i = 0; i < m; ++i)
      if (v1[i] == 0)
        V++;
    if (V != 0) {
      Eaux = m * log2f((double)m / V);
    } else
      Eaux = E;
  } else if (E <=
             (1.0 / 30.0) * pow(2, 32)) { // Intermediate range => no correction
    Eaux = E;
  }
  // Large range correction
  if (E > (1.0 / 30.0) * pow(2, 32)) {
    Eaux = -pow(2, 32) * log2f(1.0 - E / pow(2, 32));
  }
  v1.clear();
  // Return the estimate cardinality
  return Eaux;
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
  cout << "respuesta: " << hll() << endl;
  cout << "Real: " << Real.size() << endl;
  set1.clear();
  return 0;
}

void kmers(std::string seg, int k) {
  int size = seg.size();
  int kmer_size = size - k + 1;
  for (int i = 0; i < kmer_size; ++i) {
    int posi = i, posf = i + k;
    // Inserting the kmer directly in to the sketch
    procesar(seg.substr(posi, k));
    Real.insert(seg.substr(posi, k));
  }
}
