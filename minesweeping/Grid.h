#pragma once
#include"const.h"

//Grid的声明//将格子类化
class Grid {
public:
	Grid();
	//展示方块
	//设置展示方块
	void SetShowGridType(GridType ShowGridType);
	//得到展示方块
	GridType GetShowGridType() const;
	//判断展示方块是否为炸弹
	bool IsShowBomb() const;
	//判断展示方块是否为空格
	bool IsShowEmpty() const;
	//实际方块
	//设置实际方块
	void SetRealGridType(GridType RealGridType);
	//得到实际方块
	GridType GetRealGridType() const;
	//判断实际方块是否为炸弹
	bool IsRealBomb() const;
	//判断实际方块是否为空格
	bool IsRealEmpty() const;
	void ShowGrid();
private:
	GridType m_showGridType;
	GridType m_realGridType;



};