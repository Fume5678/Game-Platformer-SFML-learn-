/*
	����� ���������� �� ����������� ���� � �� �������� ���������� ������� ������.
	����� ���������� ��������� ������ � �������� ����. � ����� ��������� ���� ������ ������.
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "GameConst.h"

using FText = sf::Text;
using FString = sf::String;
using FFont = sf::Font;

const sf::Color Gray(90, 105, 136);

// ����� �������� ���� ����
class IMainMenu
{
private:
	// ��������� ��������� ������
	int MenuStatus;
	// ��������� �������
	int SelectedLvl;
	// ������� ���� ������ ��������
	int CurrBackSlide;
	bool bMenuClosed;
	// �������������� window
	sf::Uint32 ScrWidth, ScrHeight;
	sf::Uint32 FrameRate;
	// ��������� ������� ����, ����� ��������� ���������� �� ���
	sf::Vector2f LastMousePos;
	// ����� ������
	FFont Font;
	// ������� ������ � ���� ������
	FText StartBtn, SettingBtn, EndBtn;
	// �������� � ������� �������� � ������� ���� ����
	sf::Texture LogoTexture, BackMenuText;
	sf::Sprite Logo, BackMenu;

public:
	IMainMenu();

	// ������� ����, ������� ����� ����, ������� �������
	int BeginMenu(sf::RenderWindow& window, sf::Uint32 ScrWidth, sf::Uint32 ScrHeight, sf::Uint32 FrameRate);
	
	// ������������� ������ �� ������
	void Center(FText& ObjText);

	// ������� ��������� ������ 
	int BtnActivate(int CurrBtn);

	//������� ��������� ����� ������ 
	void BtnFill(int CurrBtn);

	// ������ ��������� ������ ����
	int DrawCicle(sf::RenderWindow& window);

	// ���������� ��������� ��������� �������
	const int getSelectedLvl();
};