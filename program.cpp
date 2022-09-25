#include <iostream>
using namespace std;
class Parent{
protected:
    int data = 67855;
private:
    int pri = -10;
public:
    int pub = 100;
    void print();
    void number(int &a);
};
void Parent::print(){
        cout << "Hello World" << endl;
}
void Parent::number(int &a){
    cout << a << endl;
}
class Child: public Parent{
public:
    void get_pro(){
        cout << pub << endl;
    }
    void get_data(){
        cout << data << endl;
    }
    void get_pri(){
        cout << pri << endl;
    }
};
int main(){
    Child c;
    c.get_data();
    c.get_pri();
    c.get_pro();

    return 0;
}