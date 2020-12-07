#include <SFML/Graphics.hpp>
#include<time.h>
#include<iostream>
#include "tetrisBlocks.h"
#include<cmath>
#include<cstring>
#define Log(x) cout<<x<<endl
#define Log2(x,y) cout<<x<<" "<<y<<endl

using namespace std;
using namespace sf;

struct coord{int x,y;}a[4];//coordonate piesa curenta
int p,speed,score=0;//p->piesa curenta,speed=viteza pe verticala
const unsigned int appH=430,appW=530,gridH=30,gridW=14;//dimensiunile ferestrei si a terenului, btw appH si appW is inversate, appH-width,iar appW-height, dar eh asta e soarta
bool v[gridH+1][gridW+1],dead;

void spawn();//trebuie sa o declar dinainte pentru a o folosi in checkEnd // sila sa o muta cu totul LMAO

int frames = 4,aux;//frames -> viteza de coborare, aux retine viteza cand apesi DOWN
char s[50];//text score
int offsetX=30;//offset sa mute totul pentru a lasa spatiu ramei

void checkEnd()//verifica daca piesa a atins pamant/alta piesa
{
    for(int i=0;i<4;i++)
        if(v[a[i].y/17][a[i].x/17]==true)
    {
        for(int j=0;j<4;j++)//daca da, atunci o salveaza si spawneaza una noua/ de asemnea viteza revine la normal
            v[(a[j].y-17)/17][a[j].x/17]=true;
        spawn();
        speed=0;
        frames = aux;
        return ;
    }
}

int check(int m)//verifica daca miscarea e posibila
{
    int mi=99999,ma=0;
     for(int i=0;i<4;i++)
    {
       if(a[i].x+m<0||a[i].x+m>gridW*17||v[a[i].y/17][(a[i].x+m)/17]==true||v[(a[i].y+17)/17][(a[i].x+m)/17]==true){return 0;}
    }
    return m;
}

void checkLines()//verifica daca avem vreo linie completa
{
    bool ok =true;
    for(int i=gridH-1;i>=0;i--)
    {
    ok=true;
    for(int j=0;j<=gridW;j++)
        if(v[i][j]==false)
            {
              ok=false;
            }
    if(ok==true)
        {
            score+=10;
            if(score%100==0)
            {frames++;}//crestem viteza cu scorul
            for(int q=i;q>=1;q--)
                for(int k=0;k<=gridW;k++)
                {
                    v[q][k]=v[q-1][k];
                }
        }
    }

}

void spawn()//spawn la noua piesa
{
    int i,j;
    p=rand()%19;;
    //Log(p);
    int index=0;
    switch(p)
    {
    case 0:
        //linie_O
        for(j=0;j<4;j++)
            if(linie_O[0][j]=='X')
            {
                a[index].x=j*17;
                a[index].y=0*17;
                index++;

            }
        break;
    case 15:
        //t_1
        for(i=0;i<2;i++)
            for(j=0;j<3;j++)
            if(t_1[i][j]=='X')
                 {
                a[index].x=j*17;
                a[index].y=i*17;
                index++;
            }
        break;
    case 4:
        //l_2
        for(i=0;i<2;i++)
            for(j=0;j<3;j++)
            if(l_2[i][j]=='X')
                 {
                a[index].x=j*17;
                a[index].y=i*17;
                index++;
            }
        break;
    case 8:
        //L_2
        for(i=0;i<2;i++)
            for(j=0;j<3;j++)
            if(L_2[i][j]=='X')
                 {
                a[index].x=j*17;
                a[index].y=i*17;
                index++;
            }
        break;
    case 2:
        //patrat
        for(i=0;i<2;i++)
            for(j=0;j<2;j++)
            if(patrat[i][j]=='X')
                 {
                a[index].x=j*17;
                a[index].y=i*17;
                index++;
            }
        break;
    case 11:
        //z_1
        for(i=0;i<2;i++)
            for(j=0;j<3;j++)
            if(z_1[i][j]=='X')
                 {
                a[index].x=j*17;
                a[index].y=i*17;
                index++;
            }
        break;
     case 3:
        //l_1
        for(i=0;i<3;i++)
            for(j=0;j<2;j++)
            if(l_1[i][j]=='X')
                 {
                a[index].x=j*17;
                a[index].y=i*17;
                index++;
            }
        break;
    case 5:
        //l_3
        for(i=0;i<3;i++)
            for(j=0;j<2;j++)
            if(l_3[i][j]=='X')
                 {
                a[index].x=j*17;
                a[index].y=i*17;
                index++;
            }
        break;
    case 6:
        //l_4
        for(i=0;i<2;i++)
            for(j=0;j<3;j++)
            if(l_4[i][j]=='X')
                 {
                a[index].x=j*17;
                a[index].y=i*17;
                index++;
            }
        break;
    case 1:
        //linie_V
        for(i=0;i<4;i++)
            if(linie_V[i][0]=='X')
                {
                    a[index].x=0*17;
                    a[index].y=i*17;
                    index++;
                }
        break;
    case 7:
        //L_1
        for(i=0;i<3;i++)
            for(j=0;j<2;j++)
            if(L_1[i][j]=='X')
                 {
                a[index].x=j*17;
                a[index].y=i*17;
                index++;
            }
        break;
    case 9:
        //L_3
        for(i=0;i<3;i++)
            for(j=0;j<2;j++)
            if(L_3[i][j]=='X')
                 {
                a[index].x=j*17;
                a[index].y=i*17;
                index++;
            }
        break;
    case 10:
        //L_4
        for(i=0;i<2;i++)
            for(j=0;j<3;j++)
            if(L_4[i][j]=='X')
                 {
                a[index].x=j*17;
                a[index].y=i*17;
                index++;
            }
        break;
    case 12:
        //z_2
        for(i=0;i<3;i++)
            for(j=0;j<2;j++)
            if(z_2[i][j]=='X')
                 {
                a[index].x=j*17;
                a[index].y=i*17;
                index++;
            }
        break;
    case 13:
        //z_3
        for(i=0;i<2;i++)
            for(j=0;j<3;j++)
            if(z_3[i][j]=='X')
                 {
                a[index].x=j*17;
                a[index].y=i*17;
                index++;
            }
        break;
    case 14:
        //z_4
        for(i=0;i<3;i++)
            for(j=0;j<2;j++)
            if(z_4[i][j]=='X')
                 {
                a[index].x=j*17;
                a[index].y=i*17;
                index++;
            }
        break;
    case 16:
        //t_2
        for(i=0;i<3;i++)
            for(j=0;j<2;j++)
            if(t_2[i][j]=='X')
                 {
                a[index].x=j*17;
                a[index].y=i*17;
                index++;
            }
        break;
    case 17:
        //t_3
        for(i=0;i<2;i++)
            for(j=0;j<3;j++)
            if(t_3[i][j]=='X')
                 {
                a[index].x=j*17;
                a[index].y=i*17;
                index++;
            }
        break;
    case 18:
        //t_4
        for(i=0;i<3;i++)
            for(j=0;j<2;j++)
            if(t_4[i][j]=='X')
                 {
                a[index].x=j*17;
                a[index].y=i*17;
                index++;
            }
        break;
    }

    for(index=0;index<4;index++)//pune piesa pe mijloc
        a[index].x+=(gridW/2-1)*17;
}

int main()
{
    int dif=0;
    bool verifRot;
    int moving=0;
    bool r=false;
    aux=4;
    srand((int)time(0));
    // Create the main window
    RenderWindow app(VideoMode(appH, appW), "CHETRIS",Style::Close|Style::Titlebar);
    app.setKeyRepeatEnabled(false);

    /*for(int i=0;i<4;i++){
        a[i].x=i*17;
        a[i].y=0;
    }*/
    spawn();
    // incarcam texturi si cream sprite-uri
    Texture t1,backT,frame;
    backT.loadFromFile("background1.png");
    frame.loadFromFile("frame.png");
    if (!t1.loadFromFile("tiles.png"))
        return EXIT_FAILURE;
    Sprite sprite(t1);Sprite Frame(frame);

    Font font;
    font.loadFromFile("pixelmix_bold.ttf");

    Sprite background(backT);
    //background.setScale(1.2,1);
    background.setPosition(offsetX,0);
    Frame.setOrigin(0,100);
    Frame.setScale(1.015,2);

    Text score_text;
    score_text.setFont(font);
    score_text.setCharacterSize(20);
    score_text.setFillColor(Color::White);
    score_text.setPosition(gridW*17+75,0);


    for(int i=0;i<=gridW;i++)//pamantul devine true pentru checkEnd
        v[gridH][i]=true;


	// Start the game loop
    score=0;
    while (app.isOpen())
    {
         app.setFramerateLimit(frames);
        // Process events
        Event event;
        speed = 17;//17 -> dimensiunea unui patrat
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == Event::Closed)
                app.close();
            if (event.type == Event::KeyPressed)//input
            {
			  if (event.key.code==Keyboard::Up) r=true;
			  else if (event.key.code==Keyboard::Left) moving=-17;
			  else if (event.key.code==Keyboard::Right) moving=+17;
			  else if (event.key.code==Keyboard::Down) {aux=frames; frames = 100;}
            }
        }
        dif = 0;

        if(dead==false)
        {
        if(r==true&&p!=2)//daca trebuie sa rotim si nu avem patrat
        {
		coord pp = a[1]; //center of rotation
		for (int i=0;i<4;i++)//sincer am copiat asta si n-o inteleg la acest moment cand scriu asta :))
		  {
			int x = a[i].y-pp.y;
			int y = a[i].x-pp.x;
			a[i].x = pp.x - x;
			a[i].y = pp.y + y;
			if(a[i].x < 0){  dif = max(abs(0 - a[i].x),dif); verifRot = false;}
			else if(a[i].x > gridW * 17){dif = max(abs((int)gridW*17 - a[i].x),dif); verifRot = true;}
			//retine difereenta cu care sunt in afara terenului
	 	  r=false;
        }}
        if(dif!=0)//in caz piesle s-au rotit in afara, ele trebuiesc mutate inapoi
            for(int j=0;j<4;j++)
            if(verifRot==false)
                a[j].x+=dif;
            else
                a[j].x-=dif;

        moving=check(moving);//verificam miscarea

        for(int i=0;i<4;i++){
        a[i].x=a[i].x + moving;
        a[i].y+=speed;
        //mutam piesa
        }

        checkEnd();//verificam daca am ajuns jos

        moving = 0;//resetam miscarea

        checkLines();//verificam daca avem linie

        // Clear screen
        app.clear();

        app.draw(background);
        app.draw(Frame);

        for(int i=0;i<4;i++)
        {sprite.setTextureRect(IntRect(1,1,17,17));
        sprite.setPosition(a[i].x+offsetX,a[i].y);
        app.draw(sprite);}//desenam

        for(int i=gridH;i>=0;i--)
        for(int j=0;j<=gridW;j++)
        if(v[i][j]==true)
        {
        if(i==0)
            dead=true;//daca se opreste piesa pe prima linie->murim
        sprite.setTextureRect(IntRect(1,1,17,17));
        sprite.setPosition(j*17+offsetX,i*17);
        app.draw(sprite);
        }

        char s1[100]="score:\n ";
        strcpy (s,to_string(score).c_str());
        strcat(s1,s);
        score_text.setString(s1);

        app.draw(score_text);}

        if(dead==true){//scorul cand mori
            char s[50];
        char s1[121]="Your score was:\n";
        strcpy (s,to_string(score).c_str());
        strcat(s1,s);
        score_text.setPosition(offsetX,180);
        score_text.setCharacterSize(30);
        score_text.setString(s1);

        app.draw(score_text);
        }

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
