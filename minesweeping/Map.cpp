//Map的实现文件
#include"Map.h"
using namespace sf;
//初始化地图
void Map::init(RenderWindow* pwin, Sprite* psprite) {
	this->pwin = pwin;
	this->psprite = psprite;
	initGame();
}
void Map::initGame(){
	isRunning = true;
	//定义实际地图的炸弹
	for (int i = 1;i <= MAP_COL;++i) {
		for (int j = 1;j <= MAP_ROW;++j) {
			//1/6的概率出炸弹
			if (rand() % 6 == 0) {
				grid[i][j].SetRealGridType(GridType::Grid_BOMB);
			}
			else {
				grid[i][j].SetRealGridType(GridType::Grid_EMPTY);
			}
		}
	}

	//判断周围有多少个炸弹
	for (int y = 1;y <= MAP_COL;++y) {
		for (int x = 1;x <= MAP_ROW;++x) {
			//为空则遍历周围格子
			if (grid[y][x].IsRealEmpty()) {
				//定义一个计数
				int cnt = 0;
				for (int k = 0; k < 8;++k) {
					int ty = y + Dir[k][0];
					int tx = x + Dir[k][1];
					if (grid[ty][tx].IsRealBomb()) {
						cnt++;
					}
				}
				//将cnt强制转化为GridType类型
				grid[y][x].SetRealGridType((GridType)cnt);
			}
		}
	}
	//定义初始展示地图
	for (int i = 1;i <= MAP_COL;++i) {
		for (int j = 1;j <= MAP_ROW;++j) {
			grid[i][j].SetShowGridType(GridType::Grid_HIDE);
		}
	}
}
//处理鼠标事件handle -- 处理
void Map::handleMouseEvent(Event& e, int x, int y) {
	//判断鼠标事件
	if (e.type == Event::MouseButtonPressed) {
		//判断鼠标行为
		//左键
		if (e.key.code == Mouse::Left) {
			if (isRunning) {
				grid[x][y].ShowGrid();
				if (grid[x][y].IsRealBomb()) {
					isRunning = false;
				}
			}
			else {
				initGame();
			}
			//自动展开空格周围格子
			if (grid[x][y].IsShowEmpty()) {
				for (int k = 0; k < 8;++k) {
					int ty = y + Dir[k][0];
					int tx = x + Dir[k][1];
					grid[tx][ty].ShowGrid();
				}
			}
		}
		//右键
		else if (e.key.code == Mouse::Right) {
			grid[x][y].SetShowGridType(GridType::Grid_FLAG);
		}
	}
}
//地图的绘制
void Map::draw(int x, int y) {
	//将矩形进行缩放
	psprite->setScale(Vector2f(0.5, 0.5));

	//点到炸弹自动展示全图
	for (int i = 1;i <= MAP_COL;++i) {
		for (int j = 1;j <= MAP_ROW;++j) {
			if (!isRunning) {
				grid[i][j].ShowGrid();
			}
			//定义一个纹理矩形（左上角坐标， - - - -，大小， - - - -）
			psprite->setTextureRect(IntRect(ORI_GRID_SIZE * grid[i][j].GetShowGridType(), 0, ORI_GRID_SIZE, ORI_GRID_SIZE));
			//设置该矩形位置
			psprite->setPosition(0.0f + i * GRID_SIZE, 0.0f + j * GRID_SIZE);//0.0f为浮点数，相加转换为float类型的值
			//将该矩形绘制到win对象中 因为是传入对象，所以对指针解引用
			pwin->draw(*psprite);
		}
	}

}