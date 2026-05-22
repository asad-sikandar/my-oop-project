
#include<iostream>
#include<string>
#include<ctime>
using namespace std;

class Game
{
protected:
    int difficulty;
    int score;

public:
    Game(int d)
    {
        difficulty = d;
        score = 0;
    }

    // PURE VIRTUAL FUNCTION (POLYMORPHISM)
    virtual int play() = 0;

    virtual string getGameName() = 0;

    int getScore()
    {
        return score;
    }

    virtual ~Game() {}
};

// ================= WORD SCRAMBLE GAME =================
class WordScramble : public Game
{
public:
    WordScramble(int d) : Game(d) {}

    string getGameName()
    {
        return "Word Scramble";
    }

    int play()
    {
        string answer;

        cout << "**********************" << endl;
        cout << "* WORD SCRAMBLE GAME *" << endl;
        cout << "**********************" << endl;

        if(difficulty == 1)
        {
            string words[5] = {"evolution","array","skeleton","credit","learn"};
            string scrambled[5] = {"volutioen","rayar","tonsklee","cterdi","nlear"};

            for(int i=0;i<5;i++)
            {
                cout << "\nUnscramble the word: " << scrambled[i] << endl;
                cout << "Enter correct word: ";
                cin >> answer;

                if(answer == words[i])
                {
                    cout << "Correct!\n";
                    score++;
                }
                else
                {
                    cout << "Wrong! Correct word is: " << words[i] << endl;
                }
            }
        }

        else if(difficulty == 2)
        {
            string words[5] = {"account","customer","beautiful","asteroid","difficult"};
            string scrambled[5] = {"cnacuot","ecmstoru","utabueifl","taserodi","ffidulcit"};

            for(int i=0;i<5;i++)
            {
                cout << "\nUnscramble the word: " << scrambled[i] << endl;
                cout << "Enter correct word: ";
                cin >> answer;

                if(answer == words[i])
                {
                    cout << "Correct!\n";
                    score++;
                }
                else
                {
                    cout << "Wrong! Correct word is: " << words[i] << endl;
                }
            }
        }

        else
        {
            string words[5] = {"consultant","mysterical","habitually","phenomena","compensate"};
            string scrambled[5] = {"suctanlont","tyrsiemacl","bauthllaiy","menaohpen","pomacesten"};

            for(int i=0;i<5;i++)
            {
                cout << "\nUnscramble the word: " << scrambled[i] << endl;
                cout << "Enter correct word: ";
                cin >> answer;

                if(answer == words[i])
                {
                    cout << "Correct!"<<endl;
                    score++;
                }
                else
                {
                    cout << "Wrong! Correct word is: " << words[i] << endl;
                }
            }
        }

        cout << "\nYour final score is: " << score << " out of 5" << endl;

        score = (score * 10) / 5;

        return score;
    }
};

// ================= WORD SEARCH GAME =================
class WordSearch : public Game
{
public:
    WordSearch(int d) : Game(d) {}

    string getGameName()
    {
        return "Word Search";
    }

    int play()
    {
        string guess;

        cout << "**********************" << endl;
        cout << "* WORD SEARCH GAME   *" << endl;
        cout << "**********************" << endl;

        char grid[5][5] =
        {
            {'P','S','D','E','Q'},
            {'G','T','S','A','U'},
            {'T','A','G','M','E'},
            {'G','C','M','A','U'},
            {'P','K','A','E','E'}
        };

        string words[9] =
        {
            "STACK","stack","Stack",
            "QUEUE","queue","Queue",
            "GAME","game","Game"
        };

        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }

        cout << "\nFind 3 hidden words!\n";

        for(int attempt=0;attempt<3;attempt++)
        {
            cout << "Enter a word: ";
            cin >> guess;

            bool found = false;

            for(int i=0;i<9;i++)
            {
                if(guess == words[i])
                {
                    found = true;
                }
            }

            if(found)
            {
                cout << "Correct! Word found.\n";
                score++;
            }
            else
            {
                cout << "Word not found.\n";
            }
        }

        cout << "GAME OVER!\n";

        score = (score * 10) / 3;

        return score;
    }
};

// ================= PERFORMANCE CLASS =================
class PerformanceReport
{
private:
    int totalScore;
    int gamesPlayed;
    string bestGame;
    int bestPercent;

public:
    PerformanceReport()
    {
        totalScore = 0;
        gamesPlayed = 0;
        bestGame = "none yet";
        bestPercent = 0;
    }

    void update(Game* game, int score)
    {
        totalScore += score;
        gamesPlayed++;

        if(score > bestPercent)
        {
            bestPercent = score;
            bestGame = game->getGameName();
        }
    }

    void showReport()
    {
        int average = 0;

        if(gamesPlayed > 0)
            average = (totalScore * 100) / (gamesPlayed * 10);

        string bestSkill = "Problem Solving";

        if(bestGame == "Word Scramble")
            bestSkill = "Vocabulary Strength";

        else if(bestGame == "Word Search")
            bestSkill = "Pattern Recognition";

        cout << "\n\n";
        cout << "=============================================\n";
        cout << "           GAMING PERFORMANCE REPORT         \n";
        cout << "=============================================\n\n";

        cout << "Total Games Played    : " << gamesPlayed << endl;
        cout << "Total Score           : " << totalScore << "/20" << endl;
        cout << "Average Score         : " << average << "%" << endl;
        cout << "Best Game             : " << bestGame
             << " (" << bestPercent << "%)" << endl;
        cout << "Your Skill            : " << bestSkill << endl;

        cout << "Performance Summary   : ";

        if(average >= 80)
            cout << "Excellent Performance!\nYou can try higher difficulty games.\n";

        else if(average >= 60)
            cout << "Good Job!\nKeep practicing to reach 80%+\n";

        else
            cout << "You can do better\nStart with easier levels next time.\n";

        cout << "==============================================\n";
        cout << "     CONGRATULATIONS! All Games Completed!   \n";
        cout << "==============================================\n\n";
    }
};

// ================= MAIN FUNCTION =================
int main() {
    srand(time(0));

    cout << "***************************************************************\n";
    cout << "             WELCOME TO MINI GAME ARCADE!\n";
    cout << "***************************************************************\n";

    string name;

    cout << "Enter your name : ";
    cin >> name;

    cout << "\nHello " << name << "! Let's start playing.\n";

    PerformanceReport report;

    int choice;
    int difficulty = 1;

    bool played[3] = {false,false,false};

    for(int round=0; round<2; round++)
    {
        cout << "\nWhich game would you like to play?\n";
        cout << "1. Word Scramble\n";
        cout << "2. Word Search\n";

        do
        {
            cout << "Enter your choice(1-2): ";
            cin >> choice;

            if(choice < 1 || choice > 2)
                cout << "Invalid choice!\n";

        } while(choice < 1 || choice > 2);

        Game* game;

        // POLYMORPHISM
        if(choice == 1)
        {
            game = new WordScramble(difficulty);
        }
        else
        {
            game = new WordSearch(difficulty);
        }

        int score = game->play();

        report.update(game, score);

        if(score >= 8)
        {
            difficulty++;
            cout << "Great job! Increasing difficulty level for next game.\n";
        }
        else if(score < 4)
        {
            difficulty--;
            cout << "Keep practicing! Lowering difficulty level for next game.\n";
        }
        else
        {
            cout << "Good effort! Difficulty level stays the same.\n";
        }

        if(difficulty < 1)
            difficulty = 1;

        if(difficulty > 3)
            difficulty = 3;

        delete game;
    }

    report.showReport();

    cout << "Thanks for playing, " << name << "!\n";
    return 0;
}