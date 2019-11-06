/*
	����� ��� ���������� � ��������� ���� ������ (��� ��� �� �����).
	����� ���������� ����� ������ ����, ��� �������� ������.
*/
#pragma once

#include <vector>
#include <string>
#include <thread>
#include "GameConst.h"
#include "XMLtoMap.h"
#include <Windows.h>


namespace world {
	struct FLayer
	{
		std::vector <std::vector<sf::Sprite>> Blocks;
	};
}

class UWorld
{
private:
	CRITICAL_SECTION m_lockHorizontal;
	CRITICAL_SECTION m_lockVertical;
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
	sf::Int32 AmountLayers = 0;
	// ������ �����
	world::FLayer* Layers = new world::FLayer[0];

public:
	// ������������� ������. ������ ���� �� ������ � ����� ��� � ������.
	void CreateWorld(sf::Uint32 LvlName);

	// ������� �������� � ����������� �� �����������  �����
	void LeftSpeedLimmiter(float& Speed, bool& Check, sf::FloatRect PawnRect);
	// ������� �������� � ����������� �� �����������  ������
	void RightSpeedLimmiter(float& Speed, bool& Check, sf::FloatRect PawnRect);
	// ������� �������� � ����������� �� ����������� ������
	void TopSpeedLimmiter(float& Speed, bool& Check, sf::FloatRect PawnRect);
	// ������� �������� � ����������� �� ����������� �����
	void DownSpeedLimmiter(float& Speed, bool& Check, sf::FloatRect PawnRect);

	// ��������� �������� �� ������������
	sf::Vector2f GetCorrectSpeed(EDirection XDirect, EDirection YDirect, sf::Vector2f Speed, sf::FloatRect PawnRect);

	// ������� ���������
	void DrawWorld(sf::RenderWindow& window, sf::Vector2f ViewCenter, sf::Vector2f ViewSize);

	// ���������� ��������� ������� ������
	sf::Vector2f GetStartPos();

	// ���� ������ � ����� ����� �������
	bool& pBlockCollision(sf::Int32 i, sf::Int32 j);	

	// ��������� ���� �� ��� ������ �����
	bool isEarth(sf::Vector2f PawnPos, sf::FloatRect PawnRect);

	// ������� �� ��������� � ����� 
	sf::Vector2i PointToTile(sf::Vector2f PointCoord);
	sf::Int32 XPointToTile(float x);
	sf::Int32 YPointToTile(float y);

	// ���������� ������ ������ � ������
	sf::Vector2i GetLvlSize();

	// ���������� ������ ������ � ��������
	sf::Vector2i GetTileSize();
};

