#pragma once
#ifndef INCLUDED_GAME_SCENE_H_
#define INCLUDED_GAME_SCENE_H_

#include "Scene.h"
#include "Tetrimino.h"

#include "TetrisInfo.h"
#include "CellType.h"

#include "Score.h"

class GameScene :
	public Scene
{
public:
	GameScene();
	~GameScene();

	void input(const InputKey& input) override;
	void update() override;
	void render() const override;
	SceneType nextSceneType() const override;

private :
	void fieldInit();
	unsigned int getCellColor(const CellType type) const;
	bool isCellEmpty(const CellType type) const;
	void createTetrimino();
	void textRender() const;
	void setTetriminoOnField();
	void hold();		//テトリミノをホールドする
	bool lineDelete();	//ラインを消す 消せていたらtrueを返す
	bool isGameOver();

	Score scoreCalc;
	Tetrimino* tetrimino;
	Tetrimino* nextTetrimino;	//次に落ちてくるテトリミノ
	Tetrimino* holdTetrimino;	//ホールドしているテトリミノ
	CellType field[FIELD_HEIGHT_CELL][FIELD_WIDTH_CELL];	//そのインデックスが示すマスが埋まっていればtrue
	int frameCount;		//何フレーム回ったかをカウント
	int downPace;		//テトリミノはこのフレーム経過するごとに1マス落ちる
	bool gameOverFlag;
	int level;			//10ライン消すごとにlevelが1上がる。scoreの上昇率も上がる.

	//trueの時しかホールドできない
	//一度ホールドから出すと、
	//落ちきるまでホールドできない
	bool holdFlag = true;
};


#endif // !INCLUDED_GAME_SCENE_H_

