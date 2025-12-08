#include "Roi.h"

Roi::Roi() {

    image = "static/pieces/bK.svg";
    direction = {
        {0, -1},
        {0, 1},
        {-1, 0},
        {1, 0},
        {-1, 1},
        {1, -1},
        {1, 1},
        {-1, -1}
    };

}