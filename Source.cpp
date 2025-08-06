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
        : seed(seed), a(a), c(c), m(m) {}//������ �������������

    unsigned int next() {
        //��� ���������
        seed = (a * seed + c) % m;
        return seed;
    }
};

int main() {
    //��������� ���������� c ������ �� �������� ���������
    unsigned int a = 171; 
    unsigned int c = 11213;
    unsigned int m = 53125;
    unsigned int seed = 21613; //����� ��� ������ �������

    if (m > 65535) { // m �� ������ 65535 �� ������� �������
        return 1;
    }
    LCM lcm(seed, a, c, m);

    //�������� ��������� �����
    while (true) {
        std::cout << "Next number: " << lcm.next() << std::endl;
        std::cout << "Press Enter to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return 0;
}