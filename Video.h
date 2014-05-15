#pragma once

#ifndef H_VIDEO_H
#define H_VIDEO_H

#include <stdint.h>
#include <string>


class Video
{
public:

	// -- 3D Hardware initialisation
	bool init();

	// -- 3D Hardware start up and shut down
	bool startUp();
	bool shutDown();

	// -- Resources
	void loadTexture();

	// -- Graphical User Interface
	void drawText( uint16_t p_x, uint16_t p_y, std::string p_text );
	void drawPicture();

	// -- Render world elements
	void renderTerrain();
	void renderWater();
	void renderSky();

	// --
	void renderModel();

	class Texture
	{
	public:

	protected:

	};

protected:


};

#endif // H_VIDEO_H
