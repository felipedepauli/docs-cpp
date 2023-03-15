#include "./sort.hpp"
#include <algorithm>

template<typename T>
void printVector(const std::vector<T>& vec) {
    for (const auto& element : vec) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}





int main() {

    std::vector<int> detections = { 3, 10, 7, 4, 8, 6, 1, 9, 5, 2 };
    printVector(detections);

    std::sort(detections.begin(), detections.end());
    printVector(detections);

    // I can change the comparison function to sort in descending order
    std::vector<int> detections_2 = { 3, 10, 7, 4, 8, 6, 1, 9, 5, 2 };
    std::sort(detections_2.begin(), detections_2.end(), 
        [](const int & a, const int & b) -> bool {  // This is a lambda function
            return a > b;
        });
    printVector(detections_2);
    // 3                               3
    // 3 10                            10 3
    // 10 3 7                          10 7 3
    // 10 7 3                          10 7 3
    // 10 7 3 4                        10 7 4 3
    // 10 7 4 3                        10 7 4 3
    // 10 7 4 3                        10 7 4 3
    // 10 7 4 3 8                      10 7 4 8 3
    // 10 7 4 8 3                      10 7 8 4 3
    // 10 7 8 4 3                      10 8 7 4 3
    // 10 8 7 4 3                      10 8 7 4 3


    std::vector<int> detections_2 = { 3, 10, 7, 4, 8, 6, 1, 9, 5, 2 };
    std::sort(detections_2.begin(), detections_2.end(), 
        [](const int & a, const int & b) -> bool {
            return a > b;
        });
    printVector(detections_2);
    return 0;
}