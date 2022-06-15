#include <iostream>
#include <ctime>
#include <array>

using namespace std;

int year, month, date, hour, minute, sec;

void checkTime(){       //Not finished
    time_t date = time(0);
    tm *today = localtime(&date);
    year = 1900 + today->tm_year;
    month = 1 + today->tm_mon;
    date = today->tm_mday;
    hour = today->tm_hour;
    minute = today->tm_min;
    sec = today->tm_sec;
}

void divideDate(int dmy){   //Still not working
    array<int, 6> split;
    int rdmy = dmy;
    int count = 0;

    for (int i = 0; i <= 5; i++){
        split[i] = rdmy / count % 10;

        if (i == 0){
            count += 10;
        } else {
            count = count * 10;
        }
    }

    for (int i = 0; i <= 5; i++){
        cout << split[i] << endl;
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

void addList(){

}

int main(){
    int opt1;
    bool check = true;

    cout << "Welcome to List" << endl;
    cout << "What would you like to do?" << endl;

    while (true) {
        cout << "1. Add Item" << endl;
        cout << "2. Add Data" << endl;
        cout << "3. Delete Item" << endl;
        cout << "4. Delete Data" << endl;
        cout << "5. Display Data" << endl;
        cout << "Enter your input : ";
        cin >> opt1;

        while (check){
            switch (opt1){
            case 1:
                cout << "============================================" << endl;
                break;

            case 2:
                cout << "============================================" << endl;
                break;

            case 3:
                cout << "============================================" << endl;
                break;
            
            case 4:
                cout << "============================================" << endl;
                break;

            case 5:
                cout << "============================================" << endl;
                break;
            
            default:
                cout << "============================================" << endl;
                cout << "Sorry, your input is not valid !!" << endl;
                cout << "Please re-enter a number in range 1-5 !!" << endl;
                break;
            }
            break;
        }
    }
}