//
// Created by astefu on 9/19/19.
//

#ifndef LABA1_UTILITY_H
#define LABA1_UTILITY_H

#include <stdexcept>
#include <string>

class Utility {
 public:
  static bool tryToInt(const std::string& str, int* num) {
    try {
      *num = std::stoi(str);
      return true;
    } catch (const std::invalid_argument& ex) {
      return false;
    }
  }
};

#endif  // LABA1_UTILITY_H
