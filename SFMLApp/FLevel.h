/*
	���� ����� �������� ����� �� ������ � �����.
	����� �������� ������� ��� ���������� �������� ������ � ����. 
	���� ����� ������ � ������� ����� ������ � �������, � ���������� ��������� ������ ����� ����.
	�� ���������� ������ ��� ������ � ������, ������ ���������� �������������� ������
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "APlayerPawn.h"
#include "UWorld.h"

class ULevelStarter
{
private:
	// ������ ������ � ����
	APlayerPawn PlayerPawn;
	// ������� ������ ������
	sf::Vector2f StartPos;
	// ����������\������ ����. �������� ������� ��� �������� �� ������.
	bool bGameEnd, bGameWon;
public:
	// ������������ ������, ���������� ����� �� ����������� ��������. ������ ������ ������ � ���� ��������
	// ToDo �������� �������� ������������� ������, �� ��� ������� ����� �������� �� �����. ��� ���.
	int StartLevel(sf::RenderWindow& window, int ChoosenLvl);

	// ������� ��������� ����
	void DrawLevel(sf::RenderWindow& window);

	// ������������ ���������� ������� � ����������� �� bGameWon
	void GameSummar(sf::RenderWindow& window);
	// ������ ���������� ���� 

};

