//
// Created by aknight on 9/9/18.
//

#ifndef BINARYSEARCH_BINARYSEARCH_H
#define BINARYSEARCH_BINARYSEARCH_H

#include <cstdlib>
#include <iostream>

namespace edu { namespace vcccd { namespace vc { namespace csv15 {
    template <class T>
    int64_t binarysearch(const T &value, T array[], size_t size) {
        size_t curr = size / 2;
        for(size_t hi = size - 1, lo = 0; hi - lo > 0; curr = (hi + lo)/2) {
            if (value > array[curr]) {
                lo = curr + 1;
            } else if (value < array[curr]) {
                hi = curr - 1;
            } else {
                return curr;
            }
        }
        return array[curr] == value ? curr : -1;
    }
}}}}
#endif //BINARYSEARCH_BINARYSEARCH_H
