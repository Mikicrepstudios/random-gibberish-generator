#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

std::string generateRandomWord(int length) {
    const std::string charSet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::string randomWord;
    for (int i = 0; i < length; ++i) {
        randomWord += charSet[rand() % charSet.size()];
    }
    return randomWord;
}

void generateAndSaveWords(const std::string& filename, int wordLength, int numberOfWords) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    for (int i = 0; i < numberOfWords; ++i) {
        outFile << generateRandomWord(wordLength) << std::endl;
    }

    outFile.close();
}

int main() {
    srand(static_cast<unsigned>(time(0))); // Seed the random number generator

    int wordLength;
    int numberOfWords;
    std::string filename;

    std::cout << "Enter the length of each word: ";
    std::cin >> wordLength;

    std::cout << "Enter the number of words to generate: ";
    std::cin >> numberOfWords;

    std::cout << "Enter the filename to save the words: ";
    std::cin >> filename;

    generateAndSaveWords(filename, wordLength, numberOfWords);

    std::cout << "Words have been generated and saved to " << filename << std::endl;

    return 0;
}

