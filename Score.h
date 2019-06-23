#pragma once
#ifndef INCLUDED_SCORE_H_
#define INCLUDED_SCORE_H_

class Score
{
public:
	Score();
	~Score();

	void addScore() { score += BASE_SCORE; }
	int getCurrentScore() const { return score; }
private : 
	int score;
	const int BASE_SCORE = 100;	//1ƒ‰ƒCƒ“Á‚·‚²‚Æ‚É‚±‚Ì“_•ª’Ç‰Á
};

#endif // !INCLUDED_SCORE_H_
