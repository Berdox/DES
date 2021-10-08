/**
 * @author Cody Hodge <hodgec@uleth.ca>
 * @date 2021-9-19
 */
#include "Table.h"
#include <string>
#include <map>

 Table::Table() {

 }

std::string  Table::hextobin(std::string in) {

  std::map <char, std::string> m;

  m['0'] = "0000";
  m['1'] = "0001";
  m['2'] = "0010";
  m['3'] = "0011";
  m['4'] = "0100";
  m['5'] = "0101";
  m['6'] = "0110";
  m['7'] = "0111";
  m['8'] = "1000";
  m['9'] = "1001";
  m['A'] = "1010";
  m['B'] = "1011";
  m['C'] = "1100";
  m['D'] = "1101";
  m['E'] = "1110";
  m['F'] = "1111";

  std::string temp;

  for(int i = 0; i < in.size(); i++) {
    temp = temp + m[in[i]];
  }

return temp;
}

std::string  Table::bintohex(std::string out) {

  std::map <std::string, std::string> m;

  m["0000"] = "0";
  m["0001"] = "1";
  m["0010"] = "2";
  m["0011"] = "3";
  m["0100"] = "4";
  m["0101"] = "5";
  m["0110"] = "6";
  m["0111"] = "7";
  m["1000"] = "8";
  m["1001"] = "9";
  m["1010"] = "A";
  m["1011"] = "B";
  m["1100"] = "C";
  m["1101"] = "D";
  m["1110"] = "E";
  m["1111"] = "F";
std::string temp;
return temp;
}

int Table::tb(int a) {
  return tb1[a];
}

int Table::subtab1(int a) {
  return subtab[a];
}
