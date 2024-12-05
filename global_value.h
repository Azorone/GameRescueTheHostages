#pragma once
#ifndef Global_VALUE
#define  fb         Game_brick_3*10
#define  fb1        Game_brick_1*10  
#define  R12        Game_Road                 *10
#define  R13        Game_Block               *10
#define  R14        Game_wuxie               *10
#define  R15        Game_Princess            *10
#define  R16        Game_antique1            *10
#define  R17        Game_antique2            *10
#define  R18        Game_antique3            *10
#define  R19        Game_antique4            *10
#define  R20        Game_antique5            *10
#define  R21        Game_antique6            *10
#define  R22        Game_road_sign           *10
#define  R23        Game_wooden_thorn        *10
#define  R24        Game_forbidden_woman     *10
#define  R25        Game_character           *10
#define  R26        Game_bomb_chicken        *10
#define  R27        Game_ground_thorn        *10
#define  R28        Game_door_reward_1       *10
#define  R29        Game_reward_2            *10
#define  R30        Game_reward_3            *10
#define  R31        Game_reward_4            *10
#define  R32        Game_reward_5            *10
#define  R33        Game_reward_6            *10
#define  R34        Game_monster_boos        *10
#define  R35        Game_spring_stone        *10
#define  R36        Game_monster             *10
#define  R37        Game_ground_Spikes*10*10
#define  R38        Game_brick_1             *10
#define  R39        Game_brick_2             *10
#define  R40        Game_brick_3             *10
#define  R41        Game_nail_top            *10
#define  R42        Game_nail               *10
#define  R43        Game_flay_brick_1        *10
#define  R44        Game_flay_brick_2       *10
#define  R45        Game_Stone_Monster*10                         
#define  R46        Game_Moth_Monster*10
#define  R47        Game_Max,                 *10
#define  R48        Game_D

#include <graphics.h>
const int WindowsW = 1050;
const int WindowsH = 800;
const int ObjectSizeW = 50;
const int ObjectSizeH = 50;
const int PX_SiZE = 50;
#define viewSIZE_X 24
#define viewSIZE_Y 18
const int  Big_map_size_I = 80;
const int Big_map_size_J = 80;
const int GravitationalValue = 10;
int Object_Global_Id = 1;
int success = -1; bool pause = false;
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
    Game_ground_Spikes, //地刺
    Game_brick_1,
    Game_brick_2,
    Game_brick_3,
    Game_nail_top,
    Game_nail,
    Game_flay_brick_1,
    Game_flay_brick_2,
    Game_Stone_Monster, //石头怪物
    Game_Moth_Monster,//飞蛾
    Game_Hero,
    Game_Max,
    Game_D
};

enum MenuOp
{
    See,   // 图鉴按钮
    Help,  // 帮助
    Start, // 进入关卡
    Operation, // 操作
    Home,   // 回到主目录
    Game_1, //关卡1
    Game_2  //关卡2
};
enum MenuBelong {
    Home_,
    Game_1_,
    Game_2_

};
enum MenuOp menuState = Home; // 开始是在主目录
enum MenuBelong menubelong = Home_;
int which = 0;  // 现在是哪个画面

struct Resource
{
    int gameIndex;
    IMAGE im_start[3];
    IMAGE im_homeSubPage[5]; // home子页
    IMAGE im_homeIcons[4];   // 主页图标
    IMAGE im_subpagesub[3];  //子页图标
    IMAGE im_gameBackground[10]; //游戏背景
    IMAGE im_gameObject[600];//游戏对象
    //	IMAGE im_mapObject[10];//游戏地图对象
}  res; // 全局变量

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

