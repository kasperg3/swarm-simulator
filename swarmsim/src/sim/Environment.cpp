#include "Environment.h"

namespace SwarmSim {
Environment::Environment() {
}

Environment::~Environment() {
}

}  // namespace SwarmSim    void Environment::drawScene()
    void Environment::drawScene()
    {
        size_t poly_id = 0;
        Color colour;

        for (auto polygon : scene_)
        {
            switch (scene_types_[poly_id])
            {
            case OUT_OF_BOUNDS:
                colour = RED;
                break;
            case AREA_OF_OPERATION:
                colour = RED;
                break;
            case PLAIN:
                colour = YELLOW;
                break;
            case FOREST:
                colour = GREEN;
                break;
            case LAKE:
                colour = BLUE;
                break;
            }

            for (size_t i = 1; i < polygon.size(); i++)
            {
                glm::dvec2 start = polygon[i - 1];
                glm::dvec2 end = polygon[i];
                DrawLine(start[0], start[1], end[0], end[1], colour);

                if (i + 1 == polygon.size())
                {
                    DrawLine(end[0], end[1], polygon[0][0], polygon[0][1], colour);
                }
            }
            poly_id++;
        }
    }

