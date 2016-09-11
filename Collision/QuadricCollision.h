/*
* ==========================================================================
*
*		class:	QuadricCollision
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
*		Author:  Guoxian Song, Xin Hu
*		Company:  GCL@USTC
*
*	 Note:     This file uses mathematical part of Geometric Tools Engine,
*			   a library of source code for computing in the fields of
*			   mathematics, graphics, image analysis, and physics.
*			   For more info, please refer to http://www.geometrictools.com/index.html
* ==========================================================================
*/

#pragma once

#include "Collision\Geometry.h"
#include "Collision\ExtruderCone.h"
#include "Collision\Triangle.h"
#include "WireFrame\WireFrame.h"
#include "FiberPrint\DualGraph.h"

#include <vector>
#include <GTEnginePCH.h>
#include <Mathematics/GteIntrSegment3Cone3.h>

typedef unsigned long long lld;

using namespace Geometry;
using namespace std;

//#define	STRICT_COLLISION

// ¦È=(0,180), ¦Õ=(0,360)
// target means printing edge, order menas existing edge
class QuadricCollision
{
public:
	QuadricCollision();
	QuadricCollision(WireFrame *ptr_frame);
	~QuadricCollision();

public:
	void	DetectCollision(WF_edge *target_e, DualGraph *ptr_subgraph, vector<lld> &result_map);
	void	DetectCollision(WF_edge *target_e, WF_edge *order_e, vector<lld> &colli_map);
	void	DetectCollision(WF_edge *target_e, vector<WF_edge*> exist_edge, vector<GeoV3> &output);

	void	Init(vector<lld> &colli_map);

private:
	void	DetectEdge(WF_edge *order_e, vector<lld> &colli_map);
	bool	DetectEdges(vector<WF_edge*> exist_edge, double ¦È, double ¦Õ);
	bool	DetectBulk(WF_edge *order_e, double ¦È, double ¦Õ);
	bool	DetectAngle(GeoV3 connect, GeoV3 end, GeoV3 target_end, GeoV3 normal);

	bool	Case(GeoV3 target_start, GeoV3 target_end,
				GeoV3 order_start, GeoV3 order_end, GeoV3 normal);
	bool	SpecialCase(GeoV3 connect, GeoV3 target_s, GeoV3 order_s, GeoV3 normal);
	bool	ParallelCase(GeoV3 target_start, GeoV3 target_end,
				GeoV3 order_start, GeoV3 order_end, GeoV3 normal);

	bool	DetectCone(GeoV3 start, GeoV3 normal, GeoV3 target_start, GeoV3 target_end);
	bool	DetectCylinder(GeoV3 start, GeoV3 normal, GeoV3 target_start, GeoV3 target_end);
	bool	DetectTriangle(Triangle	 triangle, GeoV3 target_start, GeoV3 target_end);
	bool	DetectTopCylinder(GeoV3 start, GeoV3 normal, GeoV3 target_start, GeoV3 target_end);

	void	GenerateVolume(GeoV3 start, GeoV3 end, GeoV3 target_start, GeoV3 target_end, GeoV3 normal);
	void	GenerateVolume(GeoV3 connect, GeoV3 target_s, GeoV3 order_s, GeoV3 normal);

	bool	Parallel(GeoV3 a, GeoV3 b);
	double	Distance(WF_edge* order_e);

	gte::Segment<3, float>		Seg(point target_start, point target_end);
	gte::Segment<3, float>		Seg(GeoV3 target_start, GeoV3 target_end);
	gte::Triangle<3, float>		Tri(GeoV3 a, GeoV3 b, GeoV3 c);

	GeoV3 Orientation(double ¦È, double ¦Õ)
	{ 
		return GeoV3(sin(¦È)*cos(¦Õ), sin(¦È)*sin(¦Õ), cos(¦È)); 
	}

public:
	//output
	void ModifyAngle(vector<lld> &angle_state, vector<lld> &colli_map)
	{
		for (int i = 0; i < 3; i++)
		{
			angle_state[i] |= colli_map[i];
		}
	}

	int ColFreeAngle(vector<lld> &colli_map)
	{
		if (colli_map[0] == (lld)0 && colli_map[1] == (lld)0 && colli_map[2] == (lld)0)
			return Divide();


		int sum_angle = 0;
		for (int j = 0; j < 62; j++)
		{
			lld mask = ((lld)1 << j);
			for (int i = 0; i < 3; i++)
			{
				if (i<2 && j>59)
					continue;

				if ((colli_map[i] & mask) == 0)
				{
					sum_angle++;
				}
			}
		}

		return sum_angle;
	}

	int Divide()
	{
		return 18 * 10 + 2;
	}

	void			Debug();

public:
	WireFrame		*ptr_frame_;
	WF_edge			*target_e_;

private:
	ExtruderCone		extruder_;
	vector<Triangle>	bulk_;
	int					divide_;

	/* (Nd * Nd) * (3) */
	/* (i, j): j's angle map & i printed */
	vector<vector<lld>*>colli_map_;				
};
