/*
* ==========================================================================
*
*		class:	Loader
*
*		This file is part of the implementation of
*
*		<Sustainable Fabrication of Frame Shapes>
*		Yijiang Huang, Juyong Zhang, Xin Hu, Guoxian Song, Zhongyuan Liu, Lei Yu, Ligang Liu
*		In ACM Transactions on Graphics (Proc. SIGGRAPH Asia 2016)
*
*		Description:
*
*		Author:  Yijiang Huang
*		Company:  GCL@USTC
* ==========================================================================
*/

#ifndef FIBER_PRINT_LOADER_H
#define FIBER_PRINT_LOADER_H

#include <string>
#include <Eigen/Sparse>

class Loader{
public:
	typedef Eigen::SparseMatrix<double> SpMat;

public:
	Loader(){ ; }
	virtual ~Loader(){ ; }

public:

	static bool uniqueFilename(const std::string& filePathName,
		const std::string& fileExtension,
		std::string& uniqueFullFileName);

	void loadFromFile(char* filename, int* N, SpMat CostMatrix);		// N : number of nodes in graph 
};


#endif
