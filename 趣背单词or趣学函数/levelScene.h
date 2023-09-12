#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define QUESTIONNUMEVERYLEVEL 20

#include"scene.h"
#include"gameData.h"
#include "btn.h"
#include <stdlib.h>

struct levelScene {
	struct scene super;

	IMAGE* bkLevel;
	IMAGE* imgBingo;
	IMAGE* imgError;

	btn* backBtn;
	btn* optionABtn;
	btn* optionBBtn;
	btn* optionCBtn;
	btn* optionDBtn;
	btn* nextBtn;

	RECT rectOptionA, rectOptionB, rectOptionC, rectOptionD;
	RECT rectQuestion;

	bool selectedOption[4];//�ĸ�����Ԫ�ض�Ӧ�ĸ�ѡ�false��ʾû�б�ѡ��true��ʾ��ѡ��

	bool isQuit;
	bool isNext;
	bool isSuccess;

	int correctOption;//1-A 2-B 3-C 4-D

	int questionIndex;//�����ǵڼ�������
	int correctAnswerIndex;//��ȷ��λ
	int errorAnswerIndex[3];//�����λ

	char words[20][50];
	char chineses[20][100];

	bool isPlayBingoSound;
	bool isPlayErrorSound;

	bool soundFlag[4];//0-A 1-B 3-C 4-D true�ǻ�û���,false���Ѿ������
};

void levelSceneInit(struct levelScene* s,struct gameData* gd);
void levelSceneDestroy(struct levelScene* s);