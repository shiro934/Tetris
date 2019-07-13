#include "GameScene.h"

#include "DxLib.h"

#include <random>

#include <cassert>

#define INIT_FALL_SPEED 60	//�����̗�����X�s�[�h

GameScene::GameScene()
{
	createBlock();
	createBlock();
	fieldInit();
	frameCount = 0;
	downPace = INIT_FALL_SPEED;
	gameOverFlag = false;
}


GameScene::~GameScene()
{
	delete tetrimino;
}

bool GameScene::isGameOver() {
	//�t�B�[���h�ŏ㕔�̐^��4�}�X�����܂������Q�[���I�[�o�[
	for (int i = 0; i < 4; i++) {
		if (field[0][(FIELD_WIDTH_CELL / 2 - 2) + i] != EMPTY) {
			gameOverFlag = true;
			return true;
		}
	}
	return false;
}

//�e�g���~�m��ςރt�B�[���h�̏�����
void GameScene::fieldInit() {
	for (int height = 0; height < FIELD_HEIGHT_CELL - 1; height++) {
		for (int width = 0; width < FIELD_WIDTH_CELL; width++) {
			if (width == 0 || width == FIELD_WIDTH_CELL - 1) {
				field[height][width] = WALL;
			}
			else {
				field[height][width] = EMPTY;
			}
		}
	}

	for (int width = 0; width < FIELD_WIDTH_CELL; width++) {
		field[FIELD_HEIGHT_CELL - 1][width] = WALL;
	}
}

void GameScene::input(const InputKey& input) {
	//�V�[����؂�ւ�
	if (input.checkKeyState(KEY_INPUT_RETURN) == KEY_DOWN) {
		nextSceneFlag = true;
	}

	if (gameOverFlag) {
		return;
	}

	if (input.checkKeyState(KEY_INPUT_LEFT) == KEY_DOWN) {
		tetrimino->move(LEFT, field);
	}
	if (input.checkKeyState(KEY_INPUT_RIGHT) == KEY_DOWN) {
		tetrimino->move(RIGHT, field);
	}
	if (input.checkKeyState(KEY_INPUT_UP) == KEY_DOWN) {	//�e�g���~�m��^���Ɉ�C�ɗ��Ƃ�
		while (tetrimino->isDownFinish() == false) {
			tetrimino->move(DOWN, field);
		}
	}
	if (input.checkKeyState(KEY_INPUT_DOWN) == KEY_DOWN) {
		tetrimino->move(DOWN, field);
	}

	//�e�g���~�m����]
	if (input.checkKeyState(KEY_INPUT_S) == KEY_DOWN) {
		tetrimino->rotateRight();
		if (tetrimino->canRotate(field) == false) {
			tetrimino->rotateLeft();
		}
	}
	if (input.checkKeyState(KEY_INPUT_A) == KEY_DOWN) {
		tetrimino->rotateLeft();
		if (tetrimino->canRotate(field) == false) {
			tetrimino->rotateRight();
		}
	}
}

void GameScene::update() {
	if (gameOverFlag) {
		return;
	}

	if (tetrimino->isDownFinish()) {
		if (isGameOver()) {
			return;
		}
		setTetriminoOnField();
		while (lineDelete()) {

		}
		createBlock();
	}
	if (frameCount % downPace == 0) {
		tetrimino->move(DOWN, field);
	}
	frameCount++;
}

void GameScene::render() const {
	/* �t�B�[���h��`�� */
	for (int i = 0; i < FIELD_HEIGHT_CELL; i++) {
		for (int j = 0; j < FIELD_WIDTH_CELL; j++) {
			unsigned int cellColor = getCellColor(field[i][j]);
			DrawBox(FIELD_POS_X + (TETRIMINO_CELL_SIZE * j), FIELD_POS_Y + (TETRIMINO_CELL_SIZE * i)
				, FIELD_POS_X + (TETRIMINO_CELL_SIZE * (j + 1)), FIELD_POS_Y + (TETRIMINO_CELL_SIZE * (i + 1)),
				cellColor, TRUE);
		}
	}

	//�e�g���~�m�̕`��
	tetrimino->render();

	nextTetrimino->nextRender();

	//�Q�[���I�[�o�[�ɂȂ�͈͂�\��
	DrawBox(FIELD_POS_X + (TETRIMINO_CELL_SIZE * (FIELD_WIDTH_CELL / 2 - 2)), FIELD_POS_Y
		, FIELD_POS_X + (TETRIMINO_CELL_SIZE * (FIELD_WIDTH_CELL / 2 + 2)), FIELD_POS_Y + TETRIMINO_CELL_SIZE,
		0xffffff, FALSE);

	textRender();
}

void GameScene::textRender() const {
	/* �����̕`�� */
	if (gameOverFlag) {
		DrawString(WND_WIDTH / 2, WND_HEIGHT / 2, "GAME OVER", 0xff0000);
	}
	DrawFormatString(0, 20, 0xffffff, "Score : %d", scoreCalc.getCurrentScore());
	DrawString(0, 40, "�� �� : ���ړ�", 0xffffff);
	DrawString(0, 60, "�� : ���ړ�", 0xffffff);
	DrawString(0, 80, "�� : ��C�ɗ��Ƃ�", 0xffffff);
	DrawString(0, 100, "A : �����v���ɉ�]", 0xffffff);
	DrawString(0, 120, "S : ���v���ɉ�]", 0xffffff);

}

SceneType GameScene::nextSceneType() const {
	return TITLE;
}

bool GameScene::isCellEmpty(const CellType type) const {
	return (type == EMPTY) ? true : false;
}

unsigned int GameScene::getCellColor(const CellType type) const {
	assert(type != CellType::MAX);
	return CELL_COLOR[type];
}

void GameScene::hold() {
	//������
	if (holdTetrimino == nullptr) {
		holdTetrimino = tetrimino;
		return;
	}
	Tetrimino* tmp = holdTetrimino;
	holdTetrimino = tetrimino;
	tetrimino = holdTetrimino;

}

void GameScene::createBlock() {

	if (tetrimino != nullptr && nextTetrimino != nullptr) {
		delete tetrimino;
		tetrimino = nextTetrimino;
	}

	//�e�g���~�m�̃����_���������΂�Ȃ��悤�ɐ��������e�g���~�m�̎�ނɃt���O�𗧂Ă�
	static bool createCellTypeFlag[TETRIMINO_NUM] = {};
	static int createTetriminoNum = 0;	//�e�g���~�m�����݉���ސ���������

	//��������u���b�N�������_���Ɍ���(�S��ނ𐶐�����܂Ŕ��Ȃ��悤�ɐ���)
	std::random_device rand;
	CellType currentTetriminoType = static_cast<CellType>(rand() % TETRIMINO_NUM);
	while (createCellTypeFlag[currentTetriminoType]) {
		currentTetriminoType = static_cast<CellType>(rand() % TETRIMINO_NUM);
	}
	createCellTypeFlag[currentTetriminoType] = true;
	createTetriminoNum++;
	if (createTetriminoNum == TETRIMINO_NUM) {
		for (int i = 0; i < TETRIMINO_NUM; i++) {
			createCellTypeFlag[i] = false;
		}
		createTetriminoNum = 0;
	}

	unsigned int tetriminoCellPosX[4] = {};
	unsigned int tetriminoCellPosY[4] = {};

	switch (currentTetriminoType) {
	case CELL_L : 
		tetriminoCellPosX[0] = 1;
		tetriminoCellPosX[1] = 1;
		tetriminoCellPosX[2] = 1;
		tetriminoCellPosX[3] = 2;

		tetriminoCellPosY[0] = 0;
		tetriminoCellPosY[1] = 1;
		tetriminoCellPosY[2] = 2;
		tetriminoCellPosY[3] = 2;

		break;
	case CELL_L_REVERSE : 
		tetriminoCellPosX[0] = 2;
		tetriminoCellPosX[1] = 2;
		tetriminoCellPosX[2] = 2;
		tetriminoCellPosX[3] = 1;

		tetriminoCellPosY[0] = 0;
		tetriminoCellPosY[1] = 1;
		tetriminoCellPosY[2] = 2;
		tetriminoCellPosY[3] = 2;

		break;
	case CELL_T : 
		tetriminoCellPosX[0] = 1;
		tetriminoCellPosX[1] = 1;
		tetriminoCellPosX[2] = 2;
		tetriminoCellPosX[3] = 1;

		tetriminoCellPosY[0] = 0;
		tetriminoCellPosY[1] = 1;
		tetriminoCellPosY[2] = 1;
		tetriminoCellPosY[3] = 2;

		break;
	case CELL_S :
		tetriminoCellPosX[0] = 1;
		tetriminoCellPosX[1] = 2;
		tetriminoCellPosX[2] = 0;
		tetriminoCellPosX[3] = 1;

		tetriminoCellPosY[0] = 1;
		tetriminoCellPosY[1] = 1;
		tetriminoCellPosY[2] = 2;
		tetriminoCellPosY[3] = 2;

		break;
	case CELL_S_REVERSE : 
		tetriminoCellPosX[0] = 0;
		tetriminoCellPosX[1] = 1;
		tetriminoCellPosX[2] = 1;
		tetriminoCellPosX[3] = 2;

		tetriminoCellPosY[0] = 1;
		tetriminoCellPosY[1] = 1;
		tetriminoCellPosY[2] = 2;
		tetriminoCellPosY[3] = 2;
		break;
	case CELL_O : 
		tetriminoCellPosX[0] = 1;
		tetriminoCellPosX[1] = 2;
		tetriminoCellPosX[2] = 1;
		tetriminoCellPosX[3] = 2;

		tetriminoCellPosY[0] = 1;
		tetriminoCellPosY[1] = 1;
		tetriminoCellPosY[2] = 2;
		tetriminoCellPosY[3] = 2;

		break;
	case CELL_I : 
		tetriminoCellPosX[0] = 0;
		tetriminoCellPosX[1] = 1;
		tetriminoCellPosX[2] = 2;
		tetriminoCellPosX[3] = 3;

		tetriminoCellPosY[0] = 1;
		tetriminoCellPosY[1] = 1;
		tetriminoCellPosY[2] = 1;
		tetriminoCellPosY[3] = 1;
		break;
	default : 
		break;
	}
	
	if (tetrimino == nullptr) {
		tetrimino = new Tetrimino(tetriminoCellPosX, tetriminoCellPosY, currentTetriminoType);
	}
	else {
		nextTetrimino = new Tetrimino(tetriminoCellPosX, tetriminoCellPosY, currentTetriminoType);
	}
}

void GameScene::setTetriminoOnField() {
	CellType type = tetrimino->getCellType();

	int rowPos[TETRIMINO_CELL_NUM];
	int linePos[TETRIMINO_CELL_NUM];
	tetrimino->blockCellPos(rowPos, linePos);

	for (int i = 0; i < TETRIMINO_CELL_NUM; i++) {
		field[linePos[i]][rowPos[i]] = type;
	}
}

bool GameScene::lineDelete() {
	int row;
	int line;
	//��������T��
	for (line = 0; line < FIELD_HEIGHT_CELL - 1; line++) {
		for (row = 1; row < FIELD_WIDTH_CELL - 1; row++) {
			if (field[line][row] == EMPTY) {
				break;
			}
		}
		if (row == FIELD_WIDTH_CELL - 1) {
			break;
		}
	}

	if (line == FIELD_HEIGHT_CELL - 1) {
		return false;
	}

	/* ������񂪑��݂��� */
	for (; line != 0; line--) {
		for (row = 1; row < FIELD_WIDTH_CELL - 1; row++) {
			field[line][row] = field[line - 1][row];
		}
	}
	for (row = 1; row < FIELD_WIDTH_CELL - 1; row++) {
		field[0][row] = EMPTY;
	}

	scoreCalc.addScore();

	return true;
}