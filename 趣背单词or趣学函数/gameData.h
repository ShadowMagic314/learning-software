#pragma once
#include"vector.h"

//�����Ĵ洢��
#include"characterDatabase.h"

struct gameData {
	void (*load)(struct gameData*);
	void (*save)(struct gameData*);

	//���ݿ�
	struct characterDatabase characterDB;

	//��Ҫ��ȡ������
	int gachaTimes;
	int exp;
	int pinkballNum;
	int levelSchedule;//1~10//1��ɺ���1
	bool* ownFiveStarCharacters;
	bool* ownFourStarCharacters;

	//ͨ������
	int level;//1~10

	bool isExit;

	bool isGachaScene;
	bool isLevelScane;
	bool isLevelFinishScene;
	bool isSelectLevelScene;
};

void gameDataInit(struct gameData*gd);
void gameDataDestroy(struct gameData* gd);