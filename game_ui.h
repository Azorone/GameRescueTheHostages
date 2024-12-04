#pragma once
#include <graphics.h>  
#include"global_value.h"
enum UI_TYPE
{	UI_type,
	Button_ok,
	Button_canel,
	
};
enum UI_EVENT_tYPE
{	UI_EVENT,
	ClickeLeft,
	MOUSE_MOVE,
	UI_Closed
};

bool isInRect(ExMessage* msg, int x, int y, int w, int h)
{
	if (msg->x > x && msg->x < x + w && msg->y > y && msg->y < y + h)
	{
		return true;
	}
	return false;
}


