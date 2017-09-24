#include <iostream>
#include <ctime>

class Person{
public:
    int data;
    int data2;
    int data3;
    int data4;
    Person(){}
    Person(int data, int data2, int data3, int data4): data(data), data2(data2), data3(data3), data4(data4){}
};

inline void sortPointer(Person *&p1, Person *&p2){
    // Быстро
    Person *temp = p1;
    p1 = p2;
    p2 = temp;
}
inline void sortObject(Person *&p1, Person *&p2){
    // Медленно
    Person temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
void sort(Person **person, int n, void(*f)(Person *&, Person*&)){
    for(int i = 0; i < n-1; i++){
        bool swapped = false;
        for(int j = 0; j < n-i-1; j++){
            if(person[j]->data < person[j+1]->data){
                swapped = true;
                // Сортировка через переданную функцию
                f(person[j], person[j+1]);
            }
            if(!swapped)
                break;
        }
    }
}

int main()
{
    void(*sortPointerPtr)(Person*&, Person*&) = &sortPointer;
    void(*sortObjectPtr)(Person*&, Person*&) = &sortObject;

    const int n = 20000;

    Person *person[n];

    for(int i = 0; i < n; i++){
        person[i] = new Person(i, i, i, i);
    }
    std::cout << "Run sort. Last element: " << person[n-1]->data << " | " << person[n-1]->data2 << std::endl;
    sort(person, n, sortPointerPtr);
    std::cout << "End sort. Last element: " << std::endl;
    for(int i = n - 50; i < n; i++){
        std::cout << person[i]->data << " | " << person[i]->data2 << std::endl;
    }
    std::cout << clock() << std::endl;
    return 0;
}