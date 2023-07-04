#pragma once
#include <Siv3D.hpp>

const Size kWindowSize = { 1920,1080 };
const String kAppTitle = U"只野駅 信号扱い所";
const String kConfigFileName = U"";

enum class State
{
	Title,
	SelectStages,
	Game,
	Result
};

using App = SceneManager<State>;
