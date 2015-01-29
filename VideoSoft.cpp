
#include "VideoSoft.h"


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
		this->optimisations.mmx    = (info[3] & ((int)1 << 23)) != 0;
		this->optimisations.sse    = (info[3] & ((int)1 << 25)) != 0;
		this->optimisations.sse2   = (info[3] & ((int)1 << 26)) != 0;
		this->optimisations.sse3   = (info[2] & ((int)1 <<  0)) != 0;

		this->optimisations.ssse3  = (info[2] & ((int)1 <<  9)) != 0;
		this->optimisations.sse41  = (info[2] & ((int)1 << 19)) != 0;
		this->optimisations.sse42  = (info[2] & ((int)1 << 20)) != 0;
	}
}

VideoSoft::~VideoSoft()
{
}


bool VideoSoft::startUp()
{
	this->backBuffer = (rgb_t*)malloc( canvasWidth * canvasHeight * 3 );
	this->depthBuffer = (uint16_t*)malloc( canvasWidth * canvasHeight * 2 );
}

bool VideoSoft::shutDown()
{
	if ( this->backBuffer != nullptr ) free( this->backBuffer );
	if ( this->depthBuffer != nullptr ) free( this->depthBuffer );

	this->backBuffer = 0;
	this->depthBuffer = 0;
}
