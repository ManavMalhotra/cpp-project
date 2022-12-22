#include<iostream.h>
#include<conio.h>
#include<math.h>

class client{
  protected:
    char name[20];
    int age;
    int risk;
    long long assets;
  public:
    
    void getdata()
    {
      cout<<"Enter name of client: ";
      cin>>name;
      cout<<"Enter age of client: ";
      cin>>age;
      cout<<"Enter risk tolerance of client: ";
      cin>>risk;
      cout<<"Enter assets of client: ";
      cin>>assets;
    }
};

class consultant:public client{
  protected:
    int time;
    int monthly;
  public:
    void getdata(){

      client::getdata();
      cout<<"Enter time period: ";
      cin>>time;
      cout<<"Enter Monthly: ";
      cin>>monthly;
    }
};
class invest:public consultant
{
  protected:
    int rate;
  public:
    void getdata()
    {
      consultant::getdata();
      if(risk>=1 && risk<=3)
      {
        cout << "Based on your age of " << age 
             << " and risk tolerance of " << risk 
             << ", we recommend the following investment strategy:" << endl;
          cout<<"invest in stocks"<<endl;
          cout << "---------------------------------" << endl;
        rate=5;
      }
      else if(risk>=4 && risk<=7)
      {
        cout << "Based on your age of " << age 
             << " and risk tolerance of " << risk 
             << ", we recommend the following investment strategy:" << endl;
          cout<<"invest in stocks"<<endl;
          cout << "---------------------------------" << endl;
        rate=8;
      }
      else if(risk>=8 && risk<=10)
      {
        cout << "Based on your age of " << age 
             << " and risk tolerance of " << risk 
             << ", we recommend the following investment strategy:" << endl;
          cout<<"invest in stocks"<<endl;
          cout << "---------------------------------" << endl;
        rate=12;
      }
      
    }
};
class total:public invest{

  
  public:
    long long new_asset;
    void getdata()
    {
      invest::getdata();
// Total amount = Principal * (1 + (Yearly interest rate/100)) ^ (Number of years) + (Monthly investment * ( 
  // ((1 + (Yearly interest rate/100)) ^ (Number of years) - 1) / (Yearly interest rate/100) ))


      new_asset = assets * pow(1 + (rate/100), time) + (monthly * ((pow(1 + (rate/100), time) - 1) / (rate/100))) ;
      
      // assets=assets+(assets*rate*time)/100;
    }
    void display()
    {
      cout<<"\nName of client: "<<name;
      cout<<"\nAge of client: "<<age;
      cout<<"\nRisk tolerance of client(1-10): "<<risk;
      cout<<"\nNew Asset: "<<new_asset;
      cout<<"\nRate: "<<rate;
      cout<<"\nMonthly: "<<monthly;
      cout<<"\nAssets of client: "<<assets;
    }
};
int main()
{
  clrscr();
  total t;
  t.getdata();
  t.display();
  getch();
  return 0;
}
