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

class FLevel
{
private:
	// ������ ������ � ����
	APlayerPawn PlayerPawn;
	// ������� ������ ������
	sf::Vector2f StartPos;
	float LocalTime;
	// ����������\������ ����. �������� ������� ��� �������� �� ������.
	bool bGameEnd, bGameWon;
public:
	// ������������ ������, ���������� ����� �� ����������� ��������. ������ ������ ������ � ���� ��������
	// ToDo �������� �������� ������������� ������, �� ��� ������� ����� �������� �� �����. ���� �����������.
	int StartLevel(sf::RenderWindow& window, int ChoosenLvl);

	// ������� ��������� ����
	int DrawCicle(sf::RenderWindow& window);

	// ������������ ���������� ������� � ����������� �� bGameWon
	void GameSummar(sf::RenderWindow& window);
	// ������ ���������� ���� 

};

