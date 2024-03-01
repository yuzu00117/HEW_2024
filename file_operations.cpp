// file_operations.cpp
#define _CRT_SECURE_NO_WARNINGS

#include "file_operations.h"
#include <stdio.h>
#include <stdlib.h>

//-------------------------------------------------------------
// �t�@�C���� CharacterStats ��ۑ�����֐�
void SaveCharacterToFile(const char* filename, struct CharacterStats* character)
{
    FILE* file = fopen(filename, "wb"); // �o�C�i�����[�h�Ńt�@�C�����J��

    if (file == NULL)
    {
        perror("�t�@�C�����J���ۂɃG���[���������܂���");
        exit(EXIT_FAILURE);
    }
    // �t�@�C���� CharacterStats �̓��e����������
    fwrite(character, sizeof(struct CharacterStats), 1, file);

    // �t�@�C�������
    fclose(file);
}
//-------------------------------------------------------------

//-------------------------------------------------------------
// �t�@�C������ CharacterStats ��ǂݍ��ފ֐�
void LoadCharacterFromFile(const char* filename, struct CharacterStats* character)
{
    FILE* file = fopen(filename, "rb"); // �o�C�i�����[�h�Ńt�@�C�����J��

    if (file == NULL)
    {
        perror("�t�@�C�����J���ۂɃG���[���������܂���");
        exit(EXIT_FAILURE);
    }

    // �t�@�C������ CharacterStats �̓��e��ǂݍ���
    fread(character, sizeof(struct CharacterStats), 1, file);

    fclose(file);
}
//-------------------------------------------------------------
