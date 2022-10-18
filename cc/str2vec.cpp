#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>

#include <sstream>

#include "arrayfire.h"



template <typename T>
std::vector<T> str2vec(const std::string& str) {
  std::stringstream ss(str);
  std::vector<T> vec;
  T i;
  while (ss >> i) {
    vec.push_back(i);
    if (ss.peek() == ',')
      ss.ignore();
  }
  return vec;
}


std::vector<float> str2vec1d(const std::string& str) {
  std::string str2 = str;
  str2.erase(std::remove(str2.begin(), str2.end(), '{'), str2.end());
  str2.erase(std::remove(str2.begin(), str2.end(), '}'), str2.end());

  return str2vec<float>(str2);
}


std::vector<std::vector<double>> str2vec2d(const std::string& str) {
  std::vector<std::vector<double>> vec2d;

  std::string str2 = str;
  str2.erase(std::remove(str2.begin(), str2.end(), '{'), str2.end());
  str2.erase(std::remove(str2.begin(), str2.end(), '}'), str2.end());

  std::stringstream ss(str2);
  std::string line;
  while (std::getline(ss, line, ',')) {
    std::vector<double> vec = str2vec<double>(line);
    vec2d.push_back(vec);
  }

  return vec2d;
}


af::array vec2af(const std::vector<float> &vec, int num_recs, int base_dim) {
  std::vector<long long int> dims = {num_recs, base_dim, base_dim};

  std::vector<long long int> rdims(dims.rbegin(), dims.rend());
  af::dim4 af_dims(rdims.size(), rdims.data());

  return af::array(af_dims, vec.data());
}







int main() {
    // Data from SPI
    std::vector<std::string> rows;
    rows.push_back("{{1015.0, 20.5}, {23,  5}}");
    rows.push_back("{{1015,   20},   {23,  1}}");
    rows.push_back("{{1015,   20},   {23,  3}}");

    
    // Convert to std::vector
    std::vector<std::vector<float>> data;
    for (unsigned int i=0; i<rows.size(); i++) {
        data.push_back(str2vec1d(rows[i]));
    }

    std::string data1 = "{{1015.0, 20.5}, {23,  5}},{{1015,   20},   {23,  1}},{{1015,   20},   {23,  3}}";
    std::vector<float> data2 = str2vec1d(data1);

    int base_dim = 2;
    int num_recs = data2.size() / (base_dim * base_dim);
    std::cout << "num_recs: " << num_recs << std::endl;

    // Convert to af::array
    af::array af_data = vec2af(data2, num_recs, base_dim);

    af::print("af_data", af_data);

    return 0;
}