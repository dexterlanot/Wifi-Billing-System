#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
static int i = 0;
using namespace std;

struct Wifi {
  string cosName, cosAddress, wifiService, contactNo;
  int  duedate, month, day, year, k=0;
  float balance, dueAmount;
  int accAccnum;

  void inputBill();
  void searchBill();
  void viewBills();
} costumers[10];


void programTitle() {
    system("cls");
    cout << "\n\n\n\t\t-----------------------------------------\n\n";
    cout << "\t\t|        PLDT WIFI BILLING SYSTEM       |\n\n";
    cout << "\t\t-----------------------------------------\n\n";
    cout << "\t\t\t\t    By: \n\n";
    cout << "\t\t   Leader: \n";
    cout << "\t\t\tCastillo, Shan Iederf\n\n";
    cout << "\t\t   Members:\n";
    cout << "\t\t\tBautisa, Cyrille\n";
    cout << "\t\t\tCastillo, Mark Dave\n";
    cout << "\t\t\tDimaandal, Justin\n";
    cout << "\t\t\tFlores, Albert Geoffrey\n";
    cout << "\t\t\tMasangcay, Adrian Joshua\n\n";
    cout << "\t\t-----------------------------------------\n\n";
    cout << "\t\t------- Press any key to continue ------- \n\t\t";
    _getch();
}

int mainMenu(int choice) {
    system("cls");
    cout << "\n\n\n\t\t-----------------------------------------\n\n";
    cout << "\t\t:::::::::|     ACCOUNTS MENU    |::::::::\n\n";
    cout << "\t\t-----------------------------------------\n\n";
    cout << "\t\t   [1] ADMIN PANEL\n\n";
    cout << "\t\t   [2] COSTUMER'S PANEL\n\n";
    cout << "\t\t   [3] EXIT\n\n";
    cout << "\t\t-----------------------------------------\n\n";
    cout << "\t\tEnter your choice: ";
    cin >> choice;
    return choice;
}

void adminLogin(string adminPass){
    login:
    system("cls");
    cout << "\n\n\n\t\t Enter admin password : ";
    cin >> adminPass;

    while(adminPass != "admin"){
      cout << "\n\n\t\t-----------------------------------------";
      cout << "\n\n\n\t\t\t   Incorrect password! \n\n\n\t\t-------- Press enter to try again -------\n\t\t";
      _getch();
      goto login;
    }
}

int adminPanel(int choice) {
    system("cls");
    cout << "\n\n\n\t\t-----------------------------------------\n\n";
    cout << "\t\t:::::::::|      ADMIN PANEL     |::::::::\n\n";
    cout << "\t\t-----------------------------------------\n\n";
    cout << "\t\t   [1] INPUT COSTUMER BILLING DETAILS\n\n";
    cout << "\t\t   [2] DISPLAY ALL COSTUMER RECORDS\n\n";
    cout << "\t\t   [3] GO BACK TO ACCOUNTS MENU\n\n";
    cout << "\t\t-----------------------------------------\n\n";
    cout << "\t\tEnter your choice: ";
    cin >> choice;
    return choice;
}

int cosPanel(int choice) {
    system("cls");
    cout << "\n\n\n\t\t-----------------------------------------\n\n";
    cout << "\t\t:::::::::|    COSTUMER PANEL    |::::::::\n\n";
    cout << "\t\t-----------------------------------------\n\n";
    cout << "\t\t  [1] SUBSCRIPTION SERVICES INFORMATION\n\n";
    cout << "\t\t  [2] SEARCH ACCOUNT BILL\n\n";
    cout << "\t\t  [3] GO BACK TO ACCOUNTS MENU\n\n";
    cout << "\t\t-----------------------------------------\n\n";
    cout << "\t\tEnter your choice: ";
    cin >> choice;
    return choice;
}

void Wifi::inputBill() {
    input:system("cls");
    cout << "\n\n\n\t\t--------------------------------------------\n\n";
    cout << "\t\t   :::::::::|    BILLING DETAILS   |::::::::\n\n";
    cout << "\t\t--------------------------------------------\n\n";
    cout << "\t\t Account no.       : ";
    cin >> costumers[i].accAccnum;
    for (int x = 0; x < i; x++) {
        if (costumers[i].accAccnum == costumers[x].accAccnum) {
            cout << "\n\t\t You already used this account no.\n\t\t Press any key again.\n\n";
            _getch();
            goto input;
        }
    }
    cin.ignore();
    cout << "\t\t Costumer name     : ";
    getline (cin, costumers[i].cosName);
    cout << "\t\t Address           : ";
    getline (cin, costumers[i].cosAddress);
    cout << "\t\t Contact no.       : ";
    cin >> costumers[i].contactNo;
    cout << "\n\t\t [1] Fiber Plus Plan 2399 \n\t\t [2] Fiber Plus Plan 2999 \n\t\t [3] Fiber Plus Plan 4099 \n";
    cout << "\n\t\t Availed Fiber Plan : ";
    cin >> costumers[i].wifiService;
    if (costumers[i].wifiService == "1"){
      costumers[i].balance = 2399.00;
      cout << "\n\t\t Total amount due  : Php ";
      cout << costumers[i].balance;
    } else if (costumers[i].wifiService == "2"){
      costumers[i].balance = 2999.00;
      cout << "\n\t\t Total amount due  : Php ";
      cout << costumers[i].balance;
    } else if (costumers[i].wifiService == "3"){
      costumers[i].balance = 4099.00;
      cout << "\n\t\t Total amount due  : Php ";
      cout << costumers[i].balance;
    } else {
      cout << "\n\t\t Invalid!\n\t\t Press any key to try again.\n";
      _getch();
      goto input;
    }

    cout << "\n\n\t\t---------------| DUE DATE |---------------\n\n";
    cout << "\n\t\t NOTE: Input date in numerical manner\n\n";
    cout << "\t\t   Month           : ";
    cin >> costumers[i].month;
    cout << "\t\t   Day             : ";
    cin >> costumers[i].day;
    cout << "\t\t   Year            : ";
    cin >> costumers[i].year;
    if (costumers[i].wifiService == "1"){
      costumers[i].dueAmount = 2499.00;
      cout << "\n\t\t Due after deadline  : Php ";
      cout << costumers[i].dueAmount;
    } else if (costumers[i].wifiService == "2"){
      costumers[i].dueAmount = 3099.00;
      cout << "\n\t\t Due after deadline  : Php ";
      cout << costumers[i].dueAmount;
    } else if (costumers[i].wifiService == "3"){
      costumers[i].dueAmount = 4199.00;
      cout << "\n\t\t Due after deadline  : Php ";
      cout << costumers[i].dueAmount;
    } else {
      cout << "\n\t\t Invalid!\n\t\t Press any key to try again.\n";
      _getch();
      goto input;
    }


    fstream readBilldata;
    readBilldata.open ("Wifibill.txt", ios::out);
    {
        for (k=0; k<10; k++){
        if (costumers[k].cosName!=""){
        readBilldata << "\t\t--------------------------------------------\n\n";
        readBilldata << "\t\t               BILL SUMMARY\n\n";
        readBilldata << "\t\t--------------------------------------------\n\n";
        readBilldata << "\t\t Account no.       : " << costumers[k].accAccnum;
        readBilldata << "\n\t\t Costumer name     : " << costumers[k].cosName;
        readBilldata << "\n\t\t Contact no.       : " << costumers[k].contactNo;
        readBilldata << "\n\t\t Address           : " <<  costumers[k].cosAddress;
        readBilldata << "\n\t\t Total amount due  :  Php " << costumers[k].balance;
        readBilldata << "\n\n\t\t Due date            : " << costumers[k].month << " / " << costumers[k].day << " / " << costumers[k].year;
        readBilldata << "\n\t\t Due after deadline  : Php " << costumers[k].dueAmount;
        readBilldata << "\n\n\t\t-----------------------------------------\n\n";

        } else {
        break;
        }
      }
      readBilldata.close();
    }

    i++;
    cout << "\n\n\t\t-----------------------------------------\n\n";
    cout << "\t\t         Bill has been created!";
}

void Wifi::viewBills() {
    system("cls");
    cout << "\n\n\n\t\t--------------------------------------------\n\n";
    cout << "\t\t ::::::::|  ALL BILLS INFORMATION   |:::::::\n\n";
    cout << "\t\t--------------------------------------------\n\n";
    for (int j=0; j<10; j++){
      if (costumers[0].accAccnum==0){
          cout << "\t\tNO CREATED BILL INFORMATION AS OF THE MOMENT\n\n";
          cout << "n\t\t--------------------------------------------\n\n";
      }
      if (costumers[j].cosName!=""){
      cout << "\t\t--------------------------------------------\n\n";
      cout << "\t\t               BILL SUMMARY\n\n";
      cout << "\t\t Account no.       : " << costumers[j].accAccnum;
      cout << "\n\t\t Costumer name     : " << costumers[j].cosName;
      cout << "\n\t\t Address           : " <<  costumers[j].cosAddress;
      cout << "\n\t\t Contact No.       : " <<  costumers[j].contactNo;
      cout << "\n\n\t\t Total amount due  : Php " << costumers[j].balance;
      cout << "\n\n\t\t Due date            : " << costumers[j].month << " / " << costumers[j].day << " / " << costumers[j].year;
      cout << "\n\t\t Due after deadline  : Php " << costumers[j].dueAmount;
      cout << "\n\n\t\t--------------------------------------------\n\n";
      }
      else {
      break;
    }
    }
  }

void subcServices(){
  system("cls");
  cout << "\n\n\n\t\t--------------------------------------------\n\n";
  cout << "\t\t ::::::::|  PDLT Fiber Plus Plans   |:::::::\n\n";
  cout << "\t\t--------------------------------------------\n\n";
  cout << "\t\t--------------------------------------------\n\n";
  cout << "\t\t\t\t  100 MBPS\n\n";
  cout << "\t\t\t       FIBER PLUS PLAN\n";
  cout << "\t\t\t        PHP 2,399.00\n\n";
  cout << "\t\t--------------------------------------------\n\n";
  cout << "\t\t      Good for big homes with more than\n\t\t        3 devices to enjoy seamless HD\n\t\t       streaming, gaming and large file\n\t\t\t\ttransfers.\n\n";
  cout << "\t\t--------------------------------------------\n\n";
  cout << "\t\t--------- Press any key to continue --------\n";
  _getch();
  system("cls");
  cout << "\n\n\n\t\t--------------------------------------------\n\n";
  cout << "\t\t ::::::::|  PDLT Fiber Plus Plans   |:::::::\n\n";
  cout << "\t\t--------------------------------------------\n\n";
  cout << "\t\t--------------------------------------------\n\n";
  cout << "\t\t\t\t  300 MBPS\n\n";
  cout << "\t\t\t       FIBER PLUS PLAN\n";
  cout << "\t\t\t        PHP 2,999.00\n\n";
  cout << "\t\t--------------------------------------------\n\n";
  cout << "\t\t      Suitable for larger households to\n\t\t     stream ultra HD, share large files,\n\t\t     and play online gaming on multiple\n\t\t\t\tdevices.\n\n";
  cout << "\t\t--------------------------------------------\n\n";
  cout << "\t\t--------- Press any key to continue --------\n";
  _getch();
  system("cls");
  cout << "\n\n\n\t\t--------------------------------------------\n\n";
  cout << "\t\t ::::::::|  PDLT Fiber Plus Plans   |:::::::\n\n";
  cout << "\t\t--------------------------------------------\n\n";
  cout << "\t\t--------------------------------------------\n\n";
  cout << "\t\t\t\t  600 MBPS\n\n";
  cout << "\t\t\t       FIBER PLUS PLAN\n";
  cout << "\t\t\t        PHP 4,099.00\n\n";
  cout << "\t\t--------------------------------------------\n\n";
  cout << "\t\t      Ideal for larger households with\n\t\t     more than 7 devices to do instant\n\t\t       file transfers, buffer-free HD\n\t\t\t   streaming and more!\n\n";
  cout << "\t\t--------------------------------------------\n\n";
}

void Wifi::searchBill() {
  system("cls");
  int accNum, counter=0;
  cout << "\n\n\t\t--------------------------------------------\n\n";
  cout << "\t\t           SEARCH YOUR WIFI BILL\n\n";
  cout << "\t\t--------------------------------------------\n\n";
  cout << "\t\tEnter your account no: ";
  cin >> accNum;
  for (int l=0; l<10; l++){
    if (costumers[l].accAccnum == accNum){
      counter++;
      cout << "\n\t\t--------------------------------------------\n\n";
      cout << "\t\t            STATEMENT OF ACCOUNT\n\n";
      cout << "\t\t--------------------------------------------\n\n";
      cout << "\t\t Account no.       : " << costumers[l].accAccnum;
      cout << "\n\t\t Costumer name     : " << costumers[l].cosName;
      cout << "\n\t\t Address           : " <<  costumers[l].cosAddress;
      cout << "\n\t\t Contact No.       : " <<  costumers[l].contactNo;
      cout << "\n\n\t\t--------------------------------------------";
      cout << "\n\n\t\t Total amount due  : Php " << costumers[l].balance;
      cout << "\n\n\t\t--------------------------------------------";
      cout << "\n\n\t\t Due date            : " << costumers[l].month << " / " << costumers[l].day << " / " << costumers[l].year;
      cout << "\n\t\t Due after deadline  : Php " << costumers[l].dueAmount;
      cout << "\n\n\t\t Please pay on or before " << costumers[l].month << " / " << costumers[l].day << " / " << costumers[l].year;;
      cout << "\n\n\t\t----------------| REMINDERS |---------------\n\n";
      cout << "\t\tDisconnection is 10 days from dure date\n\t\tindicated in this bill to prevent service \n\t\tinterruptions.";
      cout << "\n\n\t\t--------------------------------------------\n\n";
    }
  }
  if (counter==0){
      cout << "\n\t\t--------------------------------------------\n\n";
      cout << "\t\t         Admin is still working on \n\t\t\t   your bill information.\n\n";
      cout << "\t\t--------------------------------------------\n\n";
  }
}

int main(){
    int menuChoice, adminChoice, cosChoice;
    string adminPass;
    programTitle();

    main:
    system("cls");
    menuChoice = mainMenu(menuChoice);
    switch (menuChoice){
      case 1:
        adminLogin(adminPass);
        admin:
        system("cls");
        adminChoice = adminPanel(adminChoice);

        switch (adminChoice) {

          case 1:
            costumers[i].inputBill();
            cout << "\n\n\t\t-----------------------------------------\n\n";
            cout << "\t\tPress any key to go back to admin panel\n\t\t";
            _getch();
            goto admin;
          break;

          case 2:
            costumers[i].viewBills();
            cout << "\t\tPress any key to go back to admin panel\n\t\t";
            _getch();
          goto admin;
          break;

          case 3:
            goto main;
          break;

          default:
            cout << "Invalid choice!\n\n";
            cout << "Press any key to continue";
            _getch();
            goto admin;
          break;
        }
      break;

      case 2:
        cos:
        system("cls");
        cosChoice = cosPanel(cosChoice);

        switch (cosChoice){

          case 1:
            subcServices();
            cout << "\t\tPress any key to go back to costumer panel\n\t\t";
            _getch();
            goto cos;
          break;

          case 2:
            costumers[i].searchBill();
            cout << "\n\t\tPress any key to go back to costumer panel\n\t\t";
            _getch();
            goto cos;
          break;

          case 3:
            goto main;
          break;

          default:
            cout << "\t\tInvalid choice!\n\n";
            cout << "\t\tPress any key to continue\n";
            _getch();
            goto cos;
          break;
      }
      break;

      case 3:
        exit(0);
      break;

      default:
      cout << "Invalid choice!\n\n";
      cout << "Press any key to continue";
      _getch();
      goto main;
      break;
    }
  return 0;
}
