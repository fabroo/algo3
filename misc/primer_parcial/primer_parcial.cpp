#include <iostream>
#include <vector>

std::vector<int> huecos(std::vector<int> numeros) {
    std::vector<int> res;
    if (numeros.size() == 2) {
        for (int j = numeros[0] + 1; j < numeros[1]; j++) {
            res.push_back(j);
        }
    } else {
        int mid = numeros.size() / 2;

        std::vector<int> first_half = huecos(std::vector<int>(numeros.begin(), numeros.begin() + mid));
        std::vector<int> second_half = huecos(std::vector<int>(numeros.begin() + mid, numeros.end()));
        std::vector<int> middle = huecos(std::vector<int>(numeros.begin() + mid - 1, numeros.begin() + mid + 1));

        res.insert(res.end(), first_half.begin(), first_half.end());
        res.insert(res.end(), middle.begin(), middle.end());
        res.insert(res.end(), second_half.begin(), second_half.end());
    }
    return res;
}

int main() {
    std::vector<int> numeros = {1,2,4,5};
    std::vector<int> result = huecos(numeros);
    // Print the result
    std::cout << "Huecos:";
    for (int num : result) {
        std::cout << " " << num;
    }
    std::cout << std::endl;
    return 0;
}
