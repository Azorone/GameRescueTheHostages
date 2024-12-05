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
#include <random>  // �������������
#include <ctime>
#include "game_map.h"
#include "game_object.h"
#include "tool.h"
#include"global_value.h"
#include "game_map.h"
#include "game_ui.h"
#include "game_event.h"
void res_init(struct Resource* res)
{
    res->gameIndex = 0;
    loadimage(res->im_start + 0, _T("��������1.png"));
    // ��ҳ
    loadimage(res->im_homeSubPage + 0, _T("ͼ��.png"));
    loadimage(res->im_homeSubPage + 1, _T("����.png"));
    loadimage(res->im_homeSubPage + 2, _T("����.png"));
    loadimage(res->im_homeSubPage + 3, _T("img/�����ֲ�.png"));
    // ��ҳͼ��
    loadimage(res->im_homeIcons + 0, _T("����ͼ��.png"));
    loadimage(res->im_homeIcons + 1, _T("��ʼ��Ϸ����.png"));
    loadimage(res->im_homeIcons + 2, _T("��ʼ��Ϸ.png"));
    loadimage(res->im_homeIcons + 3, _T("��Ϸ��.png"));
    //��ҳͼ��
    loadimage(res->im_subpagesub + 0, _T("����.png"));
    loadimage(res->im_subpagesub + 1, _T("����ͼ��.png"));
    loadimage(res->im_subpagesub + 2, _T("����ͼ��.png"));
    //��Ϸ����
    loadimage(res->im_gameBackground + 0, _T("��Ϸ����.jpg"), WindowsW, WindowsH);
    //��Ϸ����ͼƬ
    loadimage(res->im_gameObject + Game_Block*10+No_movement, _T("img/�ϰ�.png"),ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_Road*10+ No_movement, _T("img/�ؿ�.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_wuxie*10 +No_movement, _T("img/1��а1.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_wuxie*10 + Left, _T("img/1��а��1.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_wuxie*10 + Right , _T("img/1��а2.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_wuxie*10 + Up , _T("img/1��а��1.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_wuxie*10+ Down, _T("img/1��а��1.png"), ObjectSizeW, ObjectSizeH);
    //
    loadimage(res->im_gameObject + Game_antique1*10 + No_movement , _T("img/�Ŷ�1.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_antique2*10 + No_movement , _T("img/�Ŷ�2.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_antique3*10 + No_movement , _T("img/�Ŷ�3.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_antique4*10 + No_movement , _T("img/�Ŷ�4.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_antique5*10 + No_movement , _T("img/�Ŷ�5.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_road_sign*10 + No_movement, _T("img/·��.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_ground_Spikes * 10 + No_movement, _T("img/�ϰ���.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_Princess*10 + No_movement, _T("img/����.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_door_reward_1 * 10 + No_movement, _T("img/����1.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_reward_2 * 10 + No_movement, _T("img/����2.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_reward_3 * 10 + No_movement, _T("img/����3.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_reward_4 * 10 + No_movement, _T("img/����4.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_reward_5 * 10 + No_movement, _T("img/����5.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_reward_6 * 10 + No_movement, _T("img/����6.png"), ObjectSizeW, ObjectSizeH);
    //
    loadimage(res->im_gameObject + Game_nail_top * 10 + No_movement, _T("img/����.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_nail * 10 + Down, _T("img/������.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_nail * 10 + Right, _T("img/������.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_nail * 10 + Left, _T("img/������.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_flay_brick_1 * 10 + No_movement, _T("img/��ש1.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_flay_brick_2 * 10 + No_movement, _T("img/��ש1.png"), ObjectSizeW, ObjectSizeH);
    //
    loadimage(res->im_gameObject + Game_brick_1 * 10 + No_movement, _T("img/��ש1.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_brick_2 * 10 + No_movement, _T("img/��ש2.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_Stone_Monster * 10 + Right, _T("img/��2��.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_Stone_Monster * 10 + Left, _T("img/��2��.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_Stone_Monster * 10 + No_movement, _T("img/��2��.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_Moth_Monster * 10 + No_movement, _T("img/����1.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_Moth_Monster * 10 + Left, _T("img/����1.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_Moth_Monster * 10 + Right, _T("img/����2.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_brick_3 * 10 + No_movement, _T("img/��ש3.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_Hero * 10 + No_movement, _T("img/������1.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_Hero * 10 + Left, _T("img/������1.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_Hero * 10 + Right, _T("img/������1.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_Hero * 10 + Up, _T("img/��������.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_Hero * 10 + Down, _T("img/��������.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_forbidden_woman * 10 + No_movement, _T("img/������.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_forbidden_woman * 10 + Left, _T("img/������.png"), ObjectSizeW, ObjectSizeH);
    loadimage(res->im_gameObject + Game_forbidden_woman * 10 + Right, _T("img/������.png"), ObjectSizeW, ObjectSizeH);
    
}


void GameOne() {
    int run = true;
    int newGame = true;
    Player* player = NULL;
    while (run)
    {   
        Sleep(30);
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
                        // 1. ���ͼ����ť
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
                                    std::cout << "�ؿ�"<<"\n"; 
                                    success = -1;
                                    pause = false;
                                    delete player;
                                    player = NULL;
                                    newGame = true;
                                    break;
                                }
                                else if(success == 1 && isInRect(&msg, WindowsW / 2 + 100, WindowsH / 2, res.im_homeIcons->getwidth(), res.im_homeIcons->getheight()))
                                {
                                    std::cout << "��һ��" << "\n";
                                    success = -1;
                                    pause = false;
                                    delete player;
                                    player = NULL;
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
// �˵�ѡ��

int GameTwo() {
    int run = true;
    int newGame = true;
    int D = 0;
    Player* player = NULL;
    while (run)
    {
        Sleep(60);
        if (newGame)
        {
            putimagePng(0, 0, res.im_gameBackground + 0);
            menuState = Game_1;
            int fl = 1;
            creatObjectByMap(1);
            player = new Player(1, viewSIZE_Y / 2, viewSIZE_X / 2, No_movement);
            player->imgID = getActionImgIndex(Game_Hero, No_movement);
            player->gtype = Game_Hero;
            player->belongMap = 1;
            player->useCheckCollision = true;
            player->canUse = true;
            player->speed = PX_SiZE/10;
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
        while (peekmessage(&msg))
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
                case 0x57:  player->moveEvent(1, Up,true); D = Up;   break;
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
                        // 1. ���ͼ����ť
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
                                    std::cout << "�ؿ�" << "\n";
                                    success = -1;
                                    pause = false;
                                    delete player;
                                    player = NULL;
                                    newGame = true;
                                    break;
                                }
                                else if (success == 1 && isInRect(&msg, WindowsW / 2 + 100, WindowsH / 2, res.im_homeIcons->getwidth(), res.im_homeIcons->getheight()))
                                {
                                    std::cout << "��һ��" << "\n";
                                    success = -1;
                                    pause = false;
                                    return 1;
                                }
                                else if (success == 2 && isInRect(&msg, WindowsW / 2 + 100, WindowsH / 2, res.im_homeIcons->getwidth(), res.im_homeIcons->getheight()))
                                {
                                    pause = false;
                                    delete player;
                                    player = NULL;
                                    newGame = true;
                                    return 3;

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
             
                player->moveflage[Down] = true;
                player->moveflage[Left] = true;
                player->moveflage[Right] = true;
            }
            FlushBatchDraw();
           
        }

        // startupScene(&msg);
        flushmessage();
        
    }
    return 0;
}
// ����Ƿ���ĳ����������


void startupScene(ExMessage* msg)
{
    // ����������л�����
    if (msg->message == WM_LBUTTONDOWN)
    {
        if (menuState == Home)
        {
            // 1. ���ͼ����ť
            if (isInRect(msg, 586, 637, 131, 78))
            {
                menuState = See;
            }
            // 2. ���������ť
            else if (isInRect(msg, 590, 736, 132, 66))
            {
                menuState = Help;
            }
            // 3. �����ʼ��Ϸ��ť
            else if (isInRect(msg, 869, 291, 28, 201))
            {
                menuState = Start;
          
                //  startBigEscapeGame();
            }
            // 4. ���������ť
            else if (isInRect(msg, 900, 637, 132, 66))
            {
                menuState = Operation;
            }
            // 5. ����˳���Ϸ��ť
            else if (isInRect(msg, 900, 736, 132, 66))
            {
                exit(0);
            }
        }
        else
        {
            // ����ҳ�������ذ�ť
            if (isInRect(msg, 900, 720, 100, 50))
            {
                menuState = Home;
            }
        }
    }

    // ���� menuState ��ʾ��ͬ��ͼƬ
    switch (menuState)
    {
    case Home:
        putimage(0, 0, res.im_start + 0);
        // ������ҳͼ��
        putimagePng(586, 637, res.im_homeIcons + 0);
        putimagePng(900, 637, res.im_homeIcons + 0);
        putimagePng(586, 736, res.im_homeIcons + 0);
        putimagePng(869, 291, res.im_homeIcons + 1);
        putimagePng(900, 736, res.im_homeIcons + 0);
        putimagePng(10, 20, res.im_homeIcons + 2);
        putimagePng(90, 95, res.im_homeIcons + 3);

        settextcolor(RGB(74, 100, 120));
        setbkmode(TRANSPARENT);
        settextstyle(35, 0, _T("��������"));
        outtextxy(610, 650, _T("ͼ��"));
        outtextxy(610, 750, _T("���"));
        outtextxy(925, 650, _T("����"));
        outtextxy(925, 750, _T("�˳�"));

        break;
    case See:
        putimage(0, 0, res.im_homeSubPage + 0); // ��ʾͼ��ҳͼƬ
        putimage(300, 25, res.im_subpagesub + 0); //��ʾ����ҳ
        putimagePng(1072 - 200, 800 - 100, res.im_homeIcons + 0);
        settextcolor(RGB(74, 100, 120));
        setbkmode(TRANSPARENT);
        settextstyle(35, 0, _T("��������"));
        outtextxy(900, 720, _T("����"));
        break;
    case Help:
        putimage(0, 0, res.im_homeSubPage + 1); // ��ʾ˵��ҳͼƬ
        putimagePng(1072 - 200, 800 - 100, res.im_homeIcons + 0);
        settextcolor(RGB(74, 100, 120));
        setbkmode(TRANSPARENT);
        settextstyle(35, 0, _T("��������"));
        outtextxy(900, 720, _T("����"));
        break;
    case Operation:
        putimage(0, 0, res.im_homeSubPage + 2); // ��ʾ����ҳͼƬ
        putimage(WindowsW / 2 - 200, WindowsH / 2 - 200, res.im_homeSubPage + 3);
        putimagePng(1072 - 200, 800 - 100, res.im_homeIcons + 0);
        settextcolor(RGB(74, 100, 120));
        setbkmode(TRANSPARENT);
        settextstyle(35, 0, _T("��������"));
        outtextxy(900, 720, _T("����"));
        break;
    case Start:
        
      GameOne(); 
      if ( GameTwo() == 3)
      {
          menuState = Home;
      }
       
        break;
    }
}
void Mainmenu() {
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
}
int main()
{   
    //creatMap_Game_();
    
    initgraph(WindowsW, WindowsH);
    releasecapture();
    BeginBatchDraw();
    res_init(&res);
    Mainmenu();
    getchar();
    return 0;
}
