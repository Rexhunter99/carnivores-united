#pragma once

#ifndef H_VIDEO_H
#define H_VIDEO_H

#include <stdint.h>
#include <string>
#include <glm/fwd.hpp>


class Video
{
public:

	class Texture;

	// -- 3D Hardware initialisation
	virtual bool init() = 0;

	// -- 3D Hardware start up and shut down
	virtual bool startUp() = 0;
	virtual bool shutDown() = 0;

	// -- Resources
	virtual Texture* loadTexture( std::string p_filename ) = 0;
	virtual Texture* loadTexture( void* p_data, uint16_t p_width, uint16_t p_height ) = 0;

	// -- Graphical User Interface
	virtual void drawText( glm::vec2 p_origin, std::string p_text ) = 0;
	virtual void drawPicture( glm::vec2 p_origin, float p_scale, Texture* p_image ) = 0;

	// -- Render world elementst
	virtual void renderTerrain() = 0 = 0;
	virtual void renderWater();
	virtual void renderSky() = 0;

	// --
	virtual void renderModel() = 0;

	// -- This is just a bsee object that should never be directly created
	class Texture
	{
	public:

		uint16_t	width,
					height;
		struct {
			uint8_t		mipmaps:1;
			uint8_t		glow:1;
		} properties;

	private:
		~Texture();
	};

	int		canvasWidth,
			canvasHeight;

protected:


};

#endif // H_VIDEO_H
