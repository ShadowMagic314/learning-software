#include "selectLevelScene.h"

void selectLevelSceneDraw(struct selectLevelScene* s, struct gameData* gd)
{
	setbkcolor(BLUE);
	cleardevice();
	putTransparentImage(NULL, 0, 0, s->bkSelectLevel);
	
	s->gachaBtn->super.draw((sprite*)s->gachaBtn);
	s->exitBtn->super.draw((sprite*)s->exitBtn);

	if (s->isGachaBtnHover == true) {
		settextcolor(BLACK);
		settextstyle(100, 0, "Î¢ÈíÑÅºÚ");
		setbkmode(TRANSPARENT);
		outtextxy(1550, 110, "³é¿¨");
	}

	if (s->isExitBtnHover == true) {
		settextcolor(RED);
		settextstyle(100, 0, "Î¢ÈíÑÅºÚ");
		setbkmode(TRANSPARENT);
		outtextxy(350, 25, "ÍË³öÈ¤±³µ¥´Ê");
	}

	if (s->isSelectError == true && s->selectErrorCnt <= 25) {
		s->selectErrorCnt++;

		settextcolor(RED);
		settextstyle(100, 0, "Î¢ÈíÑÅºÚ");
		setbkmode(TRANSPARENT);

		char str[30];
		sprintf(str, "ÇëÏÈÍê³ÉµÚ%d¹Ø", gd->levelSchedule + 1);
		outtextxy(0, 0, str);
		FlushBatchDraw();
	}
	else {
		s->selectErrorCnt = 0;
		s->isSelectError = false;
	}
}

void selectLevelSceneUpdate(struct selectLevelScene* s, struct gameData* gd)
{
	for (int i = 0; i < LEVEL_NUM; i++) {
		if (s->selectedLevel == i + 1) {
			if (s->selectedLevel <= gd->levelSchedule + 1) {
				gd->level = s->selectedLevel;
				gd->isLevelScane = true;
				s->isQuit = true;
				break;
			}
			else {
				s->isSelectError = true;
				s->selectedLevel = -1;
				break;
			}
		}
	}
}

void selectLevelSceneControl(struct selectLevelScene* s, ExMessage* msg, struct gameData* gd)
{
	if (msg->message == WM_LBUTTONDOWN)
	{
		for (int i = 0; i < LEVEL_NUM; i++) {
			if (s->rectLevels[i].left < msg->x && msg->x < s->rectLevels[i].right) {
				if (s->rectLevels[i].top < msg->y && msg->y < s->rectLevels[i].bottom) {
					s->selectedLevel = i + 1;
					break;
				}
			}
		}
		if (s->gachaBtn->super.x < msg->x && msg->x < s->gachaBtn->super.x + s->gachaBtn->super.width && s->gachaBtn->super.y < msg->y && msg->y < s->gachaBtn->super.y + s->gachaBtn->super.height)
		{
			gd->isGachaScene = true;
			s->isQuit = true;
		}
		if (s->exitBtn->super.x < msg->x && msg->x < s->exitBtn->super.x + s->exitBtn->super.width && s->exitBtn->super.y < msg->y && msg->y < s->exitBtn->super.y + s->exitBtn->super.height)
		{
			gd->isExit = true;
			s->isQuit = true;
		}
	}
	if (s->gachaBtn->super.x < msg->x && msg->x < s->gachaBtn->super.x + s->gachaBtn->super.width && s->gachaBtn->super.y < msg->y && msg->y < s->gachaBtn->super.y + s->gachaBtn->super.height)
	{
		s->isGachaBtnHover = true;
	}
	else {
		s->isGachaBtnHover = false;
	}

	if (s->exitBtn->super.x < msg->x && msg->x < s->exitBtn->super.x + s->exitBtn->super.width && s->exitBtn->super.y < msg->y && msg->y < s->exitBtn->super.y + s->exitBtn->super.height)
	{
		s->isExitBtnHover = true;
	}
	else {
		s->isExitBtnHover = false;
	}
}

bool selectLevelSceneIsQuit(struct selectLevelScene* s, struct gameData* gd)
{
	return s->isQuit;
}

void selectLevelSceneInit(struct selectLevelScene* s)
{
	s->super.draw = (void(*)(struct scene*, struct gameData* gd))selectLevelSceneDraw;
	s->super.update = (void(*)(struct scene*, struct gameData* gd))selectLevelSceneUpdate;
	s->super.control = (void(*)(struct scene*, ExMessage*, struct gameData* gd))selectLevelSceneControl;
	s->super.isQuit = (bool(*)(struct scene*, struct gameData* gd))selectLevelSceneIsQuit;

	s->bkSelectLevel = new IMAGE;
	loadimage(s->bkSelectLevel, "asset/image/bkSelectLevel.png");

	s->rectLevels = (RECT*)malloc(sizeof(RECT) * LEVEL_NUM);
	s->rectLevels[0] = { 163,333,448,571 };
	s->rectLevels[1] = { 486,333,768,571 };
	s->rectLevels[2] = { 820,333,1102,571 };
	s->rectLevels[3] = { 1141,333,1426,571 };
	s->rectLevels[4] = { 1465,331,1747,571 };
	for (int i = 5; i < 10; i++) {
		s->rectLevels[i].left = s->rectLevels[i - 5].left;
		s->rectLevels[i].right = s->rectLevels[i - 5].right;
		s->rectLevels[i].top = s->rectLevels[i - 5].top + 297;
		s->rectLevels[i].bottom = s->rectLevels[i - 5].bottom + 297;
	}

	s->selectedLevel = -1;

	s->isQuit = false;

	s->gachaBtn = (struct btn*)malloc(sizeof(struct btn));
	btnInit(s->gachaBtn, 1700, 80, 169, 168, "asset/image/gachaBtn.png");
	s->exitBtn= (struct btn*)malloc(sizeof(struct btn));
	btnInit(s->exitBtn, 130, 35, 187, 80, "asset/image/exitBtn.png");

	s->isGachaBtnHover = false;
	s->isExitBtnHover = false;

	s->selectErrorCnt = 0;
}

void selectLevelSceneDestroy(struct selectLevelScene* s)
{
	delete s->bkSelectLevel;

	free(s->rectLevels);

	btnDestroy(s->gachaBtn);
	free(s->gachaBtn);
}