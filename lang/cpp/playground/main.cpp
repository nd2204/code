#include <iostream>

int my_function() {
  static int count = 0;
  count++;
  return count;
}
 
int main(void)
{
  std::cout << "function called " << my_function() << " times\n";
  std::cout << "function called " << my_function() << " times\n";
  std::cout << "function called " << my_function() << " times\n";
  std::cout << "function called " << my_function() << " times\n";
  std::cout << "function called " << my_function() << " times\n";
  std::cout << "function called " << my_function() << " times\n";
  std::cout << "function called " << my_function() << " times\n";
}
