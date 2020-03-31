﻿#define _CRT_SECURE_NO_WARNINGS // это исключительно для того, чтобы все нормально компилилось в вижуалке
#include <cstdio>

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <unordered_map>

#define START "[" //Просто пишешь где-то в коде START, и на этапе компиляции оно будет заменено на “[“
#define END "]"

using std::unordered_map;
using std::string;

struct Link {
	unsigned long long Count;
	unordered_map<unsigned long long, string> Numbers;
	unordered_map<string, unsigned long> Edges; 
};

struct MarcovChain {
	unordered_map<string, Link> Chain;
};

class TekstHandel { //дескриптор текста
	bool IsEndSymbol(char c) {
		if (c == ('.' || '?' || '!')) return true;
		else return false;
	}
	char ToLowerCase(char c) {
		return (char)tolower(c);
	}
	bool Delimeter(char c) {
		if (c == ' ' || ',') return true;
		else return false;
	}
	void ParseSentence(MarcovChain& MC, std::vector<string> s) {
		string word = "", nextword = "";
		int k = 0;
		for (int count = 0; count < s.size(); ++count) {
			if (k == 2) {
				MarcovChain h;
				Link i;
				if (h.Chain.count(word) == 0) {
					i.Edges.insert(std::pair <string, unsigned long>(nextword, 1));
					i.Numbers.insert(std::pair<unsigned long long, string>(1, nextword));
					i.Count = 1;
					h.Chain.insert(std::pair <string, Link>(word, i));
				}
				else {
					auto key = h.Chain.find(word);
					if (key->second.Edges.count(nextword) == 0) {
						key->second.Edges.insert(std::pair <string, unsigned long>(nextword, 1));
						key->second.Numbers.insert(std::pair<unsigned long long, string>
						(++key->second.Count, nextword));
					}
					else {
						auto i = key->second.Edges.find(nextword);
						++i->second;
					}
				}
				k = 0;
				word = "";
				nextword = "";
			}
			else {
				if (count % 2 == 0)word = s[count];
				else nextword = s[count];
				++k;
			}
		}
		//добавляем звенья в цепь маркова из предложения  s
		//не забываем про искусственные стартовое и конечное состояние, можно использовать задефайненные 
	}
public:
	MarcovChain	Handler(string FileName) { //строим цепь маркова, filename - Имя файла, из которого читаем текст
		MarcovChain MC;
		FILE* f = fopen(FileName.c_str(), "r");// открываем тхт
		char c;
		c = fgetc(f);
		std::vector <string> buf;
		string word;
		while (c != EOF) {//EOF - спецально задефайненый символ конца файла
			buf.push_back(START);
			c = fgetc(f);//считываем
			if (Delimeter(c)) {
				buf.push_back(word);
				word = "";
			}
			else if (IsEndSymbol(c)) {
				buf.push_back(END);
				ParseSentence(MC, buf);
				buf.clear();
			}
			else word += ToLowerCase(c);
		}
		ParseSentence(MC, buf);//Это чтобы передать последнее предложение в файле
		return MC;
	}
};

class TextGenerator {
	string sentence;
	string ToHigherCase(string s) {// здесь должна быть функция, 
		//преобразующая строчную в заглавную 
	}
	string Generator() {
		MarcovChain h;
		Link j;
		auto str = h.Chain.find(START);
		unsigned long long i = str->second.Count;
		unsigned long key = rand() % i + 1;
		auto number = j.Numbers.find(key);
		// по всей видимости это будет не совсем верно 
	}
	//тут нужно сделать метод, генерирующую предложение по построенной цепи маркова
	void funct() {
		//rand() % 3 + 1 например
	}
};