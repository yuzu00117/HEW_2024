#define _CRT_SECURE_NO_WARNINGS
#include "title_screen.h"
#include "Console_color.h"

// �^�C�g����ʂ̕\��
void displayTitleScreen()
{
    // �^�C�g����ʂ̕\�����e���L�q
    /*
    printf("=== �^�C�g����� ===\n");
    printf("1. �V�����Q�[�����n�߂�\n");
    printf("2. �ȑO�̃Q�[���𑱂���\n");
    printf("3. �Q�[�����I������\n");
    */
   setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); // ���F
   printf("=============================================================\n");
   setConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY); // �ԐF
   	printf("######    ###    ######     ####    #####   #####    #######\n");
    setConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY); // �ԐF
	printf("##  ##   ## ##   ##   ##   ##  ##  ##   ##   ## ##    ##    \n");
    setConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY); // �ԐF
	printf("##  ##  ##   ##  ##   ##  ##       ##   ##   ##  ##   ##    \n");
    setConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY); // �ԐF
    printf("#####   #######  ######   ##       ##   ##   ##  ##   ####  \n");
    setConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY); // �ԐF
    printf("##  ##  ##   ##  #####    ##       ##   ##   ##  ##   ##    \n");
    setConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY); // �ԐF
    printf("##  ##  ##   ##  ##  ##    ##  ##  ##   ##   ## ##    ##    \n");
    setConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY); // �ԐF
    printf("######  ##   ##  ##   ##    ####    #####   #####    #######\n");

    printf("                                                            \n");

    setConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY); // �ԐF
	printf("######    ###   ######## ########   ##      #######   ##### \n");
    setConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY); // �ԐF
    printf("##  ##   ## ##     ##       ##      ##       ##      ##   ##\n");
    setConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY); // �ԐF
    printf("##  ##  ##   ##    ##       ##      ##       ##      ##   ##\n");
    setConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY); // �ԐF
    printf("#####   #######    ##       ##      ##       ####    ###### \n");
    setConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY); // �ԐF
    printf("##  ##  ##   ##    ##       ##      ##       ##      #####  \n");
    setConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY); // �ԐF
    printf("##  ##  ##   ##    ##       ##      ##       ##      ##  ## \n");
    setConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY); // �ԐF
    printf("######  ##   ##    ##       ##     #######  #######  ##   ##\n");
    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); // ���F
    printf("============================================================\n");
    
    printf("                                                            \n");

    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY); // ���F
    printf("========================Any Key Press========================\n");

    // �����F�𔒂ɖ߂�
    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); // ���F
    
    getchar();

    // cls
    system("cls");
}

// ���[�U�[���͂̏���
// ���g�p���Ȃ�
void handleUserInput()
{
    printf("���͂��Ă�������\n");

    // ���[�U�[�̓��͂��i�[����ϐ�
    int choice;
    scanf("%d", &choice);

    // ���͂��ꂽ�I�����ɉ����ď������s��
    switch (choice)
    {
    case 1:
        printf("�V�����Q�[�����n�߂܂�\n");
        break;
    case 2:
        printf("�ȑO�̃Q�[���𑱂��܂�\n");
    case 3:
        printf("�Q�[�����I�����܂�\n");
    default:
        printf("�����ȑI���ł�\n");
        break;
    }
}