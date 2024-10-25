#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

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

void showHelp() {
    std::cout << "Usage: program [-f filename] [-l wordLength] [-n numberOfWords] [-h]\n"
              << "Options:\n"
              << "  -f filename     Specify the output filename\n"
              << "  -l wordLength   Specify the length of each word\n"
              << "  -n numberOfWords Specify the number of words to generate\n"
              << "  -h              Show this help message\n";
}

int main(int argc, char* argv[]) {
    srand(static_cast<unsigned>(time(0))); // Seed the random number generator

    int wordLength = 0;
    int numberOfWords = 0;
    std::string filename;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "-f" && i + 1 < argc) {
            filename = argv[++i];
        } else if (arg == "-l" && i + 1 < argc) {
            wordLength = std::stoi(argv[++i]);
        } else if (arg == "-n" && i + 1 < argc) {
            numberOfWords = std::stoi(argv[++i]);
        } else if (arg == "-h") {
            showHelp();
            return 0;
        } else {
            std::cerr << "Unknown option: " << arg << std::endl;
            showHelp();
            return 1;
        }
    }

    // Validate input if not provided
    if (filename.empty()) {
        std::cout << "Enter the filename to save the words: ";
        std::cin >> filename;
    }
    if (wordLength == 0) {
        std::cout << "Enter the length of each word: ";
        std::cin >> wordLength;
    }
    if (numberOfWords == 0) {
        std::cout << "Enter the number of words to generate: ";
        std::cin >> numberOfWords;
    }

    generateAndSaveWords(filename, wordLength, numberOfWords);

    std::cout << "Words have been generated and saved to " << filename << std::endl;

    return 0;
}
