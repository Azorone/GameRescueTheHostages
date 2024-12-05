#pragma once

#include"game_object.h"
bool checkStateGravitationalForce(GameSuper* game, GameSuper* game_Object) {

    return game->useGravitational;
}
bool cheakStateCollision(GameSuper* game, GameSuper* game_Object) {

    if (!game->useCheckCollision || !game->canUse)
    {
        return false;
    }
    if (!game_Object->useCheckCollision || !game_Object->canUse)
    {
        return false;
    }
    return true;
}
void wall(GameSuper* game, GameSuper* game_Object) {
    if (game->moveDirection == Up)
    {
        game->positionY = game_Object->positionY + game->height;

    }
    if (game->moveDirection == Down)
    {
        game->positionY = game_Object->positionY - game->height;
    }
    if (game->moveDirection == Right)
    {
        game->moveDirection = game_Object->positionY - game->width;
    }
    if (game->moveDirection == Left)
    {
        game->moveDirection = game_Object->positionY + game->width;
    }

}
void Game_brick_(GameSuper* game, GameSuper* game_Object) {

    if (game->moveDirection == Up)
    {
        game->positionY = game_Object->positionY + game->height;
    }
    if (game->moveDirection == Down)
    {
        game->positionY = game_Object->positionY - game->height;
    }
    game->moveflage[Down] = false;
    game->moveflage[Up] = true;
    game->moveflage[Right] = true;
    game->moveflage[Left] = true;

}
void GameAutoMoveNailDownUp(GameSuper* game, GameSuper* game_Object) {


}
void GameAutoMoveNailRightLeft(GameSuper* game, GameSuper* game_Object) {
    int i = game_Object->autoMoveY;
    int x = game_Object->autoMoveStartX;
    std::cout << "auto_move";

    if (abs(game_Object->autoMoveStartX) > i)
    {
        if (game_Object->moveDirection == Left)
        {
            game_Object->moveDirection = Right;
        }
        else if (game_Object->moveDirection == Right) {

            game_Object->moveDirection = Left;
        }

    }
    if (game_Object->moveDirection == Left)
    {
        game_Object->autoMoveStartX = game_Object->autoMoveStartX - game_Object->speed;
    }
    else if (game_Object->moveDirection == Right) {

        game_Object->autoMoveStartX = game_Object->autoMoveStartX + game_Object->speed;
    }

}
void GravitationalForceEvent(bool f, GameSuper* game) {



}
void GravitationalForce(GameSuper* g) {
    if (g->moveflage[Down])
    {
        int speed = g->speed;
        g->speed = 5;
        g->moveEvent(1, Down);
        g->moveDirection = Down;
        g->speed = speed;
    }

}
void GameBlockCollistionEvent(GameSuper* game, int d) {
    if (game->moveDirection == d)
    {
        game->moveflage[d] = false;
    }
}
void GameAntiqueCollistionEvent(GameSuper* trigger, GameSuper* game_Object) {
    trigger->score = trigger->score + game_Object->score;
    game_Object->is_show = false;
    game_Object->useCheckCollision = false;
    game_Object->canUse = false;
}
void GameGroundThornCollistionEvent(GameSuper* trigger, GameSuper* game_Object) {
    if ((trigger->score -= game_Object->score) < 0)
    {

        trigger->score = 0;
    }
    ;
}
void GamePrincessEventCollistionEvent(GameSuper* trigger, GameSuper* game_Object) {
    std::cout << "Åö×²";

    ;
    drawPrincessMenu(trigger->score < game_Object->score, trigger->belongMap == 1);

}
void CollisionEvents(GameSuper* game, int d) {

    for (int i = 1; i < viewSIZE_Y - 1; i++)
    {
        for (int j = 1; j < viewSIZE_X - 1; j++)
        {
            int v = View[i][j];
            if (GlobalM_Game_Object[v] != NULL)
            {
                GameSuper* game_Object = GlobalM_Game_Object[v];

                if (!game->useCheckCollision || !game->canUse)
                {
                    continue;
                }
                if (!game_Object->useCheckCollision || !game_Object->canUse)
                {
                    continue;
                }
                bool b = GlobalM_Game_Object[v]->CheckCollision(game);
                if (b)
                {
                    int ty = game_Object->gtype;
                    switch (ty)
                    {
                    case Game_Block:
                        GameBlockCollistionEvent(game, d);
                        break;
                    case Game_Road:
                        break;
                    case Game_wuxie:
                        break;
                    case Game_Princess:
                        GamePrincessEventCollistionEvent(game, game_Object);
                        break;
                    case Game_antique1:
                        GameAntiqueCollistionEvent(game, game_Object);
                        break;
                    case Game_antique2:
                        GameAntiqueCollistionEvent(game, game_Object);
                        break;
                    case Game_antique3:
                        GameAntiqueCollistionEvent(game, game_Object);
                        break;
                    case Game_antique4:
                        GameAntiqueCollistionEvent(game, game_Object);
                        break;
                    case Game_antique5:
                        GameAntiqueCollistionEvent(game, game_Object);
                        break;
                    case Game_antique6:
                        GameAntiqueCollistionEvent(game, game_Object);
                        break;
                    case Game_road_sign:
                        break;
                    case Game_wooden_thorn:
                        break;
                    case Game_forbidden_woman:
                        break;
                    case Game_character:
                        break;
                    case Game_bomb_chicken:
                        break;
                    case Game_ground_thorn:
                        break;
                    case Game_door_reward_1:
                        break;
                    case Game_reward_2:
                        break;
                    case Game_reward_3:
                        break;
                    case Game_reward_4:
                        break;
                    case Game_reward_5:
                        break;
                    case Game_reward_6:
                        break;
                    case Game_monster_boos:
                        break;
                    case Game_spring_stone:
                        break;
                    case Game_monster:
                        break;
                    case Game_Max:
                        break;
                    case Game_ground_Spikes:
                        GameGroundThornCollistionEvent(game, game_Object);
                        break;
                    case Game_D:
                        break;
                    default:
                        break;
                    }
                }
            }
        }

    }
}
void RunEvent(GameSuper* game, int d) {

    for (int i = 1; i < viewSIZE_Y - 1; i++)
    {
        for (int j = 1; j < viewSIZE_X - 1; j++)
        {
            int v = View[i][j];
            if (GlobalM_Game_Object[v] != NULL)
            {
                GameSuper* game_Object = GlobalM_Game_Object[v];
                int ty = game_Object->gtype;

                switch (ty)
                {
                case Game_Block:
                    if (cheakStateCollision(game, game_Object) && game_Object->CheckCollision(game))
                    {
                        GameBlockCollistionEvent(game, d);
                    }
                    if (checkStateGravitationalForce(game_Object, game))
                    {

                    }
                    break;
                case Game_Road:
                {
                    if (cheakStateCollision(game, game_Object) && game_Object->CheckCollision(game))
                    {
                        GameBlockCollistionEvent(game, d);
                    }
                    if (checkStateGravitationalForce(game_Object, game))
                    {
                    }
                }
                break;
                case Game_wuxie: {
                    if (cheakStateCollision(game, game_Object) && game_Object->CheckCollision(game))
                    {

                    }
                    if (checkStateGravitationalForce(game_Object, game))
                    {

                    }
                }
                               break;
                case Game_Princess: {

                    if (cheakStateCollision(game, game_Object) && game_Object->CheckCollision(game))
                    {
                        GamePrincessEventCollistionEvent(game, game_Object);
                    }
                    if (checkStateGravitationalForce(game_Object, game))
                    {

                    }

                }
                break;
                case Game_antique1:
                {
                    if (cheakStateCollision(game, game_Object) && game_Object->CheckCollision(game))
                    {

                    }
                    if (checkStateGravitationalForce(game_Object, game))
                    {

                    }
                }
                break;
                case Game_antique2:
                {
                    if (cheakStateCollision(game, game_Object) && game_Object->CheckCollision(game))
                    {

                    }
                    if (checkStateGravitationalForce(game_Object, game))
                    {

                    }
                }
                break;
                case Game_antique3:
                {
                    if (cheakStateCollision(game, game_Object) && game_Object->CheckCollision(game))
                    {

                    }
                    if (checkStateGravitationalForce(game_Object, game))
                    {

                    }
                }
                break;
                case Game_antique4:
                {
                    if (cheakStateCollision(game, game_Object) && game_Object->CheckCollision(game))
                    {

                    }
                    if (checkStateGravitationalForce(game_Object, game))
                    {

                    }
                }
                break;
                case Game_antique5:
                {
                    if (cheakStateCollision(game, game_Object) && game_Object->CheckCollision(game))
                    {

                    }
                    if (checkStateGravitationalForce(game_Object, game))
                    {

                    }
                }
                break;
                case Game_antique6:
                {
                    if (cheakStateCollision(game, game_Object) && game_Object->CheckCollision(game))
                    {

                    }
                    if (checkStateGravitationalForce(game_Object, game))
                    {

                    }
                }
                break;
                case Game_road_sign:
                {
                    if (cheakStateCollision(game, game_Object) && game_Object->CheckCollision(game))
                    {

                    }
                    if (checkStateGravitationalForce(game_Object, game))
                    {

                    }
                }
                break;
                case Game_wooden_thorn:
                {
                    if (cheakStateCollision(game, game_Object) && game_Object->CheckCollision(game))
                    {

                    }
                    if (checkStateGravitationalForce(game_Object, game))
                    {

                    }
                }
                break;
                case Game_forbidden_woman:
                {
                    if (cheakStateCollision(game, game_Object) && game_Object->CheckCollision(game))
                    {

                    }
                    if (checkStateGravitationalForce(game_Object, game))
                    {

                    }
                    if (game_Object->auto_move)
                    {
                        GameAutoMoveNailRightLeft(game, game_Object);
                    }
                }
                break;
                case Game_character:
                {
                    if (cheakStateCollision(game, game_Object) && game_Object->CheckCollision(game))
                    {

                    }
                    if (checkStateGravitationalForce(game_Object, game))
                    {

                    }
                }
                break;
                case Game_bomb_chicken:
                {
                    if (cheakStateCollision(game, game_Object) && game_Object->CheckCollision(game))
                    {

                    }
                    if (checkStateGravitationalForce(game_Object, game))
                    {

                    }
                }
                break;
                case Game_ground_thorn:
                {
                    if (cheakStateCollision(game, game_Object) && game_Object->CheckCollision(game))
                    {

                    }
                    if (checkStateGravitationalForce(game_Object, game))
                    {

                    }
                }
                break;
                case Game_door_reward_1:
                {
                    if (cheakStateCollision(game, game_Object) && game_Object->CheckCollision(game))
                    {
                        GameAntiqueCollistionEvent(game, game_Object);
                    }
                    if (checkStateGravitationalForce(game_Object, game))
                    {

                    }
                }
                break;
                case Game_reward_2:
                {
                    if (cheakStateCollision(game, game_Object) && game_Object->CheckCollision(game))
                    {
                        GameAntiqueCollistionEvent(game, game_Object);
                    }
                    if (checkStateGravitationalForce(game_Object, game))
                    {

                    }
                }
                break;
                case Game_reward_3:
                {
                    if (cheakStateCollision(game, game_Object) && game_Object->CheckCollision(game))
                    {
                        GameAntiqueCollistionEvent(game, game_Object);
                    }
                    if (checkStateGravitationalForce(game_Object, game))
                    {

                    }
                }
                break;
                case Game_reward_4:
                {
                    if (cheakStateCollision(game, game_Object) && game_Object->CheckCollision(game))
                    {
                        GameAntiqueCollistionEvent(game, game_Object);
                    }
                    if (checkStateGravitationalForce(game_Object, game))
                    {

                    }
                }
                break;
                case Game_reward_5:
                {
                    if (cheakStateCollision(game, game_Object) && game_Object->CheckCollision(game))
                    {
                        GameAntiqueCollistionEvent(game, game_Object);
                    }
                    if (checkStateGravitationalForce(game_Object, game))
                    {

                    }
                }
                break;
                case Game_reward_6:
                {
                    if (cheakStateCollision(game, game_Object) && game_Object->CheckCollision(game))
                    {
                        GameAntiqueCollistionEvent(game, game_Object);
                    }
                    if (checkStateGravitationalForce(game_Object, game))
                    {

                    }
                }
                break;
                case Game_monster_boos:
                {
                    if (cheakStateCollision(game, game_Object) && game_Object->CheckCollision(game))
                    {
                        GameAntiqueCollistionEvent(game, game_Object);
                    }
                    if (checkStateGravitationalForce(game_Object, game))
                    {

                    }
                }
                break;
                case Game_spring_stone:
                {
                    if (cheakStateCollision(game, game_Object) && game_Object->CheckCollision(game))
                    {

                    }
                    if (checkStateGravitationalForce(game_Object, game))
                    {

                    }
                }
                break;
                case Game_monster:
                {
                    if (cheakStateCollision(game, game_Object) && game_Object->CheckCollision(game))
                    {
                        GameGroundThornCollistionEvent(game, game_Object);
                    }
                    if (checkStateGravitationalForce(game_Object, game))
                    {

                    }
                }
                break;
                case Game_Max:
                    break;
                case Game_ground_Spikes:
                {
                    if (cheakStateCollision(game, game_Object) && game_Object->CheckCollision(game))
                    {
                        GameGroundThornCollistionEvent(game, game_Object);
                    }
                    if (checkStateGravitationalForce(game_Object, game))
                    {

                    }
                }
                break;
                case Game_brick_1:
                    if (cheakStateCollision(game, game_Object) && game_Object->CheckCollision(game))
                    {

                        wall(game, game_Object);


                    }
                    if (checkStateGravitationalForce(game_Object, game))
                    {

                    }
                    break;
                case Game_brick_2:
                    if (cheakStateCollision(game, game_Object) && game_Object->CheckCollision(game))
                    {
                        Game_brick_(game, game_Object);
                    }
                    if (checkStateGravitationalForce(game_Object, game))
                    {

                    }
                    break;
                case Game_brick_3:
                    if (cheakStateCollision(game, game_Object) && game_Object->CheckCollision(game))
                    {
                        Game_brick_(game, game_Object);
                    }
                    if (checkStateGravitationalForce(game_Object, game))
                    {

                    }
                    break;
                case Game_flay_brick_1:
                    if (cheakStateCollision(game, game_Object) && game_Object->CheckCollision(game))
                    {
                        Game_brick_(game, game_Object);
                    }
                    if (checkStateGravitationalForce(game_Object, game))
                    {

                    }
                    break;
                case Game_flay_brick_2:
                    if (cheakStateCollision(game, game_Object) && game_Object->CheckCollision(game))
                    {
                        Game_brick_(game, game_Object);
                    }
                    if (checkStateGravitationalForce(game_Object, game))
                    {

                    }
                case Game_Moth_Monster:
                {

                    if (cheakStateCollision(game, game_Object) && game_Object->CheckCollision(game))
                    {
                        GameGroundThornCollistionEvent(game, game_Object);
                    }
                    if (checkStateGravitationalForce(game_Object, game))
                    {

                    }
                    if (game_Object->auto_move)
                    {
                        GameAutoMoveNailRightLeft(game, game_Object);
                    }
                    break;
                }
                case Game_Stone_Monster:
                {
                    if (cheakStateCollision(game, game_Object) && game_Object->CheckCollision(game))
                    {
                        GameGroundThornCollistionEvent(game, game_Object);
                    }
                    if (checkStateGravitationalForce(game_Object, game))
                    {

                    }
                    if (game_Object->auto_move)
                    {
                        GameAutoMoveNailRightLeft(game, game_Object);
                    }
                };
                case Game_nail_top:
                {
                    if (cheakStateCollision(game, game_Object) && game_Object->CheckCollision(game))
                    {
                        GameGroundThornCollistionEvent(game, game_Object);
                    }
                    if (checkStateGravitationalForce(game_Object, game))
                    {

                    }
                    if (game_Object->auto_move)
                    {
                        //  GameAutoMoveNailRightLeft(game, game_Object);
                    }
                }
                break;
                case Game_nail:
                {
                    if (cheakStateCollision(game, game_Object) && game_Object->CheckCollision(game))
                    {
                        GameGroundThornCollistionEvent(game, game_Object);
                    }
                    if (checkStateGravitationalForce(game_Object, game))
                    {

                    }
                    if (game_Object->auto_move)
                    {
                        //  GameAutoMoveNailRightLeft(game, game_Object);
                    }
                }
                case Game_D:
                    break;
                default:
                    break;
                }
            }
        }
    }

}