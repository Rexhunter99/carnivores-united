#pragma once

#ifndef H_VIDEOGL_H
#define H_VIDEOGL_H

#inlcude "Video.h"


class VideoGL : public Video
{
public:

	bool init();
	bool startUp();
	bool shutDown();

	class TextureGL : public Video::Texture
	{
	public:

		uint32_t	textureID;
        bool		hasMipmaps;

	private:

	};

private:

};


#endif // H_VIDEOGL_H
