#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include"vector.h"
#include<easyx.h>
#include<stdio.h>
#define FIVESTARCHARACTERNUM 6
#define FOURSTARCHARACTERNUM 5

//��ģ�������Ϊ�洢�⹩���ң���û�з�����ֻ��init��destroy

struct characterDatabase {
	const char* fiveStarCharacterName[FIVESTARCHARACTERNUM] = { "����","��¬��","����","Ī��","����","��", };
	const char* fourStarCharacterName[FOURSTARCHARACTERNUM] = { "����","�ϰ���","ŵ����","����", "���" };

	const int fiveStarCharacterNum = FIVESTARCHARACTERNUM;
	const int fourStarCharacterNum = FOURSTARCHARACTERNUM;

	vector vecFiveStarCharacterImg;
	vector vecFiveStarCharacterMask;
	vector vecFourStarCharacterImg;
	vector vecFourStarCharacterMask;
};

void characterDatabaseInit(struct characterDatabase*cd);
void characterDatabaseDestroy(struct characterDatabase*cd);