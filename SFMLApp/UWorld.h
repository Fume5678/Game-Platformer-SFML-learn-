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

namespace self {
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
	// ������� ������� ���� �����
	sf::Texture BackgrTex;
	sf::Sprite Backgr;
	// ������ ��������
	sf::Texture TileSetTex;
	// ��������� ������� ������
	sf::Vector2f StartPos;
	// ����������� �����
	int AmountLayers = 0;
	// ������ �����
	self::FLayer* Layers = new self::FLayer;
	// ������ ��������. ToDo ������ �������� ������ ���� �� ���������� 
	std::vector <std::vector <bool>> CollsMap;
	// * ���������� � ����� 

public:
	
	~UWorld();

	// ������������� ������. ������ ���� �� ������ � ����� ��� � ������.
	void CreateWorld(sf::Uint32 LvlName);

	// ������� ���������
	void DrawWorld(sf::RenderWindow& window);

	// ���������� ��������� ������� ������
	sf::Vector2f getStartPos();

	
};

