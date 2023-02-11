#include<stdio.h>
#include<math.h>
#include<dos.h>
#include<string.h>
//#include<graphics.h>
#include<stdlib.h>
#define SUM 1
class percom
{
    public:
        long fact(double);
        double per(double,double);
        double com(double,double);
        double pw(double,double);

};
double percom::pw(double m,double n)
{
    double a=1;
    while(n!=0)
    {
        a*=m;
        n--;
    }
    return a;
}
long percom::fact(double x)
{
    if(x==1)
        return 1;
    else
        return x*fact(x-1);
}

double percom::per(double n,double r)
{
    return fact(n)/fact(n-r);
}
double percom::com(double n,double r)
{
    return fact(n)/(fact(r)*fact(n-r));
}
class mous
{
    public:
        union REGS i,o;
        int button,mousex,mousey;
        initmouse()
        {
            i.x.ax=0;
            int86(0x33,&i,&o);
            return(o.x.ax);
        }
        showmouseptr()
        {
            i.x.ax=1;
            int86(0x33,&i,&o);
            return 0;
        }
        void hidemouseptr()
        {
            i.x.ax=2;
            int86(0x33,&i,&o);
        }
        getmousepos(int *button,int *x,int *y)
        {
            i.x.ax=3;
            int86(0x33,&i,&o);
            *button=o.x.bx;
            *x=o.x.cx;
            *y=o.x.dx;
            return 0;
        }
};
class strn
{
    public:
        void strcut(char *a);
        void del(char *d);
};
void strn::strcut(char *a)
{
    a[9]='\0';
}
void strn::del(char *d)
{
    d[strlen(d)-1]='\0';
}

class calc:public mous,public strn,public percom
{
    private:
        int gd,gm,x,y,i,j;
    public:
        void display();
        void key();
        void but_change(int,int,int,int,int,int,char*);
        void restore_but(int,int,int,int,int,int,int,int,char*,char*);
        void but_change(int tx,int ty,int bx,int by,int lx,int ly,char *s,int lx1,int ly1,char *s1);
};

void calc::display()
{
    gd=DETECT;y=185;
    initgraph(&gd,&gm,"D:\\tc\\bgi");

    setcolor(9);
    setfillstyle(1,8);
    bar(40,110,597,130);    /*standard bar*/

    setfillstyle(1,7);

    bar(40,130,597,367);     /*main box*/
    setcolor(0);
    setfillstyle(1,0);
    bar(51,141,586,169);     /*Sub display*/


    for(i=0;i<4;i++)
    {
        x=50;
        for(j=0;j<10;j++)
        {
            setfillstyle(1,8);
            bar3d(x,y,x+50,y+40,1,1);
            if(j==4)
                x+=63;
            else
                x+=53;
        }
        y+=43;
    }

    key();

}
void calc::key()
{
    setcolor(15);
    char *str;
    outtextxy(225,115,"MY SCIENTIFIC CALCULATOR");

    //outtextxy(348,288,"1");
    y=288;
    int count=1;
    for(i=0;i<3;i++)
    {
        x=348;
        for(j=0;j<3;j++)
        {
            outtextxy(x,y,itoa(count,str,10));
            count++;
            x+=53;
        }
        y-=43;
    }
    outtextxy(555,202,"AC");
    outtextxy(498,202,"DEL");
    outtextxy(558,245,"/");
    outtextxy(558,288,"-");
    outtextxy(558,325,"%");
    outtextxy(558,340,"=");
    outtextxy(505,245,"*");
    outtextxy(505,288,"+");
    outtextxy(498,331,"ANS");
    outtextxy(347,331,"0");
    outtextxy(401,329,".");
    outtextxy(445,331,"EXP");
    outtextxy(268,203,"CONST");
    outtextxy(268,253,"CONVR");
    outtextxy(117,202,"STO");
    outtextxy(171,202,"RCL");
    outtextxy(228,202,"M+");
    outtextxy(220,253,"tan´");
    outtextxy(168,253,"cos´");
    outtextxy(115,253,"sin´");
    outtextxy(65,253,"(-)");
    outtextxy(70,296,"û");
    outtextxy(117,296,"x^y");
    outtextxy(170,296,"1/x");
    outtextxy(223,296,"nPr");
    outtextxy(276,296,"e^x");
    outtextxy(275,330,"tan");
    outtextxy(222,330,"cos");
    outtextxy(169,330,"sin");
    outtextxy(120,330,"ln");
    outtextxy(63,330,"log");
    setcolor(14);
    outtextxy(56,202,"SHIFT");
    outtextxy(284,238,"E");
    outtextxy(231,238,"D");
    outtextxy(178,238,"C");
    outtextxy(125,238,"B");
    outtextxy(72,238,"A");
    outtextxy(70,281,"xý");
    outtextxy(117,281,"x^3");
    outtextxy(178,281,"!");
    outtextxy(223,281,"nCr");
    outtextxy(284,281,"'");
    //setcolor(11);
    //settextstyle(0,0,2);
    //outtextxy(415,148,"1234567890");
    //settextstyle(0,0,2);
    //setcolor(4);
    //outtextxy(60,148,"Sin");
}
void calc::but_change(int tx,int ty,int bx,int by,int lx,int ly,char *s)
{

            hidemouseptr();
            setfillstyle(1,15);
            bar(tx,ty,bx,by);
            setcolor(0);
            outtextxy(lx,ly,s);
            showmouseptr();
}
void calc::but_change(int tx,int ty,int bx,int by,int lx,int ly,char *s,int lx1,int ly1,char *s1)
{

            hidemouseptr();
            setfillstyle(1,15);
            bar(tx,ty,bx,by);
            setcolor(0);
            outtextxy(lx,ly,s);
            setcolor(1);
            outtextxy(lx1,ly1,s1);
            setcolor(0);
            showmouseptr();
}
void calc::restore_but(int tx,int ty,int bx,int by,int lx,int ly,int lx1,int ly1,char *s,char *s1)
{

            hidemouseptr();
            setfillstyle(1,8);
            bar3d(tx,ty,bx,by,1,1);
            setcolor(15);
            outtextxy(lx,ly,s);
            setcolor(14);
            outtextxy(lx1,ly1,s1);
            showmouseptr();
}

void main()
{
    int mx,my,but;
    int key=0,key1=0;
    int ptx,pty,pbx,pby,plx,ply,plx1,ply1;
    int ncr=0,shift=0,on=0,npr=0,sub=0,add=0,mul=0,div=0,rcl=0,sto=0,equal=0;
    int vx=555,vy=152,count=0;
    long int var1,var2;
    double temp1,ans=0,a=0,b=0,c=0,d=0,e=0,m=0;
    char *input;
    input[0]='\0';        /*for(int k=0;k<count;k++)
                {
                    input[k]='\0';
                }*/


    char *pstr,*pstr1;
    char *svar,*ms,*stemp;

    int operation=0;
    calc ob;
    ob.display();
    ob.initmouse();

    ob.showmouseptr();

    for(;;)
    {
        ob.getmousepos(&but,&mx,&my);


        if(mx>537&&mx<587&&my>185&&my<225)
        {

            if(key!=1)
            {
            ob.restore_but(ptx,pty,pbx,pby,plx,ply,plx1,ply1,pstr,pstr1);
            key=1;
            ob.but_change(537,185,587,225,555,202,"AC");
            ptx=537;
            pty=185;
            pbx=587;
            pby=225;
            plx=555;
            ply=202;
            pstr="AC";
            plx1=0;
            ply1=0;
            pstr1="";
            }
            if(but==1&&on==0)
                on=1;

            if(but==1&&key1!=1&&shift==0)
            {
                input[0]='\0';
                temp1=0;npr=0,sto=0,rcl=0;
                sub=0,add=0,mul=0,div=0,equal=0;
                setfillstyle(1,0);
                bar(51,141,586,169);
                setfillstyle(1,0);
                bar(200,141,586,169);
                setcolor(11);
                outtextxy(555,152,"0");
                setcolor(0);
                count=0;
                //reset();
                key1=1;
                delay(100);
                //key1=0;
            }
            if(shift==1&&but==1&&key1!=1)
            {
                free(input);
                free(pstr);
                free(pstr1);
                exit(0);
            }

        }
        else if(mx>484&&mx<534&&my>185&&my<225&&on==1)
        {

            if(key!=2)
            {
            ob.restore_but(ptx,pty,pbx,pby,plx,ply,plx1,ply1,pstr,pstr1);
            key=2;
            ob.but_change(484,185,534,225,498,202,"DEL");
            ptx=484;
            pty=185;
            pbx=534;
            pby=225;
            plx=498;
            ply=202;
            pstr="DEL";
            plx1=0;
            ply1=0;
            pstr1="";
            }
            if(but==1&&key1!=2&&shift==0)
            {
                setfillstyle(1,0);
                bar(200,141,586,169);
                setcolor(11);
                ob.del(input);
                if(input[0]!='\0')
                outtextxy(vx-strlen(input)*8+8,vy,input);
                else
                outtextxy(555,152,"0");
                count--;
                setcolor(0);
                key1=2;
                delay(200);
                key1=0;
            }


        }
        else if(mx>428&&mx<478&&my>185&&my<225&&on==1)
        {

            if(key!=3)
            {
            ob.restore_but(ptx,pty,pbx,pby,plx,ply,plx1,ply1,pstr,pstr1);
            key=3;
            ob.but_change(431,185,481,225,454,202,"9");
            ptx=431;
            pty=185;
            pbx=481;
            pby=225;
            plx=454;
            ply=202;
            pstr="9";
            plx1=0;
            ply1=0;
            pstr1="";
            }
            if(count<9)
            if(but==1&&key1!=3&&shift==0)
            {
                //temp=temp*10+9;
                setfillstyle(1,0);
                bar(200,141,586,169);
                setcolor(11);
                strcat(input,pstr);
                outtextxy(vx-count*8,vy,input);
                count++;
                setcolor(0);
                key1=3;
                delay(200);
                key1=0;
            }

        }
        else if(mx>378&&mx<428&&my>185&&my<225&&on==1)
        {
            if(count<10)
            if(key!=4)
            {
            ob.restore_but(ptx,pty,pbx,pby,plx,ply,plx1,ply1,pstr,pstr1);
            key=4;
            ob.but_change(378,185,428,225,401,202,"8");
            ptx=378;
            pty=185;
            pbx=428;
            pby=225;
            plx=401;
            ply=202;
            pstr="8";
            plx1=0;
            ply1=0;
            pstr1="";
            }
            if(count<9)
            if(but==1&&key1!=4&&shift==0)
            {
                //temp=temp*10+8;
                setfillstyle(1,0);
                bar(200,141,586,169);
                setcolor(11);
                strcat(input,pstr);
                outtextxy(vx-count*8,vy,input);
                count++;
                setcolor(0);

                key1=4;
                delay(200);
                key1=0;
            }

        }
        else if(mx>325&&mx<375&&my>185&&my<225&&on==1)
        {

            if(key!=5)
            {
            ob.restore_but(ptx,pty,pbx,pby,plx,ply,plx1,ply1,pstr,pstr1);
            key=5;
            ob.but_change(325,185,375,225,348,202,"7");
            ptx=325;
            pty=185;
            pbx=375;
            pby=225;
            plx=348;
            ply=202;
            pstr="7";
            plx1=0;
            ply1=0;
            pstr1="";
            }
            if(but==1&&key1!=5&&shift==0)
            {
                //temp=temp*10+7;
                setfillstyle(1,0);
                bar(200,141,586,169);
                setcolor(11);
                strcat(input,pstr);
                outtextxy(vx-count*8,vy,input);
                count++;
                setcolor(0);
                key1=5;
                delay(200);
                //key1=0;
            }

        }
        else if(mx>325&&mx<375&&my>228&&my<271&&on==1)
        {

            if(key!=6)
            {
            ob.restore_but(ptx,pty,pbx,pby,plx,ply,plx1,ply1,pstr,pstr1);
            key=6;
            ob.but_change(325,228,375,268,348,245,"4");
            ptx=325;
            pty=228;
            pbx=375;
            pby=268;
            plx=348;
            ply=245;
            pstr="4";
            plx1=0;
            ply1=0;
            pstr1="";
            }
            if(but==1&&key1!=6&&shift==0)
            {
                //temp=temp*10+4;
                setfillstyle(1,0);
                bar(200,141,586,169);
                setcolor(11);
                strcat(input,pstr);
                outtextxy(vx-count*8,vy,input);
                count++;
                setcolor(0);
                key1=6;
                delay(200);
                key1=0;
            }

        }
        else if(mx>378&&mx<428&&my>228&&my<271&&on==1)
        {

            if(key!=7)
            {
            ob.restore_but(ptx,pty,pbx,pby,plx,ply,plx1,ply1,pstr,pstr1);
            key=7;
            ob.but_change(378,228,428,268,401,245,"5");
            ptx=378;
            pty=228;
            pbx=428;
            pby=268;
            plx=401;
            ply=245;
            pstr="5";
            plx1=0;
            ply1=0;
            pstr1="";
            }
            if(but==1&&key1!=7&&shift==0)
            {
                //temp=temp*10+5;
                setfillstyle(1,0);
                bar(200,141,586,169);
                setcolor(11);
                strcat(input,pstr);
                outtextxy(vx-count*8,vy,input);
                count++;
                setcolor(0);
                key1=7;
                delay(200);
                key1=0;
            }

        }
        else if(mx>431&&mx<481&&my>228&&my<271&&on==1)
        {

            if(key!=8)
            {
            ob.restore_but(ptx,pty,pbx,pby,plx,ply,plx1,ply1,pstr,pstr1);
            key=8;
            ob.but_change(431,228,481,268,454,245,"6");
            ptx=431;
            pty=228;
            pbx=481;
            pby=268;
            plx=454;
            ply=245;
            pstr="6";
            plx1=0;
            ply1=0;
            pstr1="";
            }
            if(but==1&&key1!=8&&shift==0)
            {
                //temp=temp*10+6;
                setfillstyle(1,0);
                bar(200,141,586,169);
                setcolor(11);
                strcat(input,pstr);
                outtextxy(vx-count*8,vy,input);
                count++;
                setcolor(0);
                key1=8;
                delay(200);
                key1=0;
            }

        }
        else if(mx>484&&mx<534&&my>228&&my<271&&on==1)
        {

            if(key!=9)
            {
            ob.restore_but(ptx,pty,pbx,pby,plx,ply,plx1,ply1,pstr,pstr1);
            key=9;
            ob.but_change(484,228,534,268,505,245,"*");
            ptx=484;
            pty=228;
            pbx=534;
            pby=268;
            plx=505;
            ply=245;
            pstr="*";
            plx1=0;
            ply1=0;
            pstr1="";
            }
            if(but==1&&key1!=9&&shift==0)
            {
                temp1=atof(input);
                if(mul==0&&equal==1)
                {
                    mul=1;
                    equal=0;
                    outtextxy(61,152,"*");
                }
                else if(add==0&&sub==0&&mul==0&&div==0)
                {
                    ans=temp1;
                    mul=1;
                    outtextxy(61,152,"*");
                }
                else if(add==0&&sub==1&&mul==0&&div==0)
                {
                    sub=0;add=0;div=0;mul=1;
                    ans=ans-temp1;
                    outtextxy(61,152,"*");
                }
                else if(add==1&&sub==0&&mul==0&&div==0)
                {
                    sub=0;add=0;div=0;mul=1;
                    ans=ans+temp1;
                    outtextxy(61,152,"*");
                }
                else if(add==0&&sub==0&&mul==0&&div==1)
                {
                    sub=0;add=0;div=0;mul=1;
                    ans=ans/temp1;
                    outtextxy(61,152,"*");
                }
                else if(mul==1)
                {
                    sub=0;div=0;add=0;
                    ans=ans*temp1;
                    outtextxy(61,152,"*");
                }
                operation=3;
                setfillstyle(1,0);
                bar(51,141,586,169);
                setcolor(11);
                gcvt(ans,10,input);
                /*if(strlen(input)>9)
                    ob.strcut(input);*/
                outtextxy(61,152,"*");
                   //    if(strlen(input)<=9)
                outtextxy(vx-strlen(input)*8+8,vy,input);
                /*else
                outtextxy(220,152,"Digit exceed");*/
                for(int k=0;k<count;k++)
                {
                    input[k]='\0';
                }
                count=0;
                setcolor(0);
                temp1=0;
                key1=9;
                delay(200);
                //key1=0;
            }

        }
        else if(mx>537&&mx<587&&my>228&&my<271&&on==1)
        {

            if(key!=10)
            {
            ob.restore_but(ptx,pty,pbx,pby,plx,ply,plx1,ply1,pstr,pstr1);
            key=10;
            ob.but_change(537,228,587,268,558,245,"/");
            ptx=537;
            pty=228;
            pbx=587;
            pby=268;
            plx=558;
            ply=245;
            pstr="/";
            plx1=0;
            ply1=0;
            pstr1="";
            }
            if(but==1&&key1!=10&&shift==0)
            {
                temp1=atof(input);
                if(div==0&&equal==1)
                {
                    div=1;
                    equal=0;
                    outtextxy(61,152,"/");
                    gcvt(ans,10,input);
                }
                else if(add==0&&sub==0&&mul==0&&div==0)
                {
                    ans=temp1;
                    div=1;
                    outtextxy(61,152,"/");
                }
                else if(add==0&&sub==1&&mul==0&&div==0)
                {
                    sub=0;mul=0;div=1;add=0;
                    ans=ans-temp1;
                    outtextxy(61,152,"/");
                    gcvt(ans,10,input);
                }
                else if(add==1&&sub==0&&mul==0&&div==0)
                {
                    sub=0;mul=0;div=1;add=0;
                    ans=ans+temp1;
                    outtextxy(61,152,"/");
                    gcvt(ans,10,input);
                }
                else if(add==0&&sub==0&&mul==1&&div==0)
                {
                    sub=0;add=0;div=1;mul=0;
                    ans=ans*temp1;
                    outtextxy(61,152,"/");
                    gcvt(ans,10,input);
                }
                else if(div==1)
                {
                    sub=0;mul=0;add=0;
                    if(temp1==0)
                    {
                    setfillstyle(1,0);
                    bar(51,141,586,169);
                    setcolor(11);
                    input="Divide by zero error";
                    outtextxy(vx-strlen(input)*8+8,vy,input);
                    }
                    else
                    {
                    ans=ans/temp1;
                    gcvt(ans,10,input);
                    }
                }
                operation=4;
                setfillstyle(1,0);
                bar(51,141,586,169);
                outtextxy(61,152,"/");
                setcolor(11);
                    /*if(strlen(input)>9)
                    ob.strcut(input);*/
                outtextxy(61,152,"/");
                   //    if(strlen(input)<=9)
                   outtextxy(vx-strlen(input)*8+8,vy,input);

                for(int k=0;k<count;k++)
                {
                    input[k]='\0';
                }
                count=0;
                setcolor(0);
                temp1=0;
                key1=10;
                delay(200);
                //key1=0;
            }
        }
        else if(mx>325&&mx<375&&my>271&&my<311&&on==1)
        {

            if(key!=11)
            {
            ob.restore_but(ptx,pty,pbx,pby,plx,ply,plx1,ply1,pstr,pstr1);
            key=11;
            ob.but_change(325,271,375,311,348,288,"1");
            ptx=325;
            pty=271;
            pbx=375;
            pby=311;
            plx=348;
            ply=288;
            pstr="1";
            plx1=0;
            ply1=0;
            pstr1="";
            }
            if(but==1&&key1!=11&&shift==0&&strlen(input)<9)
            {
                //temp=temp*10+1;
                setfillstyle(1,0);
                bar(200,141,586,169);
                setcolor(11);
                strcat(input,pstr);
                outtextxy(vx-count*8,vy,input);
                count++;
                setcolor(0);
                key1=11;
                delay(200);
                key1=0;
            }

        }
        else if(mx>378&&mx<428&&my>271&&my<311&&on==1)
        {

            if(key!=12)
            {
            ob.restore_but(ptx,pty,pbx,pby,plx,ply,plx1,ply1,pstr,pstr1);
            key=12;
            ob.but_change(378,271,428,311,401,288,"2");
            ptx=378;
            pty=271;
            pbx=428;
            pby=311;
            plx=401;
            ply=288;
            pstr="2";
            plx1=0;
            ply1=0;
            pstr1="";
            }
            if(but==1&&key1!=12&&shift==0)
            {
                //temp=temp*10+2;
                setfillstyle(1,0);
                bar(200,141,586,169);
                setcolor(11);
                strcat(input,pstr);
                outtextxy(vx-count*8,vy,input);
                count++;
                setcolor(0);
                key1=12;
                delay(200);
                key1=0;
            }

        }
        else if(mx>431&&mx<481&&my>271&my<311&&on==1)
        {

            if(key!=13)
            {
            ob.restore_but(ptx,pty,pbx,pby,plx,ply,plx1,ply1,pstr,pstr1);
            key=13;
            ob.but_change(431,271,481,311,454,288,"3");
            ptx=431;
            pty=271;
            pbx=481;
            pby=311;
            plx=454;
            ply=288;
            pstr="3";
            plx1=0;
            ply1=0;
            pstr1="";
            }
            if(but==1&&key1!=13&&shift==0&&strlen(input)<9)
            {
                //temp=temp*10+3;
                setfillstyle(1,0);
                bar(200,141,586,169);
                setcolor(11);
                strcat(input,pstr);
                outtextxy(vx-count*8,vy,input);
                count++;
                setcolor(0);
                key1=13;
                delay(200);
                key1=0;
            }

        }
        else if(mx>484&&mx<534&&my>271&&my<311&&on==1)
        {

            if(key!=14)
            {
            ob.restore_but(ptx,pty,pbx,pby,plx,ply,plx1,ply1,pstr,pstr1);
            key=14;
            ob.but_change(484,271,534,311,505,288,"+");
            ptx=484;
            pty=271;
            pbx=534;
            pby=311;
            plx=505;
            ply=288;
            pstr="+";
            plx1=0;
            ply1=0;
            pstr1="";
            }
            if(but==1&&key1!=14&&shift==0)
            {
                temp1=atof(input);
                if(add==0&&equal==1)
                {
                    add=1;
                    equal=0;
                    outtextxy(61,152,"+");
                }
                else if(add==0&&sub==0&&mul==0&&div==0)
                {
                    ans=temp1;
                    add=1;
                    outtextxy(61,152,"+");
                }
                else if(add==0&&sub==1&&mul==0&&div==0)
                {
                    sub=0;mul=0;div=0;add=1;
                    ans=ans-temp1;
                    outtextxy(61,152,"+");
                }
                else if(add==0&&sub==0&&mul==1&&div==0)
                {
                    sub=0;mul=0;div=0;add=1;
                    ans=ans*temp1;
                    outtextxy(61,152,"+");
                }
                else if(add==0&&sub==0&&mul==0&&div==1)
                {
                    sub=0;mul=0;div=0;add=1;
                    ans=ans/temp1;
                    outtextxy(61,152,"+");
                }
                else if(add==1)
                {
                    sub=0;mul=0;div=0;
                    ans=ans+temp1;
                    outtextxy(61,152,"+");
                }
                operation=1;
                setfillstyle(1,0);
                bar(51,141,586,169);
                setcolor(11);
                gcvt(ans,10,input);
                if(strlen(input)>9)
                    ob.strcut(input);
                outtextxy(61,152,"+");
                if(strlen(input)<=9)
                outtextxy(vx-strlen(input)*8+8,vy,input);
                /*else
                outtextxy(220,152,"Digit exceed");*/
                for(int k=0;k<count;k++)
                {
                    input[k]='\0';
                }//input[0]='\0';
                count=0;
                setcolor(0);
                temp1=0;
                key1=14;
                delay(200);
                //key1=0;
            }

        }
        else if(mx>537&&mx<587&&my>271&&my<311&&on==1)
        {

            if(key!=15)
            {
            ob.restore_but(ptx,pty,pbx,pby,plx,ply,plx1,ply1,pstr,pstr1);
            key=15;
            ob.but_change(537,271,587,311,558,288,"-");
            ptx=537;
            pty=271;
            pbx=587;
            pby=311;
            plx=558;
            ply=288;
            pstr="-";
            plx1=0;
            ply1=0;
            pstr1="";
            }
            if(but==1&&key1!=15&&shift==0)
            {
                temp1=atof(input);
                if(sub==0&&equal==1)
                {
                    sub=1;
                    equal=0;
                    outtextxy(61,152,"-");
                }
                else if(sub==0&&add==0&&mul==0&&div==0)
                {
                    ans=temp1;
                    sub=1;
                    outtextxy(61,152,"-");
                }
                else if(sub==0&&add==1&&mul==0&&div==0)
                {
                    add=0;mul=0;div=0;sub=1;
                    ans=ans+temp1;
                    outtextxy(61,152,"-");
                }
                else if(add==0&&sub==0&&mul==1&&div==0)
                {
                    sub=1;mul=0;div=0;add=0;
                    ans=ans*temp1;
                    outtextxy(61,152,"-");
                }
                else if(add==0&&sub==0&&mul==0&&div==1)
                {
                    sub=0;mul=0;div=1;add=0;
                    ans=ans/temp1;
                    outtextxy(61,152,"-");
                }
                else if(sub==1)
                {
                    add=0;mul=0;div=0;
                    ans=ans-temp1;
                    outtextxy(61,152,"-");
                }
                operation=2;
                setfillstyle(1,0);
                bar(51,141,586,169);
                setcolor(11);
                gcvt(ans,10,input);
                if(strlen(input)>9)
                    ob.strcut(input);
                outtextxy(61,152,"-");
                if(strlen(input)<=9)
                outtextxy(vx-strlen(input)*8+8,vy,input);
                /*else
                outtextxy(220,152,"Digit exceed");*/
                for(int k=0;k<count;k++)
                {
                    input[k]='\0';
                }
                count=0;
                setcolor(0);
                temp1=0;
                key1=14;
                delay(200);
                //key1=0;

            }

        }
        else if(mx>325&&mx<375&&my>314&&my<354&&on==1)
        {

            if(key!=16)
            {
            ob.restore_but(ptx,pty,pbx,pby,plx,ply,plx1,ply1,pstr,pstr1);
            key=16;
            ob.but_change(325,314,375,354,347,331,"0");
            ptx=325;
            pty=314;
            pbx=375;
            pby=354;
            plx=347;
            ply=331;
            pstr="0";
            plx1=0;
            ply1=0;
            pstr1="";
            }
            if(but==1&&key1!=16&&shift==0)
            {
                //temp=temp*10+0;
                setfillstyle(1,0);
                bar(200,141,586,169);
                setcolor(11);
                strcat(input,pstr);
                outtextxy(vx-count*8,vy,input);
                count++;
                setcolor(0);
                key1=16;
                delay(200);
                key1=0;
            }

        }
        else if(mx>378&&mx<428&&my>314&&my<354&&on==1)
        {

            if(key!=17)
            {
            ob.restore_but(ptx,pty,pbx,pby,plx,ply,plx1,ply1,pstr,pstr1);
            key=17;
            ob.but_change(378,314,428,354,401,329,".");
            ptx=378;
            pty=314;
            pbx=428;
            pby=354;
            plx=401;
            ply=329;
            pstr=".";
            plx1=0;
            ply1=0;
            pstr1="";
            }
            if(but==1&&key1!=16&&shift==0)
            {
                //temp=temp*10+0;
                setfillstyle(1,0);
                bar(200,141,586,169);
                setcolor(11);
                strcat(input,pstr);
                outtextxy(vx-count*8,vy,input);
                //count++;
                setcolor(0);
                key1=17;
                delay(200);
                key1=0;
            }

        }
        else if(mx>431&&mx<481&&my>314&my<354&&on==1)
        {

            if(key!=18)
            {
            ob.restore_but(ptx,pty,pbx,pby,plx,ply,plx1,ply1,pstr,pstr1);
            key=18;
            ob.but_change(431,314,481,354,445,331,"EXP");
            ptx=431;
            pty=314;
            pbx=481;
            pby=354;
            plx=445;
            ply=331;
            pstr="EXP";
            plx1=0;
            ply1=0;
            pstr1="";
            }

        }
        else if(mx>484&&mx<534&&my>314&&my<354&&on==1)
        {

            if(key!=19)
            {
            ob.restore_but(ptx,pty,pbx,pby,plx,ply,plx1,ply1,pstr,pstr1);
            key=19;
            ob.but_change(484,314,534,354,498,331,"ANS");
            ptx=484;
            pty=314;
            pbx=534;
            pby=354;
            plx=498;
            ply=331;
            pstr="ANS";
            plx1=0;
            ply1=0;
            pstr1="";
            }
            if(but==1&&key1!=19&&shift==0)
            {
                setfillstyle(1,0);
                bar(51,141,586,169);
                setcolor(11);
                gcvt(ans,10,input);
                outtextxy(61,152,"ans");
                //if(strlen(input)<=9)
                outtextxy(vx-strlen(input)*8+8,vy,input);
                /*else
                outtextxy(220,152,"Digit exceed");*/
                for(int k=0;k<count;k++)
                {
                    input[k]='\0';
                }
                count=0;
                setcolor(0);
                temp1=0;
                key1=23;
                delay(200);
                //key1=0;

            }

        }
        else if(mx>50&&mx<100&&my>185&&my<225&&on==1)
        {

            if(key!=20)
            {
            ob.restore_but(ptx,pty,pbx,pby,plx,ply,plx1,ply1,pstr,pstr1);
            key=20;
            ob.but_change(50,185,100,225,56,202,"SHIFT");
            ptx=50;
            pty=185;
            pbx=100;
            pby=225;
            plx=56;
            ply=202;
            pstr="SHIFT";
            plx1=0;
            ply1=0;
            pstr1="";
            }
            if(but==1&&key1!=20)
            {
                if(shift==0)
                {
                setfillstyle(1,0);
                bar(61,141,200,169);
                setcolor(11);
                outtextxy(61,152,"Shift");
                setcolor(0);

                shift=1;
                }
                else
                {
                setfillstyle(1,0);
                bar(61,141,200,169);

                shift=0;
                }
                //reset();
                key1=20;
                delay(200);
                key1=0;

            }


        }
        else if(mx>103&&mx<153&&my>185&&my<225&&on==1)
        {

            if(key!=21)
            {
            ob.restore_but(ptx,pty,pbx,pby,plx,ply,plx1,ply1,pstr,pstr1);
            key=21;
            ob.but_change(103,185,153,225,117,202,"STO");
            ptx=103;
            pty=185;
            pbx=153;
            pby=225;
            plx=117;
            ply=202;
            pstr="STO";
            plx1=0;
            ply1=0;
            pstr1="";
            }
            if(but==1&&key1!=21)
            {
                if(sto==0)
                {
                setfillstyle(1,0);
                bar(61,141,200,169);
                setcolor(11);
                outtextxy(61,152,"STO");
                setcolor(0);

                sto=1;
                }
                else
                {
                setfillstyle(1,0);
                bar(61,141,200,169);

                sto=0;
                }
                //reset();
                key1=21;
                delay(200);
                key1=0;

            }


        }
        else if(mx>156&&mx<206&&my>185&&my<225&&on==1)
        {

            if(key!=22)
            {
            ob.restore_but(ptx,pty,pbx,pby,plx,ply,plx1,ply1,pstr,pstr1);
            key=22;
            ob.but_change(156,185,206,225,171,202,"RCL");
            ptx=156;
            pty=185;
            pbx=206;
            pby=225;
            plx=171;
            ply=202;
            pstr="RCL";
            plx1=0;
            ply1=0;
            pstr1="";
            }
            if(but==1&&key1!=22)
            {
                if(rcl==0)
                {
                setfillstyle(1,0);
                bar(61,141,200,169);
                setcolor(11);
                outtextxy(61,152,"RCL");
                setcolor(0);

                rcl=1;
                }
                else
                {
                setfillstyle(1,0);
                bar(61,141,200,169);

                rcl=0;
                }
                //reset();
                key1=22;
                delay(200);
                key1=0;

            }


        }
        else if(mx>209&&mx<259&&my>185&&my<225&&on==1)
        {

            if(key!=23)
            {
            ob.restore_but(ptx,pty,pbx,pby,plx,ply,plx1,ply1,pstr,pstr1);
            key=23;
            ob.but_change(209,185,259,225,228,202,"M+");
            ptx=209;
            pty=185;
            pbx=259;
            pby=225;
            plx=228;
            ply=202;
            pstr="M+";
            plx1=0;
            ply1=0;
            pstr1="";
            }
            if(but==1&&key1!=23&&shift==0)
            {
                temp1=atof(input);
                m+=temp1;
                ans=m;
                setfillstyle(1,0);
                bar(51,141,586,169);
                setcolor(11);
                gcvt(ans,10,input);
                outtextxy(61,152,"M+");
                if(strlen(input)<=9)
                outtextxy(vx-strlen(input)*8+8,vy,input);
                /*else
                outtextxy(220,152,"Digit exceed");*/
                for(int k=0;k<count;k++)
                {
                    input[k]='\0';
                }
                count=0;
                setcolor(0);
                temp1=0;
                key1=23;
                delay(200);
                //key1=0;

            }
        }
        else if(mx>262&&mx<312&&my>185&&my<225&&on==1)
        {

            if(key!=24)
            {
            ob.restore_but(ptx,pty,pbx,pby,plx,ply,plx1,ply1,pstr,pstr1);
            key=24;
            ob.but_change(262,185,312,225,268,202,"CONST");
            ptx=262;
            pty=185;
            pbx=312;
            pby=225;
            plx=268;
            ply=202;
            pstr="CONST";
            plx1=0;
            ply1=0;
            pstr1="";
            }
            if(but==1&&key1!=24&&shift==0)
            {
                //temp=temp*10+0;
                setfillstyle(1,0);
                bar(200,141,586,169);
                setcolor(11);
                int c=atoi(input);
                if(c==1)
                {
                input="1.672e-27";
                outtextxy(61,vy,"mass of proton");
                outtextxy(vx-strlen(input)*8,vy,input);

                }
                else if(c==2)
                {
                input="1.6749e-27";
                outtextxy(61,vy,"mass of neutron");
                outtextxy(vx-strlen(input)*8,vy,input);

                }
                else if(c==3)
                {
                input="9.109e-31";
                outtextxy(61,vy,"mass of electron");
                outtextxy(vx-strlen(input)*8,vy,input);

                }
                else if(c==4)
                {
                input="6.62606876e-34";
                outtextxy(61,vy,"plank constant");
                outtextxy(vx-strlen(input)*8,vy,input);

                }
                else if(c==5)
                {
                input="9.8";
                outtextxy(61,vy,"g");
                outtextxy(vx-strlen(input)*8,vy,input);

                }
                else if(c==6)
                {
                input="6.673e-11";
                outtextxy(61,vy,"G");
                outtextxy(vx-strlen(input)*8,vy,input);

                }
                else if(c==7)
                {
                input="5.6704e-8";
                outtextxy(61,vy,"å");
                outtextxy(vx-strlen(input)*8,vy,input);

                }
                else if(c==8)
                {
                input="7.297352533e-3";
                outtextxy(61,vy,"à");
                outtextxy(vx-strlen(input)*8,vy,input);

                }
                else if(c==9)
                {
                input="1.410606633e-26";
                outtextxy(61,vy,"æp");
                outtextxy(vx-strlen(input)*8,vy,input);

                }
                else if(c==10)
                {
                input="-9.28476362e-24";
                outtextxy(61,vy,"æe");
                outtextxy(vx-strlen(input)*8,vy,input);

                }
                else if(c==11)
                {
                input="-9.662364e-27";
                outtextxy(61,vy,"æn");
                outtextxy(vx-strlen(input)*8,vy,input);

                }
                else if(c==12)
                {
                input="96500";
                outtextxy(61,vy,"F");
                outtextxy(vx-strlen(input)*8,vy,input);

                }
                else if(c==13)
                {
                input="1.602176462e-19";
                outtextxy(61,vy,"e");
                outtextxy(vx-strlen(input)*8,vy,input);

                }
                else if(c==14)
                {
                input="8.314472";
                outtextxy(61,vy,"R");
                outtextxy(vx-strlen(input)*8,vy,input);

                }
                else if(c==15)
                {
                input="8.854187817e-12";
                outtextxy(61,vy,"îo");
                outtextxy(vx-strlen(input)*8,vy,input);

                }
                else if(c==16)
                {
                input="1.256637061e-6";
                outtextxy(61,vy,"æo");
                outtextxy(vx-strlen(input)*8,vy,input);

                }
                else if(c==17)
                {
                input="2.067833636e-15";
                outtextxy(61,vy,"ío");
                outtextxy(vx-strlen(input)*8,vy,input);

                }
                else if(c==18)
                {
                input="299792458";
                outtextxy(61,vy,"Co");
                outtextxy(vx-strlen(input)*8,vy,input);

                }
                else if(c==19)
                {
                input="7.748091696e-5";
                outtextxy(61,vy,"Go");
                outtextxy(vx-strlen(input)*8,vy,input);

                }
                else if(c==20)
                {
                input="1.01325";
                outtextxy(61,vy,"atm");
                outtextxy(vx-strlen(input)*8,vy,input);

                }
                //count++;
                setcolor(0);
                key1=17;
                delay(200);
                key1=0;
            }


        }
        else if(mx>50&&mx<100&&my>314&&my<354&&on==1)
        {

            if(key!=25)
            {
            ob.restore_but(ptx,pty,pbx,pby,plx,ply,plx1,ply1,pstr,pstr1);
            key=25;
            ob.but_change(50,314,100,354,63,330,"log");
            ptx=50;
            pty=314;
            pbx=100;
            pby=354;
            plx=63;
            ply=330;
            pstr="log";
            plx1=0;
            ply1=0;
            pstr1="";
            }
            if(but==1&&key1!=25&&shift==0)
            {
                temp1=atof(input);
                ans=log10(temp1);
                //operation=SUM;
                setfillstyle(1,0);
                bar(51,141,586,169);
                setcolor(11);
                gcvt(ans,10,input);
                if(strlen(input)>9)
                    ob.strcut(input);

                outtextxy(61,152,"log");
                if(strlen(input)<=9)
                outtextxy(vx-strlen(input)*8+8,vy,input);

                for(int k=0;k<count;k++)
                {
                    input[k]='\0';
                }
                count=0;
                setcolor(0);
                temp1=0;
                key1=25;
                delay(200);
                //key1=0;
            }

        }
        else if(mx>103&&mx<153&&my>314&&my<354&&on==1)
        {

            if(key!=26)
            {
            ob.restore_but(ptx,pty,pbx,pby,plx,ply,plx1,ply1,pstr,pstr1);
            key=26;
            ob.but_change(103,314,153,354,120,330,"ln");
            ptx=103;
            pty=314;
            pbx=153;
            pby=354;
            plx=120;
            ply=330;
            pstr="ln";
            plx1=0;
            ply1=0;
            pstr1="";
            }
            if(but==1&&key1!=26&&shift==0)
            {
                temp1=atof(input);
                ans=log(temp1);
                //operation=SUM;
                setfillstyle(1,0);
                bar(51,141,586,169);
                setcolor(11);
                gcvt(ans,10,input);
                if(strlen(input)>9)
                    ob.strcut(input);

                outtextxy(61,152,"ln");
                if(strlen(input)<=9)
                outtextxy(vx-strlen(input)*8+8,vy,input);

                for(int k=0;k<count;k++)
                {
                    input[k]='\0';
                }
                count=0;
                setcolor(0);
                temp1=0;
                key1=26;
                delay(200);
                //key1=0;
            }


        }
        else if(mx>156&&mx<206&&my>314&&my<354&&on==1)
        {

            if(key!=27)
            {
            ob.restore_but(ptx,pty,pbx,pby,plx,ply,plx1,ply1,pstr,pstr1);
            key=27;
            ob.but_change(156,314,206,354,169,330,"sin");
            ptx=156;
            pty=314;
            pbx=206;
            pby=354;
            plx=169;
            ply=330;
            pstr="sin";
            plx1=0;
            ply1=0;
            pstr1="";
            }
            if(but==1&&key1!=27&&shift==0)
            {
                temp1=atof(input)*0.0174533;
                ans=sin(temp1);
                //operation=SUM;
                setfillstyle(1,0);
                bar(51,141,586,169);
                setcolor(11);
                gcvt(ans,10,input);
                if(strlen(input)>9)
                    ob.strcut(input);

                outtextxy(61,152,"sin");
                if(strlen(input)<=9)
                outtextxy(vx-strlen(input)*8+8,vy,input);

                for(int k=0;k<count;k++)
                {
                    input[k]='\0';
                }
                count=0;
                setcolor(0);
                temp1=0;
                key1=27;
                delay(200);
                //key1=0;
            }

        }

        else if(mx>209&&mx<259&&my>314&&my<354&&on==1)
        {

            if(key!=28)
            {
            ob.restore_but(ptx,pty,pbx,pby,plx,ply,plx1,ply1,pstr,pstr1);
            key=28;
            ob.but_change(209,314,259,354,222,330,"cos");
            ptx=209;
            pty=314;
            pbx=259;
            pby=354;
            plx=222;
            ply=330;
            pstr="cos";
            plx1=0;
            ply1=0;
            pstr1="";
            }
            if(but==1&&key1!=28&&shift==0)
            {
                temp1=atof(input)*0.0174533;
                ans=cos(temp1);
                //operation=SUM;
                setfillstyle(1,0);
                bar(51,141,586,169);
                setcolor(11);
                gcvt(ans,10,input);
                if(strlen(input)>9)
                    ob.strcut(input);
                outtextxy(61,152,"cos");
                if(strlen(input)<=9)
                outtextxy(vx-strlen(input)*8+8,vy,input);

                for(int k=0;k<count;k++)
                {
                    input[k]='\0';
                }
                count=0;
                setcolor(0);
                temp1=0;
                key1=28;
                delay(200);
                //key1=0;
            }
        }
        else if(mx>262&&mx<312&&my>314&&my<354&&on==1)
        {

            if(key!=29)
            {
            ob.restore_but(ptx,pty,pbx,pby,plx,ply,plx1,ply1,pstr,pstr1);
            key=29;
            ob.but_change(262,314,312,354,275,330,"tan");
            ptx=262;
            pty=314;
            pbx=312;
            pby=354;
            plx=275;
            ply=330;
            pstr="tan";
            plx1=0;
            ply1=0;
            pstr1="";
            }
            if(but==1&&key1!=29&&shift==0)
            {
                temp1=atof(input)*0.0174533;
                ans=tan(temp1);
                //operation=SUM;
                setfillstyle(1,0);
                bar(51,141,586,169);
                setcolor(11);
                gcvt(ans,10,input);
                if(strlen(input)>9)
                    ob.strcut(input);
                outtextxy(61,152,"tan");
                if(strlen(input)<=9)
                outtextxy(vx-strlen(input)*8+8,vy,input);

                for(int k=0;k<count;k++)
                {
                    input[k]='\0';
                }
                count=0;
                setcolor(0);
                temp1=0;
                key1=29;
                delay(200);
                //key1=0;
            }

        }
        else if(mx>50&&mx<100&&my>228&&my<268&&on==1)
        {

            if(key!=30)
            {
            ob.restore_but(ptx,pty,pbx,pby,plx,ply,plx1,ply1,pstr,pstr1);
            key=30;
            ob.but_change(50,228,100,268,65,253,"(-)",72,238,"A");
            ptx=50;
            pty=228;
            pbx=100;
            pby=268;
            plx=65;
            ply=253;
            plx1=72;
            ply1=238;
            pstr="(-)";
            pstr1="A";
            }
            if(but==1&&key1!=30&&shift==0&&sto==1)
            {
                temp1=atof(input);
                a=temp1;sto=0;
                setfillstyle(1,0);
                bar(51,141,586,169);
                setcolor(11);
                gcvt(a,10,input);
                outtextxy(61,152,"A=");
                if(strlen(input)<=9)
                outtextxy(vx-strlen(input)*8+8,vy,input);
                for(int k=0;k<count;k++)
                {
                    input[k]='\0';
                }
                count=0;
                setcolor(0);
                temp1=0;
                key1=30;
                delay(200);
                //key1=0;
            }
            if(but==1&&key1!=30&&shift==0&&rcl==1)
            {
                //temp1=atof(input);
                ans=a;rcl=0;
                //operation=SUM;
                setfillstyle(1,0);
                bar(51,141,586,169);
                setcolor(11);
                gcvt(ans,10,input);
                if(strlen(input)>9)
                    ob.strcut(input);
                outtextxy(61,152,"A=");
                if(strlen(input)<=9)
                outtextxy(vx-strlen(input)*8+8,vy,input);

                for(int k=0;k<count;k++)
                {
                    input[k]='\0';
                }
                count=0;
                setcolor(0);
                temp1=0;
                key1=30;
                delay(200);
                //key1=0;
            }

        }
        else if(mx>103&&mx<153&&my>228&&my<268&&on==1)
        {

            if(key!=31)
            {
            ob.restore_but(ptx,pty,pbx,pby,plx,ply,plx1,ply1,pstr,pstr1);
            key=31;
            ob.but_change(103,228,153,268,115,253,"sin´",125,238,"B");
            ptx=103;
            pty=228;
            pbx=153;
            pby=268;
            plx=115;
            ply=253;
            plx1=125;
            ply1=238;
            pstr="sin´";
            pstr1="B";
            }
            if(but==1&&key1!=31&&shift==0&&sto==0&&rcl==0)
            {
                temp1=atof(input);
                ans=asin(temp1)/0.0174533;
                //operation=SUM;
                setfillstyle(1,0);
                bar(51,141,586,169);
                setcolor(11);
                gcvt(ans,10,input);
                if(strlen(input)>9)
                    ob.strcut(input);
                outtextxy(61,152,"sin´");
                if(strlen(input)<=9)
                outtextxy(vx-strlen(input)*8+8,vy,input);

                for(int k=0;k<count;k++)
                {
                    input[k]='\0';
                }
                count=0;
                setcolor(0);
                temp1=0;
                key1=31;
                delay(200);
                //key1=0;
            }
            if(but==1&&key1!=31&&shift==0&&sto==1)
            {
                temp1=atof(input);
                b=temp1;sto=0;
                setfillstyle(1,0);
                bar(51,141,586,169);
                setcolor(11);
                gcvt(b,10,input);
                outtextxy(61,152,"B=");
                if(strlen(input)<=9)
                outtextxy(vx-strlen(input)*8+8,vy,input);
                for(int k=0;k<count;k++)
                {
                    input[k]='\0';
                }
                count=0;
                setcolor(0);
                temp1=0;
                key1=31;
                delay(200);
                //key1=0;
            }
            if(but==1&&key1!=31&&shift==0&&rcl==1)
            {
                //temp1=atof(input);
                ans=b;rcl=0;
                //operation=SUM;
                setfillstyle(1,0);
                bar(51,141,586,169);
                setcolor(11);
                gcvt(ans,10,input);
                if(strlen(input)>9)
                    ob.strcut(input);
                outtextxy(61,152,"B=");
                if(strlen(input)<=9)
                outtextxy(vx-strlen(input)*8+8,vy,input);

                for(int k=0;k<count;k++)
                {
                    input[k]='\0';
                }
                count=0;
                setcolor(0);
                temp1=0;
                key1=31;
                delay(200);
                //key1=0;
            }


        }
        else if(mx>156&&mx<206&&my>228&&my<268&&on==1)
        {

            if(key!=32)
            {
            ob.restore_but(ptx,pty,pbx,pby,plx,ply,plx1,ply1,pstr,pstr1);
            key=32;
            ob.but_change(156,228,206,268,168,253,"cos´",178,238,"C");
            ptx=156;
            pty=228;
            pbx=206;
            pby=268;
            plx=168;
            ply=253;
            plx1=178;
            ply1=238;
            pstr="cos´";
            pstr1="C";
            }
            if(but==1&&key1!=32&&shift==0&&rcl==0&&sto==0)
            {
                temp1=atof(input);
                ans=acos(temp1)/0.0174533;
                //operation=SUM;
                setfillstyle(1,0);
                bar(51,141,586,169);
                setcolor(11);
                gcvt(ans,10,input);
                if(strlen(input)>9)
                    ob.strcut(input);
                outtextxy(61,152,"cos´");
                if(strlen(input)<=9)
                outtextxy(vx-strlen(input)*8+8,vy,input);

                for(int k=0;k<count;k++)
                {
                    input[k]='\0';
                }
                count=0;
                setcolor(0);
                temp1=0;
                key1=32;
                delay(200);
                //key1=0;
            }
            if(but==1&&key1!=32&&shift==0&&sto==1)
            {
                temp1=atof(input);
                c=temp1;sto=0;
                setfillstyle(1,0);
                bar(51,141,586,169);
                setcolor(11);
                gcvt(b,10,input);
                outtextxy(61,152,"C=");
                if(strlen(input)<=9)
                outtextxy(vx-strlen(input)*8+8,vy,input);
                for(int k=0;k<count;k++)
                {
                    input[k]='\0';
                }
                count=0;
                setcolor(0);
                temp1=0;
                key1=32;
                delay(200);
                //key1=0;
            }
            if(but==1&&key1!=32&&shift==0&&rcl==1)
            {
                //temp1=atof(input);
                ans=b;rcl=0;
                //operation=SUM;
                setfillstyle(1,0);
                bar(51,141,586,169);
                setcolor(11);
                gcvt(ans,10,input);
                if(strlen(input)>9)
                    ob.strcut(input);
                outtextxy(61,152,"C=");
                if(strlen(input)<=9)
                outtextxy(vx-strlen(input)*8+8,vy,input);

                for(int k=0;k<count;k++)
                {
                    input[k]='\0';
                }
                count=0;
                setcolor(0);
                temp1=0;
                key1=32;
                delay(200);
                //key1=0;
            }

        }
        else if(mx>209&&mx<259&&my>228&&my<268&&on==1)
        {

            if(key!=33)
            {
            ob.restore_but(ptx,pty,pbx,pby,plx,ply,plx1,ply1,pstr,pstr1);
            key=33;
            ob.but_change(209,228,259,268,220,253,"tan´",231,238,"D");
            ptx=209;
            pty=228;
            pbx=259;
            pby=268;
            plx=220;
            ply=253;
            plx1=231;
            ply1=238;
            pstr="tan´";
            pstr1="D";
            }
            if(but==1&&key1!=33&&shift==0&&rcl==0&&sto==0)
            {
                temp1=atof(input);
                ans=atan(temp1)/0.0174533;
                //operation=SUM;
                setfillstyle(1,0);
                bar(51,141,586,169);
                setcolor(11);
                gcvt(ans,10,input);
                if(strlen(input)>9)
                    ob.strcut(input);
                outtextxy(61,152,"tan´");
                if(strlen(input)<=9)
                outtextxy(vx-strlen(input)*8+8,vy,input);

                for(int k=0;k<count;k++)
                {
                    input[k]='\0';
                }
                count=0;
                setcolor(0);
                temp1=0;
                key1=33;
                delay(200);
                //key1=0;
            }
            if(but==1&&key1!=33&&shift==0&&sto==1)
            {
                temp1=atof(input);
                d=temp1;sto=0;
                setfillstyle(1,0);
                bar(51,141,586,169);
                setcolor(11);
                gcvt(d,10,input);
                outtextxy(61,152,"D=");
                if(strlen(input)<=9)
                outtextxy(vx-strlen(input)*8+8,vy,input);
                for(int k=0;k<count;k++)
                {
                    input[k]='\0';
                }
                count=0;
                setcolor(0);
                temp1=0;
                key1=33;
                delay(200);
                //key1=0;
            }
            if(but==1&&key1!=33&&shift==0&&rcl==1)
            {
                //temp1=atof(input);
                ans=d;rcl=0;
                //operation=SUM;
                setfillstyle(1,0);
                bar(51,141,586,169);
                setcolor(11);
                gcvt(ans,10,input);
                if(strlen(input)>9)
                    ob.strcut(input);
                outtextxy(61,152,"D=");
                if(strlen(input)<=9)
                outtextxy(vx-strlen(input)*8+8,vy,input);

                for(int k=0;k<count;k++)
                {
                    input[k]='\0';
                }
                count=0;
                setcolor(0);
                temp1=0;
                key1=33;
                delay(200);
                //key1=0;
            }


        }
        else if(mx>262&&mx<312&&my>228&&my<268&&on==1)
        {

            if(key!=34)
            {
            ob.restore_but(ptx,pty,pbx,pby,plx,ply,plx1,ply1,pstr,pstr1);
            key=34;
            ob.but_change(262,228,312,268,268,253,"CONVR",284,238,"E");
            ptx=262;
            pty=228;
            pbx=312;
            pby=268;
            plx=268;
            ply=253;
            plx1=284;
            ply1=238;
            pstr="CONVR";
            pstr1="E";
            }
            if(but==1&&key1!=34&&shift==0&&sto==1)
            {
                temp1=atof(input);
                e=temp1;sto=0;
                setfillstyle(1,0);
                bar(51,141,586,169);
                setcolor(11);
                gcvt(e,10,input);
                outtextxy(61,152,"E=");
                if(strlen(input)<=9)
                outtextxy(vx-strlen(input)*8+8,vy,input);
                for(int k=0;k<count;k++)
                {
                    input[k]='\0';
                }
                count=0;
                setcolor(0);
                temp1=0;
                key1=34;
                delay(200);
                //key1=0;
            }
            if(but==1&&key1!=34&&shift==0&&rcl==1)
            {
                //temp1=atof(input);
                ans=e;rcl=0;
                //operation=SUM;
                setfillstyle(1,0);
                bar(51,141,586,169);
                setcolor(11);
                gcvt(ans,10,input);
                if(strlen(input)>9)
                    ob.strcut(input);
                outtextxy(61,152,"E=");
                if(strlen(input)<=9)
                outtextxy(vx-strlen(input)*8+8,vy,input);

                for(int k=0;k<count;k++)
                {
                    input[k]='\0';
                }
                count=0;
                setcolor(0);
                temp1=0;
                key1=34;
                delay(200);
                //key1=0;
            }


        }
        else if(mx>50&&mx<100&&my>271&&my<311&&on==1)
        {

            if(key!=35)
            {
            ob.restore_but(ptx,pty,pbx,pby,plx,ply,plx1,ply1,pstr,pstr1);
            key=35;
            ob.but_change(50,271,100,311,70,296,"û",71,281,"xý");
            ptx=50;
            pty=271;
            pbx=100;
            pby=311;
            plx=70;
            ply=296;
            plx1=71;
            ply1=281;
            pstr="û";
            pstr1="xý";
            }
            if(but==1&&key1!=35&&shift==0)
            {
                temp1=atof(input);
                ans=sqrt(temp1);
                //operation=SUM;
                setfillstyle(1,0);
                bar(51,141,586,169);
                setcolor(11);
                gcvt(ans,10,input);
                if(strlen(input)>9)
                    ob.strcut(input);

                //outtextxy(61,152,"ln");
                if(strlen(input)<=9)
                outtextxy(vx-strlen(input)*8+8,vy,input);

                for(int k=0;k<count;k++)
                {
                    input[k]='\0';
                }
                count=0;
                setcolor(0);
                temp1=0;
                key1=35;
                delay(200);
                //key1=0;
            }
            if(but==1&&key1!=35&&shift==1)
            {
                temp1=atof(input);
                ans=pow(temp1,2);shift=0;
                //operation=SUM;
                setfillstyle(1,0);
                bar(51,141,586,169);
                setcolor(11);
                gcvt(ans,10,input);
                if(strlen(input)>9)
                    ob.strcut(input);
                //outtextxy(61,152,"ln");
                if(strlen(input)<=9)
                outtextxy(vx-strlen(input)*8+8,vy,input);

                for(int k=0;k<count;k++)
                {
                    input[k]='\0';
                }
                count=0;
                setcolor(0);
                temp1=0;
                key1=35;
                delay(200);
                //key1=0;
            }

        }
        else if(mx>103&&mx<153&&my>268&&my<311&&on==1)
        {

            if(key!=36)
            {
            ob.restore_but(ptx,pty,pbx,pby,plx,ply,plx1,ply1,pstr,pstr1);
            key=36;
            ob.but_change(103,271,153,311,117,296,"x^y",117,281,"x^3");
            ptx=103;
            pty=271;
            pbx=153;
            pby=311;
            plx=117;
            ply=296;
            plx1=117;
            ply1=281;
            pstr="x^y";
            pstr1="x^3";
            }
            if(but==1&&key1!=36&&shift==0&&npr==0)
            {
                temp1=atof(input);
                ans=temp1;npr=1;
                //operation=SUM;
                setfillstyle(1,0);
                bar(51,141,586,169);
                setcolor(11);
                gcvt(ans,10,input);
                if(strlen(input)>9)
                    ob.strcut(input);

                //outtextxy(61,152,"ln");
                if(strlen(input)<=9)
                outtextxy(vx-strlen(input)*8+8,vy,input);

                for(int k=0;k<count;k++)
                {
                    input[k]='\0';
                }
                count=0;
                setcolor(0);
                temp1=0;
                key1=36;
                delay(200);
                //key1=0;
            }
            if(but==1&&key1!=36&&shift==0&&npr==1)
            {
                temp1=atof(input);
                ans=ob.pw(ans,temp1);
                npr=0;
                setfillstyle(1,0);
                bar(51,141,586,169);
                setcolor(11);
                gcvt(ans,10,input);
                if(strlen(input)>9)
                    ob.strcut(input);


                if(strlen(input)<=9)
                outtextxy(vx-strlen(input)*8+8,vy,input);

                for(int k=0;k<count;k++)
                {
                    input[k]='\0';
                }
                count=0;
                setcolor(0);
                temp1=0;
                key1=36;
                delay(200);
                //key1=0;
            }
            if(but==1&&key1!=36&&shift==1)
            {
                temp1=atof(input);
                ans=pow(temp1,3);
                shift=0;
                setfillstyle(1,0);
                bar(51,141,586,169);
                setcolor(11);
                gcvt(ans,10,input);
                if(strlen(input)>9)
                    ob.strcut(input);
                //outtextxy(61,152,"ln");
                if(strlen(input)<=9)
                outtextxy(vx-strlen(input)*8+8,vy,input);

                for(int k=0;k<count;k++)
                {
                    input[k]='\0';
                }
                count=0;
                setcolor(0);
                temp1=0;
                key1=36;
                delay(200);
                //key1=0;
            }

        }
        else if(mx>156&&mx<206&&my>271&&my<311&&on==1)
        {

            if(key!=37)
            {
            ob.restore_but(ptx,pty,pbx,pby,plx,ply,plx1,ply1,pstr,pstr1);
            key=37;
            ob.but_change(156,271,206,311,170,296,"1/x",178,281,"!");
            ptx=156;
            pty=271;
            pbx=206;
            pby=311;
            plx=170;
            ply=296;
            plx1=178;
            ply1=281;
            pstr="1/x";
            pstr1="!";
            }
            if(but==1&&key1!=37&&shift==0)
            {
                temp1=atof(input);
                ans=1/temp1;
                //operation=SUM;
                setfillstyle(1,0);
                bar(51,141,586,169);
                setcolor(11);
                gcvt(ans,10,input);
                if(strlen(input)>9)
                    ob.strcut(input);

                //outtextxy(61,152,"ln");
                if(strlen(input)<=9)
                outtextxy(vx-strlen(input)*8+8,vy,input);

                for(int k=0;k<count;k++)
                {
                    input[k]='\0';
                }
                count=0;
                setcolor(0);
                temp1=0;
                key1=37;
                delay(200);
                //key1=0;
            }
            if(but==1&&key1!=37&&shift==1)
            {
                temp1=atof(input);
                ans=ob.fact(temp1);
                shift=0;
                //operation=SUM;
                setfillstyle(1,0);
                bar(51,141,586,169);
                setcolor(11);
                gcvt(ans,10,input);
                if(strlen(input)>9)
                    ob.strcut(input);

                //outtextxy(61,152,"ln");
                if(strlen(input)<=9)
                outtextxy(vx-strlen(input)*8+8,vy,input);

                for(int k=0;k<count;k++)
                {
                    input[k]='\0';
                }
                count=0;
                setcolor(0);
                temp1=0;
                key1=37;
                delay(200);
                //key1=0;
            }

        }
        else if(mx>209&&mx<259&&my>271&&my<311&&on==1)
        {

            if(key!=38)
            {
            ob.restore_but(ptx,pty,pbx,pby,plx,ply,plx1,ply1,pstr,pstr1);
            key=38;
            ob.but_change(209,271,259,311,223,296,"nPr",223,281,"nCr");
            ptx=209;
            pty=271;
            pbx=259;
            pby=311;
            plx=223;
            ply=296;
            plx1=223;
            ply1=281;
            pstr="nPr";
            pstr1="nCr";
            }
            if(but==1&&key1!=38&&shift==0&&npr==0)
            {
                temp1=atof(input);
                ans=temp1;
                npr=1;
                setfillstyle(1,0);
                bar(51,141,586,169);
                setcolor(11);
                gcvt(ans,10,input);
                if(strlen(input)>9)
                    ob.strcut(input);

                outtextxy(61,152,"nPr");
                if(strlen(input)<=9)
                outtextxy(vx-strlen(input)*8+8,vy,input);

                for(int k=0;k<count;k++)
                {
                    input[k]='\0';
                }
                count=0;
                setcolor(0);
                temp1=0;
                key1=38;
                delay(200);
                //key1=0;
            }
            if(but==1&&key1!=38&&shift==0&&npr==1)
            {
                temp1=atof(input);
                ans=ob.per(ans,temp1);
                npr=0;
                setfillstyle(1,0);
                bar(51,141,586,169);
                setcolor(11);
                gcvt(ans,10,input);
                if(strlen(input)>9)
                    ob.strcut(input);


                if(strlen(input)<=9)
                outtextxy(vx-strlen(input)*8+8,vy,input);

                for(int k=0;k<count;k++)
                {
                    input[k]='\0';
                }
                count=0;
                setcolor(0);
                temp1=0;
                key1=38;
                delay(200);
                //key1=0;
            }
            /*if(but==1&&key1!=38&&shift==1&&ncr==0)
            {
                temp1=atof(input);
                ans=temp1;
                ncr=1;
                setfillstyle(1,0);
                bar(51,141,586,169);
                setcolor(11);
                gcvt(ans,10,input);
                if(strlen(input)>9)
                    ob.strcut(input);

                outtextxy(61,152,"nCr");
                if(strlen(input)<=9)
                outtextxy(vx-strlen(input)*8+8,vy,input);

                for(int k=0;k<count;k++)
                {
                    input[k]='\0';
                }
                count=0;
                setcolor(0);
                temp1=0;
                key1=38;
                delay(200);
                //key1=0;
            }
            if(but==1&&key1!=38&&shift==1&&ncr==1)
            {
                temp1=atof(input);
                ans=ob.com(ans,temp1);
                ncr=0;shift=0;
                setfillstyle(1,0);
                bar(51,141,586,169);
                setcolor(11);
                gcvt(ans,10,input);
                if(strlen(input)>9)
                    ob.strcut(input);


                if(strlen(input)<=9)
                outtextxy(vx-strlen(input)*8+8,vy,input);

                for(int k=0;k<count;k++)
                {
                    input[k]='\0';
                }
                count=0;
                setcolor(0);
                temp1=0;
                key1=38;
                delay(200);
                //key1=0;
            }*/
        }
        else if(mx>262&&mx<312&&my>271&&my<311&&on==1)
        {

            if(key!=39)
            {
            ob.restore_but(ptx,pty,pbx,pby,plx,ply,plx1,ply1,pstr,pstr1);
            key=39;
            ob.but_change(262,271,312,311,276,296,"e^x",284,281,"'");
            ptx=262;
            pty=271;
            pbx=312;
            pby=311;
            plx=276;
            ply=296;
            plx1=284;
            ply1=281;
            pstr="e^x";
            pstr1="'";
            }
            if(but==1&&key1!=39&&shift==0)
            {
                temp1=atof(input);
                ans=exp(temp1);
                setfillstyle(1,0);
                bar(51,141,586,169);
                setcolor(11);
                gcvt(ans,10,input);
                if(strlen(input)>9)
                    ob.strcut(input);

                //outtextxy(61,152,"ln");
                if(strlen(input)<=9)
                outtextxy(vx-strlen(input)*8+8,vy,input);

                for(int k=0;k<count;k++)
                {
                    input[k]='\0';
                }
                count=0;
                setcolor(0);
                temp1=0;
                key1=39;
                delay(200);
                //key1=0;
            }

        }
        else if(mx>537&&mx<587&&my>314&&my<354&&on==1)
        {

            if(key!=40)
            {
            ob.restore_but(ptx,pty,pbx,pby,plx,ply,plx1,ply1,pstr,pstr1);
            key=40;
            ob.but_change(537,314,587,354,558,340,"=",558,325,"%");
            ptx=537;
            pty=314;
            pbx=587;
            pby=354;
            plx=558;
            ply=340;
            plx1=558;
            ply1=325;
            pstr="=";
            pstr1="%";
            }

            if(but==1&&key1!=40&&shift==0)
            {       switch(operation)
                {
                case 1:
                {
                    temp1=atof(input);
                    ans=ans+temp1;
                }break;
                case 2:
                {
                    temp1=atof(input);
                    ans=ans-temp1;
                }break;
                case 3:
                {
                    temp1=atof(input);
                    ans=ans*temp1;
                }break;
                case 4:
                {
                    temp1=atof(input);
                    if(temp1==0)
                    {
                        input="Divide by zero error.";
                    }
                    else
                    {
                        ans=ans/temp1;
                        gcvt(ans,10,input);
                    }
                }break;
                /*case 0:
                    ans=temp1;
                    break;*/
                }
                equal=1;
                setfillstyle(1,0);
                bar(51,141,586,169);
                setcolor(11);
                outtextxy(61,152,"=");
                if(operation==4)
                outtextxy(vx-strlen(input)*8+8,vy,input);
                else
                {
                gcvt(ans,10,input);
                if(strlen(input)>9)
                    ob.strcut(input);
                outtextxy(vx-strlen(input)*8+8,vy,input);
                }
                for(int k=0;k<count;k++)
                {
                    input[k]='\0';
                }
                operation=0;
                add=0;sub=0;mul=0;div=0;
                setcolor(0);
                temp1=0;
                key1=40;
                delay(200);
                //key1=0;
            }

        }

        /*if(printed=0)
        {
            outtextxy();
        } */
        /*else if(key!=41)
        {
            restore_but(ptx,pty,pbx,pby,plx,ply,pstr);
            key=41;
        }*/
        if(but==2)
            break;


    }
    //getch();
}