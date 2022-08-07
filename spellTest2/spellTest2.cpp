#include <windows.h>

#include <iostream>

#include <hunspell/hunspell.hxx>



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const char* aff = "ru_RU.aff";
	const char* dic = "ru_RU.dic";
	Hunspell* spellObj = new Hunspell(aff, dic);
	char** suggestWordList = NULL;

	std::cout << "Please enter one word:" << std::endl;
    std::string words;
    std::cin >> words;
	std::cout << std::endl;
	int result = spellObj->spell(words.c_str()); // проверяем корректность слова

    if (result == 0) {
        std::cout << "Spelling Error!" << std::endl;
		int count = spellObj->suggest(&suggestWordList, words.c_str()); // если слово некорректно, выводим варианты корректных слов
		for (int i = 0; i < count; ++i) {
			std::string suggestion = suggestWordList[i];
			std::cout << suggestion << std::endl;
			free(suggestWordList[i]);
		}
    }
    else {
        std::cout << "Correct Spelling!";
    }

	return result;
}
