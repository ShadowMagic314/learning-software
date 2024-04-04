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
	int levelSchedule;//1~20//1��ɺ���1
	int purpleMinimumGuaranteeCnt;
	int goldMinimumGuaranteeCnt;
	bool* ownFiveStarCharacters;
	bool* ownFourStarCharacters;

	//ͨ������
	int level;//1~10

	bool isExit;

	bool isGachaScene;
	bool isLevelScane;
	bool isLevelFinishScene;
	bool isSelectLevelScene;
	bool isMenuScene;
};

void gameDataInit(struct gameData*gd);
void gameDataDestroy(struct gameData* gd);