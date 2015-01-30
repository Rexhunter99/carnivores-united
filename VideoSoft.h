#pragma once
#ifndef __VIDEOSOFTWARE_H__
#define __VIDEOSOFTWARE_H__

#inlcude "Video.h"
#include <map>
#include <string>


class VideoSoft : public Video
{
public:

	VideoSoft();
	~VideoSoft();

	bool	createTexture( std::string name, std::string filename );
	void	setActiveTexture( std::string name, uint8_t layer = 0 );

private:

	std::map<std::string,Texture*>	texture_list;

	class TextureSoft : public Video::Texture
	{
	public:

		uint32_t	*texture_data;

	private:

	};

	struct optimizations_s {
		uint16_t	mmx:1;
		uint16_t	sse:1;
		uint16_t	sse2:1;
		uint16_t	sse3:1;
		uint16_t	ssse3:1;
		uint16_t	sse41:1;
		uint16_t	sse42:1;
		uint16_t	amd3dnow:1;
		uint16_t	reserved:8;
	} optimizations;

	void	*back_buffer,
			*depth_buffer;

};


#endif // H_VIDEOSOFT_H
