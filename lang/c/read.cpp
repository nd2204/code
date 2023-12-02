#include <iostream>
#include <fstream>
#include <sstream>

int main() {
    // Now, fileContent contains the content of the file
    std::cout << "File Content:\n" << readFile("bogus.c") << std::endl;
}
