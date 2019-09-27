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
	float Speed;
	// ����������� ��������� �� X, 0 - �����, 1 - ������
	sf::Int8 XDirection = 1;
	// ������� ���� ������ ��� ��������������� ��������
	int CurrPose;
	

public:
	// ������������� ������� �� ������� �� ������ �� ������ ����.
	APlayerPawn();

	// ������������� ����� ������ 
	void BeginPawn(sf::RenderWindow &window, float x, float y);

	// ���� ����������� �����
	void DrawPawn(sf::RenderWindow &window);

	// ����� ����� ������� � ����������� �� �����������
	void SetPose(EActionList Action);

	// ���������� ��� �� �����
	bool isAlive();

	// ���������� ������ ������ ������� ������
	const sf::Sprite& GetSprite();

	// ���������� ������ ������ �������� ������
	const sf::Texture& GetTexture();

	// ���������� ������� ������
	const sf::Vector2f& GetPos();

	// ���������� ����� ������
	int GetHealth();

	// ���������� �������� ������
	float GetSpeed();
};

