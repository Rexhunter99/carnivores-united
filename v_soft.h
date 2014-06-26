#ifndef H_V_SOFT_H
#define H_V_SOFT_H


#include <stdint.h>

typedef struct rgb24_t
{
	uint8_t r,g,b;
} rgb24_t;

typedef struct sw_vec3
{
	float x,y,z;
} sw_vec3;
sw_vec3 __sw_vec3( float x, float y, float z );

typedef struct sw_context
{
	rgb24_t*	frameBuffer;
	uint16_t*	depthBuffer;
	uint32_t*	activeTexture;
} sw_context;


sw_context vswCreateContext();
void vswDeleteContext( sw_context* );

/**
** Set a context as the current drawing context
**/
void vswSetContext( sw_context* p_context );

/**
** Set a texture as the current texture for rasterization
**/
void vswSetTexture( void* p_texture );

/**
** Drawing functions/Register drawing function functions (registering is for threading)
**/
void vswDrawDot( sw_vec3 p_p1, uint32_t p_color );
void vswDrawLine( sw_vec3 p_p1, uint32_t p_c1, sw_vec3 p_p2, uint32_t p_c2 );
void vswDrawTriange( sw_vec3 p_p1, uint32_t p_c1, sw_vec3 p_p2, uint32_t p_c2, sw_vec3 p_p3, uint32_t p_c3 );
void vswDrawPicture( sw_vec3 p_origin, void* p_texture );



#endif // H_V_SOFT_H
