#include"Grid.h"
//grid的实现文件
Grid::Grid() {
	m_showGridType = GridType::Grid_EMPTY;
	m_realGridType = GridType::Grid_EMPTY;
}
//展示方块
//设置展示方块
void Grid::SetShowGridType(GridType ShowGridType) {
	m_showGridType = ShowGridType;
}
//得到展示方块
GridType Grid::GetShowGridType() const {
	return m_showGridType;
}

//判断展示方块是否为炸弹
bool Grid::IsShowBomb() const {
	return m_showGridType == GridType::Grid_BOMB;
}
//判断展示方块是否为空格
bool Grid::IsShowEmpty() const {
	return m_showGridType == GridType::Grid_EMPTY;
}

//实际方块
//设置实际方块
void Grid::SetRealGridType(GridType RealGridType) {
	m_realGridType = RealGridType;
}
//得到实际方块
GridType Grid::GetRealGridType() const {
	return m_realGridType;
}
//判断实际方块是否为炸弹
bool Grid::IsRealBomb() const {
	return m_realGridType == GridType::Grid_BOMB;
}
//判断实际方块是否为空格
bool Grid::IsRealEmpty() const {
	return m_realGridType == GridType::Grid_EMPTY;
}

void Grid::ShowGrid() {
	m_showGridType = m_realGridType;
}