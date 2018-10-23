
// Description: This program implements a "TextTwist" game, which outputs all
// words at least three letters long using characters supplied by a user email:


#include "TextTwist.h"
#include <iostream>
int main() {
  bool run = true;
  std::cout << "Welcome to the game!" << std::endl;
  while (run) {
    TextTwist newGame; // create a new game
    newGame.solve();   // solve
    std::cout << "Here are the results: " << std::endl;
    newGame.printFinal(); // print results
    std::cout << "Continue playing the game? Enter Y/N" << std::endl;
    std::string playAgain;
    std::cin >> playAgain;
    if (playAgain[0] == 'n' || playAgain[0] == 'n'){
      run = false;
    }
  }
}
