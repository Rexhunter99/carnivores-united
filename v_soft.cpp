
#include "v_soft.h"

#include <glm/glm.hpp>
#include <thread>
#include <cstdlib>

using namespace std;


thread g_rasterizerThread;

/**
** C-Style constructor for sw_vec3
**/
sw_vec3 __sw_vec3( float x, float y, float z )
{
	sw_vec3 v;
	v.x = x;
	v.y = y;
	v.z = z;
	return v;
}

sw_context vswCreateContext()
{
	sw_context s;

	s.frameBuffer = (rgb24_t)malloc( ( 1024*768 ) * 3 );
	s.depthBuffer = (uint16_t)malloc( ( 1024*768 ) * 2 );

	g_rasterizerThread = std::thread( )

	return c;
}
