#define _CRT_SECURE_NO_WARNINGS // это исключительно для того, чтобы все нормально компилилось в вижуалке
#include <cstdio>

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <unordered_map>

#define START "[" //а как этим пользоваться?
#define END "]"

using std::unordered_map;
using std::string;

struct Link {
	unsigned long long Count; //а это для чего?
	unordered_map<string, unsigned long> Edges; //слово и кол-во раз встреч в тексте из txt
};

struct MarcovChain {
	unordered_map<string, Link> Chain;// цепь на основе которой будет генерироваться текст
	//чем в данном случае является стринг?
};

class TekstHandel { //дескриптор текста
	bool IsCorrectSymbol(char c) {
		//тут должна быть функция, проверяющая, является ли символ буквой, или пробелом, или нет
		return true;
	}

	bool IsEndSymbol(char c) {
		//тут должна быть функция, проверяющая, является ли символ концом прделожени('.', '!' или '?')
		return false;
	}

	char ToLowerCase(char c) {
		//тут должна быть функция, переводящая буквы в нижний регистр
		return c;
	}
	//запятые и другие орфограафические тонкости мы не будем учитывать? 
	void ParseSentence(MarcovChain& MC, string s) {
		//добавляем звенья в цепь маркова из предложения  s 
		
		//не забываем про искусственные стартовое и конечное состояние, можно использовать задефайненные 
	}
public:
	MarcovChain	Handler(string FileName) { //строим цепь маркова, а что в аргумент? 
		MarcovChain MC;
		FILE* f = fopen(FileName.c_str(), "r");// открываем тхт
		char c;
		c = fgetc(f);//считываем первый символ с тхт?
		string buf = "";//это пустая строка?
		while (c != EOF) {//а что такое eof?

			c = fgetc(f);//считываем?
			if (IsCorrectSymbol(c)) {//если тру добавляем в баф 
				buf += ToLowerCase(c);
			}
			else if (IsEndSymbol(c)) {
				ParseSentence(MC, buf); //передаем предложение
			}
		}
		ParseSentence(MC, buf);//а это зачем?
		return MC;
	}
};

class TextGenerator {
	//тут нужно сделать метод, генерирующую предложение по построенной цепи маркова
};

