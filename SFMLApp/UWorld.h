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
	// ��������� ������ � ��������� �����
	sf::Texture BackgrTex;
	sf::Sprite Backgr;
	self::FLayer* Layers = new self::FLayer;
	// * ���������� � ����� 

public:
	// ������������� ������. ������ ���� �� ������ � ����� ��� � ������.
	void CreateWorld(sf::Uint32 LvlName);

	// ������� ���������
	void DrawWorld(sf::RenderWindow& window);

	// ������� �������� ���� �� ������� �����.
	void MoveWorld();
	
	//
	sf::Vector2f getStartPos();

	
};

