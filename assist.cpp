// #include <iostream>
// #include <vector>
// #include <queue>
// #include <algorithm>
// using namespace std;
// class Shape{
// protected:
//     int area;
//     int girth;
// public :
//     Shape(){
//         area = 0;
//         girth = 0;
//     }
//     int getArea();
//     int getGirth();
// };

// int Shape::getArea(){
//     return area;
// }
// int Shape::getGirth(){
//     return girth;
// }
// class Circle : public Shape{
//     int radius;
// public:
//     void setRadius(int r);
// };
// void Circle::setRadius(int r){
//     if(r >= 0 && r <= 100){
//         radius = r;
//         area = radius * radius * 3.14159;
//         girth = radius * 2 * 3.14159;
//     }
// }
// class Rectangle : public Shape{

// };

// class Circle{
//     int radius;
// public:
//     void setRadius(int r);
//     int getRadius();

//     Circle(){
//         radius = 0;
//     }
// };
// class Rectangle{
//     int length;
//     int width;
// public:
//     void setLength(int l);
//     void setWidth(int w);
// };

// void Circle::setRadius(int r){
//     if(r >= 0 && r <= 100){
//         radius = r;
//     }
// }
// int Circle::getRadius(){
//     return radius;
// }
// int main(){
//     Circle c;
//     cout << c.getRadius() << endl;

//     return 0;
// }


#include <iostream>
using namespace std;
class People{
private:
    int a;
protected:
    // void print_protected();
    void print_protected(){
        cout << "It is print protected" << endl;
    }
public:
    void print();
};

void People::print(){
    cout << "It is print function" << endl;
}
void People::print_protected(){
    cout << "It is print protected" << endl;
}

class Child : public People{
public:
    void print_child();
};
void Child::print_child(){
    cout << "print child" << endl;
}
int main(){
    Child child;
    child.print_protected();

    return 0;
}