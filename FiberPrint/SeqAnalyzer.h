/*
* ==========================================================================
*
*		class:	SequenceAnalyzer
*
*		This file is part of the implementation of
*
*		<Sustainable Fabrication of Frame Shapes>
*		Yijiang Huang, Juyong Zhang, Guoxian Song, Zhongyuan Liu, Lei Yu, Ligang Liu
*		In ACM Transactions on Graphics (Proc. SIGGRAPH Asia 2016)
*
*		Description:  perform tool path searching algorithm to generate
*				a collision-free, structurally stable path.
*
*		Version:  2.0
*		Created:  Oct/20/2015
*		Updated: Aug/24/2016
*
*		Author:  Xin Hu, Yijiang Huang, Guoxian Song
*		Company:  GCL@USTC
*
*		Successor:	FFAnalyzer - FrameFab sequence analyzer
*							BFAnalyzer - Brute Force sequence analyzer
* ==========================================================================
*/

#pragma once
#include <cmath>

#include "ADMMCut.h"
#include "NormalCut.h"
#include "Collision\QuadricCollision.h"
#include "Collision\ResolveAngle.h"

class SeqAnalyzer
{
public:
	typedef Eigen::MatrixXd MX;
	typedef Eigen::Matrix3d M3;
	typedef Eigen::VectorXd VX;
	typedef Eigen::Vector3d V3;

public:
	SeqAnalyzer();
	SeqAnalyzer(
		DualGraph			*ptr_dualgraph,
		QuadricCollision	*ptr_collision,
		Stiffness			*ptr_stiffness,
		FiberPrintPARM		*ptr_parm,
		char				*ptr_path
		);
	virtual ~SeqAnalyzer();

public:
	virtual bool	SeqPrint();
	virtual void	PrintOutTimer();
	virtual void	WriteRenderPath(int min_layer, int max_layer, char *ptr_path);

public:
	bool			InputPrintOrder(vector<int> &print_queue);
	void			OutputPrintOrder(vector<WF_edge*> &print_queue);

protected:
	void			Init();

	void			PrintPillars();
	void			UpdateStructure(WF_edge *e);
	void			RecoverStructure(WF_edge *e);
	void			UpdateStateMap(WF_edge *e, vector<vector<lld>> &state_map);
	void			RecoverStateMap(WF_edge *e, vector<vector<lld>> &state_map);
	bool			TestifyStiffness(WF_edge *e);

public:
	WireFrame			*ptr_frame_;
	DualGraph			*ptr_dualgraph_;
	Stiffness			*ptr_stiffness_;
	QuadricCollision	*ptr_collision_;
	char				*ptr_path_;

protected:
	/* maintaining for sequence */
	int							Nd_;
	DualGraph					*ptr_wholegraph_;
	vector<WF_edge*>			print_queue_;
	vector<vector<lld>>			angle_state_;
	VX							D0_;

	/* parameters */
	double				gamma_;						// gamma_	: amplifier factor for adjacency cost
	double				D_tol_;							// Dt_tol	: tolerance of offset in stiffness
	double				Wp_;								// Wp_		: stablity weight for printing cost
	double				Wa_;								// Wa_		: adjacent weight for printing cost
	double				Wi_;								// Wl_		: influence weight for printing cost

	/* for debuging */
	bool				debug_;
	bool				detail_timing_;					// 1: verbose detailed timing for each computing sesseion; 0: only total runtime
	bool				fileout_;

	Timer				upd_struct_;
	Timer				rec_struct_;
	Timer				upd_map_;
	Timer				upd_map_collision_;
	Timer				rec_map_;
	Timer				test_stiff_;
};

