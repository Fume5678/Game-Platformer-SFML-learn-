/*
	����� ������, ������� ������ �������������� ����� � ��������� �������� ��� ������� �����
	��������: ������ ���� �������� ������ ���� �������� 64�64 �������, ����� �������� �������� � ������ ������� ������ ���� ������ 64.
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "GameConst.h"

using FClock = sf::Clock;

enum EActionList
{
	Idle_Left,
	Idle_Right,
	Jump_Left,
	Jump_Right,
	Move_Left,
	Move_Right,
	Down_Left,
	Down_Right
};

struct FMoveDeny {
	bool Top, Down, Left, Right;
};

class APlayerPawn
{
private:
	FMoveDeny MoveDeny = { false, false, false, false };
	sf::Texture ATexture;
	sf::Sprite ASprite; 
	sf::FloatRect PawnRect;
	// ����� ��� ������� ����� ���
	FClock Clock;
	// �������� ��� ����� ������
	int delay;
	// ������ ��� �� ��������
	bool bAlive;
	// ����� ���������
	int Health;
	// ����� ���������
	float Mass;
	float SpeedX, SpeedY, Gravity;
	// ����������� ��������� �� X, -1 - �����, 1 - ������
	sf::Int8 XDirection = 1;
	// ����������� ��������� �� Y, -1 - �����, 1 - ����
	sf::Int8 YDirection = -1;
	// ������� ���� ������ ��� ��������������� ��������
	int CurrPose;

public:
	APlayerPawn();

	// ������������� ����� ������ 
	int CreatePawn(float x, float y);

	// ���� ����������� �����
	void DrawPawn(sf::RenderWindow &window);

	// ����� ����� ������� � ����������� �� �����������
	void SetStance(EActionList Action);

	// 
	void ChangeSelfSpeed(EActionList Action);

	// ������� �������� ���������
	void MovePawn();

	// ������ ������� �������. ������� ������� ���
	void setPosition(sf::Vector2f Pos);

	// ���������� ��� �� �����
	const bool isAlive();

	// ���������� ������ ������ ������� ������
	const sf::Sprite& GetSprite();

	// ���������� ������ ������ �������� ������
	const sf::Texture& GetTexture();

	// ���������� ���� ������� ������
	const sf::FloatRect& GetPawnRect();

	// ���������� ������� ������
	const sf::Vector2f& GetPos();

	// ���������� �������� ������
	const sf::Vector2f GetSpeed();

	// ���������� ����� ������
	const int GetHealth();

	// ���������� ����������� ������
	const sf::Int8 GetXDirection();

	FMoveDeny& getMoveDeny();
};

