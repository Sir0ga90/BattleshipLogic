#include <iostream>

#include "Board.h"
#include "Player.h"
#include "GameInterface.h"

/*Battleship draft. TODO:
 * - add chars to coordinates;
 * - add enemy board with results of shooting;
 * - more robust check of input;
*/


void testGameInterface();


//============================================
int main() {
    testGameInterface();

    return 0;
}


//============================================
void testGameInterface() {
    CGameInterface game_interface{};
    game_interface.GameMainLoop();

#ifdef NDEBUG
    system("pause");
#endif
}

