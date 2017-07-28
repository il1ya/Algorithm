#include <iostream>
// стек вызовов
void greet2(std::string name){
    std::cout << "How are you, " << name << "?";
}

void bye(){
    std::cout << "ok, bye!";
}

void greet(std::string name){
    std::cout << "Hello, " << name << "!";
    greet2(name);
    std::cout << "getting ready to say bye...";
    bye();
}

int main()
{
    greet("Illya");
    return 0;
}