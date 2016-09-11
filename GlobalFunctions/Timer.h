/*
* ==========================================================================
*
*		class:	Timer
*
*		This file is part of the implementation of
*
*		<Sustainable Fabrication of Frame Shapes>
*		Yijiang Huang, Juyong Zhang, Xin Hu, Guoxian Song, Zhongyuan Liu, Lei Yu, Ligang Liu
*		In ACM Transactions on Graphics (Proc. SIGGRAPH Asia 2016)
*
*		Description:  Timing tool.
*
*		Author: Xin Hu
*		Company:  GCL@USTC
* ==========================================================================
*/

#pragma once

#ifndef FIBER_PRINT_TIMER_H
#define FIBER_PRINT_TIMER_H

#include <chrono>
#include <ctime>
#include <iostream>
#include <string>

class Timer
{
	typedef std::chrono::time_point<std::chrono::system_clock> TimePoint;
	typedef std::chrono::duration<double> Duration;
public:
	Timer();
	~Timer();

public:
	void	Start();
	void	Stop();
	void	Reset();
	void	Print(char *item);
	std::string ToString() const;

private:
	TimePoint	start_time_;
	TimePoint	end_time_;
	double		sum_time_;
	int			count_;
};

std::ostream& operator << (std::ostream & os, const Timer& t);


#endif //Timer.h