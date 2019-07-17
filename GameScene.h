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
	void hold();		//�e�g���~�m���z�[���h����
	bool lineDelete();	//���C�������� �����Ă�����true��Ԃ�
	bool isGameOver();

	Score scoreCalc;
	Tetrimino* tetrimino;
	Tetrimino* nextTetrimino;	//���ɗ����Ă���e�g���~�m
	Tetrimino* holdTetrimino;	//�z�[���h���Ă���e�g���~�m
	CellType field[FIELD_HEIGHT_CELL][FIELD_WIDTH_CELL];	//���̃C���f�b�N�X�������}�X�����܂��Ă����true
	int frameCount;		//���t���[������������J�E���g
	int downPace;		//�e�g���~�m�͂��̃t���[���o�߂��邲�Ƃ�1�}�X������
	bool gameOverFlag;
	int level;			//10���C���������Ƃ�level��1�オ��Bscore�̏㏸�����オ��.

	//true�̎������z�[���h�ł��Ȃ�
	//��x�z�[���h����o���ƁA
	//��������܂Ńz�[���h�ł��Ȃ�
	bool holdFlag = true;
};


#endif // !INCLUDED_GAME_SCENE_H_

