/********
4105056005 鄭筠庭 第二次作業10/24
4105056005 Yun-Ting Cheng The Second Homework 10/24
********/

// wp_hw02_4105056005.cpp: 主要專案檔。

#include "stdafx.h"
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace System;
using namespace System::IO;

//設定各地價錢且0棟房子
void initialLocation(array<int>^ plocaMon, array<int>^ phouses, array<int>^ pnoTax, int^ pround, array<int>^ alive, array<int>^ owner, array<int>^ pposition) {
	plocaMon[0] = 0;	plocaMon[1] = 100;	plocaMon[2] = 60;
	plocaMon[3] = 140;	plocaMon[4] = 80;	plocaMon[5] = 110;
	plocaMon[6] = 0;	plocaMon[7] = 100;	plocaMon[8] = 150;
	plocaMon[9] = 160;	plocaMon[10] = 200;	plocaMon[11] = 200;
	plocaMon[12] = 150;	plocaMon[13] = 250;	plocaMon[14] = 180;
	plocaMon[15] = 420;	plocaMon[16] = 170;	plocaMon[17] = 0;
	plocaMon[18] = 220;	plocaMon[19] = 250;	plocaMon[20] = 160;
	plocaMon[21] = 200;	plocaMon[22] = 180;	plocaMon[23] = 230;
	plocaMon[24] = 300;	plocaMon[25] = 200;	plocaMon[26] = 350;
	plocaMon[27] = 320;	plocaMon[28] = 160;	plocaMon[29] = 380;

	int^ pi = gcnew int;
	for (*pi = 0; *pi < 30; (*pi)++) {
		phouses[*pi] = 0;
		owner[*pi] = 0;//0代表無人擁有此塊地
	}

	pnoTax[0] = 0;
	pnoTax[1] = 0;
	pnoTax[2] = 0;
	pnoTax[3] = 0;

	alive[0] = 0;
	alive[1] = 0;
	alive[2] = 0;
	alive[3] = 0;

	pposition[0] = 0;
	pposition[1] = 0;
	pposition[2] = 0;
	pposition[3] = 0;

	*pround = 0;
	return;
}

//印出規則
void startNewGame() {
	Console::Write("{0,58}","-歡迎來到奇幻世界大富翁-\n\n");
	Console::Write("遊戲說明:\n    此遊戲開始金額建議為1000元，每次經過起點將獲得300元。\n");
	Console::Write("    每次行動可選擇擲骰子(d)或是重新開始整個遊戲(r)。可以存檔、讀檔與刪除所有紀錄檔。\n");
	Console::Write("    踩上土地方塊時，可以決定是否購買房子，或是繼續升級房屋，一塊土地最多升到5級房子。若土地已有該玩家蓋的房子，則可收取保護費。站到其他玩家的土地上，則會被收取過路費。\n");
	Console::Write("    踩到機會及命運方塊，系統將自動抽牌，並執行牌上的指令。\n");
	Console::Write("    踩到抽稅方塊，玩家將減少200元。若擁有逃稅卡牌將會自動使用。\n");
	Console::Write("    存檔都在同一個檔案Save.txt，讀檔也是從Save.txt讀取，若弄亂文字的格式會造成讀檔錯誤。可選擇任何存檔紀錄。\n\n");
	
	Console::Write("遊戲背景:\n    在某個奇幻世界，荒蕪的大地上充滿怪物與暴力的居民，而你是一個沒沒無聞但充滿野心的人類。\n");
	Console::Write("    你此生的夢想，就是在這片土地上建造自己的王國，但你並不是唯一想要統治這世界的人。\n");
	Console::Write("    用你手中的金幣，建造廣大的殖民地，並盡力讓你的敵人破產。最終口袋裡還有金幣的人，就是贏家...\n\n");
	return;
}

//印出大富翁地圖
void printMap(array<String^>^ plocations, array<int>^ phouses, array<int>^ plocaMon, array<int>^ owner, array<int>^ pposition, int^ people, array<int>^ alive) {
	int^ pi = gcnew int;
	int^ pj = gcnew int;
	int^ pfront = gcnew int;
	int^ pback = gcnew int;
	*pfront = 0;
	*pback = 29;
	//橫線
	for (*pi = 0; *pi < 120; (*pi)++) {
		Console::Write(L'-');
	}
	//共9個9x5小格子，左右2個13x5大格子
	for (*pj = 0; *pj < 4; (*pj)++) {
		//印出房子
		if (*pj == 0) {
			if (phouses[*pfront] > 0)
				Console::Write("|    {0}'s house", owner[*pfront]);
			else
				Console::Write("|             ");
			(*pfront)++;
			for (*pi = 0; *pi < 9; (*pi)++) {
				if (phouses[*pfront] > 0)
					Console::Write("|{0}'s house", owner[*pfront]);
				else
					Console::Write("|         ");
				(*pfront)++;
			}
			if (phouses[*pfront] > 0)
				Console::Write("|    {0}'s house| ", owner[*pfront]);
			else
				Console::Write( "|             | ");
			(*pfront)++;
		}
		//印出地名
		else if (*pj == 1) {
			*pfront = 0;
			Console::Write("|{0,13}", plocations[*pfront]);
			(*pfront)++;
			for (*pi = 0; *pi < 9; (*pi)++) {
				Console::Write("|{0,9}", plocations[*pfront]);
				(*pfront)++;
			}
			Console::Write("|{0,13}| ", plocations[*pfront]);
			(*pfront)++;
		}
		//印出玩家位置
		else if (*pj == 2) {
			*pfront = 1;
			if (pposition[0] == (*pfront) - 1)
				Console::Write("|□");
			else
				Console::Write("|  ");
			if (pposition[1] == (*pfront) - 1 && alive[1] == 0)
				Console::Write("■");
			else
				Console::Write("  ");
			if (pposition[2] == (*pfront) - 1 && *people > 2 && alive[2] == 0)
				Console::Write("△");
			else
				Console::Write("  ");
			if (pposition[3] == (*pfront) - 1 && *people > 3 && alive[3] == 0)
				Console::Write("▲     ");
			else
				Console::Write("       ");
			for (*pi = 0; *pi < 9; (*pi)++) {
				if (pposition[0] == *pfront)
					Console::Write("|□");
				else
					Console::Write("|  ");
				if (pposition[1] == *pfront && alive[1] == 0)
					Console::Write("■");
				else
					Console::Write("  ");
				if (pposition[2] == *pfront && *people > 2 && alive[2] == 0)
					Console::Write("△");
				else
					Console::Write("  ");
				if (pposition[3] == *pfront && *people > 3 && alive[3] == 0)
					Console::Write("▲ ");
				else
					Console::Write("   ");
				(*pfront)++;
			}
			if (pposition[0] == *pfront)
				Console::Write("|□");
			else
				Console::Write("|  ");
			if (pposition[1] == *pfront && alive[1] == 0)
				Console::Write("■");
			else
				Console::Write("  ");
			if (pposition[2] == *pfront && *people > 2 && alive[2] == 0)
				Console::Write("△");
			else
				Console::Write("  ");
			if (pposition[3] == *pfront && *people > 3 && alive[3] == 0)
				Console::Write("▲     | ");
			else
				Console::Write("       | ");
			(*pfront)++;
		}
		//沒有文字的行
		else {
			Console::Write("|             ");
			for (*pi = 0; *pi < 9; (*pi)++)
				Console::Write("|         ");
			Console::Write("|             | ");
		}
	}
	//橫線
	for (*pi = 0; *pi < 120; (*pi)++) {
		Console::Write(L'-');
	}
	//左右2個13x4大格子，三排
	for (*pi = 0; *pi < 4; (*pi)++) {
		for (*pj = 0; *pj < 3; (*pj)++) {
			//印出房屋
			if (*pj == 0) {
				if (phouses[*pback] > 0)
					Console::Write("|    {0}'s house|                                             ", owner[*pback]);
				else
					Console::Write("|             |                                             ");
				if (phouses[*pfront] > 0)
					Console::Write("                                            |    {0}'s house| ", owner[*pfront]);
				else
					Console::Write("                                            |             | ");
			}
			//印出地名
			else if (*pj == 1) {
				Console::Write("|{0,13}|                                             ", plocations[*pback]);
				Console::Write("                                            |{0,13}| ", plocations[*pfront]);
			}
			//印出玩家位置
			else if (*pj == 2) {
				//左邊格子
				if (pposition[0] == *pback)
					Console::Write("|□");
				else
					Console::Write("|  ");
				if (pposition[1] == *pback && alive[1] == 0)
					Console::Write("■");
				else
					Console::Write("  ");
				if (pposition[2] == *pback && *people > 2 && alive[2] == 0)
					Console::Write("△");
				else
					Console::Write("  ");
				if (pposition[3] == *pback && *people > 3 && alive[3] == 0)
					Console::Write("▲     |                                             ");
				else
					Console::Write("       |                                             ");
				//右邊格子
				if (pposition[0] == *pfront)
					Console::Write("                                            |□");
				else
					Console::Write("                                            |  ");
				if (pposition[1] == *pfront && alive[1] == 0)
					Console::Write("■");
				else
					Console::Write("  ");
				if (pposition[2] == *pfront && *people > 2 && alive[2] == 0)
					Console::Write("△");
				else
					Console::Write("  ");
				if (pposition[3] == *pfront && *people > 3 && alive[3] == 0)
					Console::Write("▲     | ");
				else
					Console::Write("       | ");
				(*pfront)++;
				(*pback)--;
			}
			else {
				Console::Write("|             |                                             ");
				Console::Write("                                            |             | ");
			}
		}
		if (*pi == 3) {
			Console::Write("|             |       □:1th player      ■:2th player      ");
			Console::Write("   △:3th player       ▲:4th player        |             | ");
		}
		else {
			Console::Write(L"--------------                                                  ");
			Console::Write(L"                                        --------------- ");
		}

	}
	//橫線
	for (*pi = 0; *pi < 120; (*pi)++) {
		Console::Write(L'-');
	}
	//共9個9x5小格子，左右2個13x5大格子
	for (*pj = 0; *pj < 4; (*pj)++) {
		//印出房子
		if (*pj == 1) {
			if (phouses[*pback] > 0)
				Console::Write("|    {0}'s house", owner[*pback]);
			else
				Console::Write("|             ");
			(*pback)--;
			for (*pi = 0; *pi < 9; (*pi)++) {
				if (phouses[*pback] > 0)
					Console::Write("|{0}'s house", owner[*pback]);
				else
					Console::Write("|         ");
				(*pback)--;
			}
			if (phouses[*pback] > 0)
				Console::Write("|    {0}'s house| ", owner[*pback]);
			else
				Console::Write("|             | ");
			(*pback)--;
		}
		//印出地名
		else if (*pj == 2) {
			*pback = 25;
			Console::Write("|{0,13}", plocations[*pback]);
			(*pback)--;
			for (*pi = 0; *pi < 9; (*pi)++) {
				Console::Write("|{0,9}", plocations[*pback]);
				(*pback)--;
			}
			Console::Write("|{0,13}| ", plocations[*pback]);
			(*pback)--;
		}
		//印出玩家位置
		else if (*pj == 3) {
			*pback = 25;
			if (pposition[0] == *pback)
				Console::Write("|□");
			else
				Console::Write("|  ");
			if (pposition[1] == *pback && alive[1] == 0)
				Console::Write("■");
			else
				Console::Write("  ");
			if (pposition[2] == *pback && *people > 2 && alive[2] == 0)
				Console::Write("△");
			else
				Console::Write("  ");
			if (pposition[3] == *pback && *people > 3 && alive[3] == 0)
				Console::Write("▲     ");
			else
				Console::Write("       ");
			(*pback)--;
			for (*pi = 0; *pi < 9; (*pi)++) {
				if (pposition[0] == *pback)
					Console::Write("|□");
				else
					Console::Write("|  ");
				if (pposition[1] == *pback && alive[1] == 0)
					Console::Write("■");
				else
					Console::Write("  ");
				if (pposition[2] == *pback && *people > 2 && alive[2] == 0)
					Console::Write("△");
				else
					Console::Write("  ");
				if (pposition[3] == *pback && *people > 3 && alive[3] == 0)
					Console::Write("▲ ");
				else
					Console::Write("   ");
				(*pback)--;
			}
			if (pposition[0] == *pback)
				Console::Write("|□");
			else
				Console::Write("|  ");
			if (pposition[1] == *pback && alive[1] == 0)
				Console::Write("■");
			else
				Console::Write("  ");
			if (pposition[2] == *pback && *people > 2 && alive[2] == 0)
				Console::Write("△");
			else
				Console::Write("  ");
			if (pposition[3] == *pback && *people > 3 && alive[3] == 0)
				Console::Write("▲     | ");
			else
				Console::Write("       | ");
			(*pback)--;
		}
		//沒有文字的行
		else {
			Console::Write(L"|             ");
			for (*pi = 0; *pi < 9; (*pi)++)
				Console::Write(L"|         ");
			Console::Write(L"|             | ");
		}
	}
	//橫線
	for (*pi = 0; *pi < 120; (*pi)++) {
		Console::Write(L'-');
	}
	return;
}

//存檔
void savetxt(array<String^>^ playerName, int^ people, array<int>^ pmoney, array<int>^ pnoTax, array<int>^ owner, array<int>^ pposition,
	array<int>^ phouses, array<int>^ plocaMon, array<int>^ alive) {
	StreamWriter^ sf = gcnew StreamWriter("Save.txt", true);
	sf->WriteLine();
	sf->WriteLine("Save File:");
	sf->WriteLine("Player's name:" + playerName[0]);
	sf->WriteLine("Number of player:" + *people);
	sf->WriteLine("Players' money:" + pmoney[0] + "/" + pmoney[1] + "/" + pmoney[2] + "/" + pmoney[3]);
	sf->WriteLine("Players' location:" + pposition[0] + "/" + pposition[1] + "/" + pposition[2] + "/" + pposition[3]);
	sf->WriteLine("Players' NoTax card:" + pnoTax[0] + "/" + pnoTax[1] + "/" + pnoTax[2] + "/" + pnoTax[3]);
	sf->WriteLine("Players are alive or not:" + alive[0] + "/" + alive[1] + "/" + alive[2] + "/" + alive[3]);
	sf->Write("Cost of each place from 00 to 29:");
	for (int^ pi = 0; *pi < 30; (*pi)++)
		sf->Write(plocaMon[*pi]+"/");
	sf->WriteLine();
	sf->Write("Number of houses on each place from 00 to 29:");
	for (int^ pi = 0; *pi < 30; (*pi)++)
		sf->Write(phouses[*pi] + "/");
	sf->WriteLine();
	sf->Write("Owner of each place from 00 to 29:");
	for (int^ pi = 0; *pi < 30; (*pi)++)
		sf->Write(owner[*pi] + "/");
	sf->WriteLine();
	sf->Close();
	Console::Write("存檔成功。(按下ENTER)");
	String^ inputString = Console::ReadLine();
	return;
}

//讀檔
void loadtxt(array<String^>^ playerName, int^ people, array<int>^ pmoney, array<int>^ pnoTax, array<int>^ owner, array<int>^ pposition,
	array<int>^ phouses, array<int>^ plocaMon, array<int>^ alive) {
	try
	{
		//讓玩家選擇讀哪個檔案
		StreamReader^ sl = File::OpenText("Save.txt");
		String^ str;
		int^ count = gcnew int;		//幾個紀錄
		int^ whichFile = gcnew int;	//選擇第幾個紀錄
		count = 0;
		while ((str = sl->ReadLine()) != nullptr){
			if (String::Compare(str, "Save File:") == 0)
				(*count)++;
		}
		if (*count == 0) {
			Console::Write("無任何存檔紀錄。\n");
			return;
		}
		Console::Write("現在有{0}個記錄檔，請輸入數字選擇要讀的紀錄檔，數字越大紀錄越新: ", *count);
		do {
			String^ inputNum = Console::ReadLine();
			*whichFile = Convert::ToInt32(inputNum);
			if (*whichFile <= 0 || *whichFile > *count)
				Console::Write("輸入錯誤，請輸入範圍內的數字:");
			else
				break;
		} while (true);
		Console::Write("選擇第{0}個檔案。讀取中....\n", *whichFile);
		sl->Close();

		//重新開啟text檔，讀取資料
		sl = File::OpenText("Save.txt");
		count = 0;
		int^ lines = gcnew int; //一個紀錄有十行文字，一行空白
		array<String^>^ words;	//分割句子
		*lines = 1;
		while ((str = sl->ReadLine()) != nullptr) {
			if (String::Compare(str, "Save File:") == 0)
				(*count)++;
			if (*count == *whichFile) {
				//Console::WriteLine("{0}", str);
				words = str->Split(':');
				switch (*lines)
				{
				case 2:		//第二行是玩家名字
					playerName[0] = words[1];
					break;
				case 3:		//第三行是玩家數量
					*people = Convert::ToInt32(words[1]);
					break;
				case 4:		//第四行是各玩家金錢
					words = words[1]->Split('/');
					pmoney[0] = Convert::ToInt32(words[0]);
					pmoney[1] = Convert::ToInt32(words[1]);
					pmoney[2] = Convert::ToInt32(words[2]);
					pmoney[3] = Convert::ToInt32(words[3]);
					break;
				case 5:		//第五行是各玩家地點
					words = words[1]->Split('/');
					pposition[0] = Convert::ToInt32(words[0]);
					pposition[1] = Convert::ToInt32(words[1]);
					pposition[2] = Convert::ToInt32(words[2]);
					pposition[3] = Convert::ToInt32(words[3]);
					break;
				case 6:		//第六行是各玩家特殊卡片數量
					words = words[1]->Split('/');
					pnoTax[0] = Convert::ToInt32(words[0]);
					pnoTax[1] = Convert::ToInt32(words[1]);
					pnoTax[2] = Convert::ToInt32(words[2]);
					pnoTax[3] = Convert::ToInt32(words[3]);
					break;
				case 7 :	//第七行是玩家存活與否
					words = words[1]->Split('/');
					alive[0] = Convert::ToInt32(words[0]);
					alive[1] = Convert::ToInt32(words[1]);
					alive[2] = Convert::ToInt32(words[2]);
					alive[3] = Convert::ToInt32(words[3]);
					break;
				case 8:		//第八行是地點價格
					words = words[1]->Split('/');
					for (int^ i = 0; *i < 30; (*i)++)
						plocaMon[*i] = Convert::ToInt32(words[*i]);
					break;
				case 9:		//第九行是房子數量
					words = words[1]->Split('/');
					for (int^ i = 0; *i < 30; (*i)++)
						phouses[*i] = Convert::ToInt32(words[*i]);
					break;
				case 10:	//第十行是房子主人
					words = words[1]->Split('/');
					for (int^ i = 0; *i < 30; (*i)++)
						owner[*i] = Convert::ToInt32(words[*i]);
					break;
				default:
					break;
				}
				(*lines)++;
			}
		}
		sl->Close();
		Console::Write("讀取成功。(按下ENTER)");
		String^ inputString = Console::ReadLine();
	}
	catch (Exception^ e)
	{
		if (dynamic_cast<FileNotFoundException^>(e))
			Console::WriteLine("file '{0}' not found", "Save.txt");
		else
			Console::WriteLine("problem reading file '{0}'", "Save.txt");
	}

	return;
}

//亂數骰骰子，從2到12點；重新進行遊戲；load或是store檔案；印出所有過往事件
int^ rollDice(int^ pdice, int^ preturn, array<String^>^ playerName, int^ people, array<int>^ pmoney, array<int>^ pnoTax, array<int>^ owner, array<int>^ pposition,
	array<int>^ phouses, array<int>^ plocaMon, array<int>^ alive, array< String^ >^ plocations) {
	do {
		Console::Write("按d擲骰子，按r重新開始，show印出所有過往事件，load載入舊遊戲檔，save存檔，delete刪除所有紀錄檔: ");
		String^ inputString = Console::ReadLine();
		if (String::Compare(inputString, "d") == 0) {
			srand(time(NULL));
			*pdice = (rand() % 11) + 2;
			Console::Write("登登愣~你共擲出了{0}點。\n", *pdice );
			*preturn = 0;
			return preturn;
		}
		else if (String::Compare(inputString, "r") == 0) {
			*preturn = 1;
			return preturn;
		}
		else if (String::Compare(inputString, "show") == 0) {
			Console::WriteLine();
			StreamReader^ din = File::OpenText("ShowEvent.txt");
			String^ str;
			while ((str = din->ReadLine()) != nullptr)
				Console::WriteLine("{0}", str);
			din->Close();
			Console::WriteLine();
		}
		else if (String::Compare(inputString, "load") == 0) {
			loadtxt(playerName, people, pmoney, pnoTax, owner, pposition, phouses, plocaMon, alive);
			printMap(plocations, phouses, plocaMon, owner, pposition, people, alive);
		}
		else if (String::Compare(inputString, "save") == 0)
			savetxt(playerName, people, pmoney, pnoTax, owner, pposition, phouses,plocaMon, alive);
		else if (String::Compare(inputString, "delete") == 0) {
			if (File::Exists("Save.txt")) {
				System::IO::File::Delete("Save.txt");
				Console::Write("已刪除所有紀錄檔。");
			}
			else
				Console::Write("無任何存檔紀錄。");
			Console::Write("(按下ENTER)");
			String^ enter = Console::ReadLine();
		}
		else {
			Console::Write("輸入錯誤。\n");
		}
	} while (true);
}

//機會
void chance(array<int>^ pmoney, array<int>^ pnoTax, int^ pround) {
	int^ ptemp = gcnew int;
	srand(time(NULL));
	*ptemp = rand() % 5;
	String^ enter;
	switch (*ptemp) {
	case 0:
		Console::Write("一名受傷又迷路的精靈向你求助，你給了他250元旅費。(按下ENTER)");
		pmoney[*pround] -= 250;
		enter = Console::ReadLine();
		break;
	case 1:
		Console::Write("被捲進半獸人戰爭，重傷住院，花700元治療費。(按下ENTER)");
		pmoney[*pround] -= 700;
		enter = Console::ReadLine();
		break;
	case 2:
		Console::Write("得到逃稅大師的親自指點，獲得一本逃稅密籍。(可以少繳一次稅)(按下ENTER)");
		pnoTax[*pround] += 1;
		enter = Console::ReadLine();
		break;
	case 3:
		Console::Write("矮人領導者送上500元，已表示友好，看來你交到了新朋友呢。(按下ENTER)");
		pmoney[*pround] += 500;
		enter = Console::ReadLine();
		break;
	case 4:
		Console::Write("到黑市變賣你偷來的精靈寶劍，賺了400元，良心好像有點不安...(按下ENTER)");
		pmoney[*pround] += 400;
		enter = Console::ReadLine();
		break;
	default:
		Console::Write("Error.");
	}
	delete ptemp;
	return;
}

//命運
void community(array<int>^ pmoney, array<int>^ pnoTax, int^ pround) {
	int* ptemp = new int;
	srand(time(NULL));
	*ptemp = rand() % 5;
	String^ enter;
	switch (*ptemp) {
	case 0:
		if (*pround == 0) {	//只有一號玩家會觸發此劇情
			Console::Write("你進到一個神祕的洞穴探險，試圖找到寶藏。(按下ENTER)");
			enter = Console::ReadLine();
			Console::Write("突然冒出了吸血鬼女王，她大聲譴責你無理的闖入行為，並露出獠牙，你嚇得雙腿發軟。(按下ENTER)");
			enter = Console::ReadLine();
			srand(time(NULL));
			*ptemp = rand() % 4;
			if (*ptemp == 2) {
				Console::Write("「喔等等，我認識你。」吸血鬼女王突然收起嚇人的表情，「你是那個到處殖民土地的怪人。」(按下ENTER)");
				enter = Console::ReadLine();
				Console::Write("吸血鬼女王表示讚賞你[邪惡]的行為，給了你2500元獎勵。你心情複雜的收下了。(按下ENTER)");
				pmoney[*pround] += 2500;
			}
			else {
				Console::Write("你轉身逃跑，慌亂中口袋的金幣掉了出來，損失100元。(按下ENTER)");
				pmoney[*pround] -= 100;
			}
			enter = Console::ReadLine();
		}
		else {
			Console::Write("他進到一個神祕的洞穴探險，試圖找到寶藏，結果甚麼都沒有。(按下ENTER)");
			enter = Console::ReadLine();
		}
		break;
	case 1:
		Console::Write("你養的龍掙脫鎖鏈，大肆破壞你的殖民地，損失慘重，花費1000元重建。(按下ENTER)");
		pmoney[*pround] -= 1000;
		enter = Console::ReadLine();
		break;
	case 2:
		Console::Write("我一見你骨骼精奇，就是練武的奇才，這兩本逃稅密籍拿去吧。(可以少繳兩次稅)(按下ENTER)");
		pnoTax[*pround] += 2;
		enter = Console::ReadLine();
		break;
	case 3:
		Console::Write("你在廢棄的礦坑裡找到一箱金幣，發財啦發財啦!!喔，等等，裡面只有50元...(按下ENTER)");
		pmoney[*pround] += 50;
		enter = Console::ReadLine();
		break;
	case 4:
		Console::Write("一隻玻璃獸躲在你的靴子裡，穿鞋時差點把他踩扁了，你抖了抖靴子，玻璃獸連同他身上的450元一起掉下來。(按下ENTER)");
		pmoney[*pround] += 450;
		enter = Console::ReadLine();
		break;
	default:
		Console::Write("Error.");
	}
	delete ptemp;
	return;
}

//電腦自動進行遊戲
void autoGame(int^ pdice, int^ preturn, array<String^>^ plocations, array<int>^ phouses, array<int>^ plocaMon, array<int>^ alive,
	array<int>^ owner, array<int>^ pposition, int^ people, int^ pround, array<int>^ pmoney, array<int>^ pnoTax, array<String^>^ playerName, String^ showStore)
{
	srand(time(NULL));
	*pdice = (rand() % 11) + 2;
	Console::Write("登登愣~擲出了{0}點。", *pdice);
	showStore = showStore + "玩家" + playerName[*pround] + "擲出" + *pdice + "點。";
	pposition[*pround] += *pdice;
	if (pposition[*pround] >= 30) {
		pposition[*pround] -= 30;
		Console::Write("經過起點，獲得300元獎勵。");
		showStore = showStore + "經過起點，獲得300元獎勵。";
		pmoney[*pround] += 300;
	}
	Console::Write("前往[ {0} ]方塊。\n", plocations[pposition[*pround]]);
	showStore = showStore + "前往[" + plocations[pposition[*pround]] + "]方塊。\n";
	//到達機會方塊
	if (pposition[*pround] == 6) {
		Console::Write("抽取一張機會牌...");
		chance(pmoney, pnoTax, pround);
	}
	//到達命運方塊
	else if (pposition[*pround] == 17) {
		Console::Write("抽取一張命運牌...");
		community(pmoney, pnoTax, pround);
	}
	//到達抽稅方塊
	else if (pposition[*pround] == 10 || pposition[*pround] == 25) {
		Console::Write("{0}站上了收稅方塊，要上繳200塊給系統。", playerName[*pround]);
		Console::Write("  (按下ENTER)");
		String^ inputString = Console::ReadLine();
		if (pnoTax[*pround] > 0) {
			Console::Write("但他使用了逃稅密籍!");
			showStore = showStore + "收稅時間，使用逃稅密籍。\n";
			pnoTax[*pround]--;
			Console::Write("  (按下ENTER)");
			inputString = Console::ReadLine();
		}
		else {
			pmoney[*pround] -= 200;
			showStore = showStore + "收稅時間，上繳200塊。\n";
		}
	}
	else if (pposition[*pround] == 0) {
		Console::Write("他伸伸懶腰，準備下次出發。");
		Console::Write("  (按下ENTER)");
		String^ inputString = Console::ReadLine();
	}
	//房屋方塊
	else {
		//到達可購買的方塊
		if (owner[pposition[*pround]] == (*pround) + 1 || owner[pposition[*pround]] == 0) {
			//土地到達五級房子
			if (phouses[pposition[*pround]] >= 5) {
				plocaMon[pposition[*pround]] = (int)plocaMon[pposition[*pround]] / 2;
				Console::Write("土地到達五級房子，收取租金，獲得{0}元。)", (int)plocaMon[pposition[*pround]] * 1.5);
				showStore = showStore + "收取租金，獲得" + (int)plocaMon[pposition[*pround]] * 1.5 + "元。\n";
				pmoney[*pround] += (int)plocaMon[pposition[*pround]] * 1.5;
				Console::Write("  (按下ENTER)");
				String^ inputString = Console::ReadLine();
			}
			//買房子
			else {
				if (phouses[pposition[*pround]] == 0)
					Console::Write("玩家{0}有現金{1}元，購買此地房子需花費{2}元。", playerName[*pround], pmoney[*pround], plocaMon[pposition[*pround]]);
				else {
					Console::Write("在此地已經有{0}級房子。收取租金，獲得{1}元。", phouses[pposition[*pround]], (int)plocaMon[pposition[*pround]] / 2 * 1.5);
					
					pmoney[*pround] += (int)plocaMon[pposition[*pround]] / 2 * 1.5;
					Console::Write("玩家{0}有現金{1}元，升級房子需要花費{2}元。", playerName[*pround], pmoney[*pround], plocaMon[pposition[*pround]]);
				}
				if (pmoney[*pround] > plocaMon[pposition[*pround]]+100) {
					pmoney[*pround] -= plocaMon[pposition[*pround]];
					phouses[pposition[*pround]] += 1;
					plocaMon[pposition[*pround]] *= 2;
					Console::Write("他選擇升級[ {0} ]的房子。 此地點是 {1} 級房屋。", plocations[pposition[*pround]], phouses[pposition[*pround]]);
					showStore = showStore + "升級了" + plocations[pposition[*pround]] + "的房子。 此地點是" + phouses[pposition[*pround]] + "級房屋。\n";
					owner[pposition[*pround]] = (*pround) + 1;
					Console::Write("  (按下ENTER)");
					String^ inputString = Console::ReadLine();
				}
				else {
					Console::Write("他拒絕購買房子，遊戲繼續。");
					showStore = showStore + "拒絕購買房子。\n";
					Console::Write("  (按下ENTER)");
					String^ inputString = Console::ReadLine();
				}
			}
		}
		//踩上別人家的土地
		else if (owner[pposition[*pround]] != (*pround) + 1 && owner[pposition[*pround]] > 0) {
			if (alive[owner[pposition[*pround]] - 1] == 0) {
				Console::Write("站上了{0}號玩家的土地，需要付{1}元過路費。", owner[pposition[*pround]], (int)plocaMon[pposition[*pround]] * 0.8);
				showStore = showStore + "站上了" + owner[pposition[*pround]] + "號玩家的土地，需要付他" + (int)plocaMon[pposition[*pround]] * 0.8 + "元過路費。\n";
				pmoney[*pround] -= (int)plocaMon[pposition[*pround]] * 0.8;
				pmoney[owner[pposition[*pround]] - 1] += (int)plocaMon[pposition[*pround]] * 0.8;
				Console::Write("  (按下ENTER)");
				String^ inputString = Console::ReadLine();
			}
			else {
				Console::Write("擁有這塊地的玩家已經死亡了，為了通過充滿怪物的荒地，他付了{0}元過路費。", (int)plocaMon[pposition[*pround]] * 0.4);
				showStore = showStore + "繳交" + (int)plocaMon[pposition[*pround]] * 0.4 + "元過路費才可以平安通過";
				pmoney[*pround] -= ((int)plocaMon[pposition[*pround]] * 0.4);
				Console::Write(" (按下ENTER)");
				String^ inputString = Console::ReadLine();
			}
		}
	}

	//破產
	if (pmoney[*pround] <= 0) {
		Console::Write("\n{0}破產了!!!(按下ENTER)\n", playerName[*pround]);
		showStore = showStore + "玩家" + playerName[*pround] + "破產了。\n";
		String^ inputString = Console::ReadLine();
		alive[*pround] = 1;
		if (*people == 2 || (alive[2] == 1 && alive[1] == 1 && *people == 3) || (alive[3] == 1 && alive[2] == 1 && alive[1] == 1)) {
			Console::Write("恭喜你贏得勝利!\n要重新開始遊戲嗎?(按r重新開始):");
			do {
				String^ YesNo = Console::ReadLine();
				if (String::Compare(YesNo, "r") == 0) {
					*preturn = 1;
					return;
				}
				else
					Console::Write("輸入錯誤，請重新輸入:");
			} while (1);
		}
	}
	//為了show存檔
	StreamWriter^ sw = gcnew StreamWriter("ShowEvent.txt", true);
	sw->WriteLine(showStore);
	sw->Close();
	showStore = nullptr;
	return;
}

//遊戲主要架構，可讓玩家輸入指令
void gameLoop(int^ pdice, int^ preturn, array<String^>^ plocations, array<int>^ phouses, array<int>^ plocaMon, array<int>^ alive,
	array<int>^ owner, array<int>^ pposition, int^ people, int^ pround, array<int>^ pmoney, array<int>^ pnoTax, array<String^>^ playerName, String^ showStore)
{
	if (*rollDice(pdice, preturn, playerName, people, pmoney, pnoTax, owner, pposition, phouses, plocaMon, alive, plocations) == 1)
		return;
	showStore = showStore + "玩家" + playerName[*pround] + "擲出" + *pdice + "點。";
	pposition[*pround] += *pdice;
	if (pposition[*pround] >= 30) {
		pposition[*pround] -= 30;
		Console::Write("經過起點，很高興你能活著回來，送你300元獎勵。\n");
		showStore = showStore + "經過起點，獲得300元獎勵。";
		pmoney[*pround] += 300;
	}
	Console::Write("前往[ {0} ]方塊。(按下ENTER)", plocations[pposition[*pround]]);
	showStore = showStore + "前往[" + plocations[pposition[*pround]] + "]方塊。\n";
	String^ enter = Console::ReadLine();
	//到達機會方塊
	if (pposition[*pround] == 6) {
		Console::Write("危機就是轉機! 親愛的玩家，抽取一張機會牌...(按下ENTER)");
		enter = Console::ReadLine();
		chance(pmoney, pnoTax, pround);
	}
	//到達命運方塊
	else if (pposition[*pround] == 17) {
		Console::Write("你到達了命運女神的殿堂，她將賜予你一張命運牌...(按下ENTER)");
		enter = Console::ReadLine();
		community(pmoney, pnoTax, pround);
	}
	//到達抽稅方塊
	else if (pposition[*pround] == 10 || pposition[*pround] == 25) {
		Console::Write("真倒楣，是收稅時間!!! 請上繳200塊給系統。(按下ENTER)");
		enter = Console::ReadLine();
		if (pnoTax[*pround] > 0) {
			Console::Write("使用逃稅密籍!!!我就是死不繳稅三十六式!\n");
			showStore = showStore + "收稅時間，使用逃稅密籍。\n";
			pnoTax[*pround]--;
		}
		else {
			pmoney[*pround] -= 200;
			showStore = showStore + "收稅時間，上繳200塊。\n";
		}
	}
	//到達起點
	else if (pposition[*pround] == 0) {
		Console::Write("歡迎回來!(按下ENTER)");
		enter = Console::ReadLine();
	}
	//房屋方塊
	else {
		//到達可購買的方塊
		if (owner[pposition[*pround]] == (*pround) + 1 || owner[pposition[*pround]] == 0) {
			//土地到達五級房子
			if (phouses[pposition[*pround]] >= 5) {
				plocaMon[pposition[*pround]] = (int)plocaMon[pposition[*pround]] / 2;
				Console::Write("此地點已是五級房子，到達土地上限，無法再蓋房子。收取租金，獲得{0}元。(按下ENTER) )", (int)plocaMon[pposition[*pround]] * 1.5);
				showStore = showStore + "收取租金，獲得" + (int)plocaMon[pposition[*pround]] * 1.5 + "元。\n";
				pmoney[*pround] += (int)plocaMon[pposition[*pround]] * 1.5;
				enter = Console::ReadLine();
			}
			//買房子
			else {
				if (phouses[pposition[*pround]] == 0)
					Console::Write("玩家{0}有現金{1}元，請問要購買房子嗎? 此地房子要{2}元。(y/n)", playerName[*pround], pmoney[*pround], plocaMon[pposition[*pround]]);
				else {
					Console::Write("你在此地已經有{0}級房子。收取租金，獲得{1}元。", phouses[pposition[*pround]], (int)plocaMon[pposition[*pround]] / 2 * 1.5);
					pmoney[*pround] += (int)plocaMon[pposition[*pround]] / 2 * 1.5;
					Console::Write("玩家{0}有現金{1}元，請問要升級房子嗎?需要花費{2}元 (y/n): ", playerName[*pround], pmoney[*pround], plocaMon[pposition[*pround]]);
				}
				do {
					String^ YesNo = Console::ReadLine();
					if (String::Compare(YesNo, "y") == 0) {
						pmoney[*pround] -= plocaMon[pposition[*pround]];
						phouses[pposition[*pround]] += 1;
						plocaMon[pposition[*pround]] *= 2;
						Console::Write("升級了[ {0} ]的房子。 此地點是 {1} 級房屋。(按下ENTER)", plocations[pposition[*pround]], phouses[pposition[*pround]]);
						showStore = showStore + "升級了" + plocations[pposition[*pround]] + "的房子。 此地點是" + phouses[pposition[*pround]] + "級房屋。\n";
						owner[pposition[*pround]] = (*pround) + 1;
						enter = Console::ReadLine();
						break;
					}
					else if (String::Compare(YesNo, "n") == 0) {
						Console::Write("拒絕購買房子，遊戲繼續。(按下ENTER)");
						showStore = showStore + "拒絕購買房子。\n"; 
						enter = Console::ReadLine();
						break;
					}
					else
						Console::Write("輸入錯誤，請重新輸入(y/n):");
				} while (true);
			}
		}
		//踩上別人家的土地
		else if(owner[pposition[*pround]] != (*pround) + 1 && owner[pposition[*pround]] > 0){
			if (alive[owner[pposition[*pround]] - 1] == 0) {
				Console::Write("你站上了{0}號玩家的土地，需要付他{1}元過路費。(按下ENTER)",owner[pposition[*pround]] , (int)plocaMon[pposition[*pround]]*0.8);
				showStore = showStore + "站上了" + owner[pposition[*pround]] + "號玩家的土地，需要付他" + (int)plocaMon[pposition[*pround]]*0.8 + "元過路費。\n";
				pmoney[*pround] -= (int)plocaMon[pposition[*pround]] * 0.8;
				pmoney[owner[pposition[*pround]]-1] += (int)plocaMon[pposition[*pround]] * 0.8;
				enter = Console::ReadLine();
			}
			else {
				Console::Write("擁有這塊地的玩家已經死亡了，這邊是一片充滿怪物的荒地，繳交{0}元過路費才可以平安通過。(按下ENTER)", (int)plocaMon[pposition[*pround]] * 0.4);
				showStore = showStore + "繳交" + (int)plocaMon[pposition[*pround]] * 0.4 + "元過路費才可以平安通過";
				pmoney[*pround] -= (int)plocaMon[pposition[*pround]] * 0.4;
				enter = Console::ReadLine();
			}
		}
	}
		
	//破產
	if (pmoney[*pround] <= 0) {
		Console::Write("\n你破產了!!!!!!!!!送你一把人生重來槍，要重新開始遊戲嗎?(按r重新開始)");
		do {
			String^ YesNo = Console::ReadLine();
			if (String::Compare(YesNo, "r") == 0) {
				*preturn = 1;
				break;
			}
			else
				Console::Write("輸入錯誤，請重新輸入:");
		} while (1);
	}
	//為了show存檔
	StreamWriter^ sw = gcnew StreamWriter("ShowEvent.txt", true);
	sw->WriteLine(showStore);
	sw->Close();
	showStore = nullptr;
	return;
}

int main(array<System::String ^> ^args)
{
	array< String^ >^ plocations;	//各地名稱
	array<int>^ plocaMon = gcnew array<int>(30);	//各地價錢
	array<int>^ phouses = gcnew array<int>(30);		//各地房子數量
	array<int>^ owner = gcnew array<int>(30);		//各地房子擁有者，0代表無人擁有，1代表1號玩家
	array<int>^ pposition = gcnew array<int>(4);	//玩家們各自所在位置
	array<String^>^ playerName = gcnew array<String^>(4);	//玩家名稱
	array<int>^ pmoney= gcnew array<int>(4);		//玩家們金錢數
	array<int>^ pnoTax = gcnew array<int>(4);		//各玩家擁有的逃稅卡
	array<int>^ alive = gcnew array<int>(4);		//玩家們是否活著，1代表死亡
	String^ showStore;			//儲存text檔給show用
	int^ pdice = gcnew int;		//骰子點數
	int^ preturn = gcnew int;	//重新開始
	int^ pround = gcnew int;	//目前輪到玩家
	int^ people = gcnew int;	//遊玩人數

	if (File::Exists("ShowEvent.txt"))
		System::IO::File::Delete("ShowEvent.txt");

	plocations = gcnew array<String^>(30){ "Start ->", "Hobbiton", "EchoIsles", "Citadel", "Midgar", "Gotham", "CHANCE", "Hideout",
	"SouthPark", "Waterdeep", "-TAX-", "Silent Hill", "Racoon City", "Los Santos", "District X", "Snowdin", "Grillby's", "COMMUNITY", "Skyrim",
	"Helheim", "Outland", "Ravenholm", "Asgard", "Detroit", "Alfheim", "-TAX-", "Highway 17", "Gravity Falls", "Black Beach", "Sea of light"};
	showStore = "遊戲開始\n";

	//遊戲迴圈
	while (1) {
		initialLocation(plocaMon, phouses, pnoTax, pround, alive, owner, pposition);
		startNewGame();
		//輸入遊戲人數，有做非整數防呆
		do {
			Console::Write("請輸入遊玩人數(2到4人): ");
			String^ inputString = Console::ReadLine();
			if (String::Compare(inputString, "2") == 0 || String::Compare(inputString, "3") == 0 || String::Compare(inputString, "4") == 0) {
				*people = Convert::ToInt32(inputString);
				Console::Write("遊玩人數為{0}人，你被指派為玩家一號，其餘為電腦玩家。 ", *people);
				showStore = showStore + "遊玩人數為" + *people + "人，你被指派為玩家一號，其餘為電腦玩家。";
				break;
			}
			else
				Console::Write("輸入錯誤。");
		} while (true);

		//輸入玩家名字和起始金額
		Console::Write("親愛的冒險者，你的英文名字是: ");
		playerName[0] = Console::ReadLine();
		do {
			Console::Write("請輸入起始金額(建議1000元，不要輸入負數或是超過一百萬): ");
			pmoney[0] = Int32::Parse(Console::ReadLine());
		} while (pmoney[0] <= 0 || pmoney[0] > 1000000);

		//設定電腦玩家
		playerName[1] = "B-Rabbit";
		int^ tempMon = gcnew int;
		*tempMon = pmoney[0];
		pmoney[1] = *tempMon;
		Console::Write("\n  玩家一號名字為{0}，金額為{1}。\n", playerName[0], pmoney[0]);
		Console::Write("  電腦玩家二號名字為B-Rabbit，金額為{0}。\n", pmoney[1]);
		showStore = showStore + "玩家一號名字為" + playerName[0] + "，金額為" + pmoney[0] + "。 ";
		showStore = showStore + "電腦玩家二號名字為B-Rabbit，金額為" + pmoney[1] + "。 ";

		if (*people > 2) {
			playerName[2] = "ConnorRK800";
			tempMon = gcnew int;
			*tempMon = pmoney[1];
			pmoney[2] = *tempMon;
			Console::Write("  電腦玩家三號名字為ConnorRK800，金額為{0}。\n", pmoney[2]);
			showStore = showStore + "電腦玩家三號名字為ConnorRK800，金額為" + pmoney[2] + "。 ";
		}
		if (*people > 3) {
			playerName[3] = "theodd1sout";
			tempMon = gcnew int;
			*tempMon = pmoney[1];
			pmoney[3] = *tempMon;
			Console::Write("  電腦玩家四號名字為theodd1sout，金額為{0}。\n", pmoney[3]);
			showStore = showStore + "電腦玩家四號名字為theodd1sout，金額為" + pmoney[2] + "。 ";
		}
		//為了show存檔
		StreamWriter^ sw = gcnew StreamWriter("ShowEvent.txt",true);
		sw->WriteLine(showStore);
		sw->Close();
		showStore = nullptr;

		do {
			if (alive[*pround] != 0) {
				(*pround)++;
				if (*pround >= (*people))
					*pround = 0;
				continue;
			}
			printMap(plocations, phouses, plocaMon, owner, pposition, people, alive);
			Console::Write("現在是玩家{0}的回合。擁有{1}元。\n", playerName[*pround], pmoney[*pround]);
			if (*pround == 0)
				gameLoop(pdice, preturn, plocations, phouses, plocaMon, alive, owner, pposition, people, pround, pmoney, pnoTax, playerName, showStore);
			else{
				autoGame(pdice, preturn, plocations, phouses, plocaMon, alive, owner, pposition, people, pround, pmoney, pnoTax, playerName, showStore);
			}
			(*pround)++;
			if (*pround >= (*people))
				*pround = 0;
		} while (*preturn == 0);
		Console::WriteLine("\n\n");
	}
    return 0;
}
