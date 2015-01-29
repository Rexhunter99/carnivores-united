
#include "v_soft.h"

#include <Windows.h>
#include <glm/glm.hpp>
#include <thread>
#include <cstdlib>

using namespace std;



BOOL WINAPI DllMain( HINSTANCE instance, DWORD reason, void* reserved )
{
	switch (reason)
	{
	case DLL_PROCESS_ATTACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	}

	return TRUE;
}


typedef struct rgb24_t
{
	unsigned int	red:5;
	unsigned int	green:5;
	unsigned int	blue:5;
	unsigned int	padding:17;
} rgb15_t;

typedef struct rgb16_t
{
	unsigned int	red:5;
	unsigned int	green:5;
	unsigned int	blue:5;
	unsigned int	alpha:1;
	unsigned int	padding:16;
} rgb16_t;

typedef struct rgb16_565_t
{
	unsigned int	red:5;
	unsigned int	green:6;
	unsigned int	blue:5;
	unsigned int	padding:15;
} rgb16_565_t;

typedef struct rgb24_t
{
	unsigned int	red:8;
	unsigned int	green:8;
	unsigned int	blue:8;
	unsigned int	padding:8;
} rgb24_t;

sw_vec3::sw_vec3( x, y, z )
{
	this->x = x;
	this->y = y;
	this->z = z;
}


sw_context g_context;
thread g_rasterizerThread;


void softwareProcessingThread( sw_context* context )
{
	// -- Todo, process all requested rendering related functions here.
}


bool createContext( HWND window )
{
	if ( !IsWindow(window) )
		return false;

	// -- Initialise the context
	memset( &g_context, 0, sizeof( sw_context ) );
	s->frameBuffer = (rgb24_t)malloc( ( 1024*768 ) * sizeof(rgb24_t) );
	s->depthBuffer = (uint16_t)malloc( ( 1024*768 ) * sizeof(uint16_t) );

	g_rasterizerThread = std::thread( softwareProcessingThread, s );

	return s;
}

void rswDestroyContext( sw_context *s )
{
	if ( s == 0 )
		return;

	free( s->frameBuffer );
	free( s->depthBuffer );

	delete s;
}
