
#include <iostream>
#include <vector>
#include <chrono>



class chrono {
public:
  chrono();
  ~chrono();

  void start();

  void end(std::string msg = "");

  void report();

private:

  std::chrono::_V2::system_clock::time_point start_time;
  std::chrono::_V2::system_clock::time_point end_time;

  std::vector<double> times;
  std::vector<std::string> messages;
};