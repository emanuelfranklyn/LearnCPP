#include <iostream>
#include <string>
using namespace std;

class Pizzaria {
  public:
    float pizzaPrice;
    string name;
    void makePizza() {
      cout << name << " is making a pizza for R$" << pizzaPrice << endl;
    };
};