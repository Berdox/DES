/**
 * @author Cody Hodge <hodgec@uleth.ca>
 * @date 2021-9-19
 */
 #include "Table.h"
 #include <iostream>
 #include <string>
 #include <unordered_map>
 #include <bitset>

  Table::Table() {

  }

  std::string Table::hex2bin(std::string s)
  {
      // hexadecimal to binary conversion
      std::unordered_map<char, std::string> mp;
      mp['0'] = "0000";
      mp['1'] = "0001";
      mp['2'] = "0010";
      mp['3'] = "0011";
      mp['4'] = "0100";
      mp['5'] = "0101";
      mp['6'] = "0110";
      mp['7'] = "0111";
      mp['8'] = "1000";
      mp['9'] = "1001";
      mp['A'] = "1010";
      mp['B'] = "1011";
      mp['C'] = "1100";
      mp['D'] = "1101";
      mp['E'] = "1110";
      mp['F'] = "1111";
      std::string bin = "";
      for (int i = 0; i < s.size(); i++) {
          bin += mp[s[i]];
      }
      return bin;
      //  std::bitset<8> temp(ch);
      //return temp.to_string();
  }

  std::string Table::bin2hex(std::string s)
  {
      // binary to hexadecimal conversion
      std::unordered_map<std::string, std::string> mp;
      mp["0000"] = "0";
      mp["0001"] = "1";
      mp["0010"] = "2";
      mp["0011"] = "3";
      mp["0100"] = "4";
      mp["0101"] = "5";
      mp["0110"] = "6";
      mp["0111"] = "7";
      mp["1000"] = "8";
      mp["1001"] = "9";
      mp["1010"] = "A";
      mp["1011"] = "B";
      mp["1100"] = "C";
      mp["1101"] = "D";
      mp["1110"] = "E";
      mp["1111"] = "F";
      std::string hex = "";
      for (int i = 0; i < s.length(); i += 4) {
          std::string ch = "";
          ch += s[i];
          ch += s[i + 1];
          ch += s[i + 2];
          ch += s[i + 3];
          hex += mp[ch];
      }
      return hex;
  }
