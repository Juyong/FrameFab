/*
* ==========================================================================
*		This file is part of the implementation of
*
*		<Sustainable Fabrication of Frame Shapes>
*		Yijiang Huang, Juyong Zhang, Xin Hu, Guoxian Song, Zhongyuan Liu, Lei Yu, Ligang Liu
*		In ACM Transactions on Graphics (Proc. SIGGRAPH Asia 2016)
*
*		Description:  GCommon.h provides some common configuration for fiberprint project.
*
*		Version:  2.0
*		Created:  Oct/20/2015
*		Updated: Aug/24/2016
*
*		Author: Yijiang Huang, Xin Hu, Guoxian Song
*		Company:  GCL@USTC
* ==========================================================================
*/

#pragma once
#include <cmath>

#ifndef FIBERPRINT_COMMON_H
#define FIBERPRINT_COMMON_H

#define FRAME3DD_PATHMAX 512
#ifndef MAXL
#define MAXL    512
#endif

#define FILENMAX 128

#ifndef VERSION
#define VERSION "20160826+"
#endif

#ifndef F_PI
#define F_PI 3.14159265358979323846264338327950288419716939937510
#endif

#ifndef  SPT_EPS
#define SPT_EPS  0.0000001	// sparse matrix eps
#endif

#ifndef  GEO_EPS						// geometry eps
#define GEO_EPS  0.001
#endif

#ifndef STIFF_TOL
#define STIFF_TOL 1.0e-9			// tolerance for stiffness RMS error
#endif

#ifndef MCOND_TOL
#define MCOND_TOL 1.0e12	// tolerance for stiffness matrix condition number
#endif

// Zvert=1: Z axis is vertical... rotate about Y-axis, then rotate about Z-axis
// Zvert=0: Y axis is vertical... rotate about Z-axis, then rotate about Y-axis
#define Zvert 1	

#endif /* FIBERPRINT_COMMON_H */

