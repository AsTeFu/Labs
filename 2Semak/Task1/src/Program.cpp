//
// Created by astefu on 9/19/19.
//

#include "../inlcude/Program.h"
#include <iostream>
#include <string>

Program::Program() : queue(50) {
  _menuItems.insert(make_pair(1, bind(&Program::pushBack, this)));
  _menuItems.insert(make_pair(2, bind(&Program::push, this)));
  _menuItems.insert(make_pair(3, bind(&Program::popBack, this)));
  _menuItems.insert(make_pair(4, bind(&Program::pop, this)));
  _menuNames = {{1, "Push back"}, {2, "Push"}, {3, "Pop back"}, {4, "Pop"}, {5, "Exit"}};
}

void Program::pushBack() {
  if (!queue.push_back(getValue())) std::cout << "Stack overflow" << std::endl;
}
void Program::push() {
  if (!queue.push(getValue())) std::cout << "Stack overflow" << std::endl;
}
void Program::pop() {
  if (queue.isEmpty()) {
    std::cout << "Queue is empty" << std::endl;
    return;
  }

  std::cout << "Last element was: " << queue.pop() << std::endl;
}
void Program::popBack() {
  if (queue.isEmpty()) {
    std::cout << "Queue is empty" << std::endl;
    return;
  }

  std::cout << "First element was: " << queue.pop_back() << std::endl;
}

std::string Program::getValue() {
  std::cout << "Input element: ";
  std::string elem;
  std::cin >> elem;
  return elem;
}
void Program::printQueue() {
  if (queue.isEmpty()) {
    std::cout << "Queue is empty!" << std::endl;
    return;
  }

  std::cout << "Queue: ";
  for (size_t i = 0; i < queue.size(); ++i) std::cout << *queue.at(i) << " ";
  std::cout << std::endl;
}
void Program::printMenu() {
  for (const auto& name : _menuNames) std::cout << name.first << ". " << name.second << std::endl;
}
void Program::invoke(int i) {
  _menuItems.at(i)();
}
