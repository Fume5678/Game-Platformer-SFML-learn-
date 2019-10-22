#include "IMainMenu.h"
#include <iostream>;

IMainMenu::IMainMenu()
{
	SelectedLvl = 0;
	CurrBackSlide = 0;
	bMenuClosed = 0;

}

int IMainMenu::BeginMenu(sf::RenderWindow &window, sf::Uint32 ScrWidth, sf::Uint32 ScrHeight, sf::Uint32 FrameRate)
{
	// ���������� ������� ������ �� �������, ����� ���� �� ��������
	sf::View Camera;
	Camera.reset(sf::FloatRect(0, 0, ScrWidth, ScrHeight));
	window.setView(Camera);

	// ���������� ���������� ������
	this->ScrWidth = ScrWidth;
	this->ScrHeight = ScrHeight;
	this->FrameRate = FrameRate;

	// ������������� ��������� ������� ����
	LastMousePos.x = 0;
	LastMousePos.y = 0;

	MenuStatus = EEndStatus::Menu;

	// ������ �������� ����
	bMenuClosed = false;

	// ������ ��������, ���� � ������� ��� ��������
	if (!LogoTexture.loadFromFile(SpritePath + "Logo.png")) {
		printf("Menu:\nLogo img: ");
		return EEndStatus::FileLoadFaled;
	}

	Logo.setTexture(LogoTexture);
	sf::FloatRect LogoRect = Logo.getLocalBounds();
	Logo.setOrigin(LogoRect.left + LogoRect.width / 2,
		LogoRect.top + LogoRect.height / 2);
	Logo.setPosition(ScrWidth / 2, 130);

	// ������ ��� ����
	if (!BackMenuText.loadFromFile(SpritePath + "MenuBack.png")) {
		printf("Menu:\nBackground img: ");
		return EEndStatus::FileLoadFaled;
	}
	BackMenu.setTexture(BackMenuText);

	if (!Font.loadFromFile(FontPath + MenuFont)) {
		printf("Menu:\nFont: ");
		return EEndStatus::FileLoadFaled;
	}

	// ������ �����, �����, ������ ������ ����
	StartBtn.setString("Start Game");
	StartBtn.setFont(Font);
	StartBtn.setCharacterSize(45);

	SettingBtn.setString("Setting");
	SettingBtn.setFont(Font);
	SettingBtn.setCharacterSize(45);

	EndBtn.setString("End Game");
	EndBtn.setFont(Font);
	EndBtn.setCharacterSize(45);





	int EndStatus = EEndStatus::GameError;
	EndStatus = DrawCicle(window);

	return EndStatus;
}

void IMainMenu::Center(FText &ObjText)
{
	sf::FloatRect TextRect = ObjText.getLocalBounds();
	ObjText.setOrigin(TextRect.left + TextRect.width / 2,
						TextRect.top + TextRect.height / 2);

	ObjText.setPosition(ScrWidth / 2, ScrHeight / 2);

}

int IMainMenu::BtnActivate(int CurrBtn)
{
	// ���������� �������� � ����������� �� ������ 
	switch (CurrBtn) {
	case(0):
		SelectedLvl = 1;
		bMenuClosed = true;
		return EEndStatus::StartGame; 
		break;
	case(1):
		printf("Nothing");
		return EEndStatus::Menu;
		break;
	case(2):
		bMenuClosed = true;
		return EEndStatus::Exit;
		break;
	default:
		return EEndStatus::Menu;
	}
}

void IMainMenu::BtnFill(int CurrBtn)
{
	// ������ ����� ��������� ������
	StartBtn.setFillColor(sf::Color::Color(255, 255, 255));
	SettingBtn.setFillColor(sf::Color::Color(255, 255, 255));
	EndBtn.setFillColor(sf::Color::Color(255, 255, 255));

	// ������� ������� ������
	switch (CurrBtn) {
	case(0):
		StartBtn.setFillColor(sf::Color::Color(0, 255, 255));
		break;
	case(1):
		SettingBtn.setFillColor(sf::Color::Color(0, 255, 255));
		break;
	case(2):
		EndBtn.setFillColor(sf::Color::Color(0, 255, 255));
		break;
	}
}

int IMainMenu::DrawCicle(sf::RenderWindow& window)
{
	// ������� ��������� ����� ����
	int CurrBtn = -1;


	// ��������� ������ ������
	sf::FloatRect StartBtnRect = StartBtn.getLocalBounds();
	sf::FloatRect SettingBtnRect = SettingBtn.getLocalBounds();
	sf::FloatRect EndBtnRect = EndBtn.getLocalBounds();

	// ������������� ������ �� �������� ������
	Center(StartBtn);
	StartBtn.setPosition(ScrWidth / 2, 260);
	Center(SettingBtn);
	SettingBtn.setPosition(ScrWidth / 2, 340);
	Center(EndBtn);
	EndBtn.setPosition(ScrWidth / 2, 420);

	// ����� ����� ��������� ��� ������ ����� ���, ������������� ������ ��������.  
	while (!bMenuClosed) {
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				bMenuClosed = true;
				return EEndStatus::Exit;
			}
			
			// �������� ������� ������
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) {
					bMenuClosed = true;
					return EEndStatus::Exit;
				}

				// �������� ��������� ������ ���� ���������� �������
				if (event.key.code == sf::Keyboard::Down) {
					if (CurrBtn < 0)
						CurrBtn = 0;

					CurrBtn = (CurrBtn + 1) % 3;

					// ����� ������� �������� ������ � ����������� �� ������� ��������� ������
					BtnFill(CurrBtn);
				}
				else if (event.key.code == sf::Keyboard::Up) {
					CurrBtn = CurrBtn - 1;

					if (CurrBtn < 0)
						CurrBtn = 2;

					// ����� ������� �������� ������ � ����������� �� ������� ��������� ������
					BtnFill(CurrBtn);
				}

				// ������������ ������� ������ 
				if (event.key.code == sf::Keyboard::Enter) {
					MenuStatus = BtnActivate(CurrBtn);
				}
			}
			
			// ������������ ������� ������ 
			if (event.type == sf::Event::MouseButtonPressed){
				if (event.mouseButton.button == sf::Mouse::Left) {
					printf("%d", CurrBtn);
					MenuStatus = BtnActivate(CurrBtn);
				}
			}
			
			// �������� ��� �������� ������
			if (event.type == sf::Event::MouseMoved) {
				if (LastMousePos.x != event.mouseMove.x && LastMousePos.y != event.mouseMove.y) {
					CurrBtn = -1;

					// ���������� ������ ������.
					if (event.mouseMove.x > StartBtn.getGlobalBounds().left&& event.mouseMove.x < (StartBtn.getGlobalBounds().left + StartBtnRect.width)) {
						if (event.mouseMove.y > StartBtn.getGlobalBounds().top&& event.mouseMove.y < (StartBtn.getGlobalBounds().top + StartBtnRect.height)) {
							CurrBtn = 0;	
						}
					}

					// ���������� ������ ��������.
					if (event.mouseMove.x > SettingBtn.getGlobalBounds().left&& event.mouseMove.x < (SettingBtn.getGlobalBounds().left + SettingBtnRect.width)) {
						if (event.mouseMove.y > SettingBtn.getGlobalBounds().top&& event.mouseMove.y < (SettingBtn.getGlobalBounds().top + SettingBtnRect.height)) {
							CurrBtn = 1;
						}
					}

					// ���������� ������ ������.
					if (event.mouseMove.x > EndBtn.getGlobalBounds().left&& event.mouseMove.x < (EndBtn.getGlobalBounds().left + EndBtnRect.width)) {
						if (event.mouseMove.y > EndBtn.getGlobalBounds().top&& event.mouseMove.y < (EndBtn.getGlobalBounds().top + EndBtnRect.height)) {
							CurrBtn = 2;
						}

					}

					// ������������� ��������� ������� ���� 
					LastMousePos.x = event.mouseMove.x;
					LastMousePos.y = event.mouseMove.y;

					// ����� ������� �������� ������ � ����������� �� ������� ��������� ������
					BtnFill(CurrBtn);	
				} 
			}
			

		}

		if (MenuStatus != EEndStatus::Menu) {
			return MenuStatus;
		}



		window.clear();

		window.draw(BackMenu);
		window.draw(Logo);
		window.draw(StartBtn);
		window.draw(SettingBtn);
		window.draw(EndBtn);
		
		window.display();
	}
	return EEndStatus::GameError;
}

const int IMainMenu::getSelectedLvl()
{
	return SelectedLvl;
}
