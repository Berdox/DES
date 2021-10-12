#include <iostream>
#include <string>
#include <fstream>
#include "Table.h"
#include "Des.h"

int main () {//abcdefgh  9a bf 7b 35 b4 dd 4f e7
std::string input = "abcdefgh", key = "ABCDEF01", plain, keys;
Des d;
Table t;
//plain64 = t.hextobin(input);
char a, b, e;
int y = 0;
std::string w;
for(int i = 0; i < input.size(); i++){

plain = plain + t.char_to_str(input[i]);
}
/*for(int i = 0; i < input.size(); i++){

plain = plain + t.hex_to_str(input[i]);
}*/
for(int i = 0; i < key.size(); i++){
keys = keys + t.char_to_str(key[i]);
}

std::cout << plain << std::endl;
//std::cout << keys << std::endl;

d.encryption(plain, keys);
//d.dencryption(plain, keys);

char c;
std::cin >> c;
  return 0;
}
