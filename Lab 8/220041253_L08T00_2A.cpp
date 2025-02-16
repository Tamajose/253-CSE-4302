#include <iostream>
#include <cmath>
using namespace std;

class Shape{
    public:
        virtual void whoAmI() const = 0;
};

class TwoDimensionalShape: public Shape{
    public:
        virtual void perimeter() const = 0;
        virtual void area() const = 0;
};

class ThreeDimensionalShape: public Shape{
    public:
        virtual void surfacearea() const = 0;
        virtual void volume() const = 0;
};

class Square: public TwoDimensionalShape{
    private:
        double side;
    public:
        Square(double l): side(l){}
        void area() const override{
            cout << "Area = " << side*side << endl;
        }
        void perimeter() const override{
            cout << "Perimeter = " << 4*side << endl;
        }
        void whoAmI() const override{
            cout << "I am Square. I am a two-dimensional shape." << endl;
        }
};

class Circle: public TwoDimensionalShape{
    private:
        double radius;
    public:
        Circle(double r): radius(r){}
        void area() const override{
            cout << "Area = " << 3.142*radius*radius << endl;
        }
        void perimeter() const override{
            cout << "Perimeter = " << 2*3.142*radius << endl;
        }
        void whoAmI() const override{
            cout << "I am Circle. I am a two-dimensional shape." << endl;
        }
};

class Triangle: public TwoDimensionalShape{
    private:
        double side_a;
        double side_b;
        double side_c;
        double semi_peri;
    public:
        Triangle(double a, double b, double c, double s): side_a(a), side_b(b), side_c(c), semi_peri(s){}
        void area() const override{
            cout << "Area = " << sqrt(semi_peri*(semi_peri-side_a)*(semi_peri-side_b)*(semi_peri-side_c)) << endl;
        }
        void perimeter() const override{
            cout << "Perimeter = " << side_a+side_b+side_c << endl;
        }
        void whoAmI() const override{
            cout << "I am Triangle. I am a two-dimensional shape." << endl;
        }
};

class Rectangle: public TwoDimensionalShape{
    private:
        double length;
        double width;
    public:
        Rectangle(double l, double w): length(l), width(w){}
        void area() const override{
            cout << "Area = " << length*width << endl;
        }
        void perimeter() const override{
            cout << "Perimeter = " << 2*(length+width) << endl;
        }
        void whoAmI() const override{
            cout << "I am Rectangle. I am a two-dimensional shape." << endl;
        }
};

class Cube: public ThreeDimensionalShape{
    private:
        double side;
    public:
        Cube(double l): side(l){}
        void surfacearea() const override{
            cout << "Surface Area = " << 6*side*side << endl;
        }
        void volume() const override{
            cout << "Volume = " << side*side*side << endl;
        }
        void whoAmI() const override{
            cout << "I am Cube. I am a three-dimensional shape." << endl;
        }
};

class Sphere: public ThreeDimensionalShape{
    private:
        double radius;
    public:
        Sphere(double r): radius(r){}
        void surfacearea() const override{
            cout << "Surface Area = " << 4*3.142*radius*radius << endl;
        }
        void volume() const override{
            cout << "Volume = " << (4*3.142*radius*radius*radius)/3 << endl;
        }
        void whoAmI() const override{
            cout << "I am Sphere. I am a three-dimensional shape." << endl;
        }
};

class Cylinder: public ThreeDimensionalShape{
    private:
        double radius;
        double height;
    public:
        Cylinder(double r, double h): radius(r), height(h){}
        void surfacearea() const override{
            cout << "Surface Area = " << (2*3.142*radius*height + 2*3.142*radius*radius) << endl;
        }
        void volume() const override{
            cout << "Volume = " << 3.142*radius*radius*height << endl;
        }
        void whoAmI() const override{
            cout << "I am Cylinder. I am a three-dimensional shape." << endl;
        }
};

class Cone: public ThreeDimensionalShape{
    private:
        double radius;
        double height;
    public:
        Cone(double r, double h): radius(r), height(h){}
        void surfacearea() const override{
            cout << "Surface Area = " << 3.142*radius*(radius+sqrt(height*height + radius*radius)) << endl;
        }
        void volume() const override{
            cout << "Volume = " << (3.142*radius*radius*height)/3 << endl;
        }
        void whoAmI() const override{
            cout << "I am Cone. I am a three-dimensional shape." << endl;
        }
};

int main(){
    Square s(2.3);
    s.area();
    s.perimeter();
    s.whoAmI();

    Circle c(2.4);
    c.area();
    c.perimeter();
    c.whoAmI();

    Triangle t(2.5, 2.6, 2.7, 10);
    t.area();
    t.perimeter();
    t.whoAmI();

    Rectangle r(2.8, 2.9);
    r.area();
    r.perimeter();
    r.whoAmI();

    Cube c1(3.0);
    c1.surfacearea();
    c1.volume();
    c1.whoAmI();

    Sphere s1(3.1);
    s1.surfacearea();
    s1.volume();
    s1.whoAmI();

    Cylinder c2(3.2, 3.3);
    c2.surfacearea();
    c2.volume();
    c2.whoAmI();

    Cone c3(3.4, 3.5);
    c3.surfacearea();
    c3.volume();
    c3.whoAmI();
}