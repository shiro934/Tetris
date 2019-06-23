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

	void input(const InputKey& input);
	void update();
	void render() const;

	SceneType nextSceneType() const;

private :
	void boxInit();
	unsigned int getCellColor(const CellType type) const;
	bool isCellEmpty(const CellType type) const;
	void createBlock();
	void setBlock();
	bool lineDelete();	//ラインを消す 消せていたらtrueを返す
	bool isGameOver();

	Block* block;
	CellType box[BOX_HEIGHT_CELL][BOX_WIDTH_CELL];	//そのインデックスが示すマスが埋まっていればtrue
	BlockCategory currentBlockType;	//現在落ちているブロックの種類
	int frameCount;		//何回回ったかをカウント
	int downPace;		//ブロックが落ちるペース
	bool gameOverFlag;
};


#endif // !INCLUDED_GAME_SCENE_H_

