#include <iostream>
/*
 * topic        C++ programming: iteration and selection statements
 * program      Rock paper scissors
 * usage        ./"Rock paper scissors"
 * compile      g++ -o "Rock paper scissors" "Rock paper scissors.cpp"
 * description  Rock, paper, scissors. The player who wins 3 out of 5 rounds wins a game
 *
 */
int main()
{
    // 1. The human plays first by entering 'R' or 'r' for rock, 'P', or 'p' for paper, and 'S', or 's' for scissors.
    char choice, pcChoice;
    int score, pcScore;
    // 2. The computer randomly selects one of the following moves: rock, paper, or scissors.
    int random;
    // 3. The program displays the moves made by both players, along with the score after each round. For example, if the human's move is rock and the computer's move is scissors, it displays "Your rock smashes my scissors. You win! ".
    // 4. The player who wins 3 rounds wins a game.
    bool game = true;
    do
    {
        score = 0;
        pcScore = 0;
        random = std::rand() % 3;

        while (pcScore < 3 && score < 3)
        {
            pcChoice = ' ';
            random = std::rand() % 3;
            std::cout << "Enter your choice (r, p, or s): ";
            std::cin >> choice;
            choice = std::tolower(choice);
            // generates random number and assigns pcChoice
            if (random == 0)
            {
                pcChoice = 'r';
            }
            else if (random == 1)
            {
                pcChoice = 'p';
            }
            else
            {
                pcChoice = 's';
            }

            if (choice == pcChoice)
            {
                std::cout << "Tie! ";
            }
            else if (choice == 'r' && pcChoice == 's')
            {
                score++;
                std::cout << "Your rock smashes my scissors. You win! ";
            }
            else if (choice == 'p' && pcChoice == 'r')
            {
                score++;
                std::cout << "Your paper covers my rock. You win! ";
            }
            else if (choice == 's' && pcChoice == 'p')
            {
                score++;
                std::cout << "Your scissors cut my paper. You win! ";
            }
            else if (choice == 'r' && pcChoice == 'p')
            {
                pcScore++;
                std::cout << "My paper covers your rock. I win! ";
            }
            else if (choice == 'p' && pcChoice == 's')
            {
                pcScore++;
                std::cout << "My scissors cut your paper. I win! ";
            }
            else if (choice == 's' && pcChoice == 'r')
            {
                pcScore++;
                std::cout << "My rocks smashes your scissors. I win! ";
            }
            if (score > pcScore)
            {
                std::cout << "The score is " << score << "-" << pcScore << " in your favor.\n";
            }
            else
            {
                std::cout << "The score is " << pcScore << "-" << score << " in my favor.\n";
            }
            std::cout << "\n";
        }
        if (score > pcScore)
        {

            std::cout << "GG, you win!\n";
        }
        else
        {
            std::cout << "GG, I win!\n";
        }
        char playAgain;
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;
        if (playAgain == 'n' || playAgain == 'N')
        {
            game = false;
        }
    } while (game == true);
}
