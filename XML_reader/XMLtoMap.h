#pragma once

#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

struct FVector2i {int x;	int y;};

struct FLayer
{
	std::string name = "";
	//int** arr;
	std::vector <std::vector<int>> arr;
};

struct FLevelStruct
{
	// ���������� ������ �� ������
	FVector2i LvlTiles;		

	// ������ � �������� ����� ������
	FVector2i LvlSizeTile;

	// ���������� ����� �� �����
	int NumbLayer = 0;

	// ��������� ������� ������
	float StartPos;
};


class FParserXML
{
private:
	std::string LvlName;
	FLevelStruct LevelStruct;
	// ToDo ���������� ��� ������������ ��������� ���������, � �� ���������� LevelStruct
	FLayer* Layers = new FLayer[0];
	
public:
	FParserXML(std::string LvlName);

	~FParserXML() {};

	
	std::string ValueByTag(std::string& line, const char* tag);

	// ��������� ���������� ������ �� ������
	FVector2i getLvlTiles();

	// ���������� ������ ����� ������
	FVector2i getSizeTile();

	// ���������� ��������� ���� �� id
	const FLayer& getLayer(int idLayer);

	// ��������� ������ ����� �� �������� � ��������� ����
	const int getLayerElement(int idLayer, int i, int j);
};


