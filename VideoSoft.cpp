
#include "VideoSoft.h"


using namespace std;


/**
** CPUID for GCC
**/
#ifdef _WIN32

//  Windows
#define cpuid(info,x)    __cpuidex(info,x,0)

#else // For non-windows/MinGW

//  GCC Inline Assembly
void cpuid(int CPUInfo[4],int InfoType)
{
	asm volatile (
    //__asm__ __volatile__ (
        "cpuid":
        "=a" (CPUInfo[0]),
        "=b" (CPUInfo[1]),
        "=c" (CPUInfo[2]),
        "=d" (CPUInfo[3]) :
        "a" (InfoType), "c" (0)
    );
}

#endif


VideoSoft::VideoSoft()
{
	// -- Detect CPU Extensions
	int info[4];
	cpuid(info, 0);
	int nIds = info[0];

	cpuid(info, 0x80000000);
	unsigned nExIds = info[0];

	if (nIds >= 0x00000001)
	{
		cpuid(info,0x00000001);
		this->optimizations.mmx    = (info[3] & ((int)1 << 23)) != 0;
		this->optimizations.sse    = (info[3] & ((int)1 << 25)) != 0;
		this->optimizations.sse2   = (info[3] & ((int)1 << 26)) != 0;
		this->optimizations.sse3   = (info[2] & ((int)1 <<  0)) != 0;

		this->optimizations.ssse3  = (info[2] & ((int)1 <<  9)) != 0;
		this->optimizations.sse41  = (info[2] & ((int)1 << 19)) != 0;
		this->optimizations.sse42  = (info[2] & ((int)1 << 20)) != 0;
	}

	// -- Allocate the frame buffer
	this->back_buffer = (rgb24_t*)malloc( canvasWidth * canvasHeight * sizeof(rgb24_t) );
	this->depth_buffer = (uint16_t*)malloc( canvasWidth * canvasHeight * 2 );
}

VideoSoft::~VideoSoft()
{
	if ( this->back_buffer != nullptr ) free( this->back_buffer );
	if ( this->depth_buffer != nullptr ) free( this->depth_buffer );

	this->back_buffer = 0;
	this->depth_buffer = 0;
}
