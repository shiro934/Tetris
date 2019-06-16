#pragma once
#ifndef INCLUDED_GAME_SCENE_H_
#define INCLUDED_GAME_SCENE_H_

#include "Scene.h"
#include "Block.h"

#include "TetrisInfo.h"
#include "CellType.h"

class GameScene :
	public Scene
{
public:
	GameScene();
	~GameScene();

	void input() const;
	void update() const;
	void render() const;

private :
	void boxInit();
	unsigned int getCellColor(const CellType type) const;
	bool isCellEmpty(const CellType type) const;

	Block* block;
	CellType box[BOX_HEIGHT_CELL][BOX_WIDTH_CELL];	//そのインデックスが示すマスが埋まっていればtrue
};


#endif // !INCLUDED_GAME_SCENE_H_

