// main.c++: main program for "twoTriangles (V2)"

#include "GLFWController.h"
#include "ModelView.h"

void createScene(GLFWController& c, ShaderIF* sIF)
{
	// define vertex coordinates for the two triangles
	vec2 vertexPositions[][3] =
	{
		// triangle 1:
		{ { -6.0, 137.0 }, { 2.0, 137.0 }, { -2.0, 145.0 } },
		// triangle 2:
		{ { -6.0, 135.0 }, { 2.0, 135.0 }, { -2.0, 127.0 } }
	};

	c.addModel( new ModelView(sIF, vertexPositions[0]) );
	c.addModel( new ModelView(sIF, vertexPositions[1]) );
}

int main(int argc, char* argv[])
{
	GLFWController c("twoTriangles: V2");
	c.reportVersions(std::cout);

	ShaderIF* sIF = new ShaderIF(
		"shaders/twoTriangles_V2.vsh", "shaders/twoTriangles_V2.fsh");

	createScene(c, sIF);

	// initialize 2D viewing information:
	// Get the overall scene bounding box in Model Coordinates:
	double xyz[6]; // xyz limits, even though this is 2D
	c.getOverallMCBoundingBox(xyz);
	std::cout << "Bounding box: " << xyz[0] << " <= x <= " << xyz[1] << '\n';
	std::cout << "              " << xyz[2] << " <= y <= " << xyz[3] << '\n';
	std::cout << "              " << xyz[4] << " <= z <= " << xyz[5] << "\n\n";
	// Tell class ModelView we initially want to see the whole scene:
	ModelView::setMCRegionOfInterest(xyz);

	glClearColor(1.0, 1.0, 1.0, 1.0);

	c.run();

	delete sIF;

	return 0;
}
