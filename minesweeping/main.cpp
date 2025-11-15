#include<SFML/Graphics.hpp>
#include <iostream>
#include<ctime>
#include<random>
#include<conio.h>
#include"const.h"
#include"Grid.h"
#include"Map.h"

using namespace std;
using namespace sf;

int main() {
	srand(time(0));
	//使用创立RenderWindow 对象win创建一个窗口宽，高,
	RenderWindow win(VideoMode(WIN_WIDE, WIN_LONG),L"飞鱼版扫雷");//前面加入""L -- 识别为长字符类型wchar 一般存储为2字节及以上字节
	Texture t;//创建一个纹理对象
	//将图片写入内存
	t.loadFromFile("minesweeping.jpg");
	//创建一个精灵对象 -- 实现对图片矩阵的平移，缩放等功能
	Sprite s(t);

	Map map;
	/*
	类化前
	//4.定义初始地图  15列10行，防止下标越界 + 1；
	//GridType showGrid[MAP_COL + 1][MAP_ROW + 1]; // -- grid -- 网格,格子
	//6,定义随机地图
	//GridType grid[MAP_COL + 1][MAP_ROW + 1];
	*/
	//优化接口 win 和 sprite 只用传一次 不用反复传，那么可以选择使用定义一个指针，在初始化地图时调用这个指针，为指针初始化
	map.init(&win,&s);

	//win.isOpen() -- 窗口打开下
	while (win.isOpen()) {
		//2,定义窗口关闭
		Event e;//事件
		//定义一个整数的二维向量
		Vector2i pos = Mouse::getPosition(win);

		int x = pos.x / GRID_SIZE;
		int y = pos.y / GRID_SIZE;

		//获得最先进来的事件 poll --n投票，v获得  -------队列
		while (win.pollEvent(e)) {
			if (e.type == Event::Closed) {//如果事件为关闭，这关闭win窗口
				cout << "窗口关闭" << endl;//输出在控制台
				win.close();
			}
			//处理鼠标事件
			map.handleMouseEvent(e, x, y);	
		}
		//绘制当前地图 -- 优化接口 win 和 sprite 只用传一次 不用反复传，那么可以选择使用定义一个指针，在初始化地图时调用这个指针，为指针初始化
		map.draw(x, y);
		//将win对象中的矩形展现到窗口中
		win.display();
	}
	return 0;
}