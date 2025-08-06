#include <iostream>
#include <limits>
class LCM { //LinearCongruentMethod
private:
    unsigned int seed;
    unsigned int a;
    unsigned int c;
    unsigned int m;

public:
    LCM(unsigned int seed, unsigned int a, unsigned int c, unsigned int m) 
        : seed(seed), a(a), c(c), m(m) {}//список инициализации

    unsigned int next() {
        //сам генератор
        seed = (a * seed + c) % m;
        return seed;
    }
};

int main() {
    //параметры генератора c одного из примеров википедии
    unsigned int a = 171; 
    unsigned int c = 11213;
    unsigned int m = 53125;
    unsigned int seed = 21613; //число для начала отсчёта

    if (m > 65535) { // m не больше 65535 по условию задания
        return 1;
    }
    LCM lcm(seed, a, c, m);

    //получаем следующее число
    while (true) {
        std::cout << "Next number: " << lcm.next() << std::endl;
        std::cout << "Press Enter to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return 0;
}