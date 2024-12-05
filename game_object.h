#pragma once
#ifndef GAME_BOJECT
#include "global_value.h"
#include<map>
class GameSuper
{
public:
    int belongMap;
    bool canUse = true;
    bool is_show = true;
    int id;
    int positionX = -1;
    int positionY = -1;
    int width;
    int height;
    int imgID;
    int beforpositionr = EQU_Befor;
    int Map_i;
    int Map_j;
    int speed = PX_SiZE;
    int maxPositionX = WindowsW;
    int maxPostionY = WindowsH;
    int minPositionX = 0;
    int minPositionY = 0;
    bool moveflage[5];
    bool auto_move;
    int mx=0, my=0;
    int descript;
    int score = 0;
    int autoMoveX = 0;
    int autoMoveY = 0;
    int autoMoveStartX = 0;
    int autoMoveStartY = 0;
    bool useGravitational = false;
    // std::string name;
    ObjectType is_transparent;
    ObjectType type;
    int gtype = 0;
    bool useCheckCollision;
    moveStateSet sta = ST_move;
    int moveDirection = No_movement;
    int addij = 0;
    GameSuper(int type, ObjectType is_tran, bool useCheck, int imgId) {
        gtype = type;
        is_transparent = is_tran;
        useCheckCollision = useCheck;
        imgID = imgId;

    }
    GameSuper() {};
    ~GameSuper() {};
    void checkPositionAndRest() {
       this->positionX = this->maxPositionX < this->positionX ? this->maxPositionX : this->positionX;
      this->positionY = this->maxPostionY < this->positionY ? this->maxPostionY : this->positionY;
    }
    void setObject(GameSuper* o)
    {
        // object = o;
    };
    int PositionToBig_MAP(int position,int base) {
        if (position == 0)
        {
            return 0;
        }
        return  position/base;
    }
    int Left_(int steup) {
    
        this->mx = this->mx + steup * speed; 
        this->positionX -= steup * speed;
        if (this->positionX < 200)
        {
            this->positionX =200;
        
        }
        if (this->mx >= ObjectSizeW)
        {
           
            if (PositionToBig_MAP(this->mx, ObjectSizeW)>0)
            {
             this->Map_j -= PositionToBig_MAP(this->mx, ObjectSizeW);  this->mx = 0;
            }
            if (this->Map_j <= 0)
            {
                this->Map_j = 0;
            }
          
        }
       
        checkPositionAndRest();
        return steup * speed;
    };
    int Right_(int steup) {
        this->mx = this->mx + steup * speed;

        this->positionX += steup * speed;
        if (this->positionX > WindowsW - 200)
        {
            this->positionX = WindowsW - 200;
 
             
        }

        if (this->mx >= ObjectSizeW)
        {
         

            if (PositionToBig_MAP(this->mx, ObjectSizeW)>0)
            {
                this->Map_j += PositionToBig_MAP(this->mx, ObjectSizeW);  this->mx = 0;
            }
            if (this->Map_j >= Big_map_size_J - 2)
            {
                this->Map_j = Big_map_size_J - 2;
            }
            
        }
      
        checkPositionAndRest();
        return steup * speed;

    };
    int Up_(int steup) {
        this->my = this->my + steup * speed;
        this->positionY -= steup * speed;
        if (this->positionY < 200)
        {
            this->positionY = 200;
        
        }
        if (this->my >= ObjectSizeH)
        {   
            this->Map_i -= PositionToBig_MAP(this->my, ObjectSizeH);
            if (this->Map_i <= 0)
            {
                this->Map_i = 0;
            }
            this->my = 0;
        }
       
        checkPositionAndRest();
        return steup * speed;
    };
    int Down_(int steup) {
  
        this->my = this->my + steup * speed;
        this->positionY += steup * speed;
        if (this->positionY > WindowsH - ObjectSizeH*3)
        {
            this->positionY = WindowsH - ObjectSizeH*3;
        
        }
        if (this->my >= ObjectSizeH)
        {
            this->Map_i += PositionToBig_MAP(this->my, ObjectSizeH);
            if (this->Map_i >= Big_map_size_I-2)
            {
                this->Map_i = Big_map_size_I - 2;
            }
            this->my = 0;
        }
   
        checkPositionAndRest();
        return steup * speed;
    }
    int moveEvent(int steup, MoveDirection d,bool jump = false) {
     
        int curspeed = 0; if (!this->moveflage[d])
        {
            
            return 0;
        }
       if(jump)
       {
             curspeed = this->speed;
            this->speed =80;
            Up_(1); this->moveflage[Up] = false;
            this->moveflage[Down] = true;
            this->moveDirection = Up;
            this->speed = curspeed;
       
            return 0;
        }
       
        this->moveDirection = d;
        switch (d)
        {
        case Left:
            Left_(steup);
            break;
        case Right:
            Right_(steup);
            break;
        case Up:
            Up_(steup);
            break;
        case Down:
            Down_(steup);
            break;
        default:
            break;
        }
        if (jump)
        {
            this->moveflage[Up] = false;
            this->moveflage[Down] = true;
            this->moveDirection = Up;
            this->speed = curspeed;
            return 0;
        }
        return 0;
    };

    bool CheckCollision(GameSuper* trigger) {
        
        if (
            trigger->positionX +trigger->width > positionX-trigger->speed
            && positionX + width > trigger->positionX - trigger->speed
            && trigger->positionY  + trigger->height> positionY - trigger->speed
            && positionY + height > trigger->positionY - trigger->speed) {



            return true;
        }
        return false;
    };
    void Collision(GameSuper* trigger) {

    };
    bool render() {

        if (is_transparent == _transparent_) {

            putimagePng(positionX, positionY, get_GameObjectImg(gtype, moveDirection));


        }
        else if (is_transparent == N_transparent_)
        {


            putimage(positionX, positionY, get_GameObjectImg(gtype, moveDirection));


        }
        return true;
    };
    bool render(int x, int y) {

        if (is_transparent == _transparent_) {

            putimage(positionX, positionY, get_GameObjectImg(gtype, moveDirection));
        }
        else if (is_transparent == N_transparent_)
        {
            putimage(positionX, positionY, get_GameObjectImg(gtype, moveDirection));
        }
        return true;
    };

private:

};

std::map <int, GameSuper*> GlobalM_Game_Object;
//Game_Object_Type type,ObjectType is_tran,bool useCheck,int imgId

GameSuper* CreatGameObject(int descript, int map, int i, int j) {
    int type = (descript / 10);
    int D = descript - (descript / 10);
    GameSuper* g_o = new GameSuper(type, N_transparent_, false, getActionImgIndex(type, D));
    g_o->belongMap = map;
    g_o->Map_i = i;
    g_o->Map_j = j;
    g_o->id = getAndAdd_ID();
    g_o->width = get_GameObjectImg(type,D)->getwidth();
    g_o->height = get_GameObjectImg(type, D)->getheight();
    g_o->canUse = true;
    g_o->auto_move = false;
    GlobalM_Game_Object[g_o->id] = g_o;
    switch (type)
    {
    case Game_Block:
        g_o->is_transparent = N_transparent_;   g_o->useCheckCollision = true;
        break;
    case Game_Road:
        g_o->is_transparent = N_transparent_;
        break;
    case Game_wuxie:
        g_o->is_transparent = _transparent_;
        break;
    case Game_Princess:
        g_o->is_transparent = _transparent_;
        g_o->score = 20;  g_o->useCheckCollision = true;
        break;
    case Game_antique1:
        g_o->is_transparent = _transparent_;
        g_o->score = 1;   g_o->useCheckCollision = true;
        break;
    case Game_antique2:
        g_o->is_transparent = _transparent_;
        g_o->score = 2;
        g_o->useCheckCollision = true;
        break;
    case Game_antique3:
        g_o->is_transparent = _transparent_;
        g_o->score = 3;  g_o->useCheckCollision = true;
        break;
    case Game_antique4:
        g_o->is_transparent = _transparent_;
        g_o->score = 4;  g_o->useCheckCollision = true;
        break;
    case Game_antique5:
        g_o->is_transparent = _transparent_;
        g_o->score = 5;  g_o->useCheckCollision = true;
        break;
    case Game_antique6:
        g_o->is_transparent = _transparent_;
        g_o->score = 6;  g_o->useCheckCollision = true;
        break;
    case Game_road_sign:
        g_o->is_transparent = _transparent_;
        break;
    case Game_wooden_thorn:
        g_o->score = 2;
        g_o->is_transparent = _transparent_;
        break;
    case Game_forbidden_woman:
        g_o->is_transparent = _transparent_;  g_o->useCheckCollision = true;
        g_o->autoMoveX = 80;
        g_o->autoMoveY = 100;
        g_o->speed = 10;
        g_o->score = 4;
        g_o->auto_move = true;
        g_o->moveDirection = Left;
        break;
    case Game_character:
        g_o->is_transparent = _transparent_;
        break;
    case Game_bomb_chicken:
        g_o->is_transparent = _transparent_;
        break;
    case Game_ground_thorn:
        g_o->is_transparent = _transparent_;
        break;
    case Game_door_reward_1:
        g_o->is_transparent = _transparent_;
        g_o->score = 1;   g_o->useCheckCollision = true;
        break;
    case Game_reward_2:
        g_o->is_transparent = _transparent_;
        g_o->score = 2;   g_o->useCheckCollision = true;
        break;
    case Game_reward_3:
        g_o->is_transparent = _transparent_;
        g_o->score = 3;   g_o->useCheckCollision = true;
        break;
    case Game_reward_4:
        g_o->is_transparent = _transparent_;
        g_o->score = 4;   g_o->useCheckCollision = true;
        break;
    case Game_reward_5:
        g_o->is_transparent = _transparent_;
        g_o->score = 5;   g_o->useCheckCollision = true;
        break;
    case Game_reward_6:
        g_o->is_transparent = _transparent_;
        g_o->score = 6;   g_o->useCheckCollision = true;
        break;
    case Game_monster_boos:
        g_o->is_transparent = _transparent_;
        break;
    case Game_spring_stone:
        g_o->is_transparent = _transparent_;
        break;
    case Game_monster:
        g_o->is_transparent = _transparent_;
        break;
    case Game_ground_Spikes:
       g_o->is_transparent = _transparent_;  g_o->useCheckCollision = true;
    case Game_brick_1:
        g_o->is_transparent = _transparent_;  g_o->useCheckCollision = true;
        break;
    case Game_brick_2:
        g_o->is_transparent = _transparent_;  g_o->useCheckCollision = true;
        break;
    case Game_brick_3:
        g_o->is_transparent = _transparent_;  g_o->useCheckCollision = true;
        break;
    case Game_flay_brick_1:
        g_o->is_transparent = _transparent_;  g_o->useCheckCollision = true;
        break;
    case Game_flay_brick_2:
        g_o->is_transparent = _transparent_;  g_o->useCheckCollision = true;
        break;
    case Game_nail_top: //钉子
        g_o->is_transparent = _transparent_;  g_o->useCheckCollision = true; 
        g_o->autoMoveX = 80;
        g_o->autoMoveY = 100;
        g_o->speed = 10;
        g_o->score = 20;
        g_o->auto_move = true;
        g_o->moveDirection = Left;
        break;
    case Game_nail:
        g_o->is_transparent = _transparent_;  g_o->useCheckCollision = true; 
        g_o->autoMoveX = 80;
        g_o->autoMoveY = 100;
        g_o->speed = 10;
        g_o->auto_move = true;
        g_o->score = 10;
        g_o->moveDirection = Left;
        break;
    case Game_Stone_Monster:
        g_o->is_transparent = _transparent_;  g_o->useCheckCollision = true; 
        g_o->autoMoveX = 80;
        g_o->autoMoveY = 100;
        g_o->speed = 10;
        g_o->score = 4;
        g_o->auto_move = true;
        g_o->moveDirection = Left;
           break;//石头怪物
    case Game_Moth_Monster:
        g_o->is_transparent = _transparent_;  g_o->useCheckCollision = true; 
        g_o->autoMoveX = 40;
        g_o->autoMoveY = 100;
        g_o->auto_move = true;
        g_o->speed = 10;
        g_o->score = 5;
        g_o->moveDirection = Left;
           break;//飞蛾
    case Game_Max:
        break;
    case Game_D:
        break;
    default:
        break;
    }

    return g_o;
}
class Player:public GameSuper
{
    
public:
    Player(int map,int i,int j,int d) {
        this->belongMap = map;
        this->Map_i = i;
        this->Map_j = j;
        this->id = getAndAdd_ID();
        GlobalM_Game_Object[this->id] = this;
        gtype = Game_wuxie;
        is_transparent = _transparent_;
        useCheckCollision =false;
        imgID = getActionImgIndex(Game_wuxie,No_movement);
        this->positionX = (j - 1) * PX_SiZE;
        this->positionY = (i - 1) * PX_SiZE;
        this->width = PX_SiZE;
        this->height = PX_SiZE;
    };
    ~Player() {};

private:

};
class PlayerTwo:public GameSuper {
public:

};
#endif // !GAME_BOJECT



