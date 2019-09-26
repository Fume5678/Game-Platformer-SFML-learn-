/*
	����� ������, ������� ������ �������������� ����� � ��������� �������� ��� ������� �����
	��������: ������ ���� �������� ������ ���� �������� 64�64 �������, ����� �������� �������� � ������ ������� ������ ���� ������ 64.
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>


enum EActionList
{
	Idle,
	Jump_Left,
	Jump_Right,
	Move_Left,
	Move_Right
};

class APlayerPawn
{
private:
	sf::Texture ATexture;
	sf::Sprite ASprite; 
	bool bAlive;
	int Health;
	float Speed;
	// ������� ������� ������ �� [0] = � � [1] = �
	float pos[2];
	// ������� ���� ������ �� [0] = Row � [1] = Line
	int CurrPose[2];

public:
	// ������������� ������� �� ������� �� ������ �� ������ ����.
	APlayerPawn(float x, float y);

	// ���� ����������� �����
	int PawnDrawCicle(sf::RenderWindow &window);

	// ����� ����� ������� � ����������� �� �����������
	void SetPose(EActionList Action);

	// ������ ������ ���� ����������
};

