#include <stdio.h>
#include <graphics.h>
#include <vector>
#include <time.h>
#include <conio.h> 
#include "EasyXPng.h"
#include <string>
#include <iostream>
#include <map>
#include <chrono>
#include <thread>
#include <random>  // 用于随机数生成
#include <ctime>
#include "game_map.h"
#include "game_object.h"
#include "tool.h"
#include"global_value.h"
#include "game_map.h"
#include "game_ui.h"

void res_init(struct Resource* res)
{
    res->gameIndex = 0;
    loadimage(res->im_start + 0, _T("开场背景1.png"));
    // 子页
    loadimage(res->im_homeSubPage + 0, _T("图鉴.png"));
    loadimage(res->im_homeSubPage + 1, _T("帮助.png"));
    loadimage(res->im_homeSubPage + 2, _T("操作.png"));
    // 主页图标
    loadimage(res->im_homeIcons + 0, _T("开场图标.png"));
    loadimage(res->im_homeIcons + 1, _T("开始游戏文字.png"));
    loadimage(res->im_homeIcons + 2, _T("开始游戏.png"));
    loadimage(res->im_homeIcons + 3, _T("游戏名.png"));
    //子页图标
    loadimage(res->im_subpagesub + 0, _T("道具.png"));
    loadimage(res->im_subpagesub + 1, _T("开场图标.png"));
    loadimage(res->im_subpagesub + 2, _T("开场图标.png"));
    //游戏对象
    loadimage(res->im_gameBackground + 0, _T("游戏背景.jpg"), WindowsW, WindowsH);
    //游戏对象图片
    loadimage(res->im_gameObject + Game_Block*10+No_movement, _T("img/障碍.png"),ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_Road*10+ No_movement, _T("img/地块.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_wuxie*10 +No_movement, _T("img/1吴邪1.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_wuxie*10 + Left, _T("img/1吴邪左1.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_wuxie*10 + Right , _T("img/1吴邪2.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_wuxie*10 + Up , _T("img/1吴邪左1.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_wuxie*10+ Down, _T("img/1吴邪左1.png"), ObjectSizeW, ObjectSizeH);
    //
    loadimage(res->im_gameObject + Game_antique1*10 + No_movement , _T("img/古董1.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_antique2*10 + No_movement , _T("img/古董2.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_antique3*10 + No_movement , _T("img/古董3.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_antique4*10 + No_movement , _T("img/古董4.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_antique5*10 + No_movement , _T("img/古董5.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_road_sign*10 + No_movement, _T("img/路标.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_ground_Spikes * 10 + No_movement, _T("img/障碍物.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_Princess*10 + No_movement, _T("img/公主.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_door_reward_1 * 10 + No_movement, _T("img/奖励1.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_reward_2 * 10 + No_movement, _T("img/奖励2.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_reward_3 * 10 + No_movement, _T("img/奖励3.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_reward_4 * 10 + No_movement, _T("img/奖励4.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_reward_5 * 10 + No_movement, _T("img/奖励5.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_reward_6 * 10 + No_movement, _T("img/奖励6.png"), ObjectSizeW, ObjectSizeH);
    //
    loadimage(res->im_gameObject + Game_nail_top * 10 + No_movement, _T("img/钉子.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_nail * 10 + Down, _T("img/钉子下.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_nail * 10 + Right, _T("img/钉子右.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_nail * 10 + Left, _T("img/钉子左.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_flay_brick_1 * 10 + No_movement, _T("img/飞砖1.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_flay_brick_2 * 10 + No_movement, _T("img/飞砖1.png"), ObjectSizeW, ObjectSizeH);

}

void GameBlockCollistionEvent(GameSuper* game, int d) {
    if (game->moveDirection == d)
    {
        game->moveflage[d] = false;
    }
}
void GameAntiqueCollistionEvent(GameSuper *trigger, GameSuper* game_Object) {
    trigger->score = trigger->score + game_Object->score;
    game_Object->is_show = false;
    game_Object->useCheckCollision = false;
    game_Object->canUse = false;
}
void GameGroundThornCollistionEvent(GameSuper* trigger, GameSuper* game_Object) {
    if (( trigger->score -= 10)<0)
    {
        trigger->score = 0;
    }
   ;
}
int success = -1; bool pause = false; 
void drawPrincessMenu(bool f) {
   
    std::cout << "绘制";
    pause = true;
    if (f)
    {
        int offset = 120;
        int offsetSiZE = 20;
        int base = WindowsW/2 - 60 ;
        int H = 0;
        int sizeOffsetH = 20;
        outtextxy(WindowsW / 2-100, WindowsH / 2-100, _T("失败！ "));
        putimagePng(WindowsW / 2, WindowsH / 2, res.im_homeIcons + 0);
        outtextxy(WindowsW / 2, WindowsH / 2, _T("退出"));
        putimagePng(WindowsW / 2 + 140, WindowsH/2, res.im_homeIcons + 0);
        outtextxy(WindowsW / 2 + 100 + offsetSiZE + offsetSiZE, WindowsH / 2, _T("重新游戏 "));
        success = 0;
    }
    else
    {
        int offset = 120;
        int offsetSiZE = 20;
        int base = WindowsW / 2 - 60;
        int H = 0;
        int sizeOffsetH = 20;
        putimagePng(WindowsW / 2, WindowsH / 2, res.im_homeIcons + 0);
        outtextxy(WindowsW / 2, WindowsH / 2, _T("退出"));
        putimagePng(WindowsW / 2 + 100, WindowsH / 2, res.im_homeIcons + 0);
        outtextxy(WindowsW / 2-100, WindowsH / 2-100, _T("成功!"));
        outtextxy(WindowsW / 2 + 100 + offsetSiZE + offsetSiZE, WindowsH / 2, _T("下一关"));
        success = 1;
    }
    FlushBatchDraw();

}
void GamePrincessEventCollistionEvent(GameSuper* trigger, GameSuper* game_Object) {
    std::cout << "碰撞";
   
    ;
    drawPrincessMenu(trigger->score < game_Object->score);
   
}
void CollisionEvents(GameSuper* game,int d) {
      
    for (int i = 1; i < viewSIZE_Y - 1; i++)
    {
        for (int j = 1; j < viewSIZE_X - 1; j++)
        {
            int v = View[i][j];
            if (GlobalM_Game_Object[v]!=NULL)
            {
                GameSuper* game_Object = GlobalM_Game_Object[v];
              
                if (!game->useCheckCollision || !game->canUse)
                {
                    continue;
                }
                if (!game_Object->useCheckCollision || !game_Object->canUse )
                {
                    continue;
                }
                  bool b = GlobalM_Game_Object[v]->CheckCollision(game);
                   if (b )
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
                           GameAntiqueCollistionEvent(game,game_Object);
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
void drawUI(int score) {
    int offset = 120;
    int offsetSiZE = 20;
    int base = 0;
    int H = 0;
    int sizeOffsetH = 20;
    putimagePng(base, H, res.im_homeIcons + 0);
    outtextxy(base + offsetSiZE, sizeOffsetH, _T("退出"));
    putimagePng(base+offset, 0, res.im_homeIcons + 0);
    outtextxy(base+offset+offsetSiZE + offsetSiZE, 10, _T("得分: "));
    putimagePng(base + offset*2 + offsetSiZE , 0, res.im_homeIcons + 0);
    TCHAR s[20];
    _stprintf_s(s, _T("%d"), score);		// 高版本 VC 推荐使用 _stprintf_s 函数
    outtextxy(120 + 120 + 30, 10, s);
  
    // 鼠标左键点击切换画面
   
    
    
    
}

void GameOne() {
    int run = true;
    int newGame = true;
    Player* player = NULL;
    while (run)
    {   
        Sleep(20);
        if (newGame)
        {
            menuState = Game_1;
            int fl = 1;
            creatObjectByMap(0);
            player = new Player(0, viewSIZE_Y / 2, viewSIZE_X / 2, No_movement);
            player->belongMap = 0;
            player->useCheckCollision = true;
            player->canUse = true;
            player->speed = 20;
            renderGam1Map(player->Map_i, player->Map_j);
       //     putimagePng(586, 736, res.im_homeIcons + 0);
            player->render();
            FlushBatchDraw();
            renderGam1Map(player->Map_i, player->Map_j);
            newGame = false;
        }
        ExMessage msg;       
        while (peekmessage(&msg,-1))
        {   
        
            if (msg.message == WM_KEYDOWN)
            {
                if (pause)
                {
                    continue;
                }
                switch (msg.vkcode)
                        {
                        case 0x41: CollisionEvents(player, Left); player->moveEvent(1, Left); player->moveflage[Left] = true; break;
                        case 0x57: CollisionEvents(player, Up); player->moveEvent(1, Up); player->moveflage[Up] = true; break;
                        case 0x53: CollisionEvents(player, Down); player->moveEvent(1, Down); player->moveflage[Down] = true; break;
                        case 0x44: CollisionEvents(player, Right); player->moveEvent(1, Right); player->moveflage[Right] = true; break;
                        default:
                            break;
                        } 
               
            }
            else if (msg.message == WM_LBUTTONDOWN)
            {
                if (msg.message == WM_LBUTTONDOWN)
                {
                    if (menuState == Game_1)
                    {
                        // 1. 点击图鉴按钮
                        if (isInRect(&msg, 0, 0, res.im_homeIcons->getwidth(), res.im_homeIcons->getheight()))
                        {
                            exit(0);
                        }
                        else if (success!=-1)
                        {
                            if (isInRect(&msg, WindowsW / 2, WindowsH / 2, res.im_homeIcons->getwidth(), res.im_homeIcons->getheight()))
                            {
                                exit(0);
                            }
                            else {
                                if (success==0&& isInRect(&msg, WindowsW / 2+100, WindowsH / 2, res.im_homeIcons->getwidth(), res.im_homeIcons->getheight()))
                                {
                                    std::cout << "重开"<<"\n"; 
                                    success = -1;
                                    pause = false;
                                    delete player;
                                    player = NULL;
                                    newGame = true;
                                    break;
                                }
                                else if(success == 1 && isInRect(&msg, WindowsW / 2 + 100, WindowsH / 2, res.im_homeIcons->getwidth(), res.im_homeIcons->getheight()))
                                {
                                    std::cout << "下一关" << "\n";
                                    success = -1;
                                    pause = false;
                                    return;
                                }
                            }
                        }

                    }
                }
            }
            BeginBatchDraw();
            if (!pause)
            {
                if (player!=NULL)
                {
                   renderGam1Map(player->Map_i, player->Map_j);
                   player->render();  
                   drawUI(player->score);
                }
        
         
           FlushBatchDraw();
            flushmessage();
         
            }
           
        
        } 
        
     
        // startupScene(&msg);
        flushmessage();
     
    }
}
// 菜单选项
bool checkStateGravitationalForce(GameSuper* game, GameSuper* game_Object) {

    return game->useGravitational;
}
bool cheakStateCollision(GameSuper *game,GameSuper* game_Object) {

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
void Game_brick_(GameSuper* game, GameSuper* game_Object) {
   
    game->moveflage[Down] = false;
    game->moveflage[Up] = true;
    game->moveflage[Right] = true;
    game->moveflage[Left] = true;
    
}
void RunEvent(GameSuper *game,int d) {
    
    for (int i = 1; i < viewSIZE_Y - 1; i++)
    {
        for (int j = 1; j < viewSIZE_X - 1; j++)
        {
            int v = View[i][j];
            if (GlobalM_Game_Object[v] != NULL)
            {
                GameSuper* game_Object = GlobalM_Game_Object[v];
                
                bool b = GlobalM_Game_Object[v]->CheckCollision(game);
                if (b)
                {
                    int ty = game_Object->gtype;
                    switch (ty)
                    {
                    case Game_Block:
                        if (cheakStateCollision)
                        {
                            GameBlockCollistionEvent(game, d);
                        }
                        if (checkStateGravitationalForce(game_Object,game))
                        {

                        }
                        break;
                    case Game_Road:
                    {
                        if (cheakStateCollision)
                        {
                            GameBlockCollistionEvent(game, d);
                        }
                        if (checkStateGravitationalForce(game_Object, game))
                        {

                        }
                    }
                        break;
                    case Game_wuxie: {
                        if (cheakStateCollision)
                        {
                           
                        }
                        if (checkStateGravitationalForce(game_Object, game))
                        {

                        }
                    }
                        break;
                    case Game_Princess: {
                        
                        if (cheakStateCollision)
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
                        if (cheakStateCollision)
                        {

                        }
                        if (checkStateGravitationalForce(game_Object, game))
                        {

                        }
                    }
                        break;
                    case Game_antique2:
                    {
                        if (cheakStateCollision)
                        {

                        }
                        if (checkStateGravitationalForce(game_Object, game))
                        {

                        }
                    }
                        break;
                    case Game_antique3:
                    {
                        if (cheakStateCollision)
                        {

                        }
                        if (checkStateGravitationalForce(game_Object, game))
                        {

                        }
                    }
                        break;
                    case Game_antique4:
                    {
                        if (cheakStateCollision)
                        {

                        }
                        if (checkStateGravitationalForce(game_Object, game))
                        {

                        }
                    }
                        break;
                    case Game_antique5:
                    {
                        if (cheakStateCollision)
                        {

                        }
                        if (checkStateGravitationalForce(game_Object, game))
                        {

                        }
                    }
                        break;
                    case Game_antique6:
                    {
                        if (cheakStateCollision)
                        {

                        }
                        if (checkStateGravitationalForce(game_Object, game))
                        {

                        }
                    }
                        break;
                    case Game_road_sign:
                    {
                        if (cheakStateCollision)
                        {

                        }
                        if (checkStateGravitationalForce(game_Object, game))
                        {

                        }
                    }
                        break;
                    case Game_wooden_thorn:
                    {
                        if (cheakStateCollision)
                        {

                        }
                        if (checkStateGravitationalForce(game_Object, game))
                        {

                        }
                    }
                        break;
                    case Game_forbidden_woman:
                    {
                        if (cheakStateCollision)
                        {

                        }
                        if (checkStateGravitationalForce(game_Object, game))
                        {

                        }
                    }
                        break;
                    case Game_character:
                    {
                        if (cheakStateCollision)
                        {

                        }
                        if (checkStateGravitationalForce(game_Object, game))
                        {

                        }
                    }
                        break;
                    case Game_bomb_chicken:
                    {
                        if (cheakStateCollision)
                        {

                        }
                        if (checkStateGravitationalForce(game_Object, game))
                        {

                        }
                    }
                        break;
                    case Game_ground_thorn:
                    {
                        if (cheakStateCollision)
                        {

                        }
                        if (checkStateGravitationalForce(game_Object, game))
                        {

                        }
                    }
                        break;
                    case Game_door_reward_1:
                    {
                        if (cheakStateCollision)
                        {

                        }
                        if (checkStateGravitationalForce(game_Object, game))
                        {

                        }
                    }
                        break;
                    case Game_reward_2:
                    {
                        if (cheakStateCollision)
                        {

                        }
                        if (checkStateGravitationalForce(game_Object, game))
                        {

                        }
                    }
                        break;
                    case Game_reward_3:
                    {
                        if (cheakStateCollision)
                        {

                        }
                        if (checkStateGravitationalForce(game_Object, game))
                        {

                        }
                    }
                        break;
                    case Game_reward_4:
                    {
                        if (cheakStateCollision)
                        {

                        }
                        if (checkStateGravitationalForce(game_Object, game))
                        {

                        }
                    }
                        break;
                    case Game_reward_5:
                    {
                        if (cheakStateCollision)
                        {

                        }
                        if (checkStateGravitationalForce(game_Object, game))
                        {

                        }
                    }
                        break;
                    case Game_reward_6:
                    {
                        if (cheakStateCollision)
                        {

                        }
                        if (checkStateGravitationalForce(game_Object, game))
                        {

                        }
                    }
                        break;
                    case Game_monster_boos:
                    {
                        if (cheakStateCollision(game,game_Object))
                        {
                            Game_brick_( game, game_Object);
                        }
                        if (checkStateGravitationalForce(game_Object, game))
                        {

                        }
                    }
                        break;
                    case Game_spring_stone:
                    {
                        if (cheakStateCollision)
                        {

                        }
                        if (checkStateGravitationalForce(game_Object, game))
                        {

                        }
                    }
                        break;
                    case Game_monster:
                    {
                        if (cheakStateCollision)
                        {

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
                        if (cheakStateCollision)
                        {
                          GameGroundThornCollistionEvent(game, game_Object);
                        }
                        if (checkStateGravitationalForce(game_Object, game))
                        {

                        }
                    }
                        
                        break;
                    case Game_brick_1:
                        if (cheakStateCollision(game, game_Object))
                        {
                            Game_brick_(game, game_Object);
                        }
                        if (checkStateGravitationalForce(game_Object, game))
                        {

                        }
                        break;
                    case Game_brick_2:
                        if (cheakStateCollision(game, game_Object))
                        {
                            Game_brick_(game, game_Object);
                        }
                        if (checkStateGravitationalForce(game_Object, game))
                        {

                        }
                        break;
                    case Game_brick_3:
                        if (cheakStateCollision(game, game_Object))
                        {
                            Game_brick_(game, game_Object);
                        }
                        if (checkStateGravitationalForce(game_Object, game))
                        {

                        }
                        break;
                    case Game_flay_brick_1:
                        if (cheakStateCollision(game, game_Object))
                        {
                            Game_brick_(game, game_Object);
                        }
                        if (checkStateGravitationalForce(game_Object, game))
                        {

                        }
                        break;
                    case Game_flay_brick_2:
                        if (cheakStateCollision(game, game_Object))
                        {
                            Game_brick_(game, game_Object);
                        }
                        if (checkStateGravitationalForce(game_Object, game))
                        {

                        }
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

void GravitationalForceEvent(bool f, GameSuper* game) {
  


}
void GravitationalForce(GameSuper* g) {
    if (g->moveflage[Down])
    {
     //  g->speed = 80;
        g->moveEvent(1, Down); 
        g->moveDirection = Down;
      //  g->speed = 80;
    }
 
}

void GameTwo() {
    int run = true;
    int newGame = true;
    int D = 0;
    Player* player = NULL;
    while (run)
    {
        Sleep(30);
        if (newGame)
        {
            putimagePng(0, 0, res.im_gameBackground + 0);
            menuState = Game_1;
            int fl = 1;
            creatObjectByMap(1);
            player = new Player(1, viewSIZE_Y / 2, viewSIZE_X / 2, No_movement);
            player->belongMap = 1;
            player->useCheckCollision = true;
            player->canUse = true;
            player->speed = 20;
            player->moveflage[Up] = true;
            player->moveflage[Down] = true;
            player->moveflage[Right] = true;
            player->moveflage[Left] = true;
            renderGam2Map(player->Map_i, player->Map_j);
            player->render();
            FlushBatchDraw();
            newGame = false;
        }  


       
         
        ExMessage msg;  
       RunEvent(player,D);
        GravitationalForce(player);
        while (peekmessage(&msg, EX_KEY))
        {  
            if (msg.message == WM_KEYDOWN)
            {
                if (pause)
                {
                    continue;
                }
                switch (msg.vkcode)
                {
                case 0x41:  player->moveEvent(1, Left); D = Left;   break;
                case 0x57:  player->moveEvent(1, Up); D = Up;   break;
                case 0x53:  player->moveEvent(1, Down); D = Down; break;
                case 0x44:  player->moveEvent(1, Right); D = Right; break;
                default:
                    break;
                }
            }
            else if (msg.message == WM_LBUTTONDOWN)
            {
                if (msg.message == WM_LBUTTONDOWN)
                {
                    if (menuState == Game_1)
                    {
                        // 1. 点击图鉴按钮
                        if (isInRect(&msg, 0, 0, res.im_homeIcons->getwidth(), res.im_homeIcons->getheight()))
                        {
                            exit(0);
                        }
                        else if (success != -1)
                        {
                            if (isInRect(&msg, WindowsW / 2, WindowsH / 2, res.im_homeIcons->getwidth(), res.im_homeIcons->getheight()))
                            {
                                exit(0);
                            }
                            else {
                                if (success == 0 && isInRect(&msg, WindowsW / 2 + 100, WindowsH / 2, res.im_homeIcons->getwidth(), res.im_homeIcons->getheight()))
                                {
                                    std::cout << "重开" << "\n";
                                    success = -1;
                                    pause = false;
                                    delete player;
                                    player = NULL;
                                    newGame = true;
                                    break;
                                }
                                else if (success == 1 && isInRect(&msg, WindowsW / 2 + 100, WindowsH / 2, res.im_homeIcons->getwidth(), res.im_homeIcons->getheight()))
                                {
                                    std::cout << "下一关" << "\n";
                                    success = -1;
                                    pause = false;
                                    return;
                                }
                            }
                        }

                    }
                }
            }

        }
        BeginBatchDraw();
        putimagePng(0, 0, res.im_gameBackground + 0);
        if (!pause)
        {
            

            if (player != NULL)

            {   
                std::cout << player->Map_i<<"\n";
                std::cout << player->Map_j << "\n";

                renderGam2Map(player->Map_i, player->Map_j);
            
                player->render();
         
                drawUI(player->score);
                player->moveflage[Up] = true;
                player->moveflage[Down] = true;
                player->moveflage[Left] = true;
                player->moveflage[Right] = true;
            }
            FlushBatchDraw();
           
        }

        // startupScene(&msg);
        flushmessage();
        
    }
}
// 鼠标是否在某个矩形区域


void startupScene(ExMessage* msg)
{
    // 鼠标左键点击切换画面
    if (msg->message == WM_LBUTTONDOWN)
    {
        if (menuState == Home)
        {
            // 1. 点击图鉴按钮
            if (isInRect(msg, 586, 637, 131, 78))
            {
                menuState = See;
            }
            // 2. 点击帮助按钮
            else if (isInRect(msg, 590, 736, 132, 66))
            {
                menuState = Help;
            }
            // 3. 点击开始游戏按钮
            else if (isInRect(msg, 869, 291, 28, 201))
            {
                menuState = Start;
          
                //  startBigEscapeGame();
            }
            // 4. 点击操作按钮
            else if (isInRect(msg, 900, 637, 132, 66))
            {
                menuState = Operation;
            }
            // 5. 点击退出游戏按钮
            else if (isInRect(msg, 900, 736, 132, 66))
            {
                exit(0);
            }
        }
        else
        {
            // 在子页面点击返回按钮
            if (isInRect(msg, 900, 720, 100, 50))
            {
                menuState = Home;
            }
        }
    }

    // 根据 menuState 显示不同的图片
    switch (menuState)
    {
    case Home:
        putimage(0, 0, res.im_start + 0);
        // 绘制主页图标
        putimagePng(586, 637, res.im_homeIcons + 0);
        putimagePng(900, 637, res.im_homeIcons + 0);
        putimagePng(586, 736, res.im_homeIcons + 0);
        putimagePng(869, 291, res.im_homeIcons + 1);
        putimagePng(900, 736, res.im_homeIcons + 0);
        putimagePng(10, 20, res.im_homeIcons + 2);
        putimagePng(90, 95, res.im_homeIcons + 3);

        settextcolor(RGB(74, 100, 120));
        setbkmode(TRANSPARENT);
        settextstyle(35, 0, _T("方正楷体"));
        outtextxy(610, 650, _T("图鉴"));
        outtextxy(610, 750, _T("简介"));
        outtextxy(925, 650, _T("操作"));
        outtextxy(925, 750, _T("退出"));

        break;
    case See:
        putimage(0, 0, res.im_homeSubPage + 0); // 显示图鉴页图片
        putimage(300, 25, res.im_subpagesub + 0); //显示道具页
        putimagePng(1072 - 200, 800 - 100, res.im_homeIcons + 0);
        settextcolor(RGB(74, 100, 120));
        setbkmode(TRANSPARENT);
        settextstyle(35, 0, _T("方正楷体"));
        outtextxy(900, 720, _T("返回"));
        break;
    case Help:
        putimage(0, 0, res.im_homeSubPage + 1); // 显示说明页图片
        putimagePng(1072 - 200, 800 - 100, res.im_homeIcons + 0);
        settextcolor(RGB(74, 100, 120));
        setbkmode(TRANSPARENT);
        settextstyle(35, 0, _T("方正楷体"));
        outtextxy(900, 720, _T("返回"));
        break;
    case Operation:
        putimage(0, 0, res.im_homeSubPage + 2); // 显示操作页图片
        putimagePng(1072 - 200, 800 - 100, res.im_homeIcons + 0);
        settextcolor(RGB(74, 100, 120));
        setbkmode(TRANSPARENT);
        settextstyle(35, 0, _T("方正楷体"));
        outtextxy(900, 720, _T("返回"));
        break;
    case Start:
        //  putimagePng(0, 0, res.im_gameBackground+0);
       GameTwo();
    //    GameOne(); 
      //  flushmessage();
        //Gamejump();
        //   GameRun1();
        break;
    }
}

int main()
{   
    //creatMap_Game_();
    
    initgraph(WindowsW, WindowsH);
    releasecapture();
    BeginBatchDraw();
    res_init(&res);
    while (true)
    {
        ExMessage msg;
        while (peekmessage(&msg, EM_MOUSE))
        {
            startupScene(&msg);
        }
        flushmessage();
        FlushBatchDraw();
    }
    getchar();
    return 0;
}
