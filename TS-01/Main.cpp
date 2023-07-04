#include "Common.hpp"
#include "Title.hpp"

void Main()
{

	App manager;
	manager.add<Title>(State::Title);

	FontAsset::Register(U"MenuFont",35);
	FontAsset::Register(U"TitleFont", FontMethod::MSDF, 50, Typeface::Medium);


	Window::Resize(kWindowSize);
	Window::SetFullscreen(true);

	while (System::Update())
	{
		if (not manager.update()){
			break;
		}
	}
}
