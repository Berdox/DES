#include <iostream>
#include <string>

int main () {
std::string input, input1;
std::cout << "Enter PLaintext: \n";
std::cin >> input1;

for (int i = 0; i < 16; i++) {
  input = input + input1[i];
}

std::cout << input;

char c;
std::cin >> c;
  return 0;
}
