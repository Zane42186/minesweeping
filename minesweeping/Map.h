#pragma once
#include<SFML/Graphics.hpp>
#include"Grid.h"

//将地图类化
class Map {
private:
	void initGame();
public:
	//初始化地图
	void init(sf::RenderWindow* pwin, sf::Sprite* psprite);
	//处理鼠标事件handle -- 处理
	void handleMouseEvent(sf::Event& e, int x, int y);
	//地图的绘制
	void draw(int x, int y);
private:
	//定义一个Grid对象储存地图
	Grid grid[MAP_COL + 1][MAP_ROW + 1];
	//优化接口 win 和 sprite 只用传一次 不用反复传，那么可以选择使用定义一个指针
	sf::RenderWindow* pwin;
	sf::Sprite* psprite;
	//判断游戏是否正在运行
	bool isRunning;
};
