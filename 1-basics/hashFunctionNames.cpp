#include <iostream>
#include <string>

int hashFunction(const std::string& initials) {
    int sum = 0;
    for (char x : initials) {
        sum += x - 'A' + 1;
    }
    return sum % 23;
}

int main() {
    std::string nameInitials;
    std::cout << "Enter name initials: ";
    std::cin >> nameInitials;

    int hashValue = hashFunction(nameInitials);
    std::cout << "Hash value: " << hashValue << std::endl;

    return 0;
}
