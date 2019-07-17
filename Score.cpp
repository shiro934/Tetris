#include "Score.h"

#define BASE_SCORE 100	//1ライン消すごとに加算する基本スコア

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