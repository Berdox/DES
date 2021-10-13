/**
 * @author Cody Hodge <hodgec@uleth.ca>
 * @date 2021-9-19
 */
 #include "Des.h"
 #include "Table.h"
 #include <iostream>
 #include <string>
 #include <cstring>
 #include <bitset>
 #include <vector>

 Des::Des() {

 }

 std::string Des::permute(std::string k, int* arr, int n)
 {
     std::string per = "";
     for (int i = 0; i < n; i++) {
         per += k[arr[i] - 1];
     }
     return per;
 }

 std::string Des::shift_left(std::string k, int shifts)
 {
     std::string s = "";
     for (int i = 0; i < shifts; i++) {
         for (int j = 1; j < 28; j++) {
             s += k[j];
         }
         s += k[0];
         k = s;
         s = "";
     }
     return k;
 }

 std::string Des::xor_(std::string a, std::string b)
 {
     std::string ans = "";
     for (int i = 0; i < a.size(); i++) {
         if (a[i] == b[i]) {
             ans += "0";
         }
         else {
             ans += "1";
         }
     }
     return ans;
 }

 std::string Des::encrypt(std::string pt, std::vector<std::string> rkb, std::vector<std::string> rk)
 {
   Table t;
   Des d;
     // Hexadecimal to binary
     pt = t.hex2bin(pt);

     // Initial Permutation
     pt = d.permute(pt, t.initial_perm, 64);
     std::cout << "After initial permutation: " << t.bin2hex(pt) << std::endl;

     // Splitting
     std::string left = pt.substr(0, 32);
     std::string right = pt.substr(32, 32);
     std::cout << "After splitting: L0=" << t.bin2hex(left)
          << " R0=" << t.bin2hex(right) << std::endl;


     std::cout << std::endl;
     for (int i = 0; i < 16; i++) {
         // Expansion D-box
         std::string right_expanded = d.permute(right, t.exp_d, 48);

         // XOR RoundKey[i] and right_expanded
         std::string x = d.xor_(rkb[i], right_expanded);

         // S-boxes
         std::string op = "";
         for (int i = 0; i < 8; i++) {
             int row = 2 * int(x[i * 6] - '0') + int(x[i * 6 + 5] - '0');
             int col = 8 * int(x[i * 6 + 1] - '0') + 4 * int(x[i * 6 + 2] - '0') + 2 * int(x[i * 6 + 3] - '0') + int(x[i * 6 + 4] - '0');
             int val = t.s[i][row][col];
             op += char(val / 8 + '0');
             val = val % 8;
             op += char(val / 4 + '0');
             val = val % 4;
             op += char(val / 2 + '0');
             val = val % 2;
             op += char(val + '0');
         }
         // Straight D-box
         op = d.permute(op, t.per, 32);

         // XOR left and op
         x = d.xor_(op, left);

         left = x;

         // Swapper
         if (i != 15) {
             std::swap(left, right);
         }
         std::cout << "Round " << i + 1 << " " << t.bin2hex(left) << " "
              << t.bin2hex(right) << " " << rk[i] << std::endl;
     }

     // Combination
     std::string combine = left + right;


     // Final Permutation
     std::string cipher = t.bin2hex(d.permute(combine, t.final_perm, 64));
     return cipher;
 }
