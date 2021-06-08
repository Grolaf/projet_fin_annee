#include "Observer.hpp"

Observer::Observer(){}

void Observer::treatMessage(Message *m){
    std::cout << "Observateur" << std::endl;
}

