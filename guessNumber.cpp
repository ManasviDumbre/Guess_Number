#include <iostream>
#include <cstdlib>  // For std::rand() and std::srand()
#include <ctime>    // For std::time()
#include<limits>

using namespace std;

// Function prototypes
void playGame();
bool playAgain();

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(0)));

    char choice;
    do {
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore any leftover characters in the input buffer
    } while (choice == 'y' || choice == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}

void playGame() {
    const int MIN_NUMBER = 1;
    const int MAX_NUMBER = 100;
    int numberToGuess = std::rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;
    int playerGuess = 0;
    int numberOfTries = 0;

    cout << "Guess the number between " << MIN_NUMBER << " to " << MAX_NUMBER << ": ";

    while (true) {
        cin >> playerGuess;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore any leftover characters in the input buffer

        if (cin.fail()) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input. Please enter an integer.\n";
            cout << "Guess the number between " << MIN_NUMBER << " and " << MAX_NUMBER << ": ";
            continue;
        }

        numberOfTries++;

        if (playerGuess < MIN_NUMBER || playerGuess > MAX_NUMBER) {
            cout << "Your guess is out of bounds. Please guess a number between " << MIN_NUMBER << " and " << MAX_NUMBER << ": ";
        } else if (playerGuess < numberToGuess) {
            cout << "Too low! Try again: ";
        } else if (playerGuess > numberToGuess) {
            cout << "Too high! Try again: ";
        } else {
            cout << "Congratulations! You've guessed the number in " << numberOfTries << " tries.\n";
            break;
        }
    }
}
