#include <iostream>
#include <vector>


int randomNum(std::vector<int> range){
    return range[0];
}


int main(){
    int startRange;
    int endRange;

    std::cin >> startRange;
    std::cin >> endRange;

    std::vector<int> range = {startRange,endRange};

    int num = randomNum(range);

    std::cout << "Guess a number from " << startRange << " to " << endRange << std::endl;

}