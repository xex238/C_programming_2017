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
	int GetPropertyInt(const string& name); // <- Номер свойства объекта в нашем списке
	float GetPropertyFloat(const string& name);
	string GetPropertyString(const string& name);

	string name; // <- Объявили переменную name типа string
	string type; // <- Объявили переменную type типа string
	Rect<float> rect; // <- Тип Rect с нецелыми значениями
	map<string, string> properties; // <- Создаём ассоциатиный массив. ключ - строковый тип, значение - строковый

	Sprite sprite; // <- Объявили спрайт
};

struct Layer // <- Слои
{
	int opacity; // <- Непрозрачность слоя
	vector<Sprite> tiles; // <- Закидываем в вектор тайлы
};

class Level // <- Главный класс - уровень
{
public:
	~Level() = default;

	void Draw(RenderWindow& window); // <- Рисуем в окно
	void Dislocate(const int& w, const int& h);
	void Dislocate_objects(const int& w, const int& h);

	bool LoadFromFile(const string& filename); // <- Возвращает false если не получилось загрузить

	Object GetObject(const string& name);

	vector<Object> GetObjects(const string& name); // <- Выдаем объект в наш уровень
	vector<Object> GetAllObjects(); // <- Выдаем все объекты в наш уровень

	Vector2i GetTileSize(); // Получаем размер тайла
private:
	int width, height, tileWidth, tileHeight; // <- В tmx файле, width, height в начале, затем размер тайла
	int firstTileID; // <- Получаем ID первого тайла
	Rect<float> drawingBounds; // <- Размер части карты которую рисуем
	Texture tilesetImage; // <- Текстура карты
	vector<Object> objects; // <- Массив типа Object, который мы создали
	vector<Layer> layers;
};

#endif
