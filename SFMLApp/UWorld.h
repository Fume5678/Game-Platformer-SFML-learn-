/*
	����� ��� ���������� � ��������� ���� ������ (��� ��� �� �����).
	����� ���������� ����� ������ ����, ��� �������� ������.
*/

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <string>
#include "GameConst.h"
#include "XMLtoMap.h"

namespace world {
	struct FLayer
	{
		std::vector <std::vector<sf::Sprite>> Blocks;
	};
}


#pragma once
class UWorld
{
private:
	// ������� �����
	sf::Vector2i LvlSize;
	// ������ ������ �����
	sf::Vector2i TileSize;
	// ������ ���� ����
	sf::Vector2i TileSetSize;
	// ����� ��������
	bool** CollisMap = new bool*;
	// ������ ������� ���� ������
	sf::Texture BackgrTex;
	sf::Sprite Backgr;
	// ������ ��������
	sf::Texture TileSetTex;
	// ��������� ������� ������
	sf::Vector2f StartPos;
	// ����������� �����
	int AmountLayers = 0;
	// ������ �����
	world::FLayer* Layers = new world::FLayer[0];
	// ������ ��������. ToDo ������ �������� ������ ���� �� ���������� 

	sf::Vector2i PointToTile(sf::Vector2f PointCoord);
public:

	// ������������� ������. ������ ���� �� ������ � ����� ��� � ������.
	void CreateWorld(sf::Uint32 LvlName);

	// ��������� �������� �� ������������
	void getCollisDirect(sf::FloatRect PawnRect, bool& bUp, bool& bDown, bool& bLeft, bool& bRight);

	// ������� ���������
	void DrawWorld(sf::RenderWindow& window);

	// ���������� ��������� ������� ������
	sf::Vector2f getStartPos();

	
};

