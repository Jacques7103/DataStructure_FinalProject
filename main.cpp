#include <iostream>
#include <ctime>
#include <array>
#include <map>
#include "./stack.hpp"
#include "./queue.hpp"

using namespace std;

int year, month, date, hour, minute, sec;
int userDate, userMonth, userYear;
int initialYear;
Stack<int> split;
int count = 0;

//List Item
Queue<string> queueItem;

//List based on item
map<string, int(*)[100]> userItem1;
map<string, int(*)[100]> userItem2;
map<string, int(*)[100]> userItem3;
map<string, int(*)[100]> userItem4;
map<string, int(*)[100]> userItem5;

//List of dmy
array<int, 100> userDMY1;
int user1count = 0;
array<int, 100> userDMY2;
int user2count = 0;
array<int, 100> userDMY3;
int user3count = 0;
array<int, 100> userDMY4;
int user4count = 0;
array<int, 100> userDMY5;
int user5count = 0;

array<string, 100> userName1;
array<string, 100> userName2;
array<string, 100> userName3;
array<string, 100> userName4;
array<string, 100> userName5;

array<int, 100> userAmount1;
array<int, 100> userAmount2;
array<int, 100> userAmount3;
array<int, 100> userAmount4;
array<int, 100> userAmount5;

//User Input / Main function
string item;
int ddmmyyyy; 
bool check = true;
bool check2 = true;
int opt1;
int addData;
string name;
int amount;
int getData;
int itemRemove;
int itemRemove2;

bool checkTime(){
    // divideDate(dmy, userDate, userMonth, userYear);
    time_t date = time(0);
    tm *today = localtime(&date);
    year = 1900 + today->tm_year;
    month = 1 + today->tm_mon;
    date = today->tm_mday;
    hour = today->tm_hour;
    minute = today->tm_min;
    sec = today->tm_sec;

    if (userYear <= year){
        if (userMonth <= month){
            if (userDate <= date){
                return true;
            }
        }
    } 
    return false;
}

//Use format day, month, year
void divideDate(int dmy, int &userDate, int &userMonth, int &userYear){
    for (int i = 0; i <= 7; i++){
        if (i == 0){
            split.add(dmy % 10); 
            count += 10;
        } else {
            split.add(dmy / count % 10);
            count = count * 10;
        }
    }

    for (int i = 0; i < 2; i++){
        int temp = split.pop();
        int temp2 = split.pop();

        if (i == 0){
            string tempDate = to_string(temp) + to_string(temp2);
            userDate = stoi(tempDate);
        } else {
            string tempMonth = to_string(temp) + to_string(temp2);
            userMonth = stoi(tempMonth);
        }
    }

    string tempYear = "";
    for (int i = 0; i <=3 ; i++){
        int temp = split.pop();

        tempYear += to_string(temp);

        if (i == 3){
            userYear = stoi(tempYear);
        }
    }
}

int combineNum(int a, int b){
    string num1 = to_string(a);
    string num2 = to_string(b);

    if (num1 == "0"){
        int result = stoi(num2);

        return result;
    } else {
        string num12 = num1 + num2;
        int result = stoi(num12);

        return result;
    }
}

int countNum(int num){
    if (num / 10 == 0){
        return 1;
    }
    return 1 + countNum(num / 10);
}

void addList(){

}

int main(){
    cout << "Welcome to the Stock List !!" << endl;
    cout << "Please tell us the year your store open (4 digit) : ";
    cin >> initialYear;
    while (countNum(initialYear) != 4 || initialYear > 2022 || initialYear < 1950){
        cout << "============================================" << endl;
        cout << "Please re-enter the valid year (4 digit) : ";
        cin >> initialYear;
    }
    cout << "What would you like to do?" << endl;

    while (check) {
        cout << "1. Add Item" << endl;
        cout << "2. Add Data" << endl;
        cout << "3. Delete Item" << endl;
        cout << "4. Delete Data" << endl;
        cout << "5. Display Data" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your input : ";
        cin >> opt1;

        while (check2){
            switch (opt1){
            case 1:
                cout << "============================================" << endl;
                cout << "Enter the name of the Item: ";
                cin >> item;
                queueItem.enqueue(item);
                cout << "'" << item << "' has successfuly added!" << endl;
                break;

            case 2:
                cout << "============================================" << endl;
                if (queueItem.getSize() == 0){
                    cout << "There is no item in the list yet !!" << endl;
                    break;
                }
                cout << "List of items : " << endl;
                for (int i = 0; i < queueItem.getSize(); i++){
                    cout << i + 1 << ". ";
                    queueItem.getIndex(i);
                }
                cout << "Please choose the item to add data : ";
                cin >> getData;
                while (true){
                    if (getData == 1 || queueItem.getSize() == 1){
                        cout << "Enter the date with format (ddmmyyyy): ";
                        cin >> ddmmyyyy;
                        divideDate(ddmmyyyy, userDate, userMonth, userYear);
                        while (true){
                            if (checkTime()){
                                userDMY1[user1count] = ddmmyyyy;
                                cout << "Enter the name of person : ";
                                cin >> name;
                                userName1[user1count] = name;
                                cout << "Enter the ammount of item that is sold : ";
                                cin >> amount;
                                while (true){
                                    if (amount < 1){
                                        cout << "The number should be greater than 1 !!" << endl;
                                        cout << "Please re-enter the number of item : ";
                                        cin >> amount;
                                    } else {
                                        userAmount1[user1count] = amount;
                                        cout << "The data has been inputed !!" << endl;
                                        break;
                                    }
                                }
                                break;
                            } else {
                                cout << "The date you inputed is invalid !!" << endl;
                                cout << "Do you wish to cancel adding data?" << endl;
                                cout << "1. Cancel adding data" << endl;
                                cout << "2. Continue adding data" << endl;
                                cout << "Enter your input : ";
                                cin >> addData;
                                if (addData == 1){
                                    break;
                                } else {
                                    cout << "Please re-enter the date with format (ddmmyyyy) : ";
                                    cin >> ddmmyyyy;
                                }
                            }
                        }
                        break;
                    } else if (getData == 2 || queueItem.getSize() == 2){
                        cout << "Enter the date with format (ddmmyyyy): ";
                        cin >> ddmmyyyy;
                        divideDate(ddmmyyyy, userDate, userMonth, userYear);
                        while (true){
                            if (checkTime()){
                                userDMY2[user2count] = ddmmyyyy;
                                cout << "Enter the name of person : ";
                                cin >> name;
                                userName2[user2count] = name;
                                cout << "Enter the ammount of item that is sold : ";
                                cin >> amount;
                                while (true){
                                    if (amount < 1){
                                        cout << "The number should be greater than 1 !!" << endl;
                                        cout << "Please re-enter the number of item : ";
                                        cin >> amount;
                                    } else {
                                        userAmount2[user2count] = amount;
                                        cout << "The data has been inputed !!" << endl;
                                        break;
                                    }
                                }
                                break;
                            } else {
                                cout << "The date you inputed is invalid !!" << endl;
                                cout << "Do you wish to cancel adding data?" << endl;
                                cout << "1. Cancel adding data" << endl;
                                cout << "2. Continue adding data" << endl;
                                cout << "Enter your input : ";
                                cin >> addData;
                                if (addData == 1){
                                    break;
                                } else {
                                    cout << "Please re-enter the date with format (ddmmyyyy) : ";
                                    cin >> ddmmyyyy;
                                }
                            }
                        }
                        break;
                    } else if (getData == 3 || queueItem.getSize() == 3){
                        cout << "Enter the date with format (ddmmyyyy): ";
                        cin >> ddmmyyyy;
                        divideDate(ddmmyyyy, userDate, userMonth, userYear);
                        while (true){
                            if (checkTime()){
                                userDMY3[user3count] = ddmmyyyy;
                                cout << "Enter the name of person : ";
                                cin >> name;
                                userName3[user3count] = name;
                                cout << "Enter the ammount of item that is sold : ";
                                cin >> amount;
                                while (true){
                                    if (amount < 1){
                                        cout << "The number should be greater than 1 !!" << endl;
                                        cout << "Please re-enter the number of item : ";
                                        cin >> amount;
                                    } else {
                                        userAmount3[user3count] = amount;
                                        cout << "The data has been inputed !!" << endl;
                                        break;
                                    }
                                }
                                break;
                            } else {
                                cout << "The date you inputed is invalid !!" << endl;
                                cout << "Do you wish to cancel adding data?" << endl;
                                cout << "1. Cancel adding data" << endl;
                                cout << "2. Continue adding data" << endl;
                                cout << "Enter your input : ";
                                cin >> addData;
                                if (addData == 1){
                                    break;
                                } else {
                                    cout << "Please re-enter the date with format (ddmmyyyy) : ";
                                    cin >> ddmmyyyy;
                                }
                            }
                        }
                        break;
                    } else if (getData == 4 || queueItem.getSize() == 4){
                        cout << "Enter the date with format (ddmmyyyy): ";
                        cin >> ddmmyyyy;
                        divideDate(ddmmyyyy, userDate, userMonth, userYear);
                        while (true){
                            if (checkTime()){
                                userDMY4[user4count] = ddmmyyyy;
                                cout << "Enter the name of person : ";
                                cin >> name;
                                userName4[user4count] = name;
                                cout << "Enter the ammount of item that is sold : ";
                                cin >> amount;
                                while (true){
                                    if (amount < 1){
                                        cout << "The number should be greater than 1 !!" << endl;
                                        cout << "Please re-enter the number of item : ";
                                        cin >> amount;
                                    } else {
                                        userAmount4[user4count] = amount;
                                        cout << "The data has been inputed !!" << endl;
                                        break;
                                    }
                                }
                                break;
                            } else {
                                cout << "The date you inputed is invalid !!" << endl;
                                cout << "Do you wish to cancel adding data?" << endl;
                                cout << "1. Cancel adding data" << endl;
                                cout << "2. Continue adding data" << endl;
                                cout << "Enter your input : ";
                                cin >> addData;
                                if (addData == 1){
                                    break;
                                } else {
                                    cout << "Please re-enter the date with format (ddmmyyyy) : ";
                                    cin >> ddmmyyyy;
                                }
                            }
                        }
                        break;
                    } else if (getData == 5 || queueItem.getSize() == 5){
                        cout << "Enter the date with format (ddmmyyyy): ";
                        cin >> ddmmyyyy;
                        divideDate(ddmmyyyy, userDate, userMonth, userYear);
                        while (true){
                            if (checkTime()){
                                userDMY5[user5count] = ddmmyyyy;
                                cout << "Enter the name of person : ";
                                cin >> name;
                                userName5[user5count] = name;
                                cout << "Enter the ammount of item that is sold : ";
                                cin >> amount;
                                while (true){
                                    if (amount < 1){
                                        cout << "The number should be greater than 1 !!" << endl;
                                        cout << "Please re-enter the number of item : ";
                                        cin >> amount;
                                    } else {
                                        userAmount5[user5count] = amount;
                                        cout << "The data has been inputed !!" << endl;
                                        break;
                                    }
                                }
                                break;
                            } else {
                                cout << "The date you inputed is invalid !!" << endl;
                                cout << "Do you wish to cancel adding data?" << endl;
                                cout << "1. Cancel adding data" << endl;
                                cout << "2. Continue adding data" << endl;
                                cout << "Enter your input : ";
                                cin >> addData;
                                if (addData == 1){
                                    break;
                                } else {
                                    cout << "Please re-enter the date with format (ddmmyyyy) : ";
                                    cin >> ddmmyyyy;
                                }
                            }
                        }
                        break;
                    } else {
                        cout << "Please enter a number in range " << queueItem.getSize() << " : ";
                        cin >> getData;
                    }
                }
                break;

            case 3:
                cout << "============================================" << endl;
                if (queueItem.getSize() == 0){
                    cout << "There is no item in the list yet !!" << endl;
                    break;
                }
                cout << "List of items : " << endl;
                for (int i = 0; i < queueItem.getSize(); i++){
                    cout << i + 1 << ". ";
                    queueItem.getIndex(i);
                }
                cout << "Enter the index that you want to remove : ";
                cin >> itemRemove;
                if (itemRemove == 1 || queueItem.getSize() == 1){
                    queueItem.getIndex(0);
                }
                break;
            
            case 4:
                cout << "============================================" << endl;
                if (queueItem.getSize() == 0){
                    cout << "There is no item in the list yet !!" << endl;
                    break;
                }
                cout << "List of items : " << endl;
                for (int i = 0; i < queueItem.getSize(); i++){
                    cout << i + 1 << ". ";
                    queueItem.getIndex(i);
                }
                cout << "Enter the index of data that you want to remove : ";
                cin >> itemRemove2;
                cout << "List of data : " << endl;
                for (int i = 0; i < )
                break;

            case 5:
                // cout << "============================================" << endl;
                // cout<< "[";
                // while(!queueData.empty()){
                //     cout<< queueData.dequeue() << " ";
                //     // queueData.pop();
                // }
                // cout<< "]" << endl;
                break;

            case 6:
                cout << "============================================" << endl;
                cout << "Thank you for using our program !!" << endl;
                cout << "See you soon !!" << endl;
                check = false;
                break;
            
            default:
                cout << "============================================" << endl;
                cout << "Sorry, your input is not valid !!" << endl;
                cout << "Please re-enter a number in range 1-5 !!" << endl;
                cin >> opt1;
                check2 = false;
                break;
            }
            break;
        }
    }
}