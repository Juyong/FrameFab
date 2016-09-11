/*
* ==========================================================================
*
*		Class:	GraphCut
*
*		This file is part of the implementation of
*
*		<Sustainable Fabrication of Frame Shapes>
*		Yijiang Huang, Juyong Zhang, Guoxian Song, Zhongyuan Liu, Lei Yu, Ligang Liu
*		In ACM Transactions on Graphics (Proc. SIGGRAPH Asia 2016)
*
*		Description:	Cut input model into layers by different means.
*
*		Version:  2.0
*		Created:  Oct/10/2015
*		Updated: Aug/24/2016
*
*		Author:  Xin Hu, Yijiang Huang, Guoxian Song
*		Company:  GCL@USTC
*
*		Successor:	ADMMCut - FrameFab ADMM cut
*							NormalCut - cut layers by sweeping from bottom to top.
*							NoneCut - no layers
* ==========================================================================
*/

#pragma once

#include <iostream>

#include "WireFrame\WireFrame.h"
#include "Stiffness\Stiffness.h"
#include "Collision\QuadricCollision.h"
#include "FiberPrintPARM.h"

using namespace std;


class GraphCut
{
public:
	GraphCut();
	virtual ~GraphCut();

public:
	virtual void	MakeLayers();	
	virtual void	PrintOutTimer();

public:
	WireFrame		*ptr_frame_;
	char			*ptr_path_;


	vector<int>		cutting_edge_;

protected:
	/* for debuging */
	bool			debug_;
	bool			detail_timing_;	// 1: verbose detailed timing for each computing sesseion; 0: only total runtime
	bool			output_stat_;	// 1: turn on output stat	0: turn off
};

