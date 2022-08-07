#include <iostream>
#include<conio.h>
#include<cstdlib>
#include<math.h>

using namespace std;

#define KEY_UP 72+256
#define KEY_DOWN 80+256
#define KEY_LEFT 75+256
#define KEY_RIGHT 77+256

int get_code()
{
    int ch = getch();
    if (ch == 0 || ch == 224)
        ch = 256 + getch();
    return ch;
}

double distanceCalculate(double x1, double y1, double x2, double y2)
{
    double x = x1 - x2;
    double y = y1 - y2;
    double dist;

    dist = pow(x,2)+pow(y,2);           //calculating distance by euclidean formula
    dist = sqrt(dist);                  //sqrt is function in math.h

    return dist;
}

int main()
{
	
	int choose, treasure,x1,y1, x=0,y=0;
	cout<<"Welcome to Treasure finding game ."<<endl;
	cout<<"choose dificulty level "<<endl;
	cout<<"1.Hard "<<endl;
	cout<<"2.Medium"<<endl;
	cout<<"3.Easy"<<endl;
	cin>>choose;
    int c = 0;
    x1=rand()%20-10;
    y1=rand()%20-10;
    cout<<x1<<y1<<endl;
    int old_dist=0;    
    switch(choose){
    	case 1:
    	int move=0;
    	cout<<"\nmove : 12";
    	
     while(move<50)
      {
      	c= get_code();
      	switch (c)
        {
        case KEY_UP:
            y++;
            break;
        case KEY_DOWN:
            y--;
            break;
        case KEY_LEFT:
            x++;
            break;
        case KEY_RIGHT:
            x--;
            break;
        }
      	   	
        double  dist = distanceCalculate(x1, y1 , x, y);
		if(dist==0){
		  cout<<"\nyou win";
		  break;
		}
		
		if(dist<old_dist)
		cout<<"\ngetting close";
		if(dist>old_dist)
		cout<<"\ngoing away";
		old_dist=dist;
		
		move++;
		
	 }
 
    }

    return 0;
}









