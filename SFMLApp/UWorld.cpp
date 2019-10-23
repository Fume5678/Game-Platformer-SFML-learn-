#include "UWorld.h" 


void UWorld::CreateWorld(sf::Uint32 LvlName)
{
	FParserXML ParserXML(std::to_string(LvlName));

	// ������ ������ ������
	LvlSize.x = ParserXML.getLvlSize().x;
	LvlSize.y = ParserXML.getLvlSize().y;

	// ������ ������ �����
	TileSize.x = ParserXML.getTileSize().x;
	TileSize.y = ParserXML.getTileSize().y;

	// ������ ������ ��������
	TileSetSize.x = ParserXML.getTileSetSize().x;
	TileSetSize.y = ParserXML.getTileSetSize().y;

	// ToDo ��������� ��������� ������� �� �������
	StartPos.x = 384.f;
	StartPos.y = 96.f;

	// ������ ������ ��� ������
	// ToDo ����������� �������� � ����������, � �������� ��� ����� ������
	BackgrTex.loadFromFile(SpritePath + "SpaceBack.jpg");
	Backgr.setTexture(BackgrTex);

	// ������ ���� � ��������
	sf::String PathToSet;
	PathToSet = ParserXML.getPathToSet();

	PathToSet.erase(0, 2);
	TileSetTex.loadFromFile("..\/Resource" + PathToSet);

	// ������ ���������� �����
	this->AmountLayers = ParserXML.getAmountLayer();

	// ������ ������� ������� �������� � ����� �������� 
	Layers = new world::FLayer[AmountLayers];
	for (int count = 0; count < AmountLayers; count++) {
		Layers[count].Blocks.resize(LvlSize.y);

		if (count == 0)
			CollisMap = new bool* [LvlSize.y];

		for (int i = 0; i < LvlSize.y; i++) {
			Layers[count].Blocks[i].resize(LvlSize.x);

			if (count == 0)
				CollisMap[i] = new bool[LvlSize.x];
		}
	}

	// ���� ���������� ����� ����������
	for (int count = 0; count < AmountLayers; count++) {
		for (int i = 0; i < LvlSize.y; i++) {
			for (int j = 0; j < LvlSize.x; j++) {
				// ���� ����� �� ���������, ��� ��������� ����� 
				int TileId = ParserXML.getLayerElement(count, i, j);
				sf::Sprite tmpSprite;

				tmpSprite.setTexture(TileSetTex);

				// �������� ������ �� ������ 
				if (TileId != 0) {
					TileId--;
					int XTileId, YTileId;
					YTileId = TileId / TileSetSize.x;
					XTileId = TileId - (YTileId * TileSetSize.x);

					tmpSprite.setTextureRect(sf::IntRect(XTileId * TileSize.x, YTileId * TileSize.y, TileSize.x, TileSize.y));
					tmpSprite.setPosition(sf::Vector2f(j * TileSize.x, i * TileSize.y));

					if (ParserXML.getLayerCollis(count) == true)
						CollisMap[i][j] = true;
					else
						CollisMap[i][j] = false;
				}
				else {
					tmpSprite.setTextureRect(sf::IntRect(-1, -1, 0, 0));
					CollisMap[i][j] = false;
				}
				Layers[count].Blocks[i][j] = tmpSprite;
			}
		}
	}

}

struct VerticalsPoint {
	sf::Vector2f Left, Right;
};

struct SidePoint {
	sf::Vector2f Top, Middle, Bottom;
};


sf::Vector2i UWorld::PointToTile(sf::Vector2f PointCoord)
{
	int xTile, yTile;

	xTile = PointCoord.x / TileSize.x;
	yTile = PointCoord.y / TileSize.y;

	return sf::Vector2i(xTile, yTile);
}


void UWorld::getCollisDirect(sf::FloatRect PawnRect, bool& bUp, bool& bDown, bool& bLeft, bool& bRight)
{
	bUp = false;
	bDown = false;
	bLeft = false;
	bRight = false;
	
}

void UWorld::DrawWorld(sf::RenderWindow& window, sf::Vector2f ViewCenter, sf::Vector2f ViewSize)
{
	window.draw(Backgr);

	// ������������ ������, �� ������� ����� ����������� ���������, ����� �������� ������ �� ���������
	int maxRight = (int(ViewCenter.x + ViewSize.x / 2) / TileSize.x), maxDown = (int(ViewCenter.y + ViewSize.y / 2) / TileSize.y);

	for (int count = 0; count < AmountLayers; count++) {

		maxDown = (int(ViewCenter.y + ViewSize.y / 2) / TileSize.y) + 1;
		if (maxDown > LvlSize.y) maxDown = LvlSize.y;

		for (int i = (int(ViewCenter.y - ViewSize.y / 2) / TileSize.y) % LvlSize.y; i < maxDown; i++) {
			if (i < 0) i = 0;

			// ��������� ����� ������ ������� �� ��������
			maxRight = (int(ViewCenter.x + ViewSize.x / 2) / TileSize.x) + 1;
			if (maxRight > LvlSize.x) maxRight = LvlSize.x;

			for (int j = (int(ViewCenter.x - ViewSize.x / 2) / TileSize.y) % LvlSize.x; j < maxRight; j++) {
				if (j < 0) j = 0;

				// ���� ������������ ������, �� �� ������������. Logic
				if (Layers[count].Blocks[i][j].getPosition().y != -1)
					window.draw(Layers[count].Blocks[i][j]);
			}
		}
	}
}

sf::Vector2f UWorld::getStartPos()
{
	return StartPos;
}

