#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <cstdio>
#include <ctime>
#include <graphics.h>
#include <mmsystem.h>

float x,y;
int delaybullet = 0,delayroket = 0,delayroketmusuh = 0,stat,delayroketalien = 0;
int delaysprite2 = 7;
int delaysprite1 = 5;
class Ccar
{
public:
    Ccar()
    {
        x = 100;
        y = (getmaxy()/6)*5;
        stat = 0;
    }
    void mobil()
    {

        if(ismouseclick(WM_RBUTTONDOWN))
        {
        stat = stat + 1;
        clearmouseclick(WM_RBUTTONDOWN);
        }
        // MOBIL MODE 0
        if(stat == 0)
        {
            readimagefile("gambar mobil mode 2-min(3)(1).gif",x-55,y-130,x+150,y+55);
        }
        if(stat == 1)
        {
            //readimagefile("gambar mobil mode 1-min.gif",x-50,y-75,x+150,y+105);
            if(delaysprite1 == 1)
            {
                readimagefile("gambar mobil mode 2-min(7)(1).gif",x-55,y-130,x+150,y+55);
                delaysprite1 = delaysprite1 + 1;
            }
            else if(delaysprite1 == 2)
            {
                    readimagefile("gambar mobil mode 2-min(6)(1).gif",x-55,y-130,x+150,y+55);
                    delaysprite1 = delaysprite1 + 1;
            }
            else if(delaysprite1 == 3)
            {
                    readimagefile("gambar mobil mode 2-min(5)(1).gif",x-55,y-130,x+150,y+55);
                    delaysprite1 = delaysprite1 + 1;
            }
            else if(delaysprite1 == 4)
            {
                    readimagefile("gambar mobil mode 2-min(4)(1).gif",x-55,y-130,x+150,y+55);
                    delaysprite1 = delaysprite1 + 1;
            }
                if(delaysprite1 == 5)
            {
                    readimagefile("gambar mobil mode 2-min(3)(1).gif",x-55,y-130,x+150,y+55);
                    delaysprite1 = delaysprite1 + 1;
            }
             else if(delaysprite1 == 6)
            {
                    readimagefile("gambar mobil mode 2-min(2)(1).gif",x-55,y-130,x+150,y+55);
                    delaysprite1 = delaysprite1 + 1;
            }
            else if(delaysprite1 == 7)
            {
                    readimagefile("gambar mobil mode 2-min(1)(1).gif",x-55,y-130,x+150,y+55);
                    delaysprite1 = delaysprite1 + 1;
            }
            else if(delaysprite1 == 8)
            {
                readimagefile("gambar mobil mode 1-min.gif",x-50,y-75,x+155,y+105);
            }

        // MOBIL MODE 2
        }

        if(stat == 2)
        {

            if(delaysprite2 == 7)
            {
                readimagefile("gambar mobil mode 2-min(1)(1).gif",x-55,y-130,x+150,y+55);
                delaysprite2 = delaysprite2 - 1;
            }
            else if(delaysprite2 == 6)
            {
                    readimagefile("gambar mobil mode 2-min(2)(1).gif",x-55,y-130,x+150,y+55);
                    delaysprite2 = delaysprite2 - 1;
            }
            else if(delaysprite2 == 5)
            {
                    readimagefile("gambar mobil mode 2-min(3)(1).gif",x-55,y-130,x+150,y+55);
                    delaysprite2 = delaysprite2 - 1;
            }
            else if(delaysprite2 == 4)
            {
                    readimagefile("gambar mobil mode 2-min(4)(1).gif",x-55,y-130,x+150,y+55);
                    delaysprite2 = delaysprite2 - 1;
            }
            else if(delaysprite2 == 3)
            {
                    readimagefile("gambar mobil mode 2-min(5)(1).gif",x-55,y-130,x+150,y+55);
                    delaysprite2 = delaysprite2 - 1;
            }
            else if(delaysprite2 == 2)
            {
                    readimagefile("gambar mobil mode 2-min(6)(1).gif",x-55,y-130,x+150,y+55);
                    delaysprite2 = delaysprite2 - 1;
            }
            else if(delaysprite2 == 1)
            {
                    readimagefile("gambar mobil mode 2-min(7)(1).gif",x-55,y-130,x+150,y+55);
            }
        }

        if(stat > 2)
        {
            stat = 1;
            delaysprite2 = 7;
            delaysprite1 = 1;
        }
    }

    void road()
    {
        setcolor(LIGHTGRAY);
        line(0,(getmaxy()/10)*9,getmaxx(),(getmaxy()/10)*9);
        setfillstyle(SOLID_FILL,LIGHTGRAY);
        floodfill(1,(getmaxy()/10)*9+1, LIGHTGRAY);
    }

    void move()
    {
        if(GetAsyncKeyState(68))
        {
            x = x+10;
        }
        if(GetAsyncKeyState(65))
        {
            x = x-10;
        }
    }
};
class Cmusuhmobil
{
    public:
    float xmobil,ymobil,vmobil;
    Cmusuhmobil()
    {
        xmobil = getmaxx()+500;
        ymobil = (getmaxy()/6) * 5 ;
        vmobil = 10 + rand() % 30;
    }
    void musuhmobil()
    {
        readimagefile("Enemy car-min.gif",xmobil,ymobil-175,xmobil-300,ymobil+125);
        //rectangle(xmobil+20,ymobil-125,xmobil+300,ymobil+60);
    }

    void gerakmusuhmobil()
    {
        xmobil = xmobil-vmobil;
        if(xmobil<0)
        {
            xmobil = getmaxx()+500;
            ymobil = (getmaxy()/6) * 5 ;
            vmobil = 10 + rand() % 30;
        }
    }
};

class Cmusuhpesawat
{
public :
    float v_xpesawat,v_ypesawat,xpesawat,ypesawat,xroketmusuh,yroketmusuh,cekroketmusuh = 0;
    int status;
    Cmusuhpesawat()
    {
        xpesawat = getmaxx() + 250;
        srand(time(0));
        ypesawat = 400;
        v_xpesawat = 20;
        v_ypesawat = 2;
        xroketmusuh = 0;
        yroketmusuh = 0;
        status = 0;
    }
    void musuhpesawat()
    {
            readimagefile("Plane enemy-min(1).gif",xpesawat-400,ypesawat-200,xpesawat+100,ypesawat);
            //rectangle(xpesawat-400,ypesawat-175,xpesawat+60,ypesawat-15);
    }

    void gerakmusuhpesawatkiri()
    {
        if(status == 0)
        {
            xpesawat = xpesawat- v_xpesawat;
            ypesawat = ypesawat-v_ypesawat;
            if(ypesawat<175)
            {
                xpesawat = xpesawat;
                ypesawat = ypesawat;
                v_xpesawat = 20 + rand() % 20;
                v_ypesawat = 2 + rand() % 3;
                status = 1;
            }
            if(xpesawat<0)
            {
                xpesawat = getmaxx()+250;
                ypesawat = rand()%(((getmaxy()*2/3)-100)- 175 + 1) + 175;
                v_xpesawat = 20 + rand() % 20;
                v_ypesawat = 2 + rand() % 3;
            }
        }
        if(status == 1)
        {
            xpesawat = xpesawat-v_xpesawat;
            ypesawat = ypesawat+v_ypesawat;
            if(ypesawat>(getmaxy()*2/3)-175)
            {
                xpesawat = xpesawat;
                ypesawat = ypesawat;
                v_xpesawat = 20 + rand() % 20;
                v_ypesawat = 2 + rand() % 3;
                status = 0;
            }
            if(xpesawat<0)
            {
                xpesawat = getmaxx()+250;
                ypesawat = rand()%(((getmaxy()*2/3)-100)- 175 + 1) + 175;
                v_xpesawat = 20 + rand() % 20;
                v_ypesawat = 2 + rand() % 3;
            }
        }

    }

        int tembakroketmusuh(int x,int y)
        {
            if(xroketmusuh == 0 && yroketmusuh == 0 && cekroketmusuh == 1)
            {
                xroketmusuh = x-15;
                yroketmusuh = y-25;
            }
            if(yroketmusuh>getmaxy())
            {
                xroketmusuh = 0;
                yroketmusuh = 0;
                cekroketmusuh = 0;
            }
            if(cekroketmusuh == 1)
            {
                //xroket = xroket + 20;
                yroketmusuh = yroketmusuh + 10;
                readimagefile("rocket-min musuh.gif",xroketmusuh,yroketmusuh,xroketmusuh+100,yroketmusuh+100);
            }
        }
        int controlroketmusuh(int x,int y)
        {
                if(delayroketmusuh == 0)
                {
                    if(yroketmusuh > getmaxy() && xroketmusuh > getmaxx());
                    {
                        cekroketmusuh = 1;
                        if(xroketmusuh == 0 && yroketmusuh == 0)
                        {
                            delayroketmusuh = 3;
                        }
                    }
                }
            tembakroketmusuh(x,y);
        }
};
class UFO
{
    public:
    float xalien,yalien,v_xalien,v_yalien,xroketalien1,yroketalien1,xroketalien2,yroketalien2,cekroketalien = 0;
    int stat;
    UFO()
    {
        xalien = getmaxx()-150;
        yalien = getmaxy()/2 - 175;
        v_xalien = 15;
        v_yalien = 2 + rand() % 3;
        xroketalien1 = 0;
        xroketalien2 = 0;
        yroketalien1 = 0;
        yroketalien2 = 0;
        stat = 0;
    }
    void drawalien()
    {
        readimagefile("Final Boss.gif",xalien-250,yalien-250,xalien+250,yalien+250);
        //rectangle(xalien-190,yalien-150,xalien+190,yalien+60);
    }
    void gerakalien()
    {
        if(stat == 0)
        {
            xalien = xalien - v_xalien;
            yalien = yalien - v_yalien;
            if(yalien < 175)
                {
//                    xalien = xalien;
//                    yalien = yalien;
                    v_xalien = 15;
                    v_yalien = 2 + rand() % 3;
                    stat = 1;
                }
        }
        if(stat == 1)
        {
            xalien = xalien - v_xalien;
            yalien = yalien + v_yalien;
            if(yalien>(getmaxy()*2/3)-175 || xalien<150)
            {
//                    xalien = xalien;
//                    yalien = yalien;
                    v_xalien = 15;
                    v_yalien = 2 + rand() % 3;
                    stat = 2;
            }
        }
        if(stat == 2)
        {
            xalien = xalien + v_xalien;
            yalien = yalien + v_yalien;
            if(yalien > (getmaxy()*2/3)-175 || xalien>getmaxx()-150)
            {
//                xalien = xalien;
//                yalien = yalien;
                v_xalien = 15;
                v_yalien = 2 + rand() % 3;
                stat = 3;
            }
        }
            if(stat ==  3)
            {
                xalien = xalien + v_xalien;
                yalien = yalien - v_yalien;
                if(xalien >= getmaxx()-150 || yalien < 150)
                {
//                    xalien = xalien;
//                    yalien = yalien;
                    v_xalien = 15;
                    v_yalien = 2 + rand() % 3;
                    stat = 0;
                }

            }
    }
    int tembakroketalien(int x,int y)
        {


            if(xroketalien1 == 0 && yroketalien1 == 0 && cekroketalien == 1 && xroketalien2 == 0 && yroketalien2 == 0)
            {
                xroketalien1 = x;
                yroketalien1 = y-25;
                xroketalien2 = x-130;
                yroketalien2 = y-25;
            }
            if(yroketalien1>getmaxy() && yroketalien2 > getmaxy())
            {
                xroketalien1 = 0;
                yroketalien1 = 0;
                xroketalien2 = 0;
                yroketalien2 = 0;
                cekroketalien = 0;
            }
            if(cekroketalien == 1)
            {
                yroketalien1 = yroketalien1 + 25;
                readimagefile("rocket-min musuh.gif",xroketalien1,yroketalien1,xroketalien1+100,yroketalien1+100);
                yroketalien2 = yroketalien2 + 25;
                readimagefile("rocket-min musuh.gif",xroketalien2,yroketalien2,xroketalien2+100,yroketalien2+100);

            }
        }
        int controlroketalien(int x,int y)
        {
                if(delayroketalien == 0)
                {
                    if(yroketalien1 > getmaxy() && xroketalien1 > getmaxx() && yroketalien2 > getmaxy() && xroketalien2 > getmaxx());
                    {
                        cekroketalien = 1;
                        if(xroketalien1 == 0 && yroketalien1 == 0 && xroketalien2 == 0 && yroketalien2 == 0)
                        {
                            delayroketalien = 2;
                        }
                    }
                }
            tembakroketalien(x,y);
        }

};
class bullet
{
    public:
    float xp,yp,xroket,yroket;
    int cekbullet = 0,cekroket = 0;
    bullet()
    {
        xp = 0;
        yp = 0;
        xroket = 0;
        yroket = 0;

    }
        int tembakpeluru(int x, int y)
    {
            if((xp == 0) && (cekbullet == 1))
            {
                xp = x+130;
                yp = y-50;
            }
            if(xp>getmaxx())
            {
              xp = 0;
              yp = 0;
              cekbullet = 0;
            }
            if(cekbullet == 1)
            {
                xp = xp + 15;
                //circle(xp+15,yp,5);
                readimagefile("Bullet-min.gif",xp,yp,xp+50,yp+50);
            }
    }
    int controlpeluru(int x,int y,int stats)
    {
        if(stats == 1 && delaysprite1 == 8)
        {
            if(delaybullet == 0)
            {
                if(GetAsyncKeyState(VK_LBUTTON))
                {
                    cekbullet = 1;
                    if(xp == 0 && yp == 0)
                    {
                        delaybullet = 3;
                    }
                }
            }
        }
        tembakpeluru(x,y);
   }
    int tembakroket(int x, int y)
    {


            if(xroket == 0 && yroket == 0 && cekroket == 1)
            {
                xroket = x-15;
                yroket = y - 200;
            }
            if(yroket>getmaxy())
            {
                xroket = 0;
                yroket = 0;
                cekroket = 0;
            }
            if(cekroket == 1)
            {
                //xroket = xroket + 20;
                yroket = yroket - 10;
                readimagefile("rocket-min.gif",xroket,yroket,xroket+100,yroket+100);

            }
    }

        int controlroket(int x,int y,int stats)
    {
        if(stats == 2 && delaysprite2 == 1)
        {
            if(delayroket == 0)
            {
                if(GetAsyncKeyState(VK_LBUTTON))
                {
                    cekroket = 1;
                    if(xroket == 0 && yroket == 0)
                    {
                        delayroket = 5;
                    }
                }
            }
        }
         tembakroket(x,y);
    }

            int statsenjata()
        {
            return stat;

        }

};

class UserInterface
{
    public:
        char str[1];
        int status = 3;
        int statusalien = 4;
        int mode;
        int level;
        int score = 0;
        char ch[5];

    void gedung(float x,float y)
    {

        // BAGIAN ATAS
            setcolor(BLACK);
            readimagefile("Gedung.gif",x-600,y-600,x,y);

    }
    void scoredisplay()
    {
            setbkcolor(LIGHTCYAN);
            setcolor(BLACK);
            settextstyle(2,HORIZ_DIR,8);
            outtextxy(50,50,"Score : ");
            sprintf(ch,"%d",score);
            outtextxy(100,50,ch);
    }
int gametitle()
{
        char choice;
        char choices;
        int mainmenu = 1;
        int status = 1;
            if(mainmenu == 1)
            {
                cleardevice();
                setfillstyle(SOLID_FILL,LIGHTCYAN);
                rectangle(0,0,getmaxx(),getmaxy());
                floodfill(1,1,LIGHTCYAN);
                setbkcolor(LIGHTCYAN);
                setcolor(BLACK);
                settextstyle(2,HORIZ_DIR,30);
                settextjustify(1,1);
                outtextxy(getmaxx() / 2 , getmaxy() / 2 - 50, " DEATH CAR");
                settextstyle(2,HORIZ_DIR,10);
                outtextxy(getmaxx()/2,(getmaxy()/2),"-> PLAY <-");
                settextstyle(2,HORIZ_DIR,10);
                outtextxy(getmaxx()/2,(getmaxy()/2) + 50 ,"EXIT");
                choice= getch();
                if(choice == 13)
                {
                    mode = 1;
                    if(mode == 1)
                    {
                        if(status == 1)
                            {
                                cleardevice();
                                setfillstyle(SOLID_FILL,LIGHTCYAN);
                                rectangle(0,0,getmaxx(),getmaxy());
                                floodfill(1,1,LIGHTCYAN);
                                setbkcolor(LIGHTCYAN);
                                setcolor(BLACK);
                                settextstyle(2,HORIZ_DIR,10);
                                settextjustify(1,1);
                                outtextxy(getmaxx() / 2 , getmaxy() / 2 - 50, "-> LEVEL 1 <-");
                                settextstyle(2,HORIZ_DIR,10);
                                outtextxy(getmaxx()/2,(getmaxy()/2),"LEVEL 2");
                                settextstyle(2,HORIZ_DIR,10);
                                outtextxy(getmaxx()/2,(getmaxy()/2) + 50 ,"LEVEL 3");
                                choices = getch();
                                if(choices == 13)
                                {
                                    level = 1;
                                    return level;
                                }
                            }
                            choices = 1;
                            while(choices != 27)
                            {
                                choices = getch();
                                if(choices == 80)
                                {
                                    status++;
                                    if(status == 2)
                                    {
                                        cleardevice();
                                        setfillstyle(SOLID_FILL,LIGHTCYAN);
                                        rectangle(0,0,getmaxx(),getmaxy());
                                        floodfill(1,1,LIGHTCYAN);
                                        setbkcolor(LIGHTCYAN);
                                        setcolor(BLACK);
                                        settextstyle(2,HORIZ_DIR,10);
                                        settextjustify(1,1);
                                        outtextxy(getmaxx() / 2 , getmaxy() / 2 - 50, "LEVEL 1");
                                        settextstyle(2,HORIZ_DIR,10);
                                        outtextxy(getmaxx()/2,(getmaxy()/2),"-> LEVEL 2 <-");
                                        settextstyle(2,HORIZ_DIR,10);
                                        outtextxy(getmaxx()/2,(getmaxy()/2) + 50 ,"LEVEL 3");
                                        choices = getch();
                                        if(choices == 13)
                                        {
                                            level = 2;
                                            return level;
                                        }
                                    }
                                    if(status == 3)
                                    {
                                        cleardevice();
                                        setfillstyle(SOLID_FILL,LIGHTCYAN);
                                        rectangle(0,0,getmaxx(),getmaxy());
                                        floodfill(1,1,LIGHTCYAN);
                                        setbkcolor(LIGHTCYAN);
                                        setcolor(BLACK);
                                        settextstyle(2,HORIZ_DIR,10);
                                        settextjustify(1,1);
                                        outtextxy(getmaxx() / 2 , getmaxy() / 2 - 50, "LEVEL 1");
                                        settextstyle(2,HORIZ_DIR,10);
                                        outtextxy(getmaxx()/2,(getmaxy()/2),"LEVEL 2");
                                        settextstyle(2,HORIZ_DIR,10);
                                        outtextxy(getmaxx()/2,(getmaxy()/2) + 50 ,"-> LEVEL 3 <-");
                                        choices = getch();
                                        if(choices == 13)
                                        {
                                            level = 3;
                                            return level;
                                        }
                                    }
                                }
                                if(choices == 72)
                                {
                                    status--;
                                    if(status == 0)
                                    {
                                        status == 1;
                                    }
                                    if(status == 1)
                                    {
                                        cleardevice();
                                        setfillstyle(SOLID_FILL,LIGHTCYAN);
                                        rectangle(0,0,getmaxx(),getmaxy());
                                        floodfill(1,1,LIGHTCYAN);
                                        setbkcolor(LIGHTCYAN);
                                        setcolor(BLACK);
                                        settextstyle(2,HORIZ_DIR,10);
                                        settextjustify(1,1);
                                        outtextxy(getmaxx() / 2 , getmaxy() / 2 - 50, "-> LEVEL 1 <-");
                                        settextstyle(2,HORIZ_DIR,10);
                                        outtextxy(getmaxx()/2,(getmaxy()/2),"LEVEL 2");
                                        settextstyle(2,HORIZ_DIR,10);
                                        outtextxy(getmaxx()/2,(getmaxy()/2) + 50 ,"LEVEL 3");
                                        choices = getch();
                                        if(choices == 13)
                                        {
                                            level = 1;
                                            return level;
                                        }
                                    }
                                    if(status == 2)
                                    {
                                        cleardevice();
                                        setfillstyle(SOLID_FILL,LIGHTCYAN);
                                        rectangle(0,0,getmaxx(),getmaxy());
                                        floodfill(1,1,LIGHTCYAN);
                                        setbkcolor(LIGHTCYAN);
                                        setcolor(BLACK);
                                        settextstyle(2,HORIZ_DIR,10);
                                        settextjustify(1,1);
                                        outtextxy(getmaxx() / 2 , getmaxy() / 2 - 50, "LEVEL 1");
                                        settextstyle(2,HORIZ_DIR,10);
                                        outtextxy(getmaxx()/2,(getmaxy()/2),"-> LEVEL 2 <-");
                                        settextstyle(2,HORIZ_DIR,10);
                                        outtextxy(getmaxx()/2,(getmaxy()/2) + 50 ,"LEVEL 3");
                                        choices = getch();
                                        if(choices == 13)
                                        {
                                            level = 2;
                                            return level;
                                        }
                                    }
                            }

                        }
                }
            }
            }
            choice = 1;
            while(choice != 96)
            {
                choice = getch();
                if(choice == 80)
                {
                    mainmenu++;
                    if(mainmenu == 2)
                    {
                    cleardevice();
                    setfillstyle(SOLID_FILL,LIGHTCYAN);
                    rectangle(0,0,getmaxx(),getmaxy());
                    floodfill(1,1,LIGHTCYAN);
                    setbkcolor(LIGHTCYAN);
                    setcolor(BLACK);
                    settextstyle(2,HORIZ_DIR,30);
                    settextjustify(1,1);
                    outtextxy(getmaxx() / 2 , getmaxy() / 2 - 50, " DEATH CAR");
                    settextstyle(2,HORIZ_DIR,10);
                    outtextxy(getmaxx()/2,(getmaxy()/2),"PLAY");
                    settextstyle(2,HORIZ_DIR,10);
                    outtextxy(getmaxx()/2,(getmaxy()/2) + 50 ,"-> EXIT <-");
                                    choice= getch();
                    if(choice == 13)
                    {
                        mode = 2;
                        if(mode == 2)
                        {
                            closegraph();
                        }
                    }
                    }
                }
                if(choice == 72)
                {
                    mainmenu--;
                    if(mainmenu == 0)
                    {
                        mainmenu = 1;
                    }
                    if(mainmenu == 1)
                    {
                        cleardevice();
                        setfillstyle(SOLID_FILL,LIGHTCYAN);
                        rectangle(0,0,getmaxx(),getmaxy());
                        floodfill(1,1,LIGHTCYAN);
                        setbkcolor(LIGHTCYAN);
                        setcolor(BLACK);
                        settextstyle(2,HORIZ_DIR,30);
                        settextjustify(1,1);
                        outtextxy(getmaxx() / 2 , getmaxy() / 2 - 50, " DEATH CAR");
                        settextstyle(2,HORIZ_DIR,10);
                        outtextxy(getmaxx()/2,(getmaxy()/2),"-> PLAY <-");
                        settextstyle(2,HORIZ_DIR,10);
                        outtextxy(getmaxx()/2,(getmaxy()/2) + 50 ,"EXIT");
                        choice= getch();
                        if(choice == 13)
                        {
                            mode = 1;
                            if(mode == 1)
                            {
                                if(status == 1)
                                {
                                    cleardevice();
                                    setfillstyle(SOLID_FILL,LIGHTCYAN);
                                    rectangle(0,0,getmaxx(),getmaxy());
                                    floodfill(1,1,LIGHTCYAN);
                                    setbkcolor(LIGHTCYAN);
                                    setcolor(BLACK);
                                    settextstyle(2,HORIZ_DIR,10);
                                    settextjustify(1,1);
                                    outtextxy(getmaxx() / 2 , getmaxy() / 2 - 50, "-> LEVEL 1 <-");
                                    settextstyle(2,HORIZ_DIR,10);
                                    outtextxy(getmaxx()/2,(getmaxy()/2),"LEVEL 2");
                                    settextstyle(2,HORIZ_DIR,10);
                                    outtextxy(getmaxx()/2,(getmaxy()/2) + 50 ,"LEVEL 3");
                                    choices = getch();
                                    if(choices == 13)
                                    {
                                        level = 1;
                                        return level;
                                    }
                                }
                            choices = 1;
                            while(choices != 27)
                            {
                                choices = getch();
                                if(choices == 80)
                                {
                                    status++;
                                    if(status == 2)
                                    {
                                        cleardevice();
                                        setfillstyle(SOLID_FILL,LIGHTCYAN);
                                        rectangle(0,0,getmaxx(),getmaxy());
                                        floodfill(1,1,LIGHTCYAN);
                                        setbkcolor(LIGHTCYAN);
                                        setcolor(BLACK);
                                        settextstyle(2,HORIZ_DIR,10);
                                        settextjustify(1,1);
                                        outtextxy(getmaxx() / 2 , getmaxy() / 2 - 50, "LEVEL 1");
                                        settextstyle(2,HORIZ_DIR,10);
                                        outtextxy(getmaxx()/2,(getmaxy()/2),"-> LEVEL 2 <-");
                                        settextstyle(2,HORIZ_DIR,10);
                                        outtextxy(getmaxx()/2,(getmaxy()/2) + 50 ,"LEVEL 3");
                                        choices = getch();
                                        if(choices == 13)
                                        {
                                            level = 2;
                                            return level;
                                        }
                                    }
                                    if(status == 3)
                                    {
                                        cleardevice();
                                        setfillstyle(SOLID_FILL,LIGHTCYAN);
                                        rectangle(0,0,getmaxx(),getmaxy());
                                        floodfill(1,1,LIGHTCYAN);
                                        setbkcolor(LIGHTCYAN);
                                        setcolor(BLACK);
                                        settextstyle(2,HORIZ_DIR,10);
                                        settextjustify(1,1);
                                        outtextxy(getmaxx() / 2 , getmaxy() / 2 - 50, "LEVEL 1");
                                        settextstyle(2,HORIZ_DIR,10);
                                        outtextxy(getmaxx()/2,(getmaxy()/2),"LEVEL 2");
                                        settextstyle(2,HORIZ_DIR,10);
                                        outtextxy(getmaxx()/2,(getmaxy()/2) + 50 ,"-> LEVEL 3 <-");
                                        choices = getch();
                                        if(choices == 13)
                                        {
                                            level = 3;
                                            return level;
                                        }
                                    }
                                }
                                if(choices == 72)
                                {
                                    status--;
                                    if(status == 0)
                                    {
                                        status == 1;
                                    }
                                    if(status == 1)
                                    {
                                        cleardevice();
                                        setfillstyle(SOLID_FILL,LIGHTCYAN);
                                        rectangle(0,0,getmaxx(),getmaxy());
                                        floodfill(1,1,LIGHTCYAN);
                                        setbkcolor(LIGHTCYAN);
                                        setcolor(BLACK);
                                        settextstyle(2,HORIZ_DIR,10);
                                        settextjustify(1,1);
                                        outtextxy(getmaxx() / 2 , getmaxy() / 2 - 50, "-> LEVEL 1 <-");
                                        settextstyle(2,HORIZ_DIR,10);
                                        outtextxy(getmaxx()/2,(getmaxy()/2),"LEVEL 2");
                                        settextstyle(2,HORIZ_DIR,10);
                                        outtextxy(getmaxx()/2,(getmaxy()/2) + 50 ,"LEVEL 3");
                                        choices = getch();
                                        if(choices == 13)
                                        {
                                            level = 1;
                                            return level;
                                        }
                                    }
                                    if(status == 2)
                                    {
                                        cleardevice();
                                        setfillstyle(SOLID_FILL,LIGHTCYAN);
                                        rectangle(0,0,getmaxx(),getmaxy());
                                        floodfill(1,1,LIGHTCYAN);
                                        setbkcolor(LIGHTCYAN);
                                        setcolor(BLACK);
                                        settextstyle(2,HORIZ_DIR,10);
                                        settextjustify(1,1);
                                        outtextxy(getmaxx() / 2 , getmaxy() / 2 - 50, "LEVEL 1");
                                        settextstyle(2,HORIZ_DIR,10);
                                        outtextxy(getmaxx()/2,(getmaxy()/2),"-> LEVEL 2 <-");
                                        settextstyle(2,HORIZ_DIR,10);
                                        outtextxy(getmaxx()/2,(getmaxy()/2) + 50 ,"LEVEL 3");
                                        choices = getch();
                                        if(choices == 13)
                                        {
                                            level = 2;
                                            return level;
                                        }
                                    }
                                }

                            }
                        }
                    }

                }
            }
    }
}
    int lifedisplay()
    {
        if(status == 3)
        {
            setbkcolor(LIGHTCYAN);
            setcolor(BLACK);
            settextstyle(2,HORIZ_DIR,8);
            outtextxy(35,20,"Life : ");
            readimagefile("Heart(1).gif",60,0,90,30);
            readimagefile("Heart(1).gif",90,0,120,30);
            readimagefile("Heart(1).gif",120,0,150,30);
        }
        if(status == 2)
        {
            setbkcolor(LIGHTCYAN);
            setcolor(BLACK);
            settextstyle(2,HORIZ_DIR,8);
            outtextxy(35,20,"Life : ");
            readimagefile("Heart(1).gif",60,0,90,30);
            readimagefile("Heart(1).gif",90,0,120,30);
        }
        if(status == 1)
        {
            setbkcolor(LIGHTCYAN);
            setcolor(BLACK);
            settextstyle(2,HORIZ_DIR,8);
            outtextxy(35,20,"Life : ");
            readimagefile("Heart(1).gif",60,0,90,30);
        }
        if(status < 0)
        {
            status = 0;
        }
    }
        void lifedisplayalien()
        {
            if(statusalien == 6)
            {
                setbkcolor(LIGHTCYAN);
                setcolor(BLACK);
                settextstyle(2,HORIZ_DIR,8);
                outtextxy(getmaxx()-285,20,"Alien's Life : ");
                readimagefile("Heart(1).gif",getmaxx()-210,0,getmaxx()-180,30);
                readimagefile("Heart(1).gif",getmaxx()-180,0,getmaxx()-150,30);
                readimagefile("Heart(1).gif",getmaxx()-150,0,getmaxx()-120,30);
                readimagefile("Heart(1).gif",getmaxx()-120,0,getmaxx()-90,30);
                readimagefile("Heart(1).gif",getmaxx()-90,0,getmaxx()-60,30);
                readimagefile("Heart(1).gif",getmaxx()-60,0,getmaxx()-30,30);
            }
            if(statusalien == 5)
            {
                setbkcolor(LIGHTCYAN);
                setcolor(BLACK);
                settextstyle(2,HORIZ_DIR,8);
                outtextxy(getmaxx()-285,20,"Alien's Life : ");
                readimagefile("Heart(1).gif",getmaxx()-210,0,getmaxx()-180,30);
                readimagefile("Heart(1).gif",getmaxx()-180,0,getmaxx()-150,30);
                readimagefile("Heart(1).gif",getmaxx()-150,0,getmaxx()-120,30);
                readimagefile("Heart(1).gif",getmaxx()-120,0,getmaxx()-90,30);
                readimagefile("Heart(1).gif",getmaxx()-90,0,getmaxx()-60,30);
            }

            if(statusalien == 4)
            {
                setbkcolor(LIGHTCYAN);
                setcolor(BLACK);
                settextstyle(2,HORIZ_DIR,8);
                outtextxy(getmaxx()-285,20,"Alien's Life : ");
                readimagefile("Heart(1).gif",getmaxx()-210,0,getmaxx()-180,30);
                readimagefile("Heart(1).gif",getmaxx()-180,0,getmaxx()-150,30);
                readimagefile("Heart(1).gif",getmaxx()-150,0,getmaxx()-120,30);
                readimagefile("Heart(1).gif",getmaxx()-120,0,getmaxx()-90,30);
            }
            if(statusalien ==3)
            {
                setbkcolor(LIGHTCYAN);
                setcolor(BLACK);
                settextstyle(2,HORIZ_DIR,8);
                outtextxy(getmaxx()-285,20,"Alien's Life : ");
                readimagefile("Heart(1).gif",getmaxx()-210,0,getmaxx()-180,30);
                readimagefile("Heart(1).gif",getmaxx()-180,0,getmaxx()-150,30);
                readimagefile("Heart(1).gif",getmaxx()-150,0,getmaxx()-120,30);
            }
            if(statusalien == 2)
            {
                setbkcolor(LIGHTCYAN);
                setcolor(BLACK);
                settextstyle(2,HORIZ_DIR,8);
                outtextxy(getmaxx()-285,20,"Alien's Life : ");
                readimagefile("Heart(1).gif",getmaxx()-210,0,getmaxx()-180,30);
                readimagefile("Heart(1).gif",getmaxx()-180,0,getmaxx()-150,30);
            }
            if(statusalien == 1)
            {
                setbkcolor(LIGHTCYAN);
                setcolor(BLACK);
                settextstyle(2,HORIZ_DIR,8);
                outtextxy(getmaxx()-285,20,"Alien's Life : ");
                readimagefile("Heart(1).gif",getmaxx()-210,0,getmaxx()-180,30);
            }
            if(statusalien < 0)
            {
                statusalien = 0;
            }
        }
    void gameover()
    {
            cleardevice();
            setbkcolor(LIGHTRED);
            setcolor(BLACK);
            settextstyle(2,HORIZ_DIR,30);
            outtextxy(getmaxx()/2,getmaxy()/2-50,"GAME OVER");
    }
    void Alienwin()
    {
            cleardevice();
            setbkcolor(LIGHTGREEN);
            setcolor(BLACK);
            settextstyle(2,HORIZ_DIR,30);
            outtextxy(getmaxx()/2,getmaxy()/2-50,"YOU WIN");
    }
    void pagelevel1()
    {
            cleardevice();
            setbkcolor(LIGHTCYAN);
            setcolor(BLACK);
            settextstyle(2,HORIZ_DIR,30);
            outtextxy(getmaxx()/2,getmaxy()/2,"LEVEL 1");
            delay(3000);
    }
    void pagelevel2()
    {
            cleardevice();
            setbkcolor(LIGHTCYAN);
            setcolor(BLACK);
            settextstyle(2,HORIZ_DIR,30);
            outtextxy(getmaxx()/2,getmaxy()/2,"LEVEL 2");
            delay(3000);
    }
    void pagelevel3()
    {
            cleardevice();
            cleardevice();
            setbkcolor(LIGHTCYAN);
            setcolor(BLACK);
            settextstyle(2,HORIZ_DIR,30);
            outtextxy(getmaxx()/2,getmaxy()/2,"LEVEL 3");
            delay(3000);
    }
};

int main()
{
    DWORD maxX = GetSystemMetrics(SM_CXSCREEN);
    DWORD maxY = GetSystemMetrics(SM_CYSCREEN);
    int page=0;
    int gameover = 0;
    int win = 0;
    initwindow(maxX,maxY);
    Ccar car1;
    bullet peluru[50];
    bullet roket[15];
    Cmusuhpesawat pesawatmusuh[5];
    Cmusuhmobil mobilmusuh[5];
    UserInterface mainmenu;
    UserInterface life;
    UFO bulletalien[4];
    UFO ufo;
    //mainmenu.backgroundgedung();
    mainmenu.gametitle();
    while(mainmenu.level == 1)
    {
        mainmenu.pagelevel1();
        while(1)
        {
        setactivepage(page);
        setvisualpage(1-page);
        cleardevice();

        readimagefile("dd1c3d16532917.562ad5374e593-min(1).gif",0,0,getmaxx(),getmaxy());
        mainmenu.scoredisplay();
        car1.mobil();
        car1.move();
        life.lifedisplay();

            for(int i = 0;i<50;i++)
            {
                peluru[i].controlpeluru(x,y,peluru[i].statsenjata());
            }
            for(int i = 0;i<3;i++)
            {
                int x_hitbox1 = mobilmusuh[i].xmobil+20;
                int x_hitbox2 = mobilmusuh[i].xmobil+300;
                int y_hitbox1 = mobilmusuh[i].ymobil-125;
                int y_hitbox2 = mobilmusuh[i].ymobil+60;
                //rectangle(mobilmusuh.xmobil+20,mobilmusuh.ymobil-125,mobilmusuh.xmobil+300,mobilmusuh.ymobil+60;);
                for(int j = 0;j<50;j++)
                {
                        if( peluru[j].xp >= x_hitbox1 &&  peluru[j].xp <= x_hitbox2)
                        {
                            mobilmusuh[i].xmobil = getmaxx() + 500;
                            mobilmusuh[i].ymobil = getmaxy() + 500;
                            peluru[j].xp = getmaxx()+1000;
                            peluru[j].yp = getmaxy()+1000;
                            mainmenu.score+=1;
                        }
                }
            }
            for(int i = 0;i<15;i++)
            {
                roket[i].controlroket(x,y,roket[i].statsenjata());
            }

            for(int i = 0;i<3;i++)
            {
                int x_hitbox_roket1 = pesawatmusuh[i].xpesawat - 400;
                int x_hitbox_roket2 = pesawatmusuh[i].xpesawat + 60;
                int y_hitbox_roket1 = pesawatmusuh[i].ypesawat - 175;
                int y_hitbox_roket2 = pesawatmusuh[i].ypesawat - 15;
                for(int j = 0;j<15;j++)
                    {
                        if(roket[j].xroket >= x_hitbox_roket1 && roket[j].xroket <= x_hitbox_roket2 && roket[j].yroket >= y_hitbox_roket1 && roket[j].yroket <= y_hitbox_roket2)
                        {
                        mainmenu.score+=2;
                        pesawatmusuh[i].xpesawat = -1000;
                        pesawatmusuh[i].ypesawat = -1000;
                        roket[j].xroket = getmaxx()+1000;
                        roket[j].yroket = getmaxy()+1000;
                        }
                    }
            }

        for(int i = 0;i<3;i++)
        {
            mobilmusuh[i].musuhmobil();
            mobilmusuh[i].gerakmusuhmobil();
            int x_hitboxmc1 = x-55;
            int x_hitboxmc2 = x+150;
            int y_hitboxmc1 = y-50;
            int y_hitboxmc2 = y+55;
            if(stat == 0)
            {
                    if(mobilmusuh[i].xmobil >= x_hitboxmc1 && mobilmusuh[i].xmobil <= x_hitboxmc2 && mobilmusuh[i].ymobil>= y_hitboxmc1 && mobilmusuh[i].ymobil<= y_hitboxmc2)
                    {
                            life.status = life.status - 1;
                            mobilmusuh[i].xmobil = getmaxx() + 250;
                            mobilmusuh[i].ymobil = getmaxy() + 250;

                    }
            }
            if(stat == 1)
            {
                    if(mobilmusuh[i].xmobil >= x_hitboxmc1 && mobilmusuh[i].xmobil <= x_hitboxmc2 && mobilmusuh[i].ymobil >= y_hitboxmc1 && mobilmusuh[i].ymobil <= y_hitboxmc2)
                    {
                        mobilmusuh[i].xmobil = getmaxx() + 250;
                        mobilmusuh[i].ymobil = getmaxy() + 250;
                        life.status = life.status - 1;
                    }
            }

            if(stat == 2)
            {
                    if(mobilmusuh[i].xmobil > x_hitboxmc1 && mobilmusuh[i].xmobil < x_hitboxmc2 && mobilmusuh[i].ymobil > y_hitboxmc1 && mobilmusuh[i].ymobil < y_hitboxmc2)
                    {
                        mobilmusuh[i].xmobil = getmaxx() + 250;
                        mobilmusuh[i].ymobil = getmaxy() + 250;
                        life.status = life.status - 1;
                    }
            }

        }
        for(int i = 0;i<3;i++)
        {
            pesawatmusuh[i].musuhpesawat();
            pesawatmusuh[i].gerakmusuhpesawatkiri();
            pesawatmusuh[i].controlroketmusuh(pesawatmusuh[i].xpesawat,pesawatmusuh[i].ypesawat);
            int x_hitboxmc1 = x-55;
            int x_hitboxmc2 = x+150;
            int y_hitboxmc1 = y-50;
            int y_hitboxmc2 = y+55;
            if(stat == 0)
            {
                    if(pesawatmusuh[i].xroketmusuh >= x_hitboxmc1 && pesawatmusuh[i].xroketmusuh <= x_hitboxmc2 && pesawatmusuh[i].yroketmusuh+70 >= y_hitboxmc1 && pesawatmusuh[i].yroketmusuh+70 <= y_hitboxmc2)
                    {
                        pesawatmusuh[i].xroketmusuh = getmaxx() + 250;
                        pesawatmusuh[i].yroketmusuh = getmaxy() + 250;
                        life.status = life.status - 1;
                    }

            }
            if(stat == 1)
            {
//                for(int j = 0;j<3;j++)
//                {
                    if(pesawatmusuh[i].xroketmusuh >= x_hitboxmc1 && pesawatmusuh[i].xroketmusuh <= x_hitboxmc2 && pesawatmusuh[i].yroketmusuh+70 >= y_hitboxmc1 && pesawatmusuh[i].yroketmusuh+70 <= y_hitboxmc2)
                    {
                        pesawatmusuh[i].xroketmusuh = getmaxx() + 250;
                        pesawatmusuh[i].yroketmusuh = getmaxy() + 250;
                        life.status = life.status - 1;
                    }
                //}
            }
            if(stat == 2)
            {

                int x_hitboxmode2_1 = x-20;
                int x_hitboxmode2_2 = x+60;
                int y_hitboxmode2_1 = y-130;
                int y_hitboxmode2_2 = y-50;
                if((pesawatmusuh[i].xroketmusuh >= x_hitboxmc1 && pesawatmusuh[i].xroketmusuh <= x_hitboxmc2 && pesawatmusuh[i].yroketmusuh >= y_hitboxmc1 && pesawatmusuh[i].yroketmusuh <= y_hitboxmc2)
                   || (pesawatmusuh[i].xroketmusuh >= x_hitboxmode2_1 && pesawatmusuh[i].xroketmusuh <= x_hitboxmode2_2 && pesawatmusuh[i].yroketmusuh >= y_hitboxmode2_1 && pesawatmusuh[i].yroketmusuh <= y_hitboxmode2_2))
                   {
                        pesawatmusuh[i].xroketmusuh = getmaxx() + 250;
                        pesawatmusuh[i].yroketmusuh = getmaxy() + 250;
                        life.status = life.status - 1;
                   }
            }

        }

        if(delaybullet != 0)
        {
            delaybullet = delaybullet -1;
        }
        if(delayroket != 0 )
        {
            delayroket = delayroket - 1;
        }

        if(delayroketmusuh != 0)
        {
            delayroketmusuh = delayroketmusuh -1;
        }
        if(life.status == 0)
        {
            gameover = 1;
            break;
        }
        if(life.score == 5)
        {
            win = 1;
            break;
        }
        page=1-page;


        delay(30);
        }
        while(gameover == 1)
        {
            setactivepage(page);
            setvisualpage(1-page);
            mainmenu.gameover();
            delay(30);
            page=1-page;
        }
        while(win == 1)
        {
            setactivepage(page);
            setvisualpage(1-page);
            mainmenu.Alienwin();
            delay(30);
            page=1-page;
        }
    }
 while(mainmenu.level == 2)
    {
        mainmenu.pagelevel2();
        while(1)
        {
        setactivepage(page);
        setvisualpage(1-page);
        cleardevice();

        readimagefile("dd1c3d16532917.562ad5374e593-min(1).gif",0,0,getmaxx(),getmaxy());
        mainmenu.scoredisplay();
        car1.mobil();
        car1.move();
        life.lifedisplay();

            for(int i =0;i<50;i++)
            {
                 peluru[i].controlpeluru(x,y,peluru[i].statsenjata());
            }

            for(int i = 0;i<4;i++)
            {
                int x_hitbox1 = mobilmusuh[i].xmobil+20;
                int x_hitbox2 = mobilmusuh[i].xmobil+300;
                int y_hitbox1 = mobilmusuh[i].ymobil-125;
                int y_hitbox2 = mobilmusuh[i].ymobil+60;;
                for(int j = 0;j<50;j++)
                {
                        if( peluru[j].xp >= x_hitbox1 &&  peluru[j].xp <= x_hitbox2)
                        {
                            mobilmusuh[i].xmobil = getmaxx() + 500;
                            mobilmusuh[i].ymobil = getmaxy() + 500;
                            peluru[j].xp = getmaxx()+1000;
                            peluru[j].yp = getmaxy()+1000;
                            mainmenu.score+=1;
                            if(mainmenu.score == 100)
                            {
                                closegraph();
                            }

                        }
                }
            }

            for(int i = 0;i<15;i++)
            {
                roket[i].controlroket(x,y,roket[i].statsenjata());
            }

            for(int i = 0;i<5;i++)
            {
                int x_hitbox_roket1 = pesawatmusuh[i].xpesawat - 400;
                int x_hitbox_roket2 = pesawatmusuh[i].xpesawat + 60;
                int y_hitbox_roket1 = pesawatmusuh[i].ypesawat - 175;
                int y_hitbox_roket2 = pesawatmusuh[i].ypesawat - 15;
                for(int j = 0;j<15;j++)
                    {
                        if(roket[j].xroket >= x_hitbox_roket1 && roket[j].xroket <= x_hitbox_roket2 && roket[j].yroket >= y_hitbox_roket1 && roket[j].yroket <= y_hitbox_roket2)
                        {
                        mainmenu.score+=2;
                        pesawatmusuh[i].xpesawat = -1000;
                        pesawatmusuh[i].ypesawat = -1000;
                        roket[i].xroket = getmaxx()+1000;
                        roket[i].yroket = getmaxy()+1000;
                        }
                }
            }

        for(int i = 0;i<4;i++)
        {
            mobilmusuh[i].musuhmobil();
            mobilmusuh[i].gerakmusuhmobil();
            int x_hitboxmc1 = x-55;
            int x_hitboxmc2 = x+150;
            int y_hitboxmc1 = y-50;
            int y_hitboxmc2 = y+55;
            if(stat == 0)
            {
                    if(mobilmusuh[i].xmobil >= x_hitboxmc1 && mobilmusuh[i].xmobil <= x_hitboxmc2 && mobilmusuh[i].ymobil>= y_hitboxmc1 && mobilmusuh[i].ymobil<= y_hitboxmc2)
                    {
                            life.status = life.status - 1;
                            mobilmusuh[i].xmobil = getmaxx() + 250;
                            mobilmusuh[i].ymobil = getmaxy() + 250;

                    }
            }
            if(stat == 1)
            {
                    if(mobilmusuh[i].xmobil >= x_hitboxmc1 && mobilmusuh[i].xmobil <= x_hitboxmc2 && mobilmusuh[i].ymobil >= y_hitboxmc1 && mobilmusuh[i].ymobil <= y_hitboxmc2)
                    {
                        mobilmusuh[i].xmobil = getmaxx() + 250;
                        mobilmusuh[i].ymobil = getmaxy() + 250;
                        life.status = life.status - 1;
                    }
            }

            if(stat == 2)
            {
                    if(mobilmusuh[i].xmobil > x_hitboxmc1 && mobilmusuh[i].xmobil < x_hitboxmc2 && mobilmusuh[i].ymobil > y_hitboxmc1 && mobilmusuh[i].ymobil < y_hitboxmc2)
                    {
                        mobilmusuh[i].xmobil = getmaxx() + 250;
                        mobilmusuh[i].ymobil = getmaxy() + 250;
                        life.status = life.status - 1;
                    }
            }

        }
        for(int i = 0;i<5;i++)
        {
            pesawatmusuh[i].musuhpesawat();
            pesawatmusuh[i].gerakmusuhpesawatkiri();
            pesawatmusuh[i].controlroketmusuh(pesawatmusuh[i].xpesawat,pesawatmusuh[i].ypesawat);
            int x_hitboxmc1 = x-55;
            int x_hitboxmc2 = x+150;
            int y_hitboxmc1 = y-50;
            int y_hitboxmc2 = y+55;
            if(stat == 0)
            {
                    if(pesawatmusuh[i].xroketmusuh >= x_hitboxmc1 && pesawatmusuh[i].xroketmusuh <= x_hitboxmc2 && pesawatmusuh[i].yroketmusuh+70 >= y_hitboxmc1 && pesawatmusuh[i].yroketmusuh+70 <= y_hitboxmc2)
                    {
                        pesawatmusuh[i].xroketmusuh = getmaxx() + 250;
                        pesawatmusuh[i].yroketmusuh = getmaxy() + 250;
                        life.status = life.status - 1;
                    }
            }
            if(stat == 1)
            {

                    if(pesawatmusuh[i].xroketmusuh >= x_hitboxmc1 && pesawatmusuh[i].xroketmusuh <= x_hitboxmc2 && pesawatmusuh[i].yroketmusuh+70 >= y_hitboxmc1 && pesawatmusuh[i].yroketmusuh+70 <= y_hitboxmc2)
                    {
                        pesawatmusuh[i].xroketmusuh = getmaxx() + 250;
                        pesawatmusuh[i].yroketmusuh = getmaxy() + 250;
                        life.status = life.status - 1;
                    }
            }
            if(stat == 2)
            {

                int x_hitboxmode2_1 = x-20;
                int x_hitboxmode2_2 = x+60;
                int y_hitboxmode2_1 = y-130;
                int y_hitboxmode2_2 = y-50;
                if((pesawatmusuh[i].xroketmusuh >= x_hitboxmc1 && pesawatmusuh[i].xroketmusuh <= x_hitboxmc2 && pesawatmusuh[i].yroketmusuh >= y_hitboxmc1 && pesawatmusuh[i].yroketmusuh <= y_hitboxmc2)
                   || (pesawatmusuh[i].xroketmusuh >= x_hitboxmode2_1 && pesawatmusuh[i].xroketmusuh <= x_hitboxmode2_2 && pesawatmusuh[i].yroketmusuh >= y_hitboxmode2_1 && pesawatmusuh[i].yroketmusuh <= y_hitboxmode2_2))
                   {
                        pesawatmusuh[i].xroketmusuh = getmaxx() + 250;
                        pesawatmusuh[i].yroketmusuh = getmaxy() + 250;
                        life.status = life.status - 1;
                   }
            }

        }

        if(delaybullet != 0)
        {
            delaybullet = delaybullet -1;
        }
        if(delayroket != 0 )
        {
            delayroket = delayroket - 1;
        }

        if(delayroketmusuh != 0)
        {
            delayroketmusuh = delayroketmusuh -1;
        }
        if(life.status == 0)
        {
            gameover = 1;
            break;
        }
        page=1-page;


        delay(30);

        }

        while(gameover == 1)
        {
            setactivepage(page);
            setvisualpage(1-page);
            mainmenu.gameover();
            delay(30);
            page=1-page;
        }
    }
    if(mainmenu.level == 3)
    {
        mainmenu.pagelevel3();
        while(1)
        {
            setactivepage(page);
            setvisualpage(1-page);
            cleardevice();
            readimagefile("dd1c3d16532917.562ad5374e593-min(1).gif",0,0,getmaxx(),getmaxy());
            mainmenu.scoredisplay();
            car1.mobil();
            car1.move();
            ufo.drawalien();
            ufo.gerakalien();
            life.lifedisplay();
            life.lifedisplayalien();

            for(int i =0;i<50;i++)
            {
                peluru[i].controlpeluru(x,y,peluru[i].statsenjata());
            }
            for(int i = 0;i<1;i++)
            {
                int x_hitbox1 = mobilmusuh[i].xmobil+20;
                int x_hitbox2 = mobilmusuh[i].xmobil+300;
                int y_hitbox1 = mobilmusuh[i].ymobil-125;
                int y_hitbox2 = mobilmusuh[i].ymobil+60;
                for(int j = 0;j<50;j++)
                {
                        if( peluru[j].xp >= x_hitbox1 &&  peluru[j].xp <= x_hitbox2)
                        {
                            mobilmusuh[i].xmobil = getmaxx() + 500;
                            mobilmusuh[i].ymobil = getmaxy() + 500;
                            peluru[j].xp = getmaxx()+1000;
                            peluru[j].yp = getmaxy()+1000;
                            mainmenu.score+=1;
                }
                }
            }
            for(int i= 0;i<15;i++)
            {
                roket[i].controlroket(x,y,roket[i].statsenjata());
            }
            for(int i = 0;i<1;i++)
            {
                int x_hitbox_alien_1 = ufo.xalien-190;
                int x_hitbox_alien_2 = ufo.xalien+190;
                int y_hitbox_alien_1 = ufo.yalien-150;
                int y_hitbox_alien_2 = ufo.yalien+60;
                for(int j = 0;j<15;j++)
                {
                    if(roket[j].xroket >= x_hitbox_alien_1 && roket[j].xroket <= x_hitbox_alien_2 && roket[j].yroket >= y_hitbox_alien_1 && roket[j].yroket <= y_hitbox_alien_2)
                    {
                        life.statusalien = life.statusalien - 1;
                        roket[j].xroket = -2000;
                        roket[j].yroket = -2000;
                        mainmenu.score = mainmenu.score+10;
                    }
                }


            }
            for(int i= 0; i<4;i++)
            {
                bulletalien[i].controlroketalien(ufo.xalien,ufo.yalien);
                int x_hitboxmc1 = x-55;
                int x_hitboxmc2 = x+150;
                int y_hitboxmc1 = y-50;
                int y_hitboxmc2 = y+55;
                if(stat == 0)
                {
                    if((bulletalien[i].xroketalien1 >= x_hitboxmc1 && bulletalien[i].xroketalien1 <= x_hitboxmc2 && bulletalien[i].yroketalien1+70 >= y_hitboxmc1 && bulletalien[i].yroketalien1+70 <= y_hitboxmc2)
                       || (bulletalien[i].xroketalien2 >= x_hitboxmc2 && bulletalien[i].xroketalien2 <= x_hitboxmc2 && bulletalien[i].yroketalien2+70 >= y_hitboxmc1 && bulletalien[i].yroketalien2+70 <= y_hitboxmc2))
                    {
                        bulletalien[i].xroketalien1 = getmaxx() + 250;
                        bulletalien[i].yroketalien1 = getmaxy() + 250;
                        bulletalien[i].xroketalien2 = getmaxx() + 250;
                        bulletalien[i].yroketalien2 = getmaxx() + 250;
                        life.status = life.status - 1;
                    }
            }
            if(stat == 1)
            {
                    if((bulletalien[i].xroketalien1 >= x_hitboxmc1 && bulletalien[i].xroketalien1 <= x_hitboxmc2 && bulletalien[i].yroketalien1+70 >= y_hitboxmc1 && bulletalien[i].yroketalien1+70 <= y_hitboxmc2)
                       || (bulletalien[i].xroketalien2 >= x_hitboxmc1 && bulletalien[i].xroketalien2 <= x_hitboxmc2 && bulletalien[i].yroketalien2+70 >= y_hitboxmc1 && bulletalien[i].yroketalien2+70 <= y_hitboxmc2))
                    {
                        bulletalien[i].xroketalien1 = getmaxx() + 250;
                        bulletalien[i].yroketalien1 = getmaxx() + 250;
                        bulletalien[i].xroketalien2 = getmaxx() + 250;
                        bulletalien[i].yroketalien2 = getmaxx() + 250;
                        life.status = life.status - 1;
                    }

            }
            if(stat == 2)
            {

                int x_hitboxmode2_1 = x-20;
                int x_hitboxmode2_2 = x+60;
                int y_hitboxmode2_1 = y-130;
                int y_hitboxmode2_2 = y-50;

                if(((bulletalien[i].xroketalien1 >= x_hitboxmc1 && bulletalien[i].xroketalien1 <= x_hitboxmc2 && bulletalien[i].yroketalien1+70 >= y_hitboxmc1 && bulletalien[i].yroketalien1+70 <= y_hitboxmc2)
                   || (bulletalien[i].xroketalien1 >= x_hitboxmode2_1 && bulletalien[i].xroketalien1 <= x_hitboxmode2_2 && bulletalien[i].yroketalien1 >= y_hitboxmode2_1 && bulletalien[i].yroketalien1 <= y_hitboxmode2_2))
                   && (bulletalien[i].xroketalien2 >= x_hitboxmc1 && bulletalien[i].xroketalien2 <= x_hitboxmc2 && bulletalien[i].yroketalien2+70 >= y_hitboxmc1 && bulletalien[i].yroketalien2+70 <= y_hitboxmc2)
                   || (bulletalien[i].xroketalien2 >= x_hitboxmode2_1 && bulletalien[i].xroketalien2 <= x_hitboxmode2_2 && bulletalien[i].yroketalien2 >= y_hitboxmode2_1 && bulletalien[i].yroketalien2 <= y_hitboxmode2_2))

                   {
                        bulletalien[i].xroketalien1 = getmaxx() + 250;
                        bulletalien[i].yroketalien1 = getmaxx() + 250;
                        bulletalien[i].xroketalien2 = getmaxx() + 250;
                        bulletalien[i].yroketalien2 = getmaxx() + 250;
                        life.status = life.status - 1;
                   }
            }

            }

            for(int i = 0;i<1;i++)
            {
                mobilmusuh[i].musuhmobil();
                mobilmusuh[i].gerakmusuhmobil();
                int x_hitboxmc1 = x-55;
                int x_hitboxmc2 = x+150;
                int y_hitboxmc1 = y-50;
                int y_hitboxmc2 = y+55;
                if(stat == 0)
            {
                    if(mobilmusuh[i].xmobil >= x_hitboxmc1 && mobilmusuh[i].xmobil <= x_hitboxmc2 && mobilmusuh[i].ymobil>= y_hitboxmc1 && mobilmusuh[i].ymobil<= y_hitboxmc2)
                    {
                            life.status = life.status - 1;
                            mobilmusuh[i].xmobil = getmaxx() + 250;
                            mobilmusuh[i].ymobil = getmaxy() + 250;

                    }
            }
            if(stat == 1)
            {
                    if(mobilmusuh[i].xmobil >= x_hitboxmc1 && mobilmusuh[i].xmobil <= x_hitboxmc2 && mobilmusuh[i].ymobil >= y_hitboxmc1 && mobilmusuh[i].ymobil <= y_hitboxmc2)
                    {
                        mobilmusuh[i].xmobil = getmaxx() + 250;
                        mobilmusuh[i].ymobil = getmaxy() + 250;
                        life.status = life.status - 1;
                    }
            }

            if(stat == 2)
            {
                    if(mobilmusuh[i].xmobil > x_hitboxmc1 && mobilmusuh[i].xmobil < x_hitboxmc2 && mobilmusuh[i].ymobil > y_hitboxmc1 && mobilmusuh[i].ymobil < y_hitboxmc2)
                    {
                        mobilmusuh[i].xmobil = getmaxx() + 250;
                        mobilmusuh[i].ymobil = getmaxy() + 250;
                        life.status = life.status - 1;
                    }
            }

        }

            if(delaybullet != 0)
            {
                delaybullet = delaybullet -1;
            }
            if(delayroket != 0 )
            {
                delayroket = delayroket - 1;
            }
            if(delayroketalien != 0)
            {
                delayroketalien = delayroketalien - 1;
            }
            if(life.status == 0)
            {
                gameover = 1;
                break;
            }
            if(life.statusalien == 0)
            {
                win = 1;
                break;
            }

            page=1-page;
            delay(30);
        }
            while(gameover == 1)
            {
                setactivepage(page);
                setvisualpage(1-page);
                mainmenu.gameover();
                delay(30);
                page=1-page;
            }
            while(win == 1)
            {
                setactivepage(page);
                setvisualpage(1-page);
                delay(30);
                mainmenu.Alienwin();
                page=1-page;
            }

    }
}



