//Problem 5
//Question: Write a program to check if a given string is a palindrome.
#include <iostream>
#include <fstream>
#include <string>

std::string reverseString(std::string in) {
    std::string out = in;
    int length = in.length();
    for(int i = 0; i < length/2; i++) {
        char temp = out[i];
        out[i] = out[length - 1 - i];
        out[length - 1 - i] = temp;
    }
    return out;
}

int main() {
    std::cout << "Palindrome Check\n";
    std::ifstream testFile("test.txt");

    if (!testFile) {
        std::cerr << "Error: Could not open test.txt" << std::endl;
        return 1;
    }

    std::string line, input, expect, output, result;
    int i = 1;
    while (std::getline(testFile, line)) {
        input = line.substr(7);  
        std::getline(testFile, line);
        expect = line.substr(8);  
        output = reverseString(input);

        if (output == input) {
            result = "yes";
        } else {
            result = "no";
        }

        if (result == expect) {
            std::cout << "Test Case " << i << " Passed\n";
        } else {
            std::cout << "Test Case " << i << " Failed\n";
        }
        
        std::cout << "  Input String    : " << input << "\n";
        std::cout << "  Reversed String : " << output << "\n";
        std::cout << "-- Is it a palindrome? --\n";
        std::cout << "      Expected: " << expect << "\n";
        std::cout << "      Computed: " << result << "\n\n";
        i++;
    }
    testFile.close();
    return 0;
}