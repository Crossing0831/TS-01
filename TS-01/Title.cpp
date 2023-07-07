#include "Title.hpp"

Title::Title(const InitData& init)
	: IScene { init }{}

void Title::update()
{
	//ステージ選択画面遷移ボタン
	{
		RectF btn = { Arg::center(Vec2{Scene::Center().x,kWindowSize.y * 0.55}),250,50 };

		if (btn.leftClicked()) {
			changeScene(State::StageSelect);
		}
	}
	//ゲーム終了ボタン
	{
		RectF btn = { Arg::center(Vec2{Scene::Center().x,kWindowSize.y * 0.63}),250,50 };

		if (btn.leftClicked()) {
			System::Exit();
		}
	}
}

void Title::draw() const
{
	FontAsset(U"TitleFont")(kAppTitle).drawAt({ Scene::Center().x , kWindowSize.y / 4});
	FontAsset(U"MenuFont")(U"～信号を操作して、定時運行を目指そう～").drawAt({ Scene::Center().x , kWindowSize.y / 2.5});

	//ステージ選択ボタン
	{
		
		RectF btn = { Arg::center(Vec2{Scene::Center().x,kWindowSize.y * 0.55}),250,50};

		if (btn.mouseOver()) {
			btn.draw(Palette::White);
			FontAsset(U"MenuFont")(U"→ Play").draw(btn,Palette::Black);
		}
		else {
			btn.drawFrame(1.5);
			FontAsset(U"MenuFont")(U"→ Play").draw(btn, Palette::White);
		}
	}
	//ゲーム終了ボタン
	{

		RectF btn = { Arg::center(Vec2{Scene::Center().x,kWindowSize.y * 0.63}),250,50 };

		if (btn.mouseOver()) {
			btn.draw(Palette::White);
			FontAsset(U"MenuFont")(U"→ Exit").draw(btn, Palette::Black);
		}
		else {
			btn.drawFrame(1.5);
			FontAsset(U"MenuFont")(U"→ Exit").draw(btn, Palette::White);
		}
	}
}
