#include "StageScene.h"
#include "Novice.h"
void StageScene::Init()
{
	input_ = Input::GetInstance();
	
	playerPos = { 640,500 };
	isShot = false;

	bulletPos = { playerPos.x ,playerPos.y - 30 };
	
	enemyPos = { 640,50 };
	isAlive = true;

	
}

void StageScene::Update()
{
	// ’e‚Ì”­ŽË
	if (input_->TriggerKey(DIK_SPACE)) {
		isShot = true;
	}

	if (isShot) {
		bulletPos.y-=5;
	}
	// “–‚½‚è”»’è
	if (bulletPos.y - 10 <= enemyPos.y + 40) {
		isAlive = false;
	}
	
	// ƒV[ƒ“‘JˆÚ
	if (!isAlive) {
		sceneNo_ = CLEAR;
	}


}
void StageScene::Draw()
{
	Novice::DrawBox(0, 0, 1280, 720, 0.0f,0x006600FF, kFillModeSolid);
	Novice::DrawEllipse((int)playerPos.x, (int)playerPos.y, 40, 40, 0.0f, WHITE, kFillModeSolid);
	if (isShot) {
		Novice::DrawEllipse((int)bulletPos.x, (int)bulletPos.y, 10, 10, 0.0f, WHITE, kFillModeSolid);
	}

	if (isAlive) {
		Novice::DrawEllipse((int)enemyPos.x, (int)enemyPos.y, 40, 40, 0.0f, BLACK, kFillModeSolid);
	}
}
// ƒQ[ƒ€‚ðI—¹
int StageScene::GameClose()
{
	if (input_->TriggerKey(DIK_ESCAPE)) {
		return true;
	}
	return false;
}