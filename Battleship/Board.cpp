#include <iostream>

#include "Board.h"


CBoard::CBoard() :
    mainBoard(BOARD_SIZE, TBoardLine(BOARD_SIZE, CBoardField())) {}


void CBoard::PlaceShip(CShip new_ship) {
    if (IsPossibleToPlaceShip(new_ship)) {
        auto ship = std::make_shared<CShip>(new_ship);

        ships.push_back(ship);

        const auto ship_head = new_ship.GetPivotPoint();
        PlaceShipUnit(ship_head, ship);

        const auto ship_size = new_ship.GetShipSize();

        if (ship_size > 1) {
            const auto pos_orientation{new_ship.GetBoardOrientation()};
            auto next_ship_unit{ship_head};

            for (uint16_t ship_unit_cntr = 1; ship_unit_cntr < ship_size; ++ship_unit_cntr) {

                if (pos_orientation == CShip::EBoardOrientation::HORIZONTAL) {
                    next_ship_unit.coord_x--;
                    PlaceShipUnit(next_ship_unit, ship);
                }
                else { //VERTICAL
                    next_ship_unit.coord_y--;
                    PlaceShipUnit(next_ship_unit, ship);
                }
            }
        }

        std::cout << "Ship placed.\n";

    }
    else {
        std::cerr << "Can't place ship.\n";
    }
}


void CBoard::Print() {
    for (auto& lane_it = mainBoard.rbegin(); lane_it != mainBoard.rend(); ++lane_it) {
        for (auto& field_it = lane_it->begin(); field_it != lane_it->end(); ++field_it) {
            std::cout << static_cast<uint16_t>(field_it->GetState()) << " ";
        }

        std::cout << "\n";
    }
}


CBoardField::EState CBoard::ProcessInputShoot(SCoordinates shoot_coordinates) {
    auto& cur_field = GetBoardField(shoot_coordinates);
    auto cur_field_state = cur_field.GetState();

    if (cur_field_state == CBoardField::EState::EMPTY) {
        cur_field.SetState(CBoardField::EState::HIT);
    }
    else if (cur_field_state == CBoardField::EState::FILLED) {
        ProcessShipHit(cur_field_state, shoot_coordinates);

        cur_field.SetState(CBoardField::EState::HIT);
    }
    else {
        //do nothing
    }

    return cur_field_state;
}


CBoardField::EState CBoard::GetFieldState(const SCoordinates shoot_coordinates) {
    return GetBoardField(shoot_coordinates).GetState();
}


CBoardField& CBoard::GetBoardField(const SCoordinates field_coordinates) {
    return mainBoard.
        at(field_coordinates.coord_y).
        at(field_coordinates.coord_x);
}


void CBoard::PlaceShipUnit(const SCoordinates& unit_coordinates,
                           CShipUnit::TShipPtr& owner_ship) {
    auto& cur_field = GetBoardField(unit_coordinates);
    cur_field.SetState(CBoardField::EState::FILLED);
    
    CShipUnit ship_unit{};

    ship_unit.SetShip(owner_ship);
    cur_field.SetShipUnit(ship_unit);
}


bool CBoard::IsFieldAppropriate(const SCoordinates& field_coordinates) {
    return GetFieldState(field_coordinates) == CBoardField::EState::EMPTY;
}


bool CBoard::IsPossibleToPlaceShip(CShip ship) {
    auto is_possible = false;
    const auto pos_orientation{ship.GetBoardOrientation()};
    const auto ship_head_x{ship.GetPivotPoint().coord_x};
    const auto ship_head_y{ship.GetPivotPoint().coord_y};

    if (IsCoordinateInBoardBounds(ship_head_x) && IsCoordinateInBoardBounds(ship_head_y)) {
        if (pos_orientation == CShip::EBoardOrientation::HORIZONTAL) {
            is_possible = IsPossibleToPlaceShipInOneOrientation(ship_head_y,
                                                                ship_head_x,
                                                                ship.GetShipSize());
        }
        else { //VERTICAL
            is_possible = IsPossibleToPlaceShipInOneOrientation(ship_head_x,
                                                                ship_head_y,
                                                                ship.GetShipSize());
        }

    }

    return is_possible;
}


bool CBoard::IsPossibleToPlaceShipInOneOrientation(SCoordinates::TCoord ship_head_a,
                                                   SCoordinates::TCoord ship_head_b,
                                                   CShip::TShipSize ship_size) {
    // a and b both could be x or y in accordance to board_orientation

    bool is_possible = false;
    constexpr SCoordinates::TCoord OBSERVED_SPACE_A = 1u;
    const SCoordinates::TCoord OBSERVED_SPACE_B = ship_size + 1;

    if (IsCoordinateInBoardBounds(ship_head_b + 1 - ship_size)) {
        for (auto a = ship_head_a + 1; a > ship_head_a - OBSERVED_SPACE_A; --a) {

            if (IsCoordinateInBoardBounds(a)) {
                for (auto b = ship_head_b + 1; b > ship_head_b - OBSERVED_SPACE_B; --b) {

                    if (IsCoordinateInBoardBounds(b)) {
                        is_possible = IsFieldAppropriate(SCoordinates(b, a));

                        if (!is_possible) {
                            break;
                        }
                    }
                    else {
                        continue;
                    }

                }
            }
            else {
                continue;
            }

        }
    }


    return is_possible;
}


bool CBoard::IsCoordinateInBoardBounds(SCoordinates::TCoord coord) {
    bool is_in_bounds = true;

    if (coord < 0 || coord >(BOARD_SIZE - 1)) {
        is_in_bounds = false;
    }

    return is_in_bounds;
}


void CBoard::ProcessShipHit(CBoardField::EState& cur_field_state,
                            const SCoordinates& shoot_coordinates) {
    const auto& cur_ship_state =
        GetBoardField(shoot_coordinates).GetShipUnit().GetShipState();

    switch (cur_ship_state) {
        case CShip::ESate::SHOT_DOWN:
        {
            cur_field_state = CBoardField::EState::SHOT_DOWN;
        }
        case CShip::ESate::SUNK:
        {
            cur_field_state = CBoardField::EState::SUNK;
        }
        default:
            break;
    }

}

