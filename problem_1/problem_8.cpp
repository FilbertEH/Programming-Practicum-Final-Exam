//Problem 8
//Write a program to merge two sorted lists into one sorted list
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

int main() {
    std::cout << "Merge Sorted Lists\n";
    std::ifstream testFile("test.txt");

    if (!testFile) {
        std::cerr << "Error: Could not open test.txt" << std::endl;
        return 1;
    }

    std::string line;
    int num;
    int i = 1;
    
    while (std::getline(testFile, line)) {
        std::getline(testFile, line);
        std::stringstream ss1(line);
        std::vector<int> list1;
        while (ss1 >> num) {
            list1.push_back(num);
        }
        
        std::getline(testFile, line);
        std::stringstream ss2(line);
        std::vector<int> list2;
        while (ss2 >> num) {
            list2.push_back(num);
        }
        
        std::vector<int> merged;
        size_t i = 0, j = 0;
        
        while (i < list1.size() && j < list2.size()) {
            if (list1[i] <= list2[j]) {
                merged.push_back(list1[i]);
                i++;
            } else {
                merged.push_back(list2[j]);
                j++;
            }
        }
        while (i < list1.size()) {
            merged.push_back(list1[i]);
            i++;
        }
        while (j < list2.size()) {
            merged.push_back(list2[j]);
            j++;
        }
        
        std::getline(testFile, line);
        std::getline(testFile, line);
        std::stringstream ss_expect(line);
        std::vector<int> expected;
        while (ss_expect >> num) {
            expected.push_back(num);
        }
        
        if (merged == expected) {
            std::cout << "Test Case " << i << " Passed\n";
        } else {
            std::cout << "Test Case " << i << " Failed\n";
        }
        std::cout << "  Input:\n    ";
        for (int num : list1) {
            std::cout << num << " ";
        }
        std::cout << "\n    ";
        for (int num : list2) {
            std::cout << num << " ";
        }
        std::cout << "\n";

        std::cout << "  Expected: ";
        for (int num : expected) {
            std::cout << num << " ";
        }
        std::cout << "\n";
        
        std::cout << "  Computed: ";
        for (int num : merged) {
            std::cout << num << " ";
        }
        std::cout << "\n\n";
        i++;
    }
    testFile.close();
    return 0;
}