/*
	���� ����� �������� ����� �� ������ � �����.
	����� �������� ������� ��� ���������� �������� ������ � ����. 
	���� ����� ������ � ������� ����� ������ � �������, � ���������� ��������� ������ ����� ����.
	�� ���������� ������ ��� ������ � ������, ������ ���������� �������������� ������
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include "XMLtoMap.h"
#include "APlayerPawn.h"
#include "UWorld.h"
#include "GameConst.h"

class FLevel
{
private:
	sf::View Camera;
	// ������ ������ � ����
	APlayerPawn PlayerPawn;
	UWorld World;
	// ������� ������ ������
	sf::Vector2f StartPos;
	float LocalTime;
	// ����������\������ ����. �������� ������� ��� �������� �� ������.
	bool bGameEnd, bGameWon;
public:
	FLevel();

	// ������������ ������, ���������� ����� �� ����������� ��������. ������ ������ ������ � ���� ��������
	// ToDo �������� �������� ������������� ������, �� ��� ������� ����� �������� �� �����. ���� �����������.
	int StartLevel(sf::RenderWindow& window, sf::Uint32 SelectedLvl);


	// ������� ��������� ����
	int DrawCicle(sf::RenderWindow& window);

	// ������������ ���������� ������� � ����������� �� bGameWon
	void GameSummar(sf::RenderWindow& window);
	
	// ������� ���������� ������ �� ������� �� ������� ������
	sf::View setView(sf::Vector2f Pos);


};

