#include <iostream>
#include <string>
#include <fstream>
#include "Table.h"
#include "Des.h"

int main () {
std::string input = "abcdefgh", key = "ABCDEFGH", plain, keys;
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
/*
for(int i = 0; i<< plain64.size(); i++) {
p = plain64[i];
p =p+ plain64[i + 1];
p =p+ plain64[i+ 2];
p =p+ plain64[i + 3];
p =p+ plain64[i+ 4];
p =p+ plain64[i+ 5];
p =p+ plain64[i + 6];
p =p+ plain64[i+ 7];
std::cout << p << std::endl;
a = t.str_to_char("01100000");
q = q + a;9
std::cout << q << std::endl;
}
a = t.str_to_char(p);
std::cout << t.str_to_char(p) << std::endl;
*/
char c;
std::cin >> c;
  return 0;
}
