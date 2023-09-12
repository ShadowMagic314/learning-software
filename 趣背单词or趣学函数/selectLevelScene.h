#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "scene.h"
#include "gameData.h"
#include "image.h"
#include "btn.h"
#include<stdio.h>

#define LEVEL_NUM 10
struct selectLevelScene {
	struct scene super;

	IMAGE* bkSelectLevel;

	RECT* rectLevels;//每一个关卡块

	int selectedLevel;//按实际来，1开始

	bool isQuit;

	btn* gachaBtn;
	btn* exitBtn;

	bool isGachaBtnHover;
	bool isExitBtnHover;

	bool isSelectError;//越级选择
	int selectErrorCnt;
};

void selectLevelSceneInit(struct selectLevelScene* s);
void selectLevelSceneDestroy(struct selectLevelScene* s);