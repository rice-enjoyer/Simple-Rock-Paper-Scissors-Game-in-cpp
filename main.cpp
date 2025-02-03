#include <iostream>
#include <ctime>

char getUserChoice();
char getComputerChoice();
void showChoice(char choice);
void chooseWinner(char player, char computer);

int main()
{
  char player, computer, again;

  srand(time(NULL));

  std::cout << "********Rock, Paper, Scissors********\n";

  do {
    player = getUserChoice();
    std::cout << "Your choice: ";
    showChoice(player);

    computer = getComputerChoice();
    std::cout << "Computer's choice: ";
    showChoice(computer);

    chooseWinner(player, computer);

    std::cout << "Want to play again? (y/n): ";
    std::cin >> again;
  } while (again == 'y' || again == 'Y');

  std::cout << "\nGoodbye";
  return 0;
}

char getUserChoice()
{
  char player;

  do {
    std::cout << "Choose:\n";
    std::cout << "'r' for Rock\n";
    std::cout << "'p' for Paper\n";
    std::cout << "'s' for Scissors\n";
    std::cin >> player;
  } while (player != 'r' && player != 'p' && player != 's');
  return player;
}

char getComputerChoice()
{
  int num = rand() % 3;

  switch (num) {
    case 0:
      return 'r';
    case 1:
      return 'p';
    case 2:
      return 's';
    }
    return 'r'; // Default return, should never reach here
}

void showChoice(char choice)
{
  switch (choice) {
  case 'r':
    std::cout << "Rock\n";
    break;
  case 'p':
    std::cout << "Paper\n";
    break;
  case 's':
    std::cout << "Scissors\n";
    break;
  }
}

void chooseWinner(char player, char computer)
{
  if (player == computer) {
    std::cout << "It's a tie.\n";
  } else if ((player == 'r' && computer == 's') || 
            (player == 'p' && computer == 'r') || 
            (player == 's' && computer == 'p')) {
    std::cout << "You win.\n";
  } else {
    std::cout << "You lose.\n";
  }
}
