#include <iostream>
#include "gtest_lite.h"
#include "memtrace.h"

#include "canvas.hpp"
#include "shape.hpp"
#include "point.hpp"
#include "polygon.hpp"
#include "regulars.hpp"
#include "pointcloud.hpp"

#include <string>
using std::string;
using std::istringstream;
using std::ostringstream;

int main() {
    TEST(Adatok, Pont) {
        istringstream a(string("10 20 20 10"));
        ostringstream b;
        Point p1, p2;
        a >> p1 >> p2;
        
        Point p3 = p1+p2;
        b << p3;
        EXPECT_STREQ("30 30", b.str().c_str());
    } END;
    
    TEST(Adatok, Heterogen) {
        istringstream a(string("3 0 0 10 10 10 0   4 50 0 0 45"));
        istringstream b(string("5 0 0 3 0 3 3 0 3 1.5 1.5"));

        Shape* poly = new Polygon();
        Regular* reg = new Regular();
        PointCloud* cl = new PointCloud();
        a >> *poly >> *reg;
        b >> *cl;
        delete poly;
        
        Canvas canv;
        canv.add(nullptr);
        canv.remove(0);
        canv.add(reg);
        canv.add(cl);

        EXPECT_TRUE(canv.isBaseShape(1));
    } END;
}