#pragma once
//5，定义常量   --- 方便 修改和维护 -- 数字在代码中过多，无法知道意思，将数字定义为常量，更直观且更已修改维护
//原先每个格子的大小
const int ORI_GRID_SIZE = 72; //original -- 原来的
//窗口中每个格子的大小
const int GRID_SIZE = 36;
//地图的列,行
const  int MAP_COL = 15;
const  int MAP_ROW = 10;
//窗口的大小
const int WIN_WIDE = GRID_SIZE * (MAP_COL + 2);
const int WIN_LONG = GRID_SIZE * (MAP_ROW + 2);

//定义一个方向判断雷的数量
const int Dir[8][2]{
	{-1,-1},{-1,0},{-1,1},//上
	{0,-1},{0,1},//中
	{1,-1},{1,0},{1,1}//下
};

//定义一个枚举变量，--每个格子的类型
enum GridType {
	//空格
	Grid_EMPTY = 0,
	//1 - 8 count -- 计数，点数
	Grid_COUNT_1 = 1,
	Grid_COUNT_2 = 2,
	Grid_COUNT_3 = 3,
	Grid_COUNT_4 = 4,
	Grid_COUNT_5 = 5,
	Grid_COUNT_6 = 6,
	Grid_COUNT_7 = 7,
	Grid_COUNT_8 = 8,
	//炸弹
	Grid_BOMB = 9,
	//隐藏的方块
	Grid_HIDE = 10,
	//旗帜
	Grid_FLAG = 11,
};