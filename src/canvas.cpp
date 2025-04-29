#include "canvas.hpp"

Canvas::Canvas() : shapes(0) {}

Canvas::~Canvas() {
    for(Shape* x : shapes)
        delete x;
}

void Canvas::remove(size_t index) {

}

void Canvas::clear() {

}

void Canvas::add(Shape* s) {
    shapes.push_back(s);
}

void Canvas::print(size_t index) {

}

void Canvas::printAll() {

}

bool Canvas::isBaseShape(size_t index) {
    return true;
}

std::istream& operator<<(std::istream& is, Canvas& c);