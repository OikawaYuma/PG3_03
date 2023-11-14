#include "TitleScene.h"
#include "Novice.h"

void TitleScene::Init()
{
	input_ = Input::GetInstance();
	
}

void TitleScene::Update()
{
	// �V�[���J��
	if (input_->TriggerKey(DIK_SPACE)) {
		sceneNo_ = STAGE;
	}
}
void TitleScene::Draw()
{
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0x660000FF, kFillModeSolid);
}

// �Q�[�����I��
int TitleScene::GameClose()
{
	if (input_->TriggerKey(DIK_ESCAPE)) {
		return true;
	}
	return false;
}