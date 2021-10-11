/**
 * @author Cody Hodge <hodgec@uleth.ca>
 * @date 2021-9-19
 */
#ifndef DES_H
#define DES_H

#include <string>
#include <vector>

class Des {
public:
Des();
std::string splitplain(std::string);
std::string keyperm(std::string);
void keysplit(std::string, Des&);
void subkey(Des&);
std::string leftshift(int, std::string&);
void combkeys(Des&);
void finalkeys(Des&);
std::string plainperm(std::string);
void halfplain(std::string, Des&);
void expandright(Des&);
void xorR(Des&, int);
void sixthbits(Des&);
void sBox(Des&, int);
void combineSBox(Des&);
void permSBox(Des&);
void finalxor(Des&);
void reverse(Des&);
void finalPerm(Des&);

std::string plaind;
std::string left;
std::string right;
std::string OriRight;
std::string leftkeys [16];
std::string rightkeys [16];
std::string keys[16];
std::string subkeys[16];
std::string xorRight;
std::string sixth[8];
std::string sBoxresult[8];
std::string newright;
std::string finalright;
std::string end;
int shift[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
};
#endif
