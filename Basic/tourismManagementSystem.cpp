#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

static int p = 0;
class a
{
  char busn[5], driver[10], arrival[5], depart[5], from[10], to[10], seat[8][4][10];

public:

  void install();

  void allotment();

  void empty();

  void show();

  void avail();

  void menu();
  void position(int i);

}

bus[10];
void vline(char ch)
{
  for (int i=80;i>0;i--)
  cout<<ch;
}
void a::install()
{

  cout<<"\n\n\n\t\t\tEnter Bus no: ";

  cin>>bus[p].busn;

  cout<<"\n\t\t\tEnter Driver's name: ";

  cin>>bus[p].driver;

  cout<<"\n\t\t\tArrival time: ";

  cin>>bus[p].arrival;

  cout<<"\n\t\t\tDeparture: ";

  cin>>bus[p].depart;

  cout<<"\n\t\t\tFrom: ";

  cin>>bus[p].from;

  cout<<"\n\t\t\tTo: ";

  cin>>bus[p].to;

  bus[p].empty();

  p++;
  
  cout<<"\n\t\t\tBus added Sucessfully ";

}

void a::allotment()

{

  int seat;

  char number[5];

  top:

  cout<<"\n\n\n\t\t\tBus no: ";

  cin>>number;

  int n;

  for(n=0;n<=p;n++)

  {

    if(strcmp(bus[n].busn, number)==0)

    break;

  }

  while(n<=p)

  {

    cout<<"\n\t\t\tSeat Number: ";

    cin>>seat;

    if(seat>32)

    {

      cout<<"\n\t\t\tThere are only 32 seats available in this bus.";

    }

    else

    {

    if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)

      {

        cout<<"\t\t\tEnter passanger's name: ";

        cin>>bus[n].seat[seat/4][(seat%4)-1];
        
        cout<<"\t\t\tSeat Reserved Sucessfully ";

        break;

      }

    else

      cout<<"\t\t\tThe seat no. is already reserved.\n";

      }

      }

    if(n>p)

    {

      cout<<"\t\t\tEnter correct bus no.\n";

      goto top;

    }

  }


void a::empty()

{

  for(int i=0; i<8;i++)

  {

    for(int j=0;j<4;j++)

    {

      strcpy(bus[p].seat[i][j], "Empty");

    }

  }

}

void a::show()

{

  int n;

  char number[5];

  cout<<"\t\t\tEnter bus no: ";

  cin>>number;

  for(n=0;n<=p;n++)

  {

    if(strcmp(bus[n].busn, number)==0)

    break;

  }

while(n<=p)

{

  vline('*');

  cout<<"\t\t\tBus no: \t"<<bus[n].busn

  <<"\n\t\t\tDriver: \t"<<bus[n].driver<<"\t\tArrival time: \t"

  <<bus[n].arrival<<"\t\t\tDeparture time:"<<bus[n].depart

  <<"\n\t\t\tFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t"<<

  bus[n].to<<"\n";

  vline('*');

  bus[0].position(n);

  int a=1;

  for (int i=0; i<8; i++)

  {

    for(int j=0;j<4;j++)

    {

      a++;

      if(strcmp(bus[n].seat[i][j],"Empty")!=0)

      cout<<"\n\t\t\tThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";

    }

  }

  break;

  }

  if(n>p)

    cout<<"\t\t\tEnter correct bus no: ";

}

void a::position(int l)

{

  int s=0;p=0;

  for (int i =0; i<8;i++)

  {

    cout<<"\n";

    for (int j = 0;j<4; j++)

    {

      s++;

      if(strcmp(bus[l].seat[i][j], "Empty")==0)

        {

          cout.width(5);

          cout.fill(' ');

          cout<<s<<".";

          cout.width(10);

          cout.fill(' ');

          cout<<bus[l].seat[i][j];

          p++;

        }

        else

        {

        cout.width(5);

        cout.fill(' ');

        cout<<s<<".";

        cout.width(10);

        cout.fill(' ');

        cout<<bus[l].seat[i][j];

        }

      }

    }

  cout<<"\n\n\t\t\tThere are "<<p<<" seats empty in Bus No: "<<bus[l].busn;

  }

void a::avail()

{
 

    

}

void a::menu()

{

system("cls");

int w;

while(1)

{


  cout<<"\n\n\n\n\n";
  
  cout<<"\t\t\tTourist Bus Booking\n\n";
  

  cout<<"\t\t\t1.Add Bus\n\t\t\t"

  <<"2.Bus Reservation\n\t\t\t"

  <<"3.Show\n\t\t\t"

  <<"4.Buses Available \n\t\t\t"

  <<"5.Press any other key to return to Tourist Admin Menu - ";

  cout<<"\n\t\t\tEnter your choice:-> ";

  cin>>w;

  switch(w)

  {

    case 1:  bus[p].install();

      break;

    case 2:  bus[p].allotment();

      break;

    case 3:  bus[0].show();

      break;

    case 4:  bus[0].avail();

      break;
    
    default:
        return;


  }

}

}


char adminf[20]="Trip.txt";
char userf[20]="Reservation.txt";

struct tour{
 	char ad_place[20],ad_to[20],ad_code[20],ad_days[20],ad_prices[20];
 	char us_phone[20],us_name[20],us_people[20],us_date[20],us_status[20],us_dcode[20];
};

class Tourist{
             public:
                void ad_pack(tour r);
	            tour ad_unpack(char a[]);
	            void ad_writedata();
	            void ad_display();
	            void us_pack(tour r);
	            tour us_unpack(char a[]);
	            void us_writedata();
	            void us_display();
	            void us_search();
	            void us_modify();
                void menu();
};

// ADMIN PANEL
void Tourist::ad_pack(tour r){
     fstream fp;
     fp.open(adminf,ios::out|ios::app);
     if(!fp){
		cout<<"\nCannot open file";
		exit(0);
     }
     char buff[500];
     strcpy(buff,r.ad_code);
     strcat(buff,"|");
     strcat(buff,r.ad_place);
     strcat(buff,"|");
     strcat(buff,r.ad_to);
     strcat(buff,"|");
     strcat(buff,r.ad_days);
     strcat(buff,"|");
     strcat(buff,r.ad_prices);
     strcat(buff,"|");
     for(int i=0;i<500-strlen(buff);i++)
            strcat(buff,"|");
     fp<<buff<<endl;
     fp.close();
}

tour Tourist::ad_unpack(char buff[]){
	tour r;
	int i=0,j=0;
	while(buff[j]!='|')
	      r.ad_code[i++]=buff[j++];
	r.ad_code[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	      r.ad_place[i++]=buff[j++];
	r.ad_place[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	      r.ad_to[i++]=buff[j++];
	r.ad_to[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	      r.ad_days[i++]=buff[j++];
	r.ad_days[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	      r.ad_prices[i++]=buff[j++];
	r.ad_prices[i]='\0';
	return(r);
}


void Tourist::ad_writedata(){
    tour s;
    cout<<"Enter the Destination Code\nD-";
    cin>>s.ad_code;
    cout<<"Enter the Destination From : \n";
    cin>>s.ad_place;
    cout<<"Enter the Destination To : \n";
    cin>>s.ad_to;
    cout<<"Enter the Number of days of the Trip : \n";
    cin>>s.ad_days;
    cout<<"Enter the Cost of the trip : \n";
    cin>>s.ad_prices;
    ad_pack(s);
}


void Tourist::ad_display(){
    
 	fstream fp;
   	char buff[500];
   	tour r;
    fp.open(adminf,ios::in);
    if(!fp){
		cout<<"\nCannot open file";
		exit(0);
    }
    cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"Sr No.\t\tDEST. CODE\tFrom\t\t\tTo\t             DAYS\t        PRICES\n";
    cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
    int c=1;
    while(1){
        fp.getline(buff,500);
        if(fp.eof())break;
       		r=ad_unpack(buff);
        cout<<c++<<"\t\t"<<r.ad_code<<"\t\t"<<r.ad_place<<"\t\t"<<r.ad_to<<"\t\t" <<r.ad_days<<"\t\t"<<r.ad_prices<<endl;
    }
    fp.close();
    return;
}




void Tourist::us_pack(tour r){
    fstream fp;
    fp.open(userf,ios::out|ios::app);
    if(!fp){
        cout<<"\nFile Not Found";
		exit(0);
    }
    char buff[80];
    strcpy(buff,r.us_name);
    strcat(buff,"|");
    strcat(buff,r.us_phone);
    strcat(buff,"|");
    strcat(buff,r.us_people);
    strcat(buff,"|");
    strcat(buff,r.us_dcode);
    strcat(buff,"|");
    strcat(buff,r.us_date);
    strcat(buff,"|");
    strcat(buff,r.us_status);
    strcat(buff,"|");
    for(int i=0;i<80-strlen(buff);i++)
     	strcat(buff,"|");
    fp<<buff<<endl;
    fp.close();
}


tour Tourist::us_unpack(char buff[]){
	tour r;
	int i=0,j=0;
	while(buff[j]!='|')
	      r.us_name[i++]=buff[j++];
	r.us_name[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	      r.us_phone[i++]=buff[j++];
	r.us_phone[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	      r.us_people[i++]=buff[j++];
	r.us_people[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	      r.us_dcode[i++]=buff[j++];
	r.us_dcode[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	      r.us_date[i++]=buff[j++];
	r.us_date[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	      r.us_status[i++]=buff[j++];
	r.us_status[i]='\0';
	return(r);
}
void Tourist::us_writedata(){
    tour r;
    cout<<"ENTER YOUR NAME: ";
    cin>>r.us_name;
    cout<<"ENTER YOUR CONTACT NO: ";
    cin>>r.us_phone;
    cout<<"ENTER NO. OF TOURIST: ";
    cin>>r.us_people;
    cout<<"ENTER THE DESTINATION CODE: D-";
    cin>>r.us_dcode;
    cout<<"ENTER DATE OF JOURNEY (DD/MM/YY): ";
    cin>>r.us_date;
    cout<<"\nENTER 'Confirm' TO CONFIRM YOUR RESERVATION: ";
    cin>>r.us_status;
    us_pack(r);
}

void Tourist::us_display(){
 	fstream fp;
   	char buff[80];
   	tour r;
    fp.open(userf,ios::in);
    if(!fp){
		cout<<"\nCannot open file";
		exit(0);
    }
    cout<<"------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"Sr No.\tNAME\t\t\tCONTACT NO\t\t\tTOTAL PEOPLE\t\t\tDATE\t\t\tDEST. CODE\t\t\tSTATUS\n";
    cout<<"------------------------------------------------------------------------------------------------------------------------\n";
    int c=1;
    while(1){
        fp.getline(buff,80);
        if(fp.eof())break;
       		r=us_unpack(buff);
        cout<<c++<<"\t"<<r.us_name<<"\t\t"<<r.us_phone<<"\t\t\t"<<r.us_people<<"\t\t\t"<<r.us_date<<"\t\t\t"<<r.us_dcode<<"\t\t\t"<<r.us_status<<endl;
    }
    fp.close();
    return;
}


void Tourist::us_modify(){
    fstream fp;
    char us_name[15],buff[80];
    int i,j;
    tour s[100];
    fp.open(userf,ios::in);
    if(!fp){
		cout<<"\nFile not Found";
		exit(0);
    }
    cout<<"\nEnter Your name to cancel  your reservation: ";
    cin>>us_name;
    i=0;
   	while(1){
        fp.getline(buff,80);
        if(fp.eof())break;
        s[i]=us_unpack(buff);
        i++;
    }
   	for(j=0;j<i;j++){
        if(strcmp(s[j].us_name,us_name)==0){
	  		cout<<"\nYour Reservation Details are:\n";
	  		cout<<"\nName: "<<s[j].us_name;
	  		cout<<"\nContact No.: "<<s[j].us_phone;
	  		cout<<"\nNo.of People: "<<s[j].us_people;
	  		cout<<"\nDestination: "<<s[j].us_dcode;
	  		cout<<"\nDate of Journey: "<<s[j].us_date;
	  		cout<<"\nStatus: "<<s[j].us_status;
	  		cout<<"\n\nENTER 'Cancel' TO CANCEL YOUR TICKET: \n";
	  		cin>>s[j].us_status;
	  		cout<<"\nYour Reservation has been Cancelled\n";
	  		cout<<"\n\nName: "<<s[j].us_name;
	  		cout<<"\nContact No.: "<<s[j].us_phone;
	  		cout<<"\nNo.of People: "<<s[j].us_people;
	  		cout<<"\nDestination: "<<s[j].us_dcode;
	  		cout<<"\nDate of Journey: "<<s[j].us_date;
	  		cout<<"\nStatus: "<<s[j].us_status;
            break;
        }
    }
   	if(j==i){
        cout<<"\nRECORD NOT FOUND";
        return;
    }
    fp.close();
    fstream fd;
    fd.open(userf,ios::out|ios::trunc);
    if(!fd){
        cout<<"\nCannot open file";
        exit(0);
    }
   	for(j=0;j<i;j++)
        us_pack(s[j]);
   	fd.close();
}

void Tourist::us_search(){
 	fstream fp;
 	char us_name[15],buff[80];
 	int i,j;
 	tour s;
    fp.open(userf,ios::in);
    if(!fp){
	 	cout<<"\nCannot open file";
		exit(0);
    }
    cout<<"\nENTER THE NAME TO BE SEARCHED: ";
    cin>>us_name;
    i=0;
   	while(1){
        fp.getline(buff,80);
        if(fp.eof())break;
        s=us_unpack(buff);
        if(strcmp(s.us_name,us_name)==0){
	  	 	cout<<"\n RESERVATION FOUND\n";
	  		cout<<"\nNAME: "<<s.us_name;
	  		cout<<"\nCONTACT NO.: "<<s.us_phone;
	  		cout<<"\nNO. OF PEOPLE: "<<s.us_people;
	  		cout<<"\nDATE OF JOURNEY: "<<s.us_date;
	  		cout<<"\nSTATUS: "<<s.us_status;
	  		return;
	 	}
    }
    cout<<"\nRESERVATION NOT FOUND";
    return;
}
void Tourist::menu(){
    cout<<"---------------------------------------------------------------------------------------------------------" << endl << endl;
    cout<<"\t\t\t\t\t\tWELCOME TO TOURISM MANAGEMENT SYSTEM\n\n\n";
    cout<<"PRESS ENTER TO CONTINUE....\n\n";

    if(cin.get()=='\n'){
        system("cls");
        int choice,ch1,ch2;
        Tourist obj;
        cout<<"----------------------------------------------------------------------------------------------------" << endl;
        cout<<"\nWould you like to proceed as an admin or a customer ?\n";
        cout<<"1. ADMIN\n";
        cout<<"2. CUSTOMER\n\n";
        cout<<"Enter any other key for exit\n\n\n";
        cout<<"Enter Your Option\n";
        cin>>choice;
        switch(choice){
            case 1:
                system("cls");
                cout<<"WELCOME ADMIN\n";
                cout<<"Enter your option\n";
                cout<<"1. New Package\n";
                cout<<"2. Display Packages\n";
                cout<<"3. Display a Reservation\n";
                cout<<"4. Bus Reservation\n";
                
                cout<<"Enter any other key for exit\n\n";
                while(1){
                    cout<<"\nENTER UR CHOICE: ";
                    cin>>ch1;
                    switch(ch1){
                        case 1:
                            obj.ad_writedata();
                            break;
                        case 2:
                            obj.ad_display();
                            break;
                        case 3:
                            obj.us_display();
                            break;
                        case 4:
                            a busReservation;
                            busReservation.menu();
                            menu();
                            break;
                        default:
                            exit(0);
            }
        }
            case 2:
                system("cls");
                cout<<"WELCOME CUSTOMER\n";
                cout<<"Enter your option\n";
                cout<<"1. New Reservation\n";
                cout<<"2. Search Reservation\n";
                cout<<"3. Cancel Reservation\n";
                cout<<"Enter any other key for exit\n\n\n";
                while(1){
                    cout<<"\nENTER UR CHOICE: ";
                    cin>>ch2;
                    switch(ch2){
                        case 1:
                            cout<<"-----------------------------------";
                            cout<<"\n Choose Your destination\n";
                            cout<<"-----------------------------------\n";
                            obj.ad_display();
                            cout<<"\n";
                            obj.us_writedata();
                            break;
                        case 2:
                            obj.us_search();
                            break;
                        case 3:
                            obj.us_modify();
                            break;
                       
                        default:
                            exit(0);
                    }
                }
            default:
                exit(0);
        }
    }
}

int main(){
    Tourist tourist;
    tourist.menu();
}