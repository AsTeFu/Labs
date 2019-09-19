#include <iostream>
#include <string>
#include "../inlcude/Program.h"
#include "../inlcude/Queue.h"
#include "../inlcude/Stack.h"
#include "../inlcude/Utility.h"

int main() {
  int key = 0;
  Program program;

  while (true) {
    program.printQueue();
    program.printMenu();

    std::string input;
    do {
      std::cout << "Select menu item: ";
      std::cin >> input;
    } while (!Utility::tryToInt(input, &key) || key > 5);

    if (key == 5) break;
    program.invoke(key);
    std::cout << std::endl;
  }

  return 0;
}
