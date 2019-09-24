#include "IMainMenu.h"


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
	IMainMenu MainMenu(ScrWidth, ScrHeight, FrameRate);

	bool bGameEnd = false;
	int res = 0;
	// ������������ ���� ����, � ��� ���������� ����� �������� ������ ����: ����, ������� � ��. � ���� ���� �� ���������
	while (!bGameEnd)
	{
		if (res != 0) {
			window.close();
			bGameEnd = true;
		}

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
				bGameEnd = true;
			}
		}

		window.clear(); // ToDo �� ������ ������ ����� ������ 
		res = MainMenu.DrawCicle(window);
		window.display();
	}

	return 0;
}