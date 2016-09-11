/*
* ==========================================================================
*
*		class:	ResolveAngle
*
*		This file is part of the implementation of
*
*		<Sustainable Fabrication of Frame Shapes>
*		Yijiang Huang, Juyong Zhang, Xin Hu, Guoxian Song, Zhongyuan Liu, Lei Yu, Ligang Liu
*		In ACM Transactions on Graphics (Proc. SIGGRAPH Asia 2016)
*
*		Description:
*
*		Version:  2.0
*		Created:  Oct/20/2015
*		Updated: Aug/24/2016
*
*		Author:  Guoxian Song
*		Company:  GCL@USTC
*
*	 Note:     This file uses mathematical part of Geometric Tools Engine,
*			   a library of source code for computing in the fields of
*			   mathematics, graphics, image analysis, and physics.
*			   For more info, please refer to http://www.geometrictools.com/index.html
* ==========================================================================
*/

#pragma once
#include"WireFrame\WireFrame.h"
#include"Collision\Geometry.h"
#include"Collision\ExtruderCone.h"

class ResolveAngle
{
public:
    ResolveAngle();
	ResolveAngle( vector< Geometry::Vector3d> list );
	~ResolveAngle();


	Geometry::Vector3d dec;
	double wave;
	vector< Geometry::Vector3d> a_;
	vector< Geometry::Vector3d> b_;
	vector< Geometry::Vector3d> c_;

	ExtruderCone extruder_;
	vector< Geometry::Vector3d> list_;
	vector< Geometry::Vector3d> Resolve();

	
	
	void Dec();

	Geometry::Vector3d Ave(vector<Geometry::Vector3d> t);
};

