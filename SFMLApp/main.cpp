/*
	���� ����������� ��������� ���� � ������������� �� �� ���������� ��� ����������� �������������
	���� ��������� ������� ����, � ����� ������
*/

#include "IMainMenu.h"
#include "FLevel.h"


int main()
{

	//TODO ����������� ������ �������� �� ����� �������
	sf::Uint32 ScrWidth, ScrHeight;
	sf::Uint32 FrameRate;
	ScrWidth = 800;
	ScrHeight = 600;
	FrameRate = 30;

	// ������������ �������� ������������ (����, � ������� ���������� ����)
	// ��������� ����������� ������ � ������� ������
	sf::RenderWindow window(sf::VideoMode(ScrWidth, ScrHeight), "SFML works!");
	window.setFramerateLimit(FrameRate);

	// ������������� ������ ����.
	IMainMenu MainMenu;
	FLevel Level;

	bool bGameEnd = false;
	int res = EEndStatus::Menu;
	// ������������ ���� ����, � ��� ���������� ����� �������� ������ ����: ����, ������� � ��. � ���� ���� �� ���������
	while (!bGameEnd)
	{
		switch (res) {
		// ��������������
		case EEndStatus::Menu:
			res = MainMenu.BeginMenu(window, ScrWidth, ScrHeight, FrameRate);
			break;

		case EEndStatus::StartGame:
			// ToDo ����������� ������� ������ ������
			res = Level.StartLevel(window, 0);
			break;

		// �����������
		case EEndStatus::Exit:
			bGameEnd = true;
			window.close();
			break;

		// ������ ���� 

		case EEndStatus::GameError:
			printf("Game was failed with erroe: %d", res);
			window.close();
			bGameEnd = true;
			system("pause");
			break;

		case EEndStatus::FileLoadFaled:
			printf("File load failed");
			window.close();
			bGameEnd = true;
			system("pause");
			break;

		default:
			printf("Game was crashed");
			window.close();
			bGameEnd = true;
			system("pause");
			break;
		}
		window.clear();
		window.display();
	}
	return 0;
}