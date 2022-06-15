#include <iostream>
#include <ctime>
#include <array>
#include <queue>

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
    queue<string> queueItem;
    queue<int> queueData;
    string item;
    int opt1;
    bool check = true;

    cout << "Welcome to List" << endl;

    while (check) {
        cout << "What would you like to do?" << endl;
        cout << "1. Add Item" << endl;
        cout << "2. Add Data" << endl;
        cout << "3. Delete Item" << endl;
        cout << "4. Delete Data" << endl;
        cout << "5. Display Item" << endl;
        cout << "6. Display Data" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your input : ";
        cin >> opt1;

        switch (opt1){
        case 1:
            cout << "============================================" << endl;
            cout << "Enter the Item: ";
            cin >> item;
            queueItem.push(item);
            cout<< "'" << item << "' has successfuly added!" << endl;
            break;

        case 2:
            cout << "============================================" << endl;
            cout << "Enter the Data: ";
            int data;
            cin >> data;
            queueData.push(data);
            cout<< "'" << data << "' has successfuly added!" << endl;
            break;

        case 3:
            cout << "============================================" << endl;
            cout<< "'" << queueItem.front() << "' succefully deleted!" << endl;
            queueItem.pop();
            break;
        
        case 4:
            cout << "============================================" << endl;
            cout<< "'" << queueData.front() << "' succefully deleted!" << endl;
            queueData.pop();
            break;

        case 5:
            cout << "============================================" << endl;
            cout<< "[";
            while(!queueItem.empty()){
                cout<< queueItem.front() << " ";
                queueItem.pop();
            }
            cout<< "]" << endl;
            break;

        case 6:
            cout << "============================================" << endl;
            cout<< "[";
            while(!queueData.empty()){
                cout<< queueData.front() << " ";
                queueData.pop();
            }
            cout<< "]" << endl;
            break;

        case 7:
            cout << "============================================" << endl;
            cout << "Exiting..." << endl;
            check = false;
            break;
        
        default:
            cout << "============================================" << endl;
            cout << "Sorry, your input is not valid !!" << endl;
            cout << "Please re-enter a number in range 1-5 !!" << endl;
            break;
        }
    }
}