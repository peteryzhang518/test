#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<list>
#include<windows.h>
using namespace std;
void gotothere(int x,int y,char z)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(handle,coord);
    cout<<z<<endl;
};
class food
{
    public:
    food(int x,int y){gotothere(x,y,'@');};
    void created(int width,int hight);
    private:
    int x,y;
};
void food::created(int width,int hight)
{
    int mark=0;
    while(mark!=1)
    {
        srand(time(NULL));
        x=rand()% width+1;
        y=rand()% hight+1;
        if(mark<1)//knock the wall or itself
        //aten by snack
        mark==1;
    }
    gotothere(x,y,'@');
};
class map
{
    public:
    map(int width,int hight);
    private:
    int width;
    int hight;
};
map::map(int width,int hight)
{
    for(int i=0;i<width+1;i++)
    {
        for (int j=0; j < hight+1; j++)
        {
            if(i==0||i==width||j==0||j==hight)
            {
                gotothere(i,j,'$');
            }
        }
        
    }
};
class snack
{
    public:
        snack(int width,int hight);
        int whatifsnackknock(list<int [2]> everysnack);
        int whatifsnackeat(list<int [2]> everysnack);
        void movesnack(list<int [2]> everysnack);
        void printfsnack(list<list<int>> everysnack);
    private:
        static list <list<int>> everysnack;
        char direction;
};
list<list<int>> snack::everysnack;
snack::snack(int width,int hight)
{   
    for(int i=0;i<5;i++)
    {
        list<int> temp;
        temp.push_back(width/2+i);
        temp.push_back(hight/2);
        everysnack.push_back(temp);
        //gotothere(width/2+i,hight/2,'$');
    }   
    printfsnack(everysnack);
}
void snack::printfsnack(list<list<int>> everysnack)
{
    for(int i=0;i<everysnack.size();i++)
    {
        list<list<int>>::iterator iterb =everysnack.begin();
        list<int> temp=*iterb;
        list<int>::iterator iters=temp.begin();
        gotothere(*iters,*(iters++),'$');
    }
};
int main()
{
    snack snack1(10,10);
    map map(10,10);
    system("pause");
    return 0;
}