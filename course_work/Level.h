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
	int GetPropertyInt(const string& name); // ����� �������� ������� � ����� ������
	float GetPropertyFloat(const string& name);
	string GetPropertyString(const string& name);

	string name; // �������� ���������� name ���� string
	string type; // � ����� ���������� type ���� string
	Rect<float> rect; // ��� Rect � �������� ����������
	map<string, string> properties; // ������ ������������ ������. ���� - ��������� ���, �������� - ���������

	Sprite sprite; // �������� ������
};

struct Layer // ����
{
	int opacity; // �������������� ����
	vector<Sprite> tiles; // ���������� � ������ �����
};

class Level // ������� ����� - �������
{
public:
	bool LoadFromFile(const string& filename); // ���������� false ���� �� ���������� ���������
	Object GetObject(const string& name);
	vector<Object> GetObjects(const string& name); // ������ ������ � ��� �������
	vector<Object> GetAllObjects(); // ������ ��� ������� � ��� �������
	void Draw(RenderWindow& window); // ������ � ����
	void Dislocate(const int& w, const int& h);
	void Dislocate_objects(const int& w, const int& h);
	Vector2i GetTileSize(); // �������� ������ �����
private:
	int width, height, tileWidth, tileHeight; // � tmx ����� width height � ������,����� ������ �����
	int firstTileID; // �������� ���� ������� �����
	Rect<float> drawingBounds; // ������ ����� ����� ������� ������
	Texture tilesetImage; // �������� �����
	vector<Object> objects; // ������ ���� �������, ������� �� �������
	vector<Layer> layers;
};

#endif