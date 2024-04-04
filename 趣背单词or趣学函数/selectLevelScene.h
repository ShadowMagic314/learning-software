#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "scene.h"
#include "gameData.h"
#include "image.h"
#include "btn.h"
#include <stdio.h>

#define LEVEL_NUM 20//���йؿ�����

struct selectLevelScene {
	struct scene super;

	IMAGE* bkSelectLevel;
	IMAGE* levelBlock;
	IMAGE* titleImg;
	IMAGE* voidstar;
	IMAGE* fullstar;

	RECT* rectLevels;//ÿһ���ؿ���

	int selectedLevel;//��ʵ������1��ʼ

	bool isQuit;

	btn* gachaBtn;
	btn* homeBtn;

	bool isGachaBtnHover;

	bool isSelectError;//Խ��ѡ��
	int selectErrorCnt;
};

void selectLevelSceneInit(struct selectLevelScene* s);
void selectLevelSceneDestroy(struct selectLevelScene* s);