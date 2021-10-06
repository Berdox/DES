#include <iostream>
#include <string>
#include <fstream>
#include "Table.h"
#include "Des.h"

int main () {
std::string input = "1234567890ABCDEF", input1, result, key, left, right;
//std::cout << "Enter PLaintext: \n";
/*std::cin >> input1;

for (int i = 0; i < 16; i++) {
  input = input + input1[i];
}*/
//std::cout << input << std::endl;
Table t;
result = t.hextobin(input);
//std::cout << result << std::endl;
Des d;
key = d.bitremove(result);
//std::cout << key << std::endl;
result = d.tp(result);
//std::cout << result << std::endl;
/*std::ofstream f;
f.open("output.txt");
f << result;
f.close();*/
d.split(result, left, right);
d.subkey(key);
char c;
std::cin >> c;
  return 0;
}
