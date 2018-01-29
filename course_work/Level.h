#include <string>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "tinyxml_2_6_2\tinyxml.h"
using namespace std;
using namespace sf;

#ifndef LEVEL_H
#define LEVEL_H

struct Object
{
	int GetPropertyInt(const string& name); // номер свойства объекта в нашем списке
	float GetPropertyFloat(const string& name);
	string GetPropertyString(const string& name);

	string name; // объ€вили переменную name типа string
	string type; // а здесь переменную type типа string
	Rect<float> rect; // тип Rect с нецелыми значени€ми
	map<string, string> properties; // создаЄм ассоциатиный массив. ключ - строковый тип, значение - строковый

	Sprite sprite; // объ€вили спрайт
};

struct Layer // слои
{
	int opacity; // непрозрачность сло€
	vector<Sprite> tiles; // закидываем в вектор тайлы
};

class Level // главный класс - уровень
{
public:
	bool LoadFromFile(const string& filename); // возвращает false если не получилось загрузить
	Object GetObject(const string& name);
	vector<Object> GetObjects(const string& name); // выдаем объект в наш уровень
	vector<Object> GetAllObjects(); // выдаем все объекты в наш уровень
	void Draw(RenderWindow& window); // рисуем в окно
	void Dislocate(const int& w, const int& h);
	void Dislocate_objects(const int& w, const int& h);
	Vector2i GetTileSize(); // получаем размер тайла
private:
	int width, height, tileWidth, tileHeight; // в tmx файле width height в начале,затем размер тайла
	int firstTileID; // получаем айди первого тайла
	Rect<float> drawingBounds; // размер части карты которую рисуем
	Texture tilesetImage; // текстура карты
	vector<Object> objects; // массив типа ќбъекты, который мы создали
	vector<Layer> layers;
};

#endif