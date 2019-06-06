#include <iostream>

#include "Board.h"

/*Battleship draft. TODO:
 * - add player class;
 * - add shooting;
 * - add main game loop;
 * - add ship sets;
 * - add chars to coordinates
*/


void boardPlaceShipTest();


//============================================
int main()
{
    boardPlaceShipTest();

    return 0;
}


//============================================
void boardPlaceShipTest()
{
    CBoard board_of_one_player{};
    const CShip dummy_ship_1{3, SCoordinates(4, 3), CShip::EBoardOrientation::HORIZONTAL};
    const CShip dummy_ship_2{2, SCoordinates(3, 4), CShip::EBoardOrientation::VERTICAL};

    std::cout << "Place ship{x = 4, y = 3}: ";
    board_of_one_player.PlaceShip(dummy_ship_1);

    std::cout << "Place ship{x = 3, y = 4}: ";
    board_of_one_player.PlaceShip(dummy_ship_2);
    board_of_one_player.Print();

    system("pause");
}

