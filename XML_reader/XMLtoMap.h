#pragma once

#include <string>
#include <fstream>
#include <algorithm>

struct FVector2i {int x;	int y;};

struct FLayer
{
	std::string name;
	int** arr = new int*;
};

struct FLevelStruct
{
	// ���������� ������ �� ������
	FVector2i LvlTiles;		

	// ������ � �������� ����� ������
	FVector2i LvlSizeTile;

	// ���������� ����� �� �����
	int NumbLayer;

	// ��������� ������ ������� ����
	FLayer* Layers = new FLayer;

	// ��������� ������� ������
	float StartPos;
};


class FParserXML
{
private:
	std::string LvlName;
	FLevelStruct LevelStruct;
	
public:
	FParserXML(std::string LvlName);

	template<class T>
	T ValueByTag(const std::string& tag);

	// ��������� ���������� ������ �� ������
	FVector2i getLvlTiles();

	// ���������� ������ ����� ������
	FVector2i getSizeTile();

	// ���������� ��������� ���� �� id
	const FLayer& getLayer(int idLayer);

	// ��������� ������ ����� �� �������� � ��������� ����
	const int getLayerElement(int idLayer, int i, int j);
};


