#pragma once

#ifndef H_VIDEOSOFT_H
#define H_VIDEOSOFT_H

#inlcude "Video.h"


class VideoSoft : public Video
{
public:

	VideoSoft();
	~VideoSoft();

	bool init();
	bool startUp();
	bool shutDown();

	/**
	** All TextureSoft textures are 32-bit internally, regardless of the color depth of the canvas.
	**/
	class TextureSoft : public Video::Texture
	{
	public:

		uint32_t*	textureData;
		uint16_t	width, height;

	private:

	};

private:

	struct {
		uint16_t	mmx:1;
		uint16_t	sse:1;
		uint16_t	sse2:1;
		uint16_t	sse3:1;
		uint16_t	ssse3:1;
		uint16_t	sse41:1;
		uint16_t	sse42:1;
		uint16_t	amd3dnow:1;
	} optimisations;

	rgb24_t		*frontBuffer;
	rgb24_t		*backBuffer;
	uint16_t	*depthBuffer;

};


#endif // H_VIDEOSOFT_H
