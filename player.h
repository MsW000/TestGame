#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

class Player {
private:
    std::string name;
    int health;

public:
    Player(const std::string &playerName, int playerHealth) : name(playerName), health(playerHealth) {}

    void displayStatus() {
        std::cout << "Player: " << name << "\nHealth: " << health << "\n";
    }

    bool isAlive() {
        return health > 0;
    }

    void takeDamage(int damage) {
        health -= damage;
        if (health < 0) {
            health = 0;
        }
        std::cout << name << " Get damage. Health: " << health << "\n";
    }
};

#endif // PLAYER_H