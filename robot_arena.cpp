#include <iostream>
#include <stdlib.h>
#include <unistd.h> 
#include <time.h> 
using namespace std;

const int MAX_HEALTH = 20;

int repairDamage(void){
    int x = rand() % 4 + 2;
    return x;
}

int attack(string robot){
	char choice;
	cout <<  "" << robot << ", enter your attack type. Choose a letter between A and D: ";
	cin >> choice;
	int damage = 0;
	switch (choice)
	{
	case 'A': 
		damage = rand() % 3 + 1;
		break;
	case 'B': 
		damage = rand() % 5 + 4;
		break;
	case 'C': 
		damage = rand() % 3 + 9;
		break;
	case 'D': 
		damage = rand() % 5 + 12;
		break;
	default: 
		damage = rand() % 5 + 1;
	}
    return damage;
}

void declareWinner(string robot){
    cout << "Congratulations, " << robot << "! You are the winner!" << endl;
    puts ("Enter a dot ('.') to exit: ");
    int c;
    do {
        c=getchar();
        putchar (c);
    } while (c != '.');
}

string nameRobot(int num){
    string name;
	cout << "Welcome Robot " << num << "!" << endl;
	cout << "Enter your name: ";
	cin >> name;
    cout << "\n";
    return name;
}

void spar(string robot1, string robot2){
    int health1 = MAX_HEALTH;
	int health2 = MAX_HEALTH;

    sleep(1);
    cout << "\n\tReady?..." << flush;
    sleep(1);
    cout <<  "Spar!\n\n" << endl;
    sleep(1);

    while (health1>0 && health2>0) {
        cout << "Robot " << robot1 << "'s health is " << health1 << endl;
        cout << "Robot " << robot2 << "'s health is " << health2 << endl;
        cout << "\n";
        int turn1;
        cout << "" << robot1 << ", will you choose to attack or repair (Attack = 1 | Repair = 2): ";
        cin >> turn1;
        if (turn1 == 1){
            int damage = attack(robot1);
            health2 = health2 - damage;
            cout << "Robot " << robot2 << " damage: " << damage;
            cout << "\n\n";
        }
        if (turn1 == 2){
            int a = repairDamage();
            health1 = health1 + a;
        }

        if(health2 <= 0) {
            declareWinner(robot1);
        }

        int turn2;
        cout << "" << robot2 << ", will you choose to attack or repair (Attack = 1 | Repair = 2): ";
        cin >> turn2;
        if (turn2 == 1){
            int damage = attack(robot2);
            health1 = health1 - damage;
            cout << "Robot " << robot1 << " damage: " << damage;
            cout << "\n\n";
        }
        if (turn2 == 2){
            int a = repairDamage();
            health2 = health2 + a;
        }

        if(health1 <= 0) {
            declareWinner(robot2);
        } else if(health2 <= 0) {
            declareWinner(robot1);
        }
    } 
}

int main() {
    srand(time(0));
    cout << "Welcome to Robot Arena!!!\n\n";

    string robot1 = nameRobot(1);
    string robot2 = nameRobot(2);
   
    spar(robot1, robot2);

    return 0;
}