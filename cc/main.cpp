#include <iostream>

#include <sstream>
#include <vector>
#include <string>

// 3
#include <algorithm>



void WaitForKeypress() {
    std::cin.clear();
    //std::cin.ignore(32767, '\n');
    std::cin.get();
}



void str2int(std::string& str, std::vector<int>& vec) {
  //str.erase(0,1);
  std::stringstream ss(str);
  int i;
  while (ss >> i) {
    if (ss.peek() == ',' || ss.peek() == ';' || ss.peek() == ' ' || 
      ss.peek() == '\t' || ss.peek() == '\n' || ss.peek() == '\r' ||
      ss.peek() == '{' || ss.peek() == '}' ||
      ss.peek() == '(' || ss.peek() == ')' ||
      ss.peek() == '[' || ss.peek() == ']')
      ss.ignore();

    vec.push_back(i);
    
    if (ss.peek() == ',' || ss.peek() == ';' || ss.peek() == ' ' || 
      ss.peek() == '\t' || ss.peek() == '\n' || ss.peek() == '\r' ||
      ss.peek() == '{' || ss.peek() == '}' ||
      ss.peek() == '(' || ss.peek() == ')' ||
      ss.peek() == '[' || ss.peek() == ']')
      ss.ignore();
  }
}





int main() {
  std::cout << "Start" << std::endl;

  std::string myString = "{1015,20,23}";
  //myString.erase(std::remove(myString.begin(), myString.end(), '{'), myString.end());
  myString.erase(0,1);

  std::vector<int> myNumbers;
  str2int(myString, myNumbers);

  for (auto i : myNumbers)
    std::cout << i << std::endl;






  return 0;
}