#pragma once

#include <stdint.h>

struct SCoordinates
{

    using TCoord = int16_t;

    SCoordinates() = default;
    SCoordinates(const TCoord x, const TCoord y);
    SCoordinates(const SCoordinates& coordinates);

    TCoord coord_x;
    TCoord coord_y;
};

