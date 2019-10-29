/*
	����� ���������� �� ����������� ���� � �� �������� ���������� ������� ������.
	����� ���������� ��������� ������ � �������� ����. � ����� ��������� ���� ������ ������.
*/

#pragma once

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
	sf::Int32 MenuStatus;
	// ��������� �������
	sf::Int32 SelectedLvl;
	// ������� ���� ������ ��������
	sf::Int32 CurrBackSlide;
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
	sf::Int32 BeginMenu(sf::RenderWindow& window, sf::Uint32 ScrWidth, sf::Uint32 ScrHeight, sf::Uint32 FrameRate);
	
	// ������������� ������ �� ������
	void Center(FText& ObjText);

	// ������� ��������� ������ 
	sf::Int32 BtnActivate(sf::Int32 CurrBtn);

	//������� ��������� ����� ������ 
	void BtnFill(sf::Int32 CurrBtn);

	// ������ ��������� ������ ����
	sf::Int32 DrawCicle(sf::RenderWindow& window);

	// ���������� ��������� ��������� �������
	const sf::Int32 getSelectedLvl();
};