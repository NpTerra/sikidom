#include "canvas.hpp"
#include "memtrace.h"

Canvas::Canvas() : shapes(0) {}

Canvas::~Canvas() {
    for(auto &x : shapes)
        delete x;
}

void remove(size_t index) {

}

void clear() {

}

void add(Shape* s) {

}

void print(size_t index) {

}

void printAll() {

}

bool isBaseShape(size_t index) {

}

std::istream& operator<<(std::istream& is, Canvas& c);