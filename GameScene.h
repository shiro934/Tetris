#pragma once
#ifndef INCLUDED_GAME_SCENE_H_
#define INCLUDED_GAME_SCENE_H_

#include "Scene.h"
#include "Block.h"

#include "TetrisInfo.h"

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
	void wallRender() const;	//�Ǖ�����`��

	Block* block;
	bool box[BOX_HEIGHT_CELL][BOX_WIDTH_CELL];	//���̃C���f�b�N�X�������}�X�����܂��Ă����true
};


#endif // !INCLUDED_GAME_SCENE_H_

