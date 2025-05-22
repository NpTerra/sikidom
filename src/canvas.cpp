#include "canvas.hpp"

#include "memtrace.h"

Canvas::Canvas() : shapes(0) {}

Canvas::~Canvas() {
    for(Shape* x : shapes)
        delete x;
}

size_t Canvas::size() const {
    return shapes.size();
}

void Canvas::remove(size_t index) {
    delete shapes[index];
    shapes.erase(index);
}

void Canvas::clear() {
    for(Shape* x : shapes)
        delete x;
    shapes.clear();
}

void Canvas::add(Shape* s) {
    if(s != nullptr)
        shapes.push_back(s);
}

void Canvas::add(const Canvas& canv) {
    for(auto& x : canv.shapes)
        this->add(x->clone());
}

void Canvas::print(size_t index, std::ostream& os) const {
    os << shapes[index]->getName() << " " << *shapes[index] << std::endl;
}

void Canvas::printAll(std::ostream& os) const {
    for(size_t i = 0; i < shapes.size(); i++) {
        os << i << " ";
        print(i, os);
    }
}

bool Canvas::isBaseShape(size_t index) const {
    Shape* base = shapes[index];
    for(auto& x : shapes) {
        if(x == base)
            continue;
        
        if(!base->contains(*x))
            return false;
    }

    return true;
}