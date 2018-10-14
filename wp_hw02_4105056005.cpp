/********
4105056005 �G�a�x �ĤG���@�~10/24
4105056005 Yun-Ting Cheng The Second Homework 10/24
********/

// wp_hw02_4105056005.cpp: �D�n�M���ɡC

#include "stdafx.h"
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace System;
using namespace System::IO;

//�]�w�U�a�����B0�ɩФl
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
		owner[*pi] = 0;//0�N��L�H�֦������a
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

//�L�X�W�h
void startNewGame() {
	Console::Write("{0,58}","-�w��Ө�_�ۥ@�ɤj�I��-\n\n");
	Console::Write("�C������:\n    ���C���}�l���B��ĳ��1000���A�C���g�L�_�I�N��o300���C\n");
	Console::Write("    �C����ʥi����Y��l(d)�άO���s�}�l��ӹC��(r)�C�i�H�s�ɡBŪ�ɻP�R���Ҧ������ɡC\n");
	Console::Write("    ��W�g�a����ɡA�i�H�M�w�O�_�ʶR�Фl�A�άO�~��ɯũЫΡA�@���g�a�̦h�ɨ�5�ũФl�C�Y�g�a�w���Ӫ��a�\���Фl�A�h�i�����O�@�O�C�����L���a���g�a�W�A�h�|�Q�����L���O�C\n");
	Console::Write("    �����|�ΩR�B����A�t�αN�۰ʩ�P�A�ð���P�W�����O�C\n");
	Console::Write("    ����|����A���a�N���200���C�Y�֦��k�|�d�P�N�|�۰ʨϥΡC\n");
	Console::Write("    �s�ɳ��b�P�@���ɮ�Save.txt�AŪ�ɤ]�O�qSave.txtŪ���A�Y�˶ä�r���榡�|�y��Ū�ɿ��~�C�i��ܥ���s�ɬ����C\n\n");
	
	Console::Write("�C���I��:\n    �b�Y�ө_�ۥ@�ɡA����j�a�W�R���Ǫ��P�ɤO���~���A�ӧA�O�@�ӨS�S�L�D���R�����ߪ��H���C\n");
	Console::Write("    �A���ͪ��ڷQ�A�N�O�b�o���g�a�W�سy�ۤv������A���A�ä��O�ߤ@�Q�n�Ϊv�o�@�ɪ��H�C\n");
	Console::Write("    �ΧA�⤤�������A�سy�s�j���ޥ��a�A�úɤO���A���ĤH�}���C�̲פf�U���٦��������H�A�N�OĹ�a...\n\n");
	return;
}

//�L�X�j�I�Φa��
void printMap(array<String^>^ plocations, array<int>^ phouses, array<int>^ plocaMon, array<int>^ owner, array<int>^ pposition, int^ people, array<int>^ alive) {
	int^ pi = gcnew int;
	int^ pj = gcnew int;
	int^ pfront = gcnew int;
	int^ pback = gcnew int;
	*pfront = 0;
	*pback = 29;
	//��u
	for (*pi = 0; *pi < 120; (*pi)++) {
		Console::Write(L'-');
	}
	//�@9��9x5�p��l�A���k2��13x5�j��l
	for (*pj = 0; *pj < 4; (*pj)++) {
		//�L�X�Фl
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
		//�L�X�a�W
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
		//�L�X���a��m
		else if (*pj == 2) {
			*pfront = 1;
			if (pposition[0] == (*pfront) - 1)
				Console::Write("|��");
			else
				Console::Write("|  ");
			if (pposition[1] == (*pfront) - 1 && alive[1] == 0)
				Console::Write("��");
			else
				Console::Write("  ");
			if (pposition[2] == (*pfront) - 1 && *people > 2 && alive[2] == 0)
				Console::Write("��");
			else
				Console::Write("  ");
			if (pposition[3] == (*pfront) - 1 && *people > 3 && alive[3] == 0)
				Console::Write("��     ");
			else
				Console::Write("       ");
			for (*pi = 0; *pi < 9; (*pi)++) {
				if (pposition[0] == *pfront)
					Console::Write("|��");
				else
					Console::Write("|  ");
				if (pposition[1] == *pfront && alive[1] == 0)
					Console::Write("��");
				else
					Console::Write("  ");
				if (pposition[2] == *pfront && *people > 2 && alive[2] == 0)
					Console::Write("��");
				else
					Console::Write("  ");
				if (pposition[3] == *pfront && *people > 3 && alive[3] == 0)
					Console::Write("�� ");
				else
					Console::Write("   ");
				(*pfront)++;
			}
			if (pposition[0] == *pfront)
				Console::Write("|��");
			else
				Console::Write("|  ");
			if (pposition[1] == *pfront && alive[1] == 0)
				Console::Write("��");
			else
				Console::Write("  ");
			if (pposition[2] == *pfront && *people > 2 && alive[2] == 0)
				Console::Write("��");
			else
				Console::Write("  ");
			if (pposition[3] == *pfront && *people > 3 && alive[3] == 0)
				Console::Write("��     | ");
			else
				Console::Write("       | ");
			(*pfront)++;
		}
		//�S����r����
		else {
			Console::Write("|             ");
			for (*pi = 0; *pi < 9; (*pi)++)
				Console::Write("|         ");
			Console::Write("|             | ");
		}
	}
	//��u
	for (*pi = 0; *pi < 120; (*pi)++) {
		Console::Write(L'-');
	}
	//���k2��13x4�j��l�A�T��
	for (*pi = 0; *pi < 4; (*pi)++) {
		for (*pj = 0; *pj < 3; (*pj)++) {
			//�L�X�Ы�
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
			//�L�X�a�W
			else if (*pj == 1) {
				Console::Write("|{0,13}|                                             ", plocations[*pback]);
				Console::Write("                                            |{0,13}| ", plocations[*pfront]);
			}
			//�L�X���a��m
			else if (*pj == 2) {
				//�����l
				if (pposition[0] == *pback)
					Console::Write("|��");
				else
					Console::Write("|  ");
				if (pposition[1] == *pback && alive[1] == 0)
					Console::Write("��");
				else
					Console::Write("  ");
				if (pposition[2] == *pback && *people > 2 && alive[2] == 0)
					Console::Write("��");
				else
					Console::Write("  ");
				if (pposition[3] == *pback && *people > 3 && alive[3] == 0)
					Console::Write("��     |                                             ");
				else
					Console::Write("       |                                             ");
				//�k���l
				if (pposition[0] == *pfront)
					Console::Write("                                            |��");
				else
					Console::Write("                                            |  ");
				if (pposition[1] == *pfront && alive[1] == 0)
					Console::Write("��");
				else
					Console::Write("  ");
				if (pposition[2] == *pfront && *people > 2 && alive[2] == 0)
					Console::Write("��");
				else
					Console::Write("  ");
				if (pposition[3] == *pfront && *people > 3 && alive[3] == 0)
					Console::Write("��     | ");
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
			Console::Write("|             |       ��:1th player      ��:2th player      ");
			Console::Write("   ��:3th player       ��:4th player        |             | ");
		}
		else {
			Console::Write(L"--------------                                                  ");
			Console::Write(L"                                        --------------- ");
		}

	}
	//��u
	for (*pi = 0; *pi < 120; (*pi)++) {
		Console::Write(L'-');
	}
	//�@9��9x5�p��l�A���k2��13x5�j��l
	for (*pj = 0; *pj < 4; (*pj)++) {
		//�L�X�Фl
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
		//�L�X�a�W
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
		//�L�X���a��m
		else if (*pj == 3) {
			*pback = 25;
			if (pposition[0] == *pback)
				Console::Write("|��");
			else
				Console::Write("|  ");
			if (pposition[1] == *pback && alive[1] == 0)
				Console::Write("��");
			else
				Console::Write("  ");
			if (pposition[2] == *pback && *people > 2 && alive[2] == 0)
				Console::Write("��");
			else
				Console::Write("  ");
			if (pposition[3] == *pback && *people > 3 && alive[3] == 0)
				Console::Write("��     ");
			else
				Console::Write("       ");
			(*pback)--;
			for (*pi = 0; *pi < 9; (*pi)++) {
				if (pposition[0] == *pback)
					Console::Write("|��");
				else
					Console::Write("|  ");
				if (pposition[1] == *pback && alive[1] == 0)
					Console::Write("��");
				else
					Console::Write("  ");
				if (pposition[2] == *pback && *people > 2 && alive[2] == 0)
					Console::Write("��");
				else
					Console::Write("  ");
				if (pposition[3] == *pback && *people > 3 && alive[3] == 0)
					Console::Write("�� ");
				else
					Console::Write("   ");
				(*pback)--;
			}
			if (pposition[0] == *pback)
				Console::Write("|��");
			else
				Console::Write("|  ");
			if (pposition[1] == *pback && alive[1] == 0)
				Console::Write("��");
			else
				Console::Write("  ");
			if (pposition[2] == *pback && *people > 2 && alive[2] == 0)
				Console::Write("��");
			else
				Console::Write("  ");
			if (pposition[3] == *pback && *people > 3 && alive[3] == 0)
				Console::Write("��     | ");
			else
				Console::Write("       | ");
			(*pback)--;
		}
		//�S����r����
		else {
			Console::Write(L"|             ");
			for (*pi = 0; *pi < 9; (*pi)++)
				Console::Write(L"|         ");
			Console::Write(L"|             | ");
		}
	}
	//��u
	for (*pi = 0; *pi < 120; (*pi)++) {
		Console::Write(L'-');
	}
	return;
}

//�s��
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
	Console::Write("�s�ɦ��\�C(���UENTER)");
	String^ inputString = Console::ReadLine();
	return;
}

//Ū��
void loadtxt(array<String^>^ playerName, int^ people, array<int>^ pmoney, array<int>^ pnoTax, array<int>^ owner, array<int>^ pposition,
	array<int>^ phouses, array<int>^ plocaMon, array<int>^ alive) {
	try
	{
		//�����a���Ū�����ɮ�
		StreamReader^ sl = File::OpenText("Save.txt");
		String^ str;
		int^ count = gcnew int;		//�X�Ӭ���
		int^ whichFile = gcnew int;	//��ܲĴX�Ӭ���
		count = 0;
		while ((str = sl->ReadLine()) != nullptr){
			if (String::Compare(str, "Save File:") == 0)
				(*count)++;
		}
		if (*count == 0) {
			Console::Write("�L����s�ɬ����C\n");
			return;
		}
		Console::Write("�{�b��{0}�ӰO���ɡA�п�J�Ʀr��ܭnŪ�������ɡA�Ʀr�V�j�����V�s: ", *count);
		do {
			String^ inputNum = Console::ReadLine();
			*whichFile = Convert::ToInt32(inputNum);
			if (*whichFile <= 0 || *whichFile > *count)
				Console::Write("��J���~�A�п�J�d�򤺪��Ʀr:");
			else
				break;
		} while (true);
		Console::Write("��ܲ�{0}���ɮסCŪ����....\n", *whichFile);
		sl->Close();

		//���s�}��text�ɡAŪ�����
		sl = File::OpenText("Save.txt");
		count = 0;
		int^ lines = gcnew int; //�@�Ӭ������Q���r�A�@��ť�
		array<String^>^ words;	//���Υy�l
		*lines = 1;
		while ((str = sl->ReadLine()) != nullptr) {
			if (String::Compare(str, "Save File:") == 0)
				(*count)++;
			if (*count == *whichFile) {
				//Console::WriteLine("{0}", str);
				words = str->Split(':');
				switch (*lines)
				{
				case 2:		//�ĤG��O���a�W�r
					playerName[0] = words[1];
					break;
				case 3:		//�ĤT��O���a�ƶq
					*people = Convert::ToInt32(words[1]);
					break;
				case 4:		//�ĥ|��O�U���a����
					words = words[1]->Split('/');
					pmoney[0] = Convert::ToInt32(words[0]);
					pmoney[1] = Convert::ToInt32(words[1]);
					pmoney[2] = Convert::ToInt32(words[2]);
					pmoney[3] = Convert::ToInt32(words[3]);
					break;
				case 5:		//�Ĥ���O�U���a�a�I
					words = words[1]->Split('/');
					pposition[0] = Convert::ToInt32(words[0]);
					pposition[1] = Convert::ToInt32(words[1]);
					pposition[2] = Convert::ToInt32(words[2]);
					pposition[3] = Convert::ToInt32(words[3]);
					break;
				case 6:		//�Ĥ���O�U���a�S��d���ƶq
					words = words[1]->Split('/');
					pnoTax[0] = Convert::ToInt32(words[0]);
					pnoTax[1] = Convert::ToInt32(words[1]);
					pnoTax[2] = Convert::ToInt32(words[2]);
					pnoTax[3] = Convert::ToInt32(words[3]);
					break;
				case 7 :	//�ĤC��O���a�s���P�_
					words = words[1]->Split('/');
					alive[0] = Convert::ToInt32(words[0]);
					alive[1] = Convert::ToInt32(words[1]);
					alive[2] = Convert::ToInt32(words[2]);
					alive[3] = Convert::ToInt32(words[3]);
					break;
				case 8:		//�ĤK��O�a�I����
					words = words[1]->Split('/');
					for (int^ i = 0; *i < 30; (*i)++)
						plocaMon[*i] = Convert::ToInt32(words[*i]);
					break;
				case 9:		//�ĤE��O�Фl�ƶq
					words = words[1]->Split('/');
					for (int^ i = 0; *i < 30; (*i)++)
						phouses[*i] = Convert::ToInt32(words[*i]);
					break;
				case 10:	//�ĤQ��O�Фl�D�H
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
		Console::Write("Ū�����\�C(���UENTER)");
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

//�üƻ��l�A�q2��12�I�F���s�i��C���Fload�άOstore�ɮסF�L�X�Ҧ��L���ƥ�
int^ rollDice(int^ pdice, int^ preturn, array<String^>^ playerName, int^ people, array<int>^ pmoney, array<int>^ pnoTax, array<int>^ owner, array<int>^ pposition,
	array<int>^ phouses, array<int>^ plocaMon, array<int>^ alive, array< String^ >^ plocations) {
	do {
		Console::Write("��d�Y��l�A��r���s�}�l�Ashow�L�X�Ҧ��L���ƥ�Aload���J�¹C���ɡAsave�s�ɡAdelete�R���Ҧ�������: ");
		String^ inputString = Console::ReadLine();
		if (String::Compare(inputString, "d") == 0) {
			srand(time(NULL));
			*pdice = (rand() % 11) + 2;
			Console::Write("�n�n�h~�A�@�Y�X�F{0}�I�C\n", *pdice );
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
				Console::Write("�w�R���Ҧ������ɡC");
			}
			else
				Console::Write("�L����s�ɬ����C");
			Console::Write("(���UENTER)");
			String^ enter = Console::ReadLine();
		}
		else {
			Console::Write("��J���~�C\n");
		}
	} while (true);
}

//���|
void chance(array<int>^ pmoney, array<int>^ pnoTax, int^ pround) {
	int^ ptemp = gcnew int;
	srand(time(NULL));
	*ptemp = rand() % 5;
	String^ enter;
	switch (*ptemp) {
	case 0:
		Console::Write("�@�W���ˤS�g�������F�V�A�D�U�A�A���F�L250���ȶO�C(���UENTER)");
		pmoney[*pround] -= 250;
		enter = Console::ReadLine();
		break;
	case 1:
		Console::Write("�Q���i�b�~�H�Ԫ��A���˦�|�A��700���v���O�C(���UENTER)");
		pmoney[*pround] -= 700;
		enter = Console::ReadLine();
		break;
	case 2:
		Console::Write("�o��k�|�j�v���˦۫��I�A��o�@���k�|�K�y�C(�i�H��ú�@���|)(���UENTER)");
		pnoTax[*pround] += 1;
		enter = Console::ReadLine();
		break;
	case 3:
		Console::Write("�G�H��ɪ̰e�W500���A�w��ܤͦn�A�ݨӧA���F�s�B�ͩO�C(���UENTER)");
		pmoney[*pround] += 500;
		enter = Console::ReadLine();
		break;
	case 4:
		Console::Write("��¥��ܽ�A���Ӫ����F�_�C�A�ȤF400���A�}�ߦn�����I���w...(���UENTER)");
		pmoney[*pround] += 400;
		enter = Console::ReadLine();
		break;
	default:
		Console::Write("Error.");
	}
	delete ptemp;
	return;
}

//�R�B
void community(array<int>^ pmoney, array<int>^ pnoTax, int^ pround) {
	int* ptemp = new int;
	srand(time(NULL));
	*ptemp = rand() % 5;
	String^ enter;
	switch (*ptemp) {
	case 0:
		if (*pround == 0) {	//�u���@�����a�|Ĳ�o���@��
			Console::Write("�A�i��@�ӯ������}�ޱ��I�A�չϧ���_�áC(���UENTER)");
			enter = Console::ReadLine();
			Console::Write("��M�_�X�F�l�尭�k���A�o�j�n���d�A�L�z�����J�欰�A���S�X�y���A�A�~�o���L�o�n�C(���UENTER)");
			enter = Console::ReadLine();
			srand(time(NULL));
			*ptemp = rand() % 4;
			if (*ptemp == 2) {
				Console::Write("�u�ᵥ���A�ڻ{�ѧA�C�v�l�尭�k����M���_�~�H�����A�u�A�O���Ө�B�ޥ��g�a���ǤH�C�v(���UENTER)");
				enter = Console::ReadLine();
				Console::Write("�l�尭�k������g��A[���c]���欰�A���F�A2500�����y�C�A�߱����������U�F�C(���UENTER)");
				pmoney[*pround] += 2500;
			}
			else {
				Console::Write("�A�ਭ�k�]�A�W�ä��f�U���������F�X�ӡA�l��100���C(���UENTER)");
				pmoney[*pround] -= 100;
			}
			enter = Console::ReadLine();
		}
		else {
			Console::Write("�L�i��@�ӯ������}�ޱ��I�A�չϧ���_�áA���G�ƻ򳣨S���C(���UENTER)");
			enter = Console::ReadLine();
		}
		break;
	case 1:
		Console::Write("�A�i���s�ò�����A�j�v�}�a�A���ޥ��a�A�l���G���A��O1000�����ءC(���UENTER)");
		pmoney[*pround] -= 1000;
		enter = Console::ReadLine();
		break;
	case 2:
		Console::Write("�ڤ@���A���f��_�A�N�O�m�Z���_�~�A�o�⥻�k�|�K�y���h�a�C(�i�H��ú�⦸�|)(���UENTER)");
		pnoTax[*pround] += 2;
		enter = Console::ReadLine();
		break;
	case 3:
		Console::Write("�A�b�o���q�|�̧��@�c�����A�o�]�յo�]��!!��A�����A�̭��u��50��...(���UENTER)");
		pmoney[*pround] += 50;
		enter = Console::ReadLine();
		break;
	case 4:
		Console::Write("�@�������~���b�A���u�l�̡A��c�ɮt�I��L���F�A�A�ݤF�ݹu�l�A�����~�s�P�L���W��450���@�_���U�ӡC(���UENTER)");
		pmoney[*pround] += 450;
		enter = Console::ReadLine();
		break;
	default:
		Console::Write("Error.");
	}
	delete ptemp;
	return;
}

//�q���۰ʶi��C��
void autoGame(int^ pdice, int^ preturn, array<String^>^ plocations, array<int>^ phouses, array<int>^ plocaMon, array<int>^ alive,
	array<int>^ owner, array<int>^ pposition, int^ people, int^ pround, array<int>^ pmoney, array<int>^ pnoTax, array<String^>^ playerName, String^ showStore)
{
	srand(time(NULL));
	*pdice = (rand() % 11) + 2;
	Console::Write("�n�n�h~�Y�X�F{0}�I�C", *pdice);
	showStore = showStore + "���a" + playerName[*pround] + "�Y�X" + *pdice + "�I�C";
	pposition[*pround] += *pdice;
	if (pposition[*pround] >= 30) {
		pposition[*pround] -= 30;
		Console::Write("�g�L�_�I�A��o300�����y�C");
		showStore = showStore + "�g�L�_�I�A��o300�����y�C";
		pmoney[*pround] += 300;
	}
	Console::Write("�e��[ {0} ]����C\n", plocations[pposition[*pround]]);
	showStore = showStore + "�e��[" + plocations[pposition[*pround]] + "]����C\n";
	//��F���|���
	if (pposition[*pround] == 6) {
		Console::Write("����@�i���|�P...");
		chance(pmoney, pnoTax, pround);
	}
	//��F�R�B���
	else if (pposition[*pround] == 17) {
		Console::Write("����@�i�R�B�P...");
		community(pmoney, pnoTax, pround);
	}
	//��F��|���
	else if (pposition[*pround] == 10 || pposition[*pround] == 25) {
		Console::Write("{0}���W�F���|����A�n�Wú200�����t�ΡC", playerName[*pround]);
		Console::Write("  (���UENTER)");
		String^ inputString = Console::ReadLine();
		if (pnoTax[*pround] > 0) {
			Console::Write("���L�ϥΤF�k�|�K�y!");
			showStore = showStore + "���|�ɶ��A�ϥΰk�|�K�y�C\n";
			pnoTax[*pround]--;
			Console::Write("  (���UENTER)");
			inputString = Console::ReadLine();
		}
		else {
			pmoney[*pround] -= 200;
			showStore = showStore + "���|�ɶ��A�Wú200���C\n";
		}
	}
	else if (pposition[*pround] == 0) {
		Console::Write("�L�����i�y�A�ǳƤU���X�o�C");
		Console::Write("  (���UENTER)");
		String^ inputString = Console::ReadLine();
	}
	//�ЫΤ��
	else {
		//��F�i�ʶR�����
		if (owner[pposition[*pround]] == (*pround) + 1 || owner[pposition[*pround]] == 0) {
			//�g�a��F���ũФl
			if (phouses[pposition[*pround]] >= 5) {
				plocaMon[pposition[*pround]] = (int)plocaMon[pposition[*pround]] / 2;
				Console::Write("�g�a��F���ũФl�A���������A��o{0}���C)", (int)plocaMon[pposition[*pround]] * 1.5);
				showStore = showStore + "���������A��o" + (int)plocaMon[pposition[*pround]] * 1.5 + "���C\n";
				pmoney[*pround] += (int)plocaMon[pposition[*pround]] * 1.5;
				Console::Write("  (���UENTER)");
				String^ inputString = Console::ReadLine();
			}
			//�R�Фl
			else {
				if (phouses[pposition[*pround]] == 0)
					Console::Write("���a{0}���{��{1}���A�ʶR���a�Фl�ݪ�O{2}���C", playerName[*pround], pmoney[*pround], plocaMon[pposition[*pround]]);
				else {
					Console::Write("�b���a�w�g��{0}�ũФl�C���������A��o{1}���C", phouses[pposition[*pround]], (int)plocaMon[pposition[*pround]] / 2 * 1.5);
					
					pmoney[*pround] += (int)plocaMon[pposition[*pround]] / 2 * 1.5;
					Console::Write("���a{0}���{��{1}���A�ɯũФl�ݭn��O{2}���C", playerName[*pround], pmoney[*pround], plocaMon[pposition[*pround]]);
				}
				if (pmoney[*pround] > plocaMon[pposition[*pround]]+100) {
					pmoney[*pround] -= plocaMon[pposition[*pround]];
					phouses[pposition[*pround]] += 1;
					plocaMon[pposition[*pround]] *= 2;
					Console::Write("�L��ܤɯ�[ {0} ]���Фl�C ���a�I�O {1} �ũЫΡC", plocations[pposition[*pround]], phouses[pposition[*pround]]);
					showStore = showStore + "�ɯŤF" + plocations[pposition[*pround]] + "���Фl�C ���a�I�O" + phouses[pposition[*pround]] + "�ũЫΡC\n";
					owner[pposition[*pround]] = (*pround) + 1;
					Console::Write("  (���UENTER)");
					String^ inputString = Console::ReadLine();
				}
				else {
					Console::Write("�L�ڵ��ʶR�Фl�A�C���~��C");
					showStore = showStore + "�ڵ��ʶR�Фl�C\n";
					Console::Write("  (���UENTER)");
					String^ inputString = Console::ReadLine();
				}
			}
		}
		//��W�O�H�a���g�a
		else if (owner[pposition[*pround]] != (*pround) + 1 && owner[pposition[*pround]] > 0) {
			if (alive[owner[pposition[*pround]] - 1] == 0) {
				Console::Write("���W�F{0}�����a���g�a�A�ݭn�I{1}���L���O�C", owner[pposition[*pround]], (int)plocaMon[pposition[*pround]] * 0.8);
				showStore = showStore + "���W�F" + owner[pposition[*pround]] + "�����a���g�a�A�ݭn�I�L" + (int)plocaMon[pposition[*pround]] * 0.8 + "���L���O�C\n";
				pmoney[*pround] -= (int)plocaMon[pposition[*pround]] * 0.8;
				pmoney[owner[pposition[*pround]] - 1] += (int)plocaMon[pposition[*pround]] * 0.8;
				Console::Write("  (���UENTER)");
				String^ inputString = Console::ReadLine();
			}
			else {
				Console::Write("�֦��o���a�����a�w�g���`�F�A���F�q�L�R���Ǫ�����a�A�L�I�F{0}���L���O�C", (int)plocaMon[pposition[*pround]] * 0.4);
				showStore = showStore + "ú��" + (int)plocaMon[pposition[*pround]] * 0.4 + "���L���O�~�i�H���w�q�L";
				pmoney[*pround] -= ((int)plocaMon[pposition[*pround]] * 0.4);
				Console::Write(" (���UENTER)");
				String^ inputString = Console::ReadLine();
			}
		}
	}

	//�}��
	if (pmoney[*pround] <= 0) {
		Console::Write("\n{0}�}���F!!!(���UENTER)\n", playerName[*pround]);
		showStore = showStore + "���a" + playerName[*pround] + "�}���F�C\n";
		String^ inputString = Console::ReadLine();
		alive[*pround] = 1;
		if (*people == 2 || (alive[2] == 1 && alive[1] == 1 && *people == 3) || (alive[3] == 1 && alive[2] == 1 && alive[1] == 1)) {
			Console::Write("���ߧAĹ�o�ӧQ!\n�n���s�}�l�C����?(��r���s�}�l):");
			do {
				String^ YesNo = Console::ReadLine();
				if (String::Compare(YesNo, "r") == 0) {
					*preturn = 1;
					return;
				}
				else
					Console::Write("��J���~�A�Э��s��J:");
			} while (1);
		}
	}
	//���Fshow�s��
	StreamWriter^ sw = gcnew StreamWriter("ShowEvent.txt", true);
	sw->WriteLine(showStore);
	sw->Close();
	showStore = nullptr;
	return;
}

//�C���D�n�[�c�A�i�����a��J���O
void gameLoop(int^ pdice, int^ preturn, array<String^>^ plocations, array<int>^ phouses, array<int>^ plocaMon, array<int>^ alive,
	array<int>^ owner, array<int>^ pposition, int^ people, int^ pround, array<int>^ pmoney, array<int>^ pnoTax, array<String^>^ playerName, String^ showStore)
{
	if (*rollDice(pdice, preturn, playerName, people, pmoney, pnoTax, owner, pposition, phouses, plocaMon, alive, plocations) == 1)
		return;
	showStore = showStore + "���a" + playerName[*pround] + "�Y�X" + *pdice + "�I�C";
	pposition[*pround] += *pdice;
	if (pposition[*pround] >= 30) {
		pposition[*pround] -= 30;
		Console::Write("�g�L�_�I�A�ܰ����A�ଡ�ۦ^�ӡA�e�A300�����y�C\n");
		showStore = showStore + "�g�L�_�I�A��o300�����y�C";
		pmoney[*pround] += 300;
	}
	Console::Write("�e��[ {0} ]����C(���UENTER)", plocations[pposition[*pround]]);
	showStore = showStore + "�e��[" + plocations[pposition[*pround]] + "]����C\n";
	String^ enter = Console::ReadLine();
	//��F���|���
	if (pposition[*pround] == 6) {
		Console::Write("�M���N�O���! �˷R�����a�A����@�i���|�P...(���UENTER)");
		enter = Console::ReadLine();
		chance(pmoney, pnoTax, pround);
	}
	//��F�R�B���
	else if (pposition[*pround] == 17) {
		Console::Write("�A��F�F�R�B�k��������A�o�N�礩�A�@�i�R�B�P...(���UENTER)");
		enter = Console::ReadLine();
		community(pmoney, pnoTax, pround);
	}
	//��F��|���
	else if (pposition[*pround] == 10 || pposition[*pround] == 25) {
		Console::Write("�u�˷��A�O���|�ɶ�!!! �ФWú200�����t�ΡC(���UENTER)");
		enter = Console::ReadLine();
		if (pnoTax[*pround] > 0) {
			Console::Write("�ϥΰk�|�K�y!!!�ڴN�O����ú�|�T�Q����!\n");
			showStore = showStore + "���|�ɶ��A�ϥΰk�|�K�y�C\n";
			pnoTax[*pround]--;
		}
		else {
			pmoney[*pround] -= 200;
			showStore = showStore + "���|�ɶ��A�Wú200���C\n";
		}
	}
	//��F�_�I
	else if (pposition[*pround] == 0) {
		Console::Write("�w��^��!(���UENTER)");
		enter = Console::ReadLine();
	}
	//�ЫΤ��
	else {
		//��F�i�ʶR�����
		if (owner[pposition[*pround]] == (*pround) + 1 || owner[pposition[*pround]] == 0) {
			//�g�a��F���ũФl
			if (phouses[pposition[*pround]] >= 5) {
				plocaMon[pposition[*pround]] = (int)plocaMon[pposition[*pround]] / 2;
				Console::Write("���a�I�w�O���ũФl�A��F�g�a�W���A�L�k�A�\�Фl�C���������A��o{0}���C(���UENTER) )", (int)plocaMon[pposition[*pround]] * 1.5);
				showStore = showStore + "���������A��o" + (int)plocaMon[pposition[*pround]] * 1.5 + "���C\n";
				pmoney[*pround] += (int)plocaMon[pposition[*pround]] * 1.5;
				enter = Console::ReadLine();
			}
			//�R�Фl
			else {
				if (phouses[pposition[*pround]] == 0)
					Console::Write("���a{0}���{��{1}���A�аݭn�ʶR�Фl��? ���a�Фl�n{2}���C(y/n)", playerName[*pround], pmoney[*pround], plocaMon[pposition[*pround]]);
				else {
					Console::Write("�A�b���a�w�g��{0}�ũФl�C���������A��o{1}���C", phouses[pposition[*pround]], (int)plocaMon[pposition[*pround]] / 2 * 1.5);
					pmoney[*pround] += (int)plocaMon[pposition[*pround]] / 2 * 1.5;
					Console::Write("���a{0}���{��{1}���A�аݭn�ɯũФl��?�ݭn��O{2}�� (y/n): ", playerName[*pround], pmoney[*pround], plocaMon[pposition[*pround]]);
				}
				do {
					String^ YesNo = Console::ReadLine();
					if (String::Compare(YesNo, "y") == 0) {
						pmoney[*pround] -= plocaMon[pposition[*pround]];
						phouses[pposition[*pround]] += 1;
						plocaMon[pposition[*pround]] *= 2;
						Console::Write("�ɯŤF[ {0} ]���Фl�C ���a�I�O {1} �ũЫΡC(���UENTER)", plocations[pposition[*pround]], phouses[pposition[*pround]]);
						showStore = showStore + "�ɯŤF" + plocations[pposition[*pround]] + "���Фl�C ���a�I�O" + phouses[pposition[*pround]] + "�ũЫΡC\n";
						owner[pposition[*pround]] = (*pround) + 1;
						enter = Console::ReadLine();
						break;
					}
					else if (String::Compare(YesNo, "n") == 0) {
						Console::Write("�ڵ��ʶR�Фl�A�C���~��C(���UENTER)");
						showStore = showStore + "�ڵ��ʶR�Фl�C\n"; 
						enter = Console::ReadLine();
						break;
					}
					else
						Console::Write("��J���~�A�Э��s��J(y/n):");
				} while (true);
			}
		}
		//��W�O�H�a���g�a
		else if(owner[pposition[*pround]] != (*pround) + 1 && owner[pposition[*pround]] > 0){
			if (alive[owner[pposition[*pround]] - 1] == 0) {
				Console::Write("�A���W�F{0}�����a���g�a�A�ݭn�I�L{1}���L���O�C(���UENTER)",owner[pposition[*pround]] , (int)plocaMon[pposition[*pround]]*0.8);
				showStore = showStore + "���W�F" + owner[pposition[*pround]] + "�����a���g�a�A�ݭn�I�L" + (int)plocaMon[pposition[*pround]]*0.8 + "���L���O�C\n";
				pmoney[*pround] -= (int)plocaMon[pposition[*pround]] * 0.8;
				pmoney[owner[pposition[*pround]]-1] += (int)plocaMon[pposition[*pround]] * 0.8;
				enter = Console::ReadLine();
			}
			else {
				Console::Write("�֦��o���a�����a�w�g���`�F�A�o��O�@���R���Ǫ�����a�Aú��{0}���L���O�~�i�H���w�q�L�C(���UENTER)", (int)plocaMon[pposition[*pround]] * 0.4);
				showStore = showStore + "ú��" + (int)plocaMon[pposition[*pround]] * 0.4 + "���L���O�~�i�H���w�q�L";
				pmoney[*pround] -= (int)plocaMon[pposition[*pround]] * 0.4;
				enter = Console::ReadLine();
			}
		}
	}
		
	//�}��
	if (pmoney[*pround] <= 0) {
		Console::Write("\n�A�}���F!!!!!!!!!�e�A�@��H�ͭ��Ӻj�A�n���s�}�l�C����?(��r���s�}�l)");
		do {
			String^ YesNo = Console::ReadLine();
			if (String::Compare(YesNo, "r") == 0) {
				*preturn = 1;
				break;
			}
			else
				Console::Write("��J���~�A�Э��s��J:");
		} while (1);
	}
	//���Fshow�s��
	StreamWriter^ sw = gcnew StreamWriter("ShowEvent.txt", true);
	sw->WriteLine(showStore);
	sw->Close();
	showStore = nullptr;
	return;
}

int main(array<System::String ^> ^args)
{
	array< String^ >^ plocations;	//�U�a�W��
	array<int>^ plocaMon = gcnew array<int>(30);	//�U�a����
	array<int>^ phouses = gcnew array<int>(30);		//�U�a�Фl�ƶq
	array<int>^ owner = gcnew array<int>(30);		//�U�a�Фl�֦��̡A0�N��L�H�֦��A1�N��1�����a
	array<int>^ pposition = gcnew array<int>(4);	//���a�̦U�۩Ҧb��m
	array<String^>^ playerName = gcnew array<String^>(4);	//���a�W��
	array<int>^ pmoney= gcnew array<int>(4);		//���a�̪�����
	array<int>^ pnoTax = gcnew array<int>(4);		//�U���a�֦����k�|�d
	array<int>^ alive = gcnew array<int>(4);		//���a�̬O�_���ۡA1�N���`
	String^ showStore;			//�x�stext�ɵ�show��
	int^ pdice = gcnew int;		//��l�I��
	int^ preturn = gcnew int;	//���s�}�l
	int^ pround = gcnew int;	//�ثe���쪱�a
	int^ people = gcnew int;	//�C���H��

	if (File::Exists("ShowEvent.txt"))
		System::IO::File::Delete("ShowEvent.txt");

	plocations = gcnew array<String^>(30){ "Start ->", "Hobbiton", "EchoIsles", "Citadel", "Midgar", "Gotham", "CHANCE", "Hideout",
	"SouthPark", "Waterdeep", "-TAX-", "Silent Hill", "Racoon City", "Los Santos", "District X", "Snowdin", "Grillby's", "COMMUNITY", "Skyrim",
	"Helheim", "Outland", "Ravenholm", "Asgard", "Detroit", "Alfheim", "-TAX-", "Highway 17", "Gravity Falls", "Black Beach", "Sea of light"};
	showStore = "�C���}�l\n";

	//�C���j��
	while (1) {
		initialLocation(plocaMon, phouses, pnoTax, pround, alive, owner, pposition);
		startNewGame();
		//��J�C���H�ơA�����D��ƨ��b
		do {
			Console::Write("�п�J�C���H��(2��4�H): ");
			String^ inputString = Console::ReadLine();
			if (String::Compare(inputString, "2") == 0 || String::Compare(inputString, "3") == 0 || String::Compare(inputString, "4") == 0) {
				*people = Convert::ToInt32(inputString);
				Console::Write("�C���H�Ƭ�{0}�H�A�A�Q���������a�@���A��l���q�����a�C ", *people);
				showStore = showStore + "�C���H�Ƭ�" + *people + "�H�A�A�Q���������a�@���A��l���q�����a�C";
				break;
			}
			else
				Console::Write("��J���~�C");
		} while (true);

		//��J���a�W�r�M�_�l���B
		Console::Write("�˷R���_�I�̡A�A���^��W�r�O: ");
		playerName[0] = Console::ReadLine();
		do {
			Console::Write("�п�J�_�l���B(��ĳ1000���A���n��J�t�ƩάO�W�L�@�ʸU): ");
			pmoney[0] = Int32::Parse(Console::ReadLine());
		} while (pmoney[0] <= 0 || pmoney[0] > 1000000);

		//�]�w�q�����a
		playerName[1] = "B-Rabbit";
		int^ tempMon = gcnew int;
		*tempMon = pmoney[0];
		pmoney[1] = *tempMon;
		Console::Write("\n  ���a�@���W�r��{0}�A���B��{1}�C\n", playerName[0], pmoney[0]);
		Console::Write("  �q�����a�G���W�r��B-Rabbit�A���B��{0}�C\n", pmoney[1]);
		showStore = showStore + "���a�@���W�r��" + playerName[0] + "�A���B��" + pmoney[0] + "�C ";
		showStore = showStore + "�q�����a�G���W�r��B-Rabbit�A���B��" + pmoney[1] + "�C ";

		if (*people > 2) {
			playerName[2] = "ConnorRK800";
			tempMon = gcnew int;
			*tempMon = pmoney[1];
			pmoney[2] = *tempMon;
			Console::Write("  �q�����a�T���W�r��ConnorRK800�A���B��{0}�C\n", pmoney[2]);
			showStore = showStore + "�q�����a�T���W�r��ConnorRK800�A���B��" + pmoney[2] + "�C ";
		}
		if (*people > 3) {
			playerName[3] = "theodd1sout";
			tempMon = gcnew int;
			*tempMon = pmoney[1];
			pmoney[3] = *tempMon;
			Console::Write("  �q�����a�|���W�r��theodd1sout�A���B��{0}�C\n", pmoney[3]);
			showStore = showStore + "�q�����a�|���W�r��theodd1sout�A���B��" + pmoney[2] + "�C ";
		}
		//���Fshow�s��
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
			Console::Write("�{�b�O���a{0}���^�X�C�֦�{1}���C\n", playerName[*pround], pmoney[*pround]);
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
