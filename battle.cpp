#include "battle.h"

#include "Console_color.h"

void battle(struct CharacterStats *character)
{
    // �L�����N�^�[�̃X�e�[�^�X�͍\���̂���Q��
    
    // �G�l�~�[�̃X�e�[�^�X���`
    srand((unsigned)time(NULL));
    int enemyHP = rand() % 100 + 50;
    float enemyATK = rand() % 15 + 5;
    float enemyDEF = 3;

    // �^�[����
    int turn = 5; // �^�[�����͔C�ӂŕύX�\

    // �U���v�Z�p
    int characterDMG, enemyDMG;
    int randomDamage; // �_���[�W�̃����_�����Ɏg�p

    // 5�^�[��
    for (int i = 0; i < turn; i++)
    {
        // �_���[�W�̃����_����
        srand((unsigned)time(NULL));
        randomDamage = rand() & 3;

        // �U���͂Ɩh��͂̌v�Z
        characterDMG = (character->CharacterATK - enemyDEF) + randomDamage;
        enemyDMG = (enemyATK - character->CharacterDEF);
        
        printf("------------------\n");
        // �L�����N�^�[�̍s��
        // �L�����N�^�[����F����
        setConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY); // �ΐF
        printf("%s", character->CharacterName);
        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        printf("�̍U���F%d�̃_���[�W\n",characterDMG);
        character->CharacterHP -= enemyDMG;

        // �G�l�~�[�̍s��
        // �G�l�~�[�̖��O��F����
        setConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY); // �ԐF
        printf("Enemy");
        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        printf("�̍U���F%d�̃_���[�W\n", enemyDMG);
        enemyHP -= characterDMG;
        printf("------------------\n");

        // ��b���ɏ���
        Sleep(2000);
        // system("clear");
    }

    printf("�^�[���I�����%s��HP�F%d\n", character->CharacterName, character->CharacterHP);
    printf("�^�[���I����̓G��HP�F%d\n", enemyHP);

    if (character->CharacterHP < enemyHP)
    {
        printf("�G�̏����I\n");
    }
    else if (character->CharacterHP > enemyHP)
    {
        printf("�v���C���[�̏����I\n");
    }
}