#include <iostream>
#include <string>
#include <fstream>
#include "Table.h"
#include "Des.h"

int main () {
std::string input = "1234567890ABCEGF", input1, result;
std::cout << "Enter PLaintext: \n";
/*std::cin >> input1;

for (int i = 0; i < 16; i++) {
  input = input + input1[i];
}*/
std::cout << input << std::endl;
Table t;
result = t.hextobin(input);
std::cout << result << std::endl;
std::ofstream f;
f.open("output.txt");
f << result;
f.close();
Des d;
result = d.bitremove(result);
std::cout << result << std::endl;
char c;
std::cin >> c;
  return 0;
}
