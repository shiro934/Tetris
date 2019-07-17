#pragma once
#ifndef INCLUDED_SCORE_H_
#define INCLUDED_SCORE_H_

class Score
{
public:
	Score();
	~Score();

	void addScore(const int level);
	int getCurrentScore() const { return score; }
private : 
	int score;
};

#endif // !INCLUDED_SCORE_H_
