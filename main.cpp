#include <iostream>
#include <cstdlib>
#include <string>
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
    int globalScore = 0;
    int globalScorePc = 0;
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
                if (choice == 'r')
                {
                    std::cout << "Our rocks clash. It's a tie! ";
                }
                else if (choice == 'p')
                {
                    std::cout << "Our papers fly. It's a tie! ";
                }
                else
                {
                    std::cout << "Our scissors clash. It's a tie! ";
                }
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

            globalScore++;
            std::cout << "GG, you win!\n";
        }
        else
        {
            globalScorePc++;
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

    // 1 If the global score is a tie, it displays the message "It was a tight match. You are a worthy opponent!".
    if (globalScore == globalScorePc)
    {
        std::cout << "It was a tight match. You are a worthy opponent";
    }
    else if (globalScore < globalScorePc)
    {
        // 2 If the computer wins by only one game difference, for example 2 games to 1, it displays the message “I won! The global score is 2-1”.
        if (globalScorePc - globalScore == 1)
        {
            std::cout << "I won! The global score is " << globalScorePc << "-" << globalScore;
        }
        // 3 If the computer wins by two or more game difference, for example 3 games to 1, it displays the message "I won! The global score is 3-1. You are a weak opponent!".
        else
        {
            std::cout << "I won! The global score is " << globalScorePc << "-" << globalScore << ". You are a weak opponent!";
        }
    }
    else
    {
        // 4 If the computer looses by one game difference, for example 1 game to 2, it displays the message "You won! The global score is 1-2".
        if (globalScore - globalScorePc == 1)
        {
            std::cout << "You won! The global score is " << globalScore << "-" << globalScorePc;
        }
        // 5. If the computer looses by two or more game difference, for example 1 game to 3, it displays the message "You won! The global score is 1-3. Congrats, you are a tough player!".
        else
        {
            std::cout << "You won! The global score is " << globalScore << "-" << globalScorePc << ". Congrats, you are a tough player!";
        }
    }
}
