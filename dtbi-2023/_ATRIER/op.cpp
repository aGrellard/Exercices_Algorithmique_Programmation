#include <iostream>

int main() {

    int reste = 8 % 2;
    std::cout << "rest: " << reste << std::endl;
    int division = 8 / 2;
    if (reste) {
        std::cout << "division + reste = " << division + reste << std::endl;
    } else {
        std::cout << "division = " << division << std::endl;
    }

    return 0;

}