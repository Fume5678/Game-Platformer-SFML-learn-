/*
	����� ������, ������� ������ �������������� ����� � ��������� �������� ��� ������� �����
	��������: ������ ���� �������� ������ ���� �������� 64�64 �������, ����� �������� �������� � ������ ������� ������ ���� ������ 64.
*/
#pragma once

#include "GameConst.h"
#include <cmath>

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
	sf::Texture ATexture;
	sf::Sprite ASprite; 
	sf::FloatRect PawnRect;
	// ����� ��� ������� ����� ���
	FClock Clock;
	// �������� ��� ����� ������
	sf::Int32 delay;
	// ���������� �� ����� �� ��������
	bool bOnEarth;
	// ����� ���������
	sf::Int32 Health;
	// ����� ���������
	float Mass;
	float Gravity;
	sf::Vector2f Speed;
	EDirection XDirection;
	EDirection YDirection;
	// ������� ���� ������ ��� ��������������� ��������
	sf::Int32 CurrPoseFrame;
	// ������� ��������
	EActionList Action;

public:
	APlayerPawn();

	// ������������� ����� ������ 
	sf::Int32 CreatePawn(float x, float y);

	// ���� ����������� �����
	void DrawPawn(sf::RenderWindow &window);

	// ������� �������� ������ �� �������� ���������
	void ChangeSelfSpeed(EActionList Action);

	// ������� ����� �����
	void MoveLeft();

	// ������� ����� ������
	void MoveRight();
	
	// ������� ����� ������
	void Jump();

	// ������������ ��������. ������� �������� ������
	void MoveModificators();

	// ������� �������� ���������
	void AcceptMove();

	// ������ ������� �������. ������� ������� ���
	void setPosition(sf::Vector2f Pos);

	// ������ ������� �������. ������� ������� ���
	void setSpeed(sf::Vector2f Speed);

	// ������������� ����� �����
	void setHealth(sf::Int32 Health);

	// ���������� ��� �� �����
	bool isAlive();

	// ��������� �� ����� �� �����
	bool& pOnEarthStatus();

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

protected:
	// ����� ����� ������� � ����������� �� �����������
	void ChangePose();
};

