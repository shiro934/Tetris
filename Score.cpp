#include "Score.h"

#define BASE_SCORE 100	//1���C���������Ƃɉ��Z�����{�X�R�A

Score::Score()
{
	score = 0;
}


Score::~Score()
{
}

void Score::addScore(const int level) {
	score += BASE_SCORE * level;
}