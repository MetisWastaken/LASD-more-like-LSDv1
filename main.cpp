
#include "zlasdtest/test.hpp"

#include "zmytest/test.hpp"

/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

int main() {
std::cout << "-----LASD Libraries 2025-----" << std::endl;
int choice;
std::cout << "Test choice:\n";
std::cout << "1. lasdtest\n";
std::cout << "2. mytest\n";
std::cout << "Select test 1/2 or press any other key to exit: \n";
std::cin >> choice;

switch(choice) {
  case 1:
    lasdtest();
    break;
  case 2:
    mytest();
    break;
  default:
    std::cout << "Exiting now...Goodbye!" << std::endl;
    break;
}
  return 0;
}
