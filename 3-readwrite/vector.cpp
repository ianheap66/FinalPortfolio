#include <vector>
#include <iostream>
#include <string>



//constructed this by understanding and looking at c++ documentation online

int main(){
    std::vector<std::string> vector;

    vector.push_back("Ian");
    vector.push_back("Max");
    vector.push_back("Duval");
    vector.push_back("Frank");

    for(int i = 0; i < vector.size(); i++){
        std::cout << vector[i] << std::endl;
    }

    vector.pop_back();

    for(int k = 0; k < vector.size(); k++){
        std::cout << vector[k] << std::endl;
    }

    vector.push_back("Ian");
    //vector.push_back(5);

    std::cout << vector.size() << std::endl;
}