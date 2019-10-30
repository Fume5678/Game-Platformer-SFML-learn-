/*
	���� ����� �������� ����� �� ������ � �����.
	����� �������� ������� ��� ���������� �������� ������ � ����. 
	���� ����� ������ � ������� ����� ������ � �������, � ���������� ��������� ������ ����� ����.
	�� ���������� ������ ��� ������ � ������, ������ ���������� �������������� ������
*/
#pragma once

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
	sf::Int32 StartLevel(sf::RenderWindow& window, sf::Uint32 SelectedLvl);


	// ������� ��������� ����
	sf::Int32 DrawCicle(sf::RenderWindow& window);

	// ������������ ���������� ������� � ����������� �� bGameWon
	void GameSummar(sf::RenderWindow& window);
	
	// ������� ���������� ������ �� ������� �� ������� ������
	sf::View setView(sf::Vector2f Pos);


};

