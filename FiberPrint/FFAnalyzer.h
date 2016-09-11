/*
* ==========================================================================
*
*		class:	FFAnalyzer
*
*		This file is part of the implementation of
*
*		<Sustainable Fabrication of Frame Shapes>
*		Yijiang Huang, Juyong Zhang, Guoxian Song, Zhongyuan Liu, Lei Yu, Ligang Liu
*		In ACM Transactions on Graphics (Proc. SIGGRAPH Asia 2016)
*
*		Description:  perform the greedy searching algorithm in FrameFab to generate 
*		a collision-free, structurally-stable path.
*
*		Version:  2.0
*		Created:  Oct/10/2015
*		Updated: Aug/24/2016
*
*		Author:  Xin Hu, Yijiang Huang, Guoxian Song
*		Company:  GCL@USTC
*		Note:	Backtracking Greedy Approach:
*				At every decision state, a trail solution is performed,
*				unvisited current layer edges that are connected to already printed
*				structure and calculate their adjacency,collision and stiffness weight.
*
*				The total printing cost is weighted sum of the three:
*
*					Wp_*P + Wa_*A + Wi_*I
*
*					P: stabiliy weight
*					L: collision cost
*					A: influence weight
* ==========================================================================
*/

#pragma once
#include <cmath>
#include <cstring>

#include "SeqAnalyzer.h"


class FFAnalyzer : public SeqAnalyzer
{
public:
	typedef Eigen::MatrixXd MX;
	typedef Eigen::Matrix3d M3;
	typedef Eigen::VectorXd VX;
	typedef Eigen::Vector3d V3;

public:
	FFAnalyzer(WireFrame *ptr_frame = NULL);
	FFAnalyzer(
		DualGraph			*ptr_dualgraph,
		QuadricCollision	*ptr_collision,
		Stiffness			*ptr_stiffness,
		FiberPrintPARM		*ptr_parm,
		char				*ptr_path
		)
		:SeqAnalyzer(ptr_dualgraph, ptr_collision, ptr_stiffness,
		ptr_parm, ptr_path){}
	~FFAnalyzer();

public:
	bool			SeqPrint();

private:
	bool			GenerateSeq(int l, int h, int t);
	double		GenerateCost(WF_edge *ei, WF_edge *ej);

public:
	void			PrintOutTimer();
	void			WriteRenderPath(int min_layer, int max_layer, char *ptr_path);

private:
	vector<vector<WF_edge*>>	layers_;			// store dual_node's id for each layers

	double			min_z_;
	double			max_z_;


	Timer			FF_analyzer_;
};

