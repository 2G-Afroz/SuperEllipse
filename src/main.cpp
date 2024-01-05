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

/**
 * @brief Generates a set of 2D points representing a superellipse.
 *
 * This function calculates points on a superellipse, a two-dimensional geometric
 * shape defined by its center position (`pos`), semi-major axis (`a`), semi-minor
 * axis (`b`), and an exponent parameter (`n`).
 *
 * @param pos The center position of the superellipse.
 * @param a   The semi-major axis length.
 * @param b   The semi-minor axis length.
 * @param n   The exponent parameter, controlling the shape of the superellipse.
 *
 * @return A vector of Vector2 representing the points on the superellipse.
 */
std::vector<Vector2> getSuperEllipsePoints(Vector2 pos, float a, float b, float n){

	std::vector<Vector2> points;

	// Validate parameters
    if (a < 0 || b < 0 || n <= 0) {
        return points;
    }

	// Getting points of Super Ellipse
	for(double ang = 0; ang < PI * 2; ang+=0.01){
		float x = pow(abs(cos(ang)), 2/n) * a * sgn(cos(ang));
		float y = pow(abs(sin(ang)), 2/n) * b * sgn(sin(ang));

		x = x + pos.x;
		y = y + pos.y;

		points.push_back(Vector2{x, y});
	}

	return points;
}

int main() {
 	// Initialize raylib
	int width = 850;
	int height = 850;
 	InitWindow(width, height, "SuperEllipse");
  ClearBackground(BLACK);
	SetTargetFPS(20);

	// Variables
	Vector2 centre = {425, 425};
	std::vector<Vector2> points;
	float n = 2.0f;
	float a = 200.0f;
	float b = 200.0f;

 	// Main game loop
 	while (!WindowShouldClose()) {
		ClearBackground(BLACK);
   	// Draw
   	BeginDrawing();
   	DrawText("Hello, 2G-Afroz!", 10, 10, 20, WHITE);

		// Gettin SuperEllipse points
		points = getSuperEllipsePoints(centre, a, b, n);

		// Drawing SuperEllipse
		for (size_t i = 0; i < points.size()-1; i++) {
			DrawLine(points.at(i).x, points.at(i).y, points.at(i+1).x, points.at(i+1).y, WHITE);
		}
		// For the last line
		DrawLine(points.at(0).x, points.at(0).y, points.at(points.size()-1).x, points.at(points.size()-1).y, WHITE);

		// Drawing values
		DrawText(TextFormat("a: %0.2f\nb: %0.2f\nn: %0.2f", a, b, n), 10, 40, 15, WHITE);

   	EndDrawing();
 	}
	
  // Clean up
	CloseWindow();
	return 0;
}
