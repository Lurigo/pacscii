#include "Teleport.h"
#include "Game.h"
#include "Player.h"

#include <QTimer>

extern Game *game;

Teleport::Teleport(int x, int y, QGraphicsItem *parent)
{
    // Set teleporter size, position
    setRect(0,0,game->BLOCK_SIZE,game->BLOCK_SIZE);
    setPos(x*game->BLOCK_SIZE,y*game->BLOCK_SIZE);

    // load sound effect
    tp = new QMediaPlayer;
    tp->setMedia(QUrl("qrc:/sounds/teleport.wav"));

    // Set destination coordinates and direction
    switch (x)
    {
        case 9: destX = 21; destY = 0; break;
        case 10: destX = 22; destY = 24; break;
        case 21: destX = 9; destY = 24; break;
        case 22: destX = 10; destY = 0; break;
    }

    // Connect timer to detector function
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(detect()));
    timer->start(game->PING*8);
}

void Teleport::detect()
{
    // Check if the player is present
    if ((game->player->getX() == pos().x()) && (game->player->getY() == pos().y()))
    {
        game->player->setPos(destX*game->BLOCK_SIZE, destY*game->BLOCK_SIZE);
        tp->play();
    }
}


