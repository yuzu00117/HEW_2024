// character_operations.cpp
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file_operations.h"
#include "character_operations.h"
#include "character.h"
#include "Console_color.h"

//-------------------------------------------------------------
// �L�����N�^�[�쐬
int askForCharacterCreation(struct CharacterStats *character)
{
    // �V�����L�����N�^�[���쐬���邩�ǂ�����I��

    // ���[�U�[����̓���(y/n)���i�[����ϐ�
    char createNewCharacter;

    printf("�V�����L�����N�^�[���쐬���܂����H (y/n): \n");
    setConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
    printf("���ۑ����Ă���L�����N�^�[�͍폜����܂�");
    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

    // ���[�U�[����(y/n)
    rewind(stdin);
    scanf("%c", &createNewCharacter);

    if (createNewCharacter == 'y' || createNewCharacter == 'Y')
    {
        rewind(stdin);
        // �V�����L�����N�^�[���쐬
        CharacterCreate(character);
        // �t�@�C���ɕۑ�
        SaveCharacterToFile("character.dat", character);
    }
    else if (createNewCharacter == 'n' || createNewCharacter == 'N')
    {
        LoadCharacterFromFile("character.dat", character);

        // �ǂݍ��܂ꂽ�f�[�^�̕\��
        printf("�ǂݍ��܂ꂽ�L�����N�^�[�̖��O: %s\n", character->CharacterName);
        printf("�ǂݍ��܂ꂽ�L�����N�^�[��HP: %d\n", character->CharacterHP);
        printf("�ǂݍ��܂ꂽ�L�����N�^�[��ATK: %d\n", character->CharacterATK);
        printf("�ǂݍ��܂ꂽ�L�����N�^�[��DEF: %d\n", character->CharacterDEF);
    }
    else
    {
        printf("���������͂��s���ĉ������B\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

//-------------------------------------------------------------
// �o�[�R�[�h�̐��l�����ƂɃX�e�[�^�X�𐶐�
void GenerateStatusFromBarcode(struct CharacterStats *character, int barcode)
{
    // �o�[�R�[�h�ԍ������ƂɃ����_����HP��ATK�𐶐�
    srand(barcode);
    character->CharacterHP = rand() % 100 + 50;
    character->CharacterATK = rand() % 15 + 5;

    printf("�o�[�R�[�h���琶�����ꂽHP: %d\n", character->CharacterHP);
    printf("�o�[�R�[�h���琶�����ꂽATK: %d\n", character->CharacterATK);
}
//-------------------------------------------------------------

//-------------------------------------------------------------
// �L�����쐬�֐�
void CharacterCreate(struct CharacterStats *character)
{
    int barcode;

    // ���[�U�[����̃L�����N�^�[������
    printf("�L�����N�^�[������͂��Ă�������: ");

    // fgets�֐����g�p���ĕ���������
    // �������ɂ͕�������i�[����z��A�������ɂ͍ő�ǂݍ��ݕ������A��O�����ɂ͓��͌��i�ʏ�͕W�����́j���w��
    fgets(character->CharacterName, sizeof(character->CharacterName), stdin);

    // ���s�������܂܂�Ă���ꍇ�A���s�������k�������ɒu��������
    char *newline = strchr(character->CharacterName, '\n');
    if (newline != NULL)
    {
        *newline = '\0';
    }
    else
    {
        // �o�b�t�@�����ė]���ȕ������c���Ă���\�������邽�߁A�s�v�ȕ������N���A����
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    // ���[�U�[����̃o�[�R�[�h����
    printf("�o�[�R�[�h�̐��l����͂��Ă�������: ");
    scanf("%d", &barcode);

    // ���s�������N���A
    getchar();

    // �o�[�R�[�h����X�e�[�^�X�𐶐�
    GenerateStatusFromBarcode(character, barcode);

    // characterDEF���Œ�l�ő��
    // �������@DEF�������_���Ő����ł���悤�ɕύX�\��
    character->CharacterDEF = 3;
}