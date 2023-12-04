#pragma once
#include "Vector2.h"
class Player
{
private:
	Vector2 pos;
	float speed_;


public:
	Player();

	void Init();
	void Update();
	void Draw();

	// キーごとにコマンドを作る
	void MoveRight();
	void MoveLeft();

};

