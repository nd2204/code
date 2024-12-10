#include <iostream>
#include <thread>

int main() {
  std::cout << "number of concurrent thread: " << std::thread::hardware_concurrency() << '\n';

  return 0;
}
