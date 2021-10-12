/**
 * @author Cody Hodge <hodgec@uleth.ca>
 * @date 2021-9-19
 */
 #include "Table.h"
 #include <iostream>
 #include <string>
 #include <map>
 #include <bitset>

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

 // convert a group of 8 digits to a character
char Table::str_to_char(std::string group)
{
    std::bitset<8> temp(group);
    return temp.to_ulong();
}

// convert a character to a group of eight digits
std::string Table::char_to_str(char ch)
{
    std::bitset<8> temp(ch);
    return temp.to_string();
}

std::string Table::hex_to_str(char ch)
{
  std::bitset<4> temp(ch);
return temp.to_string();
}
