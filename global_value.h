#pragma once
#ifndef Global_VALUE
#define  fb     Game_flay_brick_1*10
#define  fb1     Game_flay_brick_2*10
#include <graphics.h>
const int WindowsW = 1050;
const int WindowsH = 800;
const int ObjectSizeW = 50;
const int ObjectSizeH = 40;
const int PX_SiZE = 60;
#define viewSIZE_X 21
#define viewSIZE_Y 23
const int  Big_map_size_I = 60;
const int Big_map_size_J = 60;
const int GravitationalValue = 10;
int Object_Global_Id = 1;
int getAndAdd_ID() {
    Object_Global_Id++;
    return Object_Global_Id - 1;
}
enum BeforPosition
{
    EQU_Befor,
    LOW_Befor,
    Above_Befor

};
enum ObjectType
{
    map_object,
    game_Object,
    _transparent_,
    N_transparent_,
    isBlock,
    n_block
};
enum MoveDirection
{   
    No_movement,
    Left,
    Right,
    Up,
    Down,


};
enum Game_Object_Type
{
   
    Game_Road,
    Game_Block,
    Game_wuxie,
    Game_Princess,
    Game_antique1,
    Game_antique2,
    Game_antique3,
    Game_antique4,
    Game_antique5,
    Game_antique6,
    Game_road_sign,
    Game_wooden_thorn,
    Game_forbidden_woman,
    Game_character,
    Game_bomb_chicken,
    Game_ground_thorn,
    Game_door_reward_1,
    Game_reward_2,
    Game_reward_3,
    Game_reward_4,
    Game_reward_5,
    Game_reward_6,
    Game_monster_boos,
    Game_spring_stone,
    Game_monster,
    Game_ground_Spikes, //�ش�
    Game_brick_1,
    Game_brick_2,
    Game_brick_3,
    Game_nail_top,
    Game_nail,
    Game_flay_brick_1,
    Game_flay_brick_2,

    Game_Max,
    Game_D
};

enum MenuOp
{
    See,   // ͼ����ť
    Help,  // ����
    Start, // ����ؿ�
    Operation, // ����
    Home,   // �ص���Ŀ¼
    Game_1, //�ؿ�1
    Game_2  //�ؿ�2
};
enum MenuBelong {
    Home_,
    Game_1_,
    Game_2_

};
enum MenuOp menuState = Home; // ��ʼ������Ŀ¼
enum MenuBelong menubelong = Home_;
int which = 0;  // �������ĸ�����

struct Resource
{
    int gameIndex;
    IMAGE im_start[3];
    IMAGE im_homeSubPage[3]; // home��ҳ
    IMAGE im_homeIcons[4];   // ��ҳͼ��
    IMAGE im_subpagesub[3];  //��ҳͼ��
    IMAGE im_gameBackground[10]; //��Ϸ����
    IMAGE im_gameObject[600];//��Ϸ����
    //	IMAGE im_mapObject[10];//��Ϸ��ͼ����
}  res; // ȫ�ֱ���

enum moveStateSet {
    Wallk_move,
    Run_move,
    Jump_move,
    Down_move,
    ST_move,
    flay,
};
int getActionImgIndex(int type, int md) {

    return type *10 + md;
}
IMAGE* get_GameObjectImg(int type, int md) {
    return res.im_gameObject + getActionImgIndex(type, md);
}
#endif // !Global_VALUE

