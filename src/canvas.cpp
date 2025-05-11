#include "canvas.hpp"

Canvas::Canvas() : shapes(0) {}

Canvas::~Canvas() {
    for(Shape* x : shapes)
        delete x;
}

void Canvas::remove(size_t index) {
    shapes.erase(index);
}

void Canvas::clear() {
    shapes.clear();
}

void Canvas::add(Shape* s) {
    shapes.push_back(s);
}

void Canvas::print(size_t index, std::ostream& os) {
    os << shapes[index] << "\n";
}

void Canvas::printAll(std::ostream& os) {
    for(size_t i = 0; i < shapes.size(); i++)
        os << i << " " << shapes[i] << "\n";
}

bool Canvas::isBaseShape(size_t index) {
    Shape* base = shapes[index];
    for(auto& x : shapes) {
        if(x == base)
            continue;
        
        if(!base->contains(*x))
            return false;
    }

    return true;
}

std::istream& operator<<(std::istream& is, Canvas& c);