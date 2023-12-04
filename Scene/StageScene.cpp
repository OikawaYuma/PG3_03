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

	inputHandler_ = new InputHandle();

	//Assign command
	inputHandler_->AssignMoveRightCommand2PressKeyD();
	inputHandler_->AssignMoveLeftCommand2PressKeyA();

	//New Player
	player_ = new Player();
	player_->Init();

	
}

void StageScene::Update()
{
	// 弾の発射
	if (input_->TriggerKey(DIK_SPACE)) {
		isShot = true;
	}

	if (isShot) {
		bulletPos.y-=5;
	}
	// 当たり判定
	if (bulletPos.y - 10 <= enemyPos.y + 40) {
		isAlive = false;
	}
	
	// シーン遷移
	if (!isAlive) {
		sceneNo_ = CLEAR;
	}

	command_ = inputHandler_->HandleInput();

	if (this->command_) {
		command_->Exec(*player_);
	}
	player_->Update();
}
void StageScene::Draw()
{
	Novice::DrawBox(0, 0, 1280, 720, 0.0f,0x006600FF, kFillModeSolid);
	//Novice::DrawEllipse((int)playerPos.x, (int)playerPos.y, 40, 40, 0.0f, WHITE, kFillModeSolid);
	player_->Draw();
	if (isShot) {
		Novice::DrawEllipse((int)bulletPos.x, (int)bulletPos.y, 10, 10, 0.0f, WHITE, kFillModeSolid);
	}

	if (isAlive) {
		Novice::DrawEllipse((int)enemyPos.x, (int)enemyPos.y, 40, 40, 0.0f, BLACK, kFillModeSolid);
	}
}
// ゲームを終了
int StageScene::GameClose()
{
	if (input_->TriggerKey(DIK_ESCAPE)) {
		return true;
	}
	return false;
}