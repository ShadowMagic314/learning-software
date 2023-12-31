#pragma once
#include"vector.h"

//包含的存储库
#include"characterDatabase.h"

struct gameData {
	void (*load)(struct gameData*);
	void (*save)(struct gameData*);

	//数据库
	struct characterDatabase characterDB;

	//需要存取的数据
	int gachaTimes;
	int exp;
	int pinkballNum;
	int levelSchedule;//1~10//1完成后是1
	bool* ownFiveStarCharacters;
	bool* ownFourStarCharacters;

	//通用数据
	int level;//1~10

	bool isExit;

	bool isGachaScene;
	bool isLevelScane;
	bool isLevelFinishScene;
	bool isSelectLevelScene;
};

void gameDataInit(struct gameData*gd);
void gameDataDestroy(struct gameData* gd);