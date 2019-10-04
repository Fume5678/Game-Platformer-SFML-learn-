/*
	����� ������, ������� ������ �������������� ����� � ��������� �������� ��� ������� �����
	��������: ������ ���� �������� ������ ���� �������� 64�64 �������, ����� �������� �������� � ������ ������� ������ ���� ������ 64.
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

using FClock = sf::Clock;

enum EActionList
{
	Idle_Left,
	Idle_Right,
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
	// ����� ��� ������� ����� ���
	FClock Clock;
	// �������� ��� ����� ������
	int delay;
	bool bAlive;
	int Health;
	float SpeedX, SpeedY;
	// ����������� ��������� �� X, -1 - �����, 1 - ������
	sf::Int8 XDirection = 1;
	// ����������� ��������� �� Y, -1 - �����, 1 - ����
	sf::Int8 YDirection = -1;
	// ������� ���� ������ ��� ��������������� ��������
	int CurrPose;
	

public:
	// ������������� ����� ������ 
	int CreatePawn(float x, float y);

	// ���� ����������� �����
	void DrawPawn(sf::RenderWindow &window);

	// ����� ����� ������� � ����������� �� �����������
	void SetStance(EActionList Action);

	// ���������� ��� �� �����
	bool isAlive();

	// ������� �������� ���������
	void MovePawn();

	// ���������� ������ ������ ������� ������
	const sf::Sprite& GetSprite();

	// ���������� ������ ������ �������� ������
	const sf::Texture& GetTexture();

	// ���������� ������� ������
	const sf::Vector2f& GetPos();

	// ���������� �������� ������
	const sf::Vector2f GetSpeed();

	// ���������� ����� ������
	const int GetHealth();

	// ���������� ����������� ������
	const sf::Int8 GetXDirection();
};

