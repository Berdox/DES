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
std::string permute(std::string, int*, int);
std::string shift_left(std::string, int);
std::string xor_(std::string, std::string);
std::string encrypt(std::string, std::vector<std::string>, std::vector<std::string>);
};
#endif
