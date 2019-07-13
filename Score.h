#pragma once
#ifndef INCLUDED_SCORE_H_
#define INCLUDED_SCORE_H_

#define BASE_SCORE 100	//1ライン消すごとにこの点分追加

class Score
{
public:
	Score();
	~Score();

	void addScore() { score += BASE_SCORE; }
	int getCurrentScore() const { return score; }
private : 
	int score;
};

#endif // !INCLUDED_SCORE_H_
