
#ifndef MYTEST_HPP
#define MYTEST_HPP

#include "../../vector/vector.hpp"
/* ************************************************************************** */

template <typename Data>

void EqualVector(uint& testnum, uint& testerr, const lasd::Vector<Data>& vec1, const lasd::Vector<Data>& vec2, bool expected) {
    testnum++;
    bool result = false;
    try {
        result = (vec1 == vec2);
        std::cout << " " << testnum << " (" << testerr << ") The two vectors are "
                  << (result ? "" : "not ") << "equal: "
                  << ((result == expected) ? "Correct" : "Error") << "!" << std::endl;
        if (result != expected) testerr++;
    } catch (const std::exception& exc) {
        std::cout << "\"" << exc.what() << "\": "
                  << ((expected) ? "Error" : "Correct") << "!" << std::endl;
        if (expected) testerr++;
    }

void NonEqualVector(uint& testnum, uint& testerr, const lasd::Vector<Data>& vec1, const lasd::Vector<Data>& vec2, bool expected) {
    ++testnum;
    bool result = false;
    try {
        result = (vec1 != vec2);
        std::cout << " " << testnum << " (" << testerr << ") The two vectors are "
                            << (result ? "not " : "") << "equal: "
                            << ((result == expected) ? "Correct" : "Error") << "!" << std::endl;
        if (result != expected) testerr++;
    } catch (const std::exception& exc) {
        std::cout << "\"" << exc.what() << "\": "
                  << ((!expected) ? "Correct" : "Error") << "!" << std::endl;
        if (expected) testerr++;
    }
}


/* ************************************************************************** */

#endif
