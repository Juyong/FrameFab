/*
* ==========================================================================
*
*		class:	NormalCut
*
*		This file is part of the implementation of
*
*		<Sustainable Fabrication of Frame Shapes>
*		Yijiang Huang, Juyong Zhang, Guoxian Song, Zhongyuan Liu, Lei Yu, Ligang Liu
*		In ACM Transactions on Graphics (Proc. SIGGRAPH Asia 2016)
*
*		Description:	Cut layers by sweeping from bottom to top.
*
*		Version:  1.0
*		Created:  Mar/25/2016
*		Update :  Mar/26/2016
*
*		Author:  Xin Hu, Yijiang Huang, Guoxian Song
*		Company:  GCL@USTC
* ==========================================================================
*/

#pragma once

#include <map>

#include "GraphCut.h"

using namespace std;

class NormalCut : public GraphCut
{
public:
	NormalCut();
	NormalCut(WireFrame *ptr_frame, char *ptr_path);
	~NormalCut();

public:
	void	MakeLayers();

private:
	multimap<double, WF_edge*>	sweep_queue_;
};

