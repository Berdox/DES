#include <iostream>
#include <string>
#include <fstream>
#include "Table.h"
#include "Des.h"

int main () {//abcdefgh
std::string input = "abcdefgh", key = "ABCDEF01", plain, keys;
Des d;
Table t;
//plain64 = t.hextobin(input);
char a;
for(int i = 0; i < input.size(); i++){
plain = plain + t.char_to_str(input[i]);
keys = plain + t.char_to_str(key[i]);
}
//std::cout << plain << std::endl;

d.encryption(plain, keys);
//d.dencryption(plain, keys);

char c;
std::cin >> c;
  return 0;
}
