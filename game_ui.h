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
void drawUI(int score) {
    int offset = 120;
    int offsetSiZE = 20;
    int base = 0;
    int H = 0;
    int sizeOffsetH = 20;
    putimagePng(base, H, res.im_homeIcons + 0);
    outtextxy(base + offsetSiZE, sizeOffsetH, _T("�˳�"));
    putimagePng(base + offset, 0, res.im_homeIcons + 0);
    outtextxy(base + offset + offsetSiZE + offsetSiZE, 10, _T("�÷�: "));
    putimagePng(base + offset * 2 + offsetSiZE, 0, res.im_homeIcons + 0);
    TCHAR s[20];
    _stprintf_s(s, _T("%d"), score);		// �߰汾 VC �Ƽ�ʹ�� _stprintf_s ����
    outtextxy(120 + 120 + 30, 10, s);

    // ����������л�����

}
void drawPrincessMenu(bool f, bool last) {


    pause = true;
    if (f)
    {
        int offset = 120;
        int offsetSiZE = 20;
        int base = WindowsW / 2 - 60;
        int H = 0;
        int sizeOffsetH = 20;
        outtextxy(WindowsW / 2 - 100, WindowsH / 2 - 100, _T("ʧ�ܣ� "));
        putimagePng(WindowsW / 2 - 120, WindowsH / 2, res.im_homeIcons + 0);
        outtextxy(WindowsW / 2 - 120 + 10, WindowsH / 2, _T("�˳�"));
        putimagePng(WindowsW / 2 + 140, WindowsH / 2, res.im_homeIcons + 0);
        outtextxy(WindowsW / 2 + 140 + offsetSiZE + offsetSiZE, WindowsH / 2, _T("������Ϸ "));
        success = 0;
    }
    else
    {
        int offset = 120;
        int offsetSiZE = 20;
        int base = WindowsW / 2 - 60;
        int H = 0;
        int sizeOffsetH = 20;
        outtextxy(WindowsW / 2 - 100, WindowsH / 2 - 100, _T("�ɹ�!"));
        putimagePng(WindowsW / 2 - 120, WindowsH / 2, res.im_homeIcons + 0);
        outtextxy(WindowsW / 2 - 120 + 10, WindowsH / 2, _T("�˳�"));
        putimagePng(WindowsW / 2 + 100, WindowsH / 2, res.im_homeIcons + 0);

        outtextxy(WindowsW / 2 + 100 + offsetSiZE + offsetSiZE, WindowsH / 2, _T("��һ��"));
        success = 1;
        if (last)
        {
            outtextxy(WindowsW / 2 + 100 + offsetSiZE + offsetSiZE, WindowsH / 2, _T("�������˵�"));
            success = 2;
        }

    }
    FlushBatchDraw();

}


