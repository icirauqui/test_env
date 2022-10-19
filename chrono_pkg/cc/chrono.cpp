#include "chrono.h"


chrono::chrono() {};

chrono::~chrono() {};

void chrono::start() {
  start_time = std::chrono::high_resolution_clock::now();
}

void chrono::end(std::string msg) {
  end_time = std::chrono::high_resolution_clock::now();
  auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
  times.push_back(duration1.count());
  messages.push_back(msg);
}


void chrono::report() {
  std::cout << " Times: " << std::endl;
  for (unsigned int i=0; i<times.size(); i++) {
    std::cout << "   " << messages[i] << " : " << times[i] << std::endl;
  }
}
