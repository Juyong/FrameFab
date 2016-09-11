/*
* ==========================================================================
*
*		class:	ExtruderCone
*
*		This file is part of the implementation of
*
*		<Sustainable Fabrication of Frame Shapes>
*		Yijiang Huang, Juyong Zhang, Xin Hu, Guoxian Song, Zhongyuan Liu, Lei Yu, Ligang Liu
*		In ACM Transactions on Graphics (Proc. SIGGRAPH Asia 2016)
*
*		Description:  This class maintains extruder bounding cone info
*				   and OpenGL rendering interfaces.
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
#include "GlobalFunctions\GCommon.h"
#include "WireFrame\WireFrame.h"
#include "Triangle.h"

using namespace std;

class ExtruderCone
{
public:
	ExtruderCone();
	ExtruderCone(
		double height, 
		point base_point, 
		Vec3f normal, 
		double angle
	);
	~ExtruderCone();

public:
	/* Data I/O */
	double	Height() { return height_; }
	double	Angle()	 { return angle_; }
	double	WaveAngle() { return wave_angle_; }
	double ToolLenth(){ return tool_lenth_; }
	double Radii(){ return radii_; }
	double CyclinderLenth(){ return cyclinder_height_; }
	point	BasePoint() { return base_point_; }
	Vec3f	Normal()	{ return normal_; }


	/*top cylidner*/
	double TopCenter(){ return top_cylin_center_lenth_; }
	double TopLenth(){ return top_cylin_lenth_; }
	double TopRadii(){ return top_cylin_radii_; }
	/* Generate Extruder Cone */
	void GeneCone();

	/* Debug Screenplay Function */
	void	Test();

	/* Geometric transformation, for rendering purpose */
	void	RotateTri(Triangle temp);
    point	Multi(point s);
	void	Rotation(double angle, point start, point end);
	void	Rotation(GeoV3 normal, point start, point end);

	/* OpenGL Rendering Interface */
	void	Render(WireFrame* ptr_frame, double alpha);

private:
	/* Extruder Property Data */
	double				angle_;
	double				height_;
	double          tool_lenth_;
	double radii_;
	double cyclinder_height_;

	double				wave_angle_;
    vector<Triangle>	side_;
	point				base_point_;
	Vec3f				normal_;

	/* Extruder Render Data */
	int					divide_;	/* Traingle division for cone	  */
	vector<Triangle>	side_end_;  /* Triangle Approx for the cone   */
	vector<point>		top_;		/* Ploygon represent top covering */

	/* Transformation for Rendering */
	float rotate_[4][4];
	point start_,end_;

	//Top_Cylinder
	double top_cylin_center_lenth_;
	double top_cylin_lenth_;
	double top_cylin_radii_;
};