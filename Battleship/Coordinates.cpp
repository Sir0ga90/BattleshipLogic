#include "Coordinates.h"


SCoordinates::SCoordinates(const TCoord x, const TCoord y) :
    coord_x{x}, //TODO: add check for min and max vals
    coord_y{y}
{}


SCoordinates::SCoordinates(const SCoordinates& coordinates) :
    coord_x{coordinates.coord_x},
    coord_y{coordinates.coord_y}
{}
