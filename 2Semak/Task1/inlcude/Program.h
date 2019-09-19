//
// Created by astefu on 9/19/19.
//

#ifndef LABA1_PROGRAM_H
#define LABA1_PROGRAM_H

#include <functional>
#include <map>
#include "../inlcude/Queue.h"

using std::bind;
using std::function;
using std::make_pair;

class Program {
 private:
  std::map<int, function<void()>> _menuItems;
  std::map<int, std::string> _menuNames;
  Queue<std::string> queue;

  std::string getValue();

  void pushBack();
  void push();
  void pop();
  void popBack();

 public:
  Program();
  void printQueue();
  void printMenu();
  void invoke(int i);
};

#endif  // LABA1_PROGRAM_H
