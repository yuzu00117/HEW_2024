// character_operations.h

#ifndef CHARACTER_OPERATIONS_H
#define CHARACTER_OPERATIONS_H

#include "file_operations.h"

// �L�����N�^�[�쐬
int askForCharacterCreation(struct CharacterStats *character);

// �L�����쐬�֐��̐錾��ǉ�
void CharacterCreate(struct CharacterStats* character);

// �o�[�R�[�h�̐��l�����ƂɃX�e�[�^�X�𐶐�
void GenerateStatusFromBarcode(struct CharacterStats* character, int barcode);

#endif // CHARACTER_OPERATIONS_H
