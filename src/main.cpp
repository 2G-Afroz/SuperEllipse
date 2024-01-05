// main.cpp
#include <raylib.h>
#include <vector>
#include <cmath>

int main() {
    	// Initialize raylib
    	InitWindow(850, 850, "My Raylib Project");
      ClearBackground(BLACK);
	
			// Variables
			float r = 200.0f;
			Vector2 centre = {425, 425};
			std::vector<Vector2> points;

			// Getting points of circle
			for(double a = 0; a < PI * 2; a+=0.01){
				float x = r*sin(a);
				float y = r*cos(a);

				x = x + centre.x;
				y = y + centre.y;

				points.push_back(Vector2{x, y});
			}

    	// Main game loop
    	while (!WindowShouldClose()) {
        	// Draw
        	BeginDrawing();
        	DrawText("Hello, 2G-Afroz!", 10, 10, 20, WHITE);

					DrawCircle(centre.x, centre.y, r, WHITE);

					for (size_t i = 0; i < points.size()-1; i++) {
						DrawLine(points.at(i).x, points.at(i).y, points.at(i+1).x, points.at(i+1).y, RED);
					}
					// For the last line
					DrawLine(points.at(0).x, points.at(0).y, points.at(points.size()-1).x, points.at(points.size()-1).y, RED);

        	EndDrawing();
    	}
	
    	// Clean up
	CloseWindow();
	return 0;
}
