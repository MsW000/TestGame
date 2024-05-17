#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <vector>
#include "player.h" // Include Player.h to access the Player class

// Update the rest of your code to utilize the Player class as needed



class Inventory {
private:
    std::vector<std::string> items;

public:
    void addItem(const std::string& item) {
        items.push_back(item);
    }

    void displayInventory() {
        if (items.empty()) {
            // std::cout << "Inventory is empty\n";
            return;
        }
        for (const std::string& item : items) {
            std::cout << "- " << item << std::endl;
        }
    }
};

class Enemy {
private:
    std::string type;
    int damage;

public:
    Enemy(const std::string &enemyType, int enemyDamage) : type(enemyType), damage(enemyDamage) {}

    void attack(Player &player) {
        std::cout << "Enemy " << type << " attack!\n";
        player.takeDamage(damage);
    }
};

void displayMenu() {
    int uc = 0;

    std::cout << "Choose your game localization: \n1. English\n2. Russian\n";
    std::cin >> uc;

    std::string user_reply;
    if (uc == 1) {
        std::cout << "You chose English. Are you sure you want to continue? (yes/no)\n";
    } else if (uc == 2) {
        std::cout << "You chose Russian. Are you sure you want to continue? (yes/no)\n";
    }

    std::cin >> user_reply;
    if (user_reply == "yes") {
        std::cout << "Nice! We can begin the story.\n";
    } else {
        std::cout << "Exiting the game.\n";
        exit(0);
    }
}

class History : public Player {
private:
    Inventory inventory;

public:
    History(const std::string& playerName, int playerHealth) : Player(playerName, playerHealth) {}

    void addToInventory(const std::string& item) {
        inventory.addItem(item);
        std::cout << item << " added to your inventory!\n";
    }

    void displayInventory() {
        int sword;
        int costumeAdventure;
        int food;
        int waterBottle;

        inventory.displayInventory();
    }
    
    void printWithDelay(const std::string& text, int delay) {
        for (char c : text) {
            std::cout << c << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        }
    }
   
    void printWelcomeMessage() {
        std::string welcomeText = "Welcome to the game 'Journey to the Forgotten Valley'!\n";
        printWithDelay(welcomeText, 50);

        std::string storyText = "\n\nIt was a quiet non-intrusive day, as always. But suddenly you receive a mysterious letter from the letter carrier. Which is surprising because you haven't corresponded with anyone for a long time. You lead a quiet and very private and measured life. What would you prefer to do with the letter?\n";
        printWithDelay(storyText, 50);

        std::string options = "1. Open the letter\n2. Remove the letter\n";
        printWithDelay(options, 50);

    int choice;
    std::cin >> choice;

    std::string openLetterText;
    std::string viewPhoto; // Declare viewPhoto here

    // Declare optPhoto here to ensure initialization before use
    std::string optPhoto;
    std::string firstStep;
    switch (choice) {
        case 1:
            std::cout << "You decided to open the letter. Exciting!\n";
            // Perform actions for opening the letter
            openLetterText = "After opening the letter, you find that your friend asks you to come to the forgotten valley. A place that is considered long forgotten for the majority of people. You have heard that this mysterious place, according to legend, hides some ancient secret.\n";
            printWithDelay(openLetterText, 50);

            firstStep = "\n\nYou read the letter and immediately began to pack your things.  To figure out what's going on.\n\t  After all, your friend is not one of those who would just write to you.  And I certainly wouldn’t ask anyone for help.\n\n\tYou immediately collect your luggage and then hit the road.\n";
            printWithDelay(firstStep, 50);


            break;
        case 2:
            std::cout << "You chose to remove the letter. Interesting choice!\n";
            // Perform actions for removing the letter
            viewPhoto = "Then you continued working in the garden. You need to go to the shed to get the tool. There you found a photo with your friend.\n\t\t View photos?\n";
            printWithDelay(viewPhoto, 50);

            optPhoto = "1. yes\n2. no\n"; // Initialize optPhoto

            int photoChoice;
            std::cout << optPhoto;
            std::cin >> photoChoice;

            if (photoChoice == 1) {
                std::cout << "You chose to view the photos.\n";
                // Perform actions for viewing the photos
                std::cout << "You look at the photo with your friend.  To tell the truth, you haven’t had many friends in your entire life.  But in this photo you look very happy.\n";
            } else if (photoChoice == 2) {
                std::cout << "You chose not to view the photos.\n";
                // Perform actions for not viewing the photos
                std::string taketool;
                taketool = "You remember when you were alone.  And there was one person who did not consider you an outcast.  This was your friend.\n Take a tool and go to work?\n";
                printWithDelay(taketool, 50);
                
                taketool = "1. yes\n2. no\n";
                int takechoice;
                std::cout << taketool;
                std::cin >> takechoice;

                if(takechoice == 1) {
                    std::cout << "You took the tool and went to work.\n";
                }else {
                    std::cout << "You have decided not to go to work today.\n";
                }
            }
            break;
        default:
            std::cout << "Invalid choice. Please select 1 or 2.\n";
            break;
        }
    } 

    void chapterOun(){
        std::string takeBug = "\t0. You took your: 'adventurer' costume \n\t1.sword - 3 unit's of damage\n\t2.food - 2 apple (Oune apple 2 points)\n\t3. Water in bottle. (One bottle restores 50 points)\n";
        printWithDelay(takeBug, 50);
        
        Player player("Edward", 100);
        Player slime("Slime", 10);
        
        std::string ouneEnemy= "Along the way you met a slug. This is the weakest monster that exists in this world.  What do you want to do with it?\n\t1.Attack\n\t2.Pass by\n\n";
    while(player.isAlive() && slime.isAlive()){
        printWithDelay(ouneEnemy, 50);
        
        int slimeChoice = 0;
        std::cin >> slimeChoice;


        if (slimeChoice == 1){
            std::cout << "You decide to attack the slime." << std::endl;
            slime.takeDamage(3);
        } else {
            std::cout << "The slime attacked you but missed." << std::endl;
        }
        
        player.displayStatus();
        slime.displayStatus();
     }
    }

};



int main() {
    displayMenu();
    History history("Edward", 100);

    Player player("Edward", 100);
    Enemy enemy("Monster", 25);

    history.addToInventory("Bag");

    history.printWelcomeMessage();
    player.displayStatus();
    history.chapterOun();

    return 0;
}