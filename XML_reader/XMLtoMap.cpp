#include "XMLtoMap.h"
#include <iostream>

FParserXML::FParserXML(std::string LvlName)
{
	std::ifstream ifsLvl;
	ifsLvl.open(LvlName + ".tmx");

	std::string line;

	if (!ifsLvl.is_open())
		printf("File opening faled");

	while (!ifsLvl.eof()) {
		// ���������� �� �����
		getline(ifsLvl, line);

		std::string::size_type FindRes = std::string::npos;

		FindRes = line.find("<map");
		if (FindRes != std::string::npos) {
			// �������� �� ���� ������� �����
			LevelStruct.LvlTiles.x = std::stoi(ValueByTag(line, "width"));
			LevelStruct.LvlTiles.y = std::stoi(ValueByTag(line, "height"));
			
			// �������� �� ���� ������ �����
			LevelStruct.LvlSizeTile.x = std::stoi(ValueByTag(line, "tilewidth"));
			LevelStruct.LvlSizeTile.y = std::stoi(ValueByTag(line, "tileheight"));
		}	

		FindRes = std::string::npos;

		FindRes = line.find("<layer");
		if (FindRes != std::string::npos) {
			// ���������� ������ ���������� ����� �� ������
			LevelStruct.NumbLayer++;
			int CurrLayer = LevelStruct.NumbLayer - 1;
			std::string LayerName = ValueByTag(line, "name");

			// ��������� ������������ ������ � �������� �� 1 ������, ��� ���������� ��������� ��� �������
			FLayer* tmp = new FLayer[LevelStruct.NumbLayer];

			for (int i = 0; i < LevelStruct.NumbLayer - 1; i++) {
				tmp[i] = LevelStruct.Layers[i];
			}

			delete[] LevelStruct.Layers;

			LevelStruct.Layers = new FLayer[LevelStruct.NumbLayer];
			LevelStruct.Layers = tmp;
			//LevelStruct.Layers[CurrLayer].name = LayerName;

			delete[] tmp;

			std::cout << LevelStruct.Layers[CurrLayer].name;

			// ���� ��� ����
			// i - �����, j - ������� 
			int i = 0, j = 0;
			for (int count = 0; count < LevelStruct.LvlTiles.y; count++) {
				// ���������� �� �����
				getline(ifsLvl, line);
				LevelStruct.Layers[CurrLayer].arr[i].push_back(stoi(ValueByTag(line, "gid")));
				i = i + ((j + 1) / LevelStruct.LvlTiles.x);
				j = (j + 1) % LevelStruct.LvlTiles.x;
			}

			for (int i = 0; i < LevelStruct.LvlTiles.y; i++) {
				for (int j = 0; j < LevelStruct.LvlTiles.x; j++) {
					printf("%d ", LevelStruct.Layers[CurrLayer].arr[i][j]);
				}
				printf("\n");
			}
		}
	}

	ifsLvl.close();	
}


std::string FParserXML::ValueByTag(std::string& line, const char* tag)
{
	// ToDo �������� ���������� ������ �������� �� ����
	std::string Value = "";
	std::string::size_type res = std::string::npos;

	res = line.find(tag);
	if (res == std::string::npos)
		return "0";

	res = line.find_first_of('\"', res);
	
	for (size_t i = res + 1; line[i] != '\"'; i++) {
		Value.push_back(line[i]);
	}

	return Value;
}

FVector2i FParserXML::getLvlTiles()
{
	return LevelStruct.LvlTiles;
}

FVector2i FParserXML::getSizeTile()
{
	return LevelStruct.LvlSizeTile;
}

const FLayer& FParserXML::getLayer(int idLayer)
{
	return LevelStruct.Layers[idLayer];
}

const int FParserXML::getLayerElement(int idLayer, int i, int j)
{
	return LevelStruct.Layers[idLayer].arr[i][j];
}