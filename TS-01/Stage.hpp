#pragma once
#include "Common.hpp"

class Stage {

private :

	String time_zone;
	FilePath stage_file_path;

public:
	Stage(String time, FilePath path) {

		if (time_zone.length() != 13) {
			throw Error{ U"Stage Class : 指定された時刻形式が違います。"};
		}
		if (not FileSystem::Exists(path)) {
			throw Error{ U"Stage Class : 指定されたステージ情報ファイルが存在しません。"};
		}
		time_zone = time;
		stage_file_path = path;
	}
};
