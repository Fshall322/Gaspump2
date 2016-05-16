#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include <iomanip>

using namespace std;

//class for gaspump attributes
class GasPump{

    // private variables for gaspump attributes.

private :
    string methodOfPayment;
    int grade;
    char continuePumping;
    double gallonsDispenced;
    double amountCharged;

    // sets and gets
public :
    void setMethodOfPayment(string);
    string getMethodOfPayment();
    void setGrade(int);
    int getGrade();
    void setContinuePumping(char);
    char getContinuePumping();
    void setGallonsDispenced(double);
    double getGallonsDispenced();
    void setAmountCharged(double);
    double getAmountCharged();

    //function prototypes
    void paymentMethod();
    double cashPayed();
    void gradeOfGas(double, double, double);
    void pumpGas(double&, double, double, double, double);
    void creditCharge(double, double, double, double);
};

// int main
int main() {
    //variables
    double gallonsCount;
    const double CPG_87 = 1.35;
    const double CPG_89 = 1.45;
    const double CPG_93 = 1.55;
    const double GASPUMPED = 1.0;

    // class object decleration
    GasPump pump;
    //function calls
    pump.paymentMethod();
    pump.gradeOfGas(CPG_87, CPG_89, CPG_93);
    pump.pumpGas(gallonsCount, CPG_87, CPG_89, CPG_93, GASPUMPED);
    return 0;
}// end main

// sets and gets for class attributes.
void GasPump :: setMethodOfPayment(string m){
    methodOfPayment = m;
}
string GasPump :: getMethodOfPayment(){
    return methodOfPayment;
}

void GasPump :: setGrade(int g){
    grade = g;
}
int GasPump :: getGrade(){
    return grade;
}

void GasPump :: setContinuePumping(char c){
    continuePumping = c;
}
char GasPump :: getContinuePumping(){
    return continuePumping;
}

void GasPump :: setGallonsDispenced(double gd){
    gallonsDispenced = gd;
}
double GasPump :: getGallonsDispenced(){
    return gallonsDispenced;
}

void GasPump :: setAmountCharged(double a){
    amountCharged = a;
}
double GasPump :: getAmountCharged(){
    return amountCharged;
}

// function to get the payment method from the user.
void GasPump :: paymentMethod(){
    string method;
    bool quit = false;
    do{
        cout<<"Please enter in the payment type"<<endl;
        cout<<"Enter in Cash to pay with cash, or enter Credit to pay with credit"<<endl;
        cin>>method;
        setMethodOfPayment(method);
        quit=true;
        system("cls");// clears screen so only the text below will show while pumping

        if(method == "cash" || method == "Cash"){
            cout<<"You chose "<<getMethodOfPayment()<<endl;
            quit = true;
        }
        else if(method == "credit" || method == "Credit"){
            cout<<"You chose "<<getMethodOfPayment()<<endl;
            quit = true;
        }
        else{
            cout<<"You didnt enter in the right response"<<endl;
            quit = false;
        }
    }while(quit == false);
}

//function to get the desired cash amount of gas from the user.
double GasPump :: cashPayed(){
    double cashEntered;
    cout<<"Please enter in the cash amount you would like to buy in gas"<<endl;
    cin>>cashEntered;
    system("cls");// clears screen so only the text below will show while pumping

    if(cashEntered == 0){
        cout<<"You didnt enter in an amount"<<endl;
        cout<<"Please  enter in your amount again"<<endl;
        cin>>cashEntered;
    }
    else{
        cout<<"Thank you"<<endl;
        system("cls");// clears screen so only the text below will show while pumping
    }
    return cashEntered;
}

//function to get the desired grade of gas.. 87, 89, 93 octanes
void GasPump :: gradeOfGas(double CPG_87, double CPG_89, double CPG_93){
    bool quit = false;
    int gradeGas;
    do{
        cout<<"You can choose three types of gasses"<<endl;
        cout<<"If you would like 87 octane please enter 87"<<endl;
        cout<<"If you would like 89 octane please enter 89"<<endl;
        cout<<"If you would like 93 octane please enter 93"<<endl;
        cin>>gradeGas;
        setGrade(gradeGas);
        system("cls");// clears screen so only the text below will show while pumping

        if(getGrade() == 87){
            cout<<"you chose "<<getGrade()<<" octane and that will cost $"<<setprecision(2)<<fixed<<CPG_87<<" per gallon"<<endl;
            quit = true;
        }
        else if(getGrade() == 89){
            cout<<"you chose "<<getGrade()<<" octane and that will cost $"<<setprecision(2)<<fixed<<CPG_89<<" per gallon"<<endl;
            quit = true;
        }
        else if(getGrade() == 93){
            cout<<"you chose "<<getGrade()<<" octane and that will cost $"<<setprecision(2)<<fixed<<CPG_93<<" per gallon"<<endl;
            quit = true;
        }
        else
        {
            cout<<"You didn't enter in a proper value"<<endl;
            quit = false;
        }
    }while(quit == false);

}

//function to handle gaspumping. if you paid cash.
void  GasPump :: pumpGas(double& galCount, double CPG_87, double CPG_89, double CPG_93, double GASPUMPED){
    char keepPumping;
    double gallonsOwed;
    double galDispenced;
    double gasCost;
    double cash; // variable decleration

    // handles cash
    if(getMethodOfPayment() == "cash" || getMethodOfPayment() == "Cash"){

        //function call
        cash = cashPayed();

        cout<<" You paid $"<<cash<< " for your gas."<<endl;
        if(getGrade() == 87){
            gallonsOwed = cash / CPG_87;
        }
        else if(getGrade() == 89){
            gallonsOwed = cash / CPG_89;
        }
        else{
            gallonsOwed = cash / CPG_93;
        }
        cout<<"You'll get "<<gallonsOwed <<" gallons of gas"<<endl;
        cout<<"Once you have reached $"<<setprecision(2)<<fixed<<cash<<" in gas the pump will stop.."<<endl;
        cout<<"You may beign pumping"<<endl;

        if(getGrade() == 87){
            do{
                cout<<"Press y to continue pumping"<<endl;
                cin>>keepPumping;
                system("cls");// clears screen so only the text below will show while pumping
                setContinuePumping(keepPumping);
                double less = gallonsOwed - galCount;
                if ((less <= 1))
                {
                    galCount = gallonsOwed;
                    gasCost = cash;
                    galDispenced= galCount + 0.0005;
                }
                else
                {
                    ++galCount;
                    galDispenced = galCount * GASPUMPED;
                }
                setGallonsDispenced(galDispenced);
                gasCost = galCount * CPG_87;
                cout<<"Gas Cost: $"<<setprecision(2)<<fixed<<gasCost<<endl;
                cout<<"gallons: "<<getGallonsDispenced()<<endl;

            }while(getGallonsDispenced() <= gallonsOwed);
            system("cls");// clears screen so only the text below will show while pumping
            cout<<"You pumped "<<getGallonsDispenced()<<" gallons"<<endl;
            cout<<"Amount paid $"<<setprecision(2)<<fixed<<cash<<endl;
            cout<< "Please make sure to hang the pump up before you drive off"<<endl;
            cout<<"Have a nice day and thank you for your business"<<endl;
        }
        else if(getGrade() == 89){
            do{
                cout<<"Press y to continue pumping"<<endl;
                cin>>keepPumping;
                system("cls");// clears screen so only the text below will show while pumping
                setContinuePumping(keepPumping);
                double less = gallonsOwed - galCount;
                if ((less <= 1))
                {
                    galCount = gallonsOwed;
                    gasCost = cash;
                    galDispenced= galCount + 0.0005;
                }
                else
                {
                    ++galCount;
                    galDispenced = galCount * GASPUMPED;
                }
                setGallonsDispenced(galDispenced);
                gasCost = galCount * CPG_89;
                cout<<"Gas Cost: $"<<setprecision(2)<<fixed<<gasCost<<endl;
                cout<<"gallons: "<<getGallonsDispenced()<<endl;

            }while(getGallonsDispenced() <= gallonsOwed);
            system("cls");// clears screen so only the text below will show while pumping
            cout<<"You pumped "<<getGallonsDispenced()<<" gallons"<<endl;
            cout<<"Amount paid $"<<setprecision(2)<<fixed<<cash<<endl;
            cout<< "Please make sure to hang the pump up before you drive off"<<endl;
            cout<<"Have a nice day and thank you for your business"<<endl;
        }
        else{
            do{
                cout<<"Press y to continue pumping"<<endl;
                cin>>keepPumping;
                system("cls");// clears screen so only the text below will show while pumping
                setContinuePumping(keepPumping);
                double less = gallonsOwed - galCount;
                if ((less <= 1))
                {
                    galCount = gallonsOwed;
                    gasCost = cash;
                    galDispenced= galCount + 0.0005;
                }
                else
                {
                    ++galCount;
                    galDispenced = galCount * GASPUMPED;
                }
                setGallonsDispenced(galDispenced);
                gasCost = galCount * CPG_93;
                cout<<"Gas Cost: $"<<setprecision(2)<<fixed<<cash<<endl;
                cout<<"gallons: "<<getGallonsDispenced()<<endl;

            }while(getGallonsDispenced() <= gallonsOwed);
            system("cls");// clears screen so only the text below will show while pumping
            cout<<"You pumped "<<getGallonsDispenced()<<" gallons"<<endl;
            cout<<"Amount paid $"<<setprecision(2)<<fixed<<cash<<endl;
            cout<< "Please make sure to hang the pump up before you drive off"<<endl;
            cout<<"Have a nice day and thank you for your business"<<endl;
        }
    }
        // handles Credit
    else if(getMethodOfPayment() == "credit" || getMethodOfPayment() == "Credit"){
        srand( time( NULL ) );
        int gasTank = rand() % 24 + 1;// for a 24 tank truck..
        cout<<"Your gas tank is low: "<<gasTank<<" gallons"<<endl;
        cout<<"Thank You!"<<endl;
        cout<<"You may beign pumping"<<endl;

        if(getGrade() == 87){
            do{
                cout<<"Press y to continue pumping, n to stop"<<endl;
                cin>>keepPumping;
                if (keepPumping == 'n')
                    break;
                system("cls");// clears screen so only the text below will show while pumping
                setContinuePumping(keepPumping);
                ++galCount;
                gasCost = galCount * CPG_87;
                cout<<"Gas cost is: $"<<setprecision(2)<<fixed<<gasCost<<endl;
                cout<<"Gallon count is: "<<galCount<<endl;

            }while(getContinuePumping( ) == 'y');

            creditCharge(galCount, CPG_87, CPG_89, CPG_93);
        }
        else if(getGrade() == 89){
            do{
                cout<<"Press y to continue pumping, n to stop"<<endl;
                cin>>keepPumping;
                if (keepPumping == 'n')
                    break;
                system("cls");// clears screen so only the text below will show while pumping
                setContinuePumping(keepPumping);
                ++galCount;
                gasCost = galCount * CPG_89;
                cout<<"Gas cost is: $"<<setprecision(2)<<fixed<<gasCost<<endl;
                cout<<"Gallon count is: "<<galCount<<endl;

            }while(getContinuePumping( ) == 'y');

            creditCharge(galCount, CPG_87, CPG_89, CPG_93);
        }
        else{

            do{
                cout<<"Press y to continue pumping, n to stop"<<endl;
                cin>>keepPumping;
                if (keepPumping == 'n')
                    break;
                system("cls");// clears screen so only the text below will show while pumping
                setContinuePumping(keepPumping);
                ++galCount;
                gasCost = galCount * CPG_93;
                cout<<"Gas cost is: $"<<setprecision(2)<<fixed<<gasCost<<endl;
                cout<<"Gallon count is: "<<galCount<<endl;

            }while(getContinuePumping( ) == 'y');

            creditCharge(galCount, CPG_87, CPG_89, CPG_93);
        }
    }
}//end pumpGas

//Function to determine the amount to charge to credit card.
void GasPump :: creditCharge(double gallonsCount, double CPG_87, double CPG_89, double CPG_93){
    double gasCost;
    if(getGrade() == 87){
        gasCost = gallonsCount * CPG_87;
    }
    else if(getGrade() == 89){
        gasCost = gallonsCount * CPG_89;
    }
    else{
        gasCost = gallonsCount * CPG_93;
    }
    system("cls");// clears screen so only the text below will show while pumping
    cout<<"The price that will be charged to your credit card is: $"<<setprecision(2)<<fixed<<gasCost<<endl;
    cout<< "Please make sure to hang the pump up before you drive off"<<endl;
    cout<<"Have a nice day and thank you for your business"<<endl;
}
