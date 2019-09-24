/*
	����� ���������� �� ����������� ���� � �� �������� ���������� ������� ������.
	����� ���������� ��������� ������ � �������� ����. � ����� ��������� ���� ������ ������.
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


using FText = sf::Text;
using FString = sf::String;
using FFont = sf::Font;

const sf::Color Gray(90, 105, 136);


// ����� �������� ���� ����
class IMainMenu
{
private:
	int LvlChoose;
	bool isMenuClosed;
	FString StartStr = "Start Game", SettingStr = "Settings\*", EndStr = "End Game";
	FFont MenuFont;
	sf::Uint32 ScrWidth, ScrHeight;
	sf::Uint32 FrameRate;
	FFont Font;
	FText Button;

public:

	// ������������� ���������� ����. �������� ������ ����.
	IMainMenu(sf::Uint32 ScrWidth, sf::Uint32 ScrHeight, sf::Uint32 FrameRate);

	// ������� ��������� ������ ����
	void DrawText(sf::RenderWindow& window, const FString OutText, int height);
	int DrawCicle(sf::RenderWindow& window);

};

