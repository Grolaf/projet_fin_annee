#include "Observer.hpp"
#include <iostream>

Observer::Observer(){}

void Observer::treatMessage(Message *m){
    std::cout << "Observateur" << std::endl;
}

