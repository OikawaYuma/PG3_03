#include "ClearScene.h"
#include "Novice.h"
void ClearScene::Init()
{
	
}

void ClearScene::Update()
{
	// ƒV[ƒ“‘JˆÚ
	if (input_->TriggerKey(DIK_SPACE)) {
		sceneNo_ = TITLE;
	}
}
void ClearScene::Draw()
{
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0x000066FF, kFillModeSolid);
}


// ƒQ[ƒ€‚ðI—¹
int ClearScene::GameClose()
{
	if (input_->TriggerKey(DIK_ESCAPE)) {
		return true;
	}
	return false;
}