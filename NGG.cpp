#include <iostream>
#include <cstdlib> // for random number generation
#include <ctime>   // for seeding the random number generator

int main() {
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Generate a random number between 1 and 100
    int secretNumber = (std::rand() % 100) + 1;

    int guess;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I'm thinking of a number between 1 and 100. Try to guess it." << std::endl;

    while (true) {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        attempts++;

        if (guess == secretNumber) {
            std::cout << "Congratulations! You guessed the number (" << secretNumber << ") in " << attempts << " attempts." << std::endl;
            break;
        } else if (guess < secretNumber) {
            std::cout << "Try a higher number." << std::endl;
        } else {
            std::cout << "Try a lower number." << std::endl;
        }
    }

    return 0;
}
