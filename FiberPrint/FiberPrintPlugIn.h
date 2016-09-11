/*
* ==========================================================================
*
*		class:	FiberPrintPlugin
*
*		This file is part of the implementation of
*
*		<Sustainable Fabrication of Frame Shapes>
*		Yijiang Huang, Juyong Zhang, Guoxian Song, Zhongyuan Liu, Lei Yu, Ligang Liu
*		In ACM Transactions on Graphics (Proc. SIGGRAPH Asia 2016)
*
*		Description:	This module is a container for several searching and cut computational 
*		module, which are public slots to renderwidgets.
*
*		Version:  2.0
*		Created:  Oct/10/2015
*		Updated: Aug/24/2016
*
*		Author:  Xin Hu, Yijiang Huang, Guoxian Song
*		Company:  GCL@USTC
* ==========================================================================
*/

#pragma once

#ifndef FIBERPRINTPLUGIN_H
#define FIBERPRINTPLUGIN_H

#include <vector>
#include "ADMMCut.h"
#include "NormalCut.h"
#include "FFAnalyzer.h"
#include "BFAnalyzer.h"
#include "ProcAnalyzer.h"


class FiberPrintPlugIn
{
public:
	typedef Eigen::MatrixXd MX;
	typedef Eigen::VectorXd VX;

public:
	FiberPrintPlugIn();
	FiberPrintPlugIn(WireFrame *ptr_frame, FiberPrintPARM *ptr_parm,
						char *path);
	~FiberPrintPlugIn();

public:
	void			Init();

	/* Fiber printing */
	void			FrameFabPrint();
	void			BruteForcePrint();
	void			SweepingPrint();
	void			OneLayerPrint();

	/* apply stiffness computation directly to the input frame shape */
	void			GetDeformation();
	void			GetFrameFabCut();

	bool			ImportPrintOrder(char *fname);
	void			ExportPrintOrder(char *fname);

	void			InputPrintOrder(vector<int> &queue)			{ ptr_seqanalyzer_->InputPrintOrder(queue); }
	void			OutputPrintOrder(vector<WF_edge*> &queue)	{ ptr_seqanalyzer_->OutputPrintOrder(queue); }
	void			ExportRenderPath(int min_layer, int max_layer, char *ptr_path)
	{
		ptr_seqanalyzer_->WriteRenderPath(min_layer, max_layer, ptr_path);
	}

	void			Debug();		// return value: edge index in mesh, for cut rendering

public:
	WireFrame			*ptr_frame_;
	DualGraph			*ptr_dualgraph_;
	QuadricCollision	*ptr_collision_;
	Stiffness			*ptr_stiffness_;

	GraphCut			*ptr_graphcut_;
	SeqAnalyzer			*ptr_seqanalyzer_;
	ProcAnalyzer		*ptr_procanalyzer_;

	char				*ptr_path_;
	FiberPrintPARM		*ptr_parm_;

private:
	Timer				fiber_print_;
};

#endif // FIBERPRINTPLUGIN_H
