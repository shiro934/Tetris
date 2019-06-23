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
	bool lineDelete();	//���C�������� �����Ă�����true��Ԃ�
	bool isGameOver();

	Block* block;
	CellType box[BOX_HEIGHT_CELL][BOX_WIDTH_CELL];	//���̃C���f�b�N�X�������}�X�����܂��Ă����true
	BlockCategory currentBlockType;	//���ݗ����Ă���u���b�N�̎��
	int frameCount;		//�������������J�E���g
	int downPace;		//�u���b�N��������y�[�X
	bool gameOverFlag;
};


#endif // !INCLUDED_GAME_SCENE_H_

