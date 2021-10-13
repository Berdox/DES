
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include "Table.h"
#include "Des.h"
using namespace std;

int main()
{
  Table t;
  Des d;
    // pt is plain text
    string pt, key;
    /*cout<<"Enter plain text(in hexadecimal): ";
    cin>>pt;
    cout<<"Enter key(in hexadecimal): ";
    cin>>key;*/

    pt = "123456ABCD132536";
    key = "AABB09182736CCDD";
    // Key Generation

    // Hex to binary
    key = t.hex2bin(key);
    std::cout << key << std::endl;

    // getting 56 bit key from 64 bit using the parity bits
    key = d.permute(key, t.keyper, 65); // key without parity

    // Splitting
    string left = key.substr(0, 28);
    string right = key.substr(28, 28);

    vector<string> rkb; // rkb for RoundKeys in binary
    vector<string> rk; // rk for RoundKeys in hexadecimal
    for (int i = 0; i < 16; i++) {
        // Shifting
        left = d.shift_left(left, t.shift[i]);
        right = d.shift_left(right, t.shift[i]);

        // Combining
        string combine = left + right;

        // Key Compression
        string RoundKey = d.permute(combine, t.key_comp, 48);

        rkb.push_back(RoundKey);
        rk.push_back(t.bin2hex(RoundKey));
    }

    cout << "\nEncryption:\n\n";
    string cipher = d.encrypt(pt, rkb, rk);
    cout << "\nCipher Text: " << cipher << endl;

    cout << "\nDecryption\n\n";
    reverse(rkb.begin(), rkb.end());
    reverse(rk.begin(), rk.end());
    string text = d.encrypt(cipher, rkb, rk);
    cout << "\nPlain Text: " << text << endl;
char c;
std::cin >> c;
  return 0;
}
