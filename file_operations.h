// file_operations.h

#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include "character.h"

// �L�����N�^�[�̃Z�[�u&���[�h
void SaveCharacterToFile(const char* filename, struct CharacterStats* character);
void LoadCharacterFromFile(const char* filename, struct CharacterStats* character);

#endif // FILE_OPERATION_H