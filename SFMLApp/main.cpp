/*
	���� ����������� ��������� ���� � ������������� �� �� ���������� ��� ����������� �������������
	���� ��������� ������� ����, � ����� ������
*/

#include "IMainMenu.h"
#include "APlayerPawn.h"


int main()
{

	//TODO ����������� ������ �������� �� �����////////
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

	bool bGameEnd = false;
	int res = EEndStatus::Begin;
	// ������������ ���� ����, � ��� ���������� ����� �������� ������ ����: ����, ������� � ��. � ���� ���� �� ���������
	while (!bGameEnd)
	{
		switch (res) {
		case EEndStatus::Exit:
			window.close();
			bGameEnd = true;
			break;

		case EEndStatus::Begin:
			res = MainMenu.BeginMenu(window, ScrWidth, ScrHeight, FrameRate);
			break;

		case EEndStatus::StartGame:
			// ToDo ����������� ������� ������ ������
			printf("Sosi jepu");
			res = EEndStatus::Begin;
			break;

		case EEndStatus::GameError:
			printf("Game was failed with erroe: %d", res);
			window.close();
			system("pause");
			break;

		default:
			printf("Game was crashed");
			window.close();
			system("pause");
			break;
		}
		window.clear();
		window.display();
	}

	return 0;
}