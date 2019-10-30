/*
	����� ������, ������� ������ �������������� ����� � ��������� �������� ��� ������� �����
	��������: ������ ���� �������� ������ ���� �������� 64�64 �������, ����� �������� �������� � ������ ������� ������ ���� ������ 64.
*/
#pragma once

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
	Down_Right,
	Idle_Vertical // ToDo ������ ����� ���������� ������ 
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
	sf::Int32 delay;
	// ������ ��� �� ��������
	bool bAlive;
	// ����� ���������
	sf::Int32 Health;
	// ����� ���������
	float Mass;
	float Gravity;
	sf::Vector2f Speed;
	// ����������� ��������� �� X, -1 - �����, 1 - ������
	EDirection XDirection;
	// ����������� ��������� �� Y, -1 - �����, 1 - ����
	EDirection YDirection;
	// ������� ���� ������ ��� ��������������� ��������
	sf::Int32 CurrPose;

public:
	APlayerPawn();

	// ������������� ����� ������ 
	sf::Int32 CreatePawn(float x, float y);

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

	// ������ ������� �������. ������� ������� ���
	void setSpeed(sf::Vector2f Speed);

	// ���������� ��� �� �����
	bool isAlive();

	// ���������� ������ ������ ������� ������
	const sf::Sprite GetSprite();

	// ���������� ������ ������ �������� ������
	const sf::Texture GetTexture();

	// ���������� ���� ������� ������
	const sf::FloatRect GetPawnRect();

	// ���������� ������� ������
	const sf::Vector2f GetPos();

	// ���������� �������� ������
	const sf::Vector2f GetSpeed();

	// ���������� ����� ������
	const sf::Int32 GetHealth();

	// ���������� ����������� ������
	const EDirection GetXDirection();

	// ���������� ����������� ������
	const EDirection GetYDirection();
};

