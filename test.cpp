#include<iostream.h>
#include<conio.h>

class Information{
  protected:
    char name[];
    int age;
    float salary;
    float savings;
    float investment_goals;
    int risk_tolerance;
    // 1-10 where 1 is low risk low return and vice versa
public:
   void getInfo(){
    cout <<"\n"<< "Enter Name: ";
    cin >> name;
    cout <<"\n"<< "Enter Age: ";
    cin >> age;
    cout <<"\n"<< "Enter Salary: ";
    cin >> salary;
    cout <<"\n"<< "Enter Your Savings: ";
    cin >> savings;
    cout <<"\n"<< "Your Risk Tolerance: ";
    cin >> risk_tolerance;

   }  
};

class goals : protected virtual Information{
  protected:
    float mutual_funds_return_percentage;
    int number_of_years;
  public:
    int goal;
    void getGoals(){
      number_of_years = 10;
      cout << "******Your Goal*******"<<"\n";
      cout << "Enter Goal: "<<"\n";
      cout << "1. High Risk High Return "<<"\n";
      cout << "2. Medium Risk Medium Return "<<"\n";
      cout << "3. Low Risk Low Return "<<"\n";
      cin >> goal;
    }
};

class stocks : protected Information, protected goals{
  float stock_market_return_percentage;
  float stocksReturn;
  public:
  void calculator(){
    stock_market_return_percentage = 10;
    float initial_amount = (30 * salary)/100;

    // float final_amount = initial_amount * ((1 + stock_market_return_percentage) ** number_of_years);
    cout<<"initial_amount: "<< salary <<"\n";
    cout<<"stock_market_return_percentage: "<<stock_market_return_percentage <<"\n";
    cout<<"number_of_years: "<<number_of_years<<"\n";
    // cout<<"CALALALLA: "<<final_amount<<"\n";
  }
  
};

void main(){
  clrscr();
  Information client1;
  client1.getInfo();
  goals goal1;
  goal1.getGoals();
  if (goal1.goal == 1)
  {
      stocks StockObj;
      StockObj.calculator();
    
  }
  getch();
}
