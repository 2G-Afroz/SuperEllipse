// main.cpp
#include <raylib.h>
#include <vector>
#include <cmath>

/**
 * @brief Determines the sign of a given double value.
 *
 * This function returns an integer representing the sign of the input value:
 * - If the input value is greater than 0, it returns 1.
 * - If the input value is less than 0, it returns -1.
 * - If the input value is equal to 0, it returns 0.
 *
 * @param d The double value for which the sign is to be determined.
 * @return An integer representing the sign of the input value.
 */
int sgn(double d){
	return (d > 0) ? 1 : (d < 0 ? -1 : 1);
}

int main() {
    	// Initialize raylib
    	InitWindow(850, 850, "My Raylib Project");
      ClearBackground(BLACK);
	
			// Variables
			Vector2 centre = {425, 425};
			std::vector<Vector2> points;

			float n = 1.5f;
			float a = 200.0f;
			float b = 200.0f;

			// Getting points of circle
			for(double ang = 0; ang < PI * 2; ang+=0.01){
				// float x = r*sin(a);
				// float y = r*cos(a);

				float x = pow(abs(cos(ang)), 2/n) * a * sgn(cos(ang));
				float y = pow(abs(sin(ang)), 2/n) * b * sgn(sin(ang));

				x = x + centre.x;
				y = y + centre.y;

				points.push_back(Vector2{x, y});
			}

    	// Main game loop
    	while (!WindowShouldClose()) {
        	// Draw
        	BeginDrawing();
        	DrawText("Hello, 2G-Afroz!", 10, 10, 20, WHITE);

					for (size_t i = 0; i < points.size()-1; i++) {
						DrawLine(points.at(i).x, points.at(i).y, points.at(i+1).x, points.at(i+1).y, WHITE);
					}
					// For the last line
					DrawLine(points.at(0).x, points.at(0).y, points.at(points.size()-1).x, points.at(points.size()-1).y, WHITE);

        	EndDrawing();
    	}
	
    	// Clean up
	CloseWindow();
	return 0;
}
