#include <iostream>
#include <string>
using namespace std;
#include "pizzaria.cpp"

int main() {
  Pizzaria superPizza;
  superPizza.name = "Super Pizza";
  superPizza.pizzaPrice = 34.99;
  superPizza.makePizza();
  return 0;
}