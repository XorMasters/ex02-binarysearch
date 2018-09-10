#include <iostream>
#include <algorithm>

#include "binarysearch.h"

template <class T>
struct Value {
    Value(T val): visited(false), value(val) {}

    mutable bool visited;
    T value;

    bool operator <(const Value& other) const { visited = other.visited = true; return value < other.value; }
    bool operator >(const Value& other) const { visited = other.visited = true; return value > other.value; }
    bool operator ==(const Value& other) const { return value == other.value; }
};

int main() {
    Value<uint64_t> values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    Value<uint64_t> find(10);
    int64_t index = edu::vcccd::vc::csv15::binarysearch<Value<uint64_t>>(find, values, 11);

    long visited = std::count_if(values, values+10, [&] (Value<uint64_t> &v) {
        return v.visited;
    } );

    std::cout << "Values visited: " <<  visited << std::endl;

    std::cout << "Hello, World!: " << index << std::endl;
    return 0;
}