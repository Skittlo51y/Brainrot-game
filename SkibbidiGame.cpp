
enum Action {  // Enumeration for possible actions
    Attack,
    Defend,
    Heal
};

struct Player {  // Struct for player and enemy stats
    int health;
    int attackPower;
    float defense;
};

void battle(Player &player, Player &enemy) {
    while (player.health > 0 && enemy.health > 0) {  // Fight loop
        std::cout << "Choose your action:\n";
        std::cout << "1. Attack\n2. Defend\n3. Heal\n";
        const int action;
        std::cin >> action;

        if (action == Attack) {
            std::cout << "You attack the enemy!\n";
            int damage = player.attackPower - enemy.defense;
            if (damage > 0) enemy.health -= damage;
            std::cout << "Enemy health: " << enemy.health << "\n";
        } else if (action == Defend) {
            std::cout << "You defend!\n";
            player.defense += 5;  // Temporarily boost defense
        } else if (action == Heal) {
            std::cout << "You heal yourself!\n";
            player.health += 10;
            if (player.health > 100) player.health = 100;
        } else {
            std::cout << "Invalid action!\n";
            continue;
        }

        // Enemy's turn
        int enemyAction = rand() % 2;  // Randomize enemy action
        if (enemyAction == 0) {
            std::cout << "Enemy attacks you!\n";
            int damage = enemy.attackPower - player.defense;
            if (damage > 0) player.health -= damage;
            std::cout << "Your health: " << player.health << "\n";
        } else {
            std::cout << "Enemy defends!\n";
            enemy.defense += 3;
        }

        if (player.health <= 0) {
            std::cout << "You lost the battle!\n";
            break;
        }
        if (enemy.health <= 0) {
            std::cout << "You won the battle!\n";
            break;
        }

        continue;  // Continue to the next round
    }

    return;
}

int main() {
    const Player player = {100, 20, 5};  // Initialize player stats
    const Player enemy = {80, 15, 3};   // Initialize enemy stats

    battle(player, enemy);

    return 0;
}
