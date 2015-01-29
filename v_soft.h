#ifndef H_V_SOFT_H
#define H_V_SOFT_H

#include <stdint.h>

// -- Color Formats
typedef struct rgb15_t		rgb15_t;
typedef struct rgb16_t		rgb16_t;
typedef struct rgb16_565_t	rgb16_565_t;
typedef struct rgb24_t		rgb24_t;

class sw_vec3
{
public:

	float x,y,z;

	sw_vec3( x, y, z );
};

typedef struct sw_context
{
	void		*frameBuffer;
	uint16_t	*depthBuffer;
	uint32_t	**activeTexture;
} sw_context;


sw_context rswCreateContext();
void rswDeleteContext( sw_context* );

/**
** Set a context as the current drawing context
**/
void rswSetContext( sw_context* p_context );

/**
** Set a texture as the current texture for rasterization
**/
void rswSetTexture( void* p_texture );

/**
** Drawing functions/Register drawing function functions (registering is for threading)
**/
void rswDrawDot( sw_vec3 p_p1, uint32_t p_color );
void rswDrawLine( sw_vec3 p_p1, uint32_t p_c1, sw_vec3 p_p2, uint32_t p_c2 );
void rswDrawTriange( sw_vec3 p_p1, uint32_t p_c1, sw_vec3 p_p2, uint32_t p_c2, sw_vec3 p_p3, uint32_t p_c3 );
void rswDrawPicture( sw_vec3 p_origin, void* p_texture );



#endif // H_V_SOFT_H
