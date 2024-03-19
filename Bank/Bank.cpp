#include <iostream>
#include <Windows.h>
using namespace std;

struct Info {
    int accountNumber;
    double balance;
    double interestRate;

    Info(int accountNumber, double balance, double interestRate) {
        this->accountNumber = accountNumber; 
        this->balance = 0; 
        this->interestRate = 0; 
    }
};

class BankAccount {
private:
    int accountNumber;
    double balance;
    double interestRate;

public:
    
    void deposit();
    void withdraw(); 
    void getBalance(); 
    void getInterestRate(); 
    void setInterestRate(); 
    void getAccountNumber();

    
    BankAccount(int accountNumber, double balance, double interestRate) {
        this->accountNumber = accountNumber; 
        this->balance = 0; 
        this->interestRate = 0; 
    }

    friend bool transfer(BankAccount& from, BankAccount& to, double amount);

};



void BankAccount::deposit() {
    cout << "Введите номер счета: ";
    cin >> this->accountNumber; 
    cout << "Внесите деньги: ";
    cin >> this->balance; 
    cout << "Счёт открыт!!!" << endl << endl;
}

void BankAccount::getBalance() {
    cout << endl << "Текущее состояние счёта: " << endl;
    cout << "Номер счета: " << this->accountNumber << endl; 
    cout << "Количество средств на счёте: " << this->balance << endl; 
}

void BankAccount::withdraw() {
    long long int a;

    do {
        cout << "Сколько желаете снять? ";
        cin >> a; 
        if (a > this->balance) cout << "Недостаточно средств на счете!" << endl;
    } while (a > this->balance);
    this->balance -= a; 
    cout << "Деньги успешно сняты" << endl;
}

void BankAccount::getInterestRate() {
    double monthlyInterestRate = 1.0 / 12; 
    cout << "Ваша процентная ставка пока что ноль. Введите по какой ставке хотите положить деньги " << endl;
    cin >> this->interestRate; 
    double interestEarned = this->balance * this->interestRate * monthlyInterestRate; 
    cout << "Теперь вы будете получать в год: " << interestEarned << endl;
}

void BankAccount::setInterestRate() {
    double a = 1.0 / 12; 
    int b = 5; 
    this->interestRate = this->balance * b * a; 
    cout << "Ваша процентная ставка обновлена до 5 и теперь вы будете получать: " << this->interestRate << endl;
}

void BankAccount::getAccountNumber() {
    cout << "Номер вашей банковской карточки: " << this->accountNumber << endl; 
}

bool transfer(BankAccount& from, BankAccount& to, double amount) {
    if (from.balance >= amount) {
        from.balance -= amount;
        to.balance += amount;
        cout << "Перевод успешно выполнен" << endl;
        return true;
    }
    else {
        cout << "Недостаточно средств для перевода" << endl;
        return false;
    }



}
int main() {
    setlocale(LC_ALL, "Rus");
    BankAccount ac1(0, 0, 0); 
    BankAccount ac2(888, 50000, 0); 

    int choice;

    do {
        cout << "Добро пожаловать в мобильное приложение ^Банк - золотое дно^ \n";
        cout << "Выберите операцию. \n";
        cout << "1. Создать счет и внести сумму. \n";
        cout << "2. Информация о счете. \n";
        cout << "3. Снять деньги со счета. \n";
        cout << "4. Рассчитать деньги по процентной ставки. \n";
        cout << "5. Новая процентная ставка. \n";
        cout << "6. Номер банковской карточки. \n";
        cout << "7. Перевести средства в другу(его счет 888). \n"; 
        cout << "8. Выход. \n";
        cin >> choice;

        if (!(cin >> choice)) {
                cout << "Ошибка: Неверный ввод. Пожалуйста, введите число." << endl;
                cin.clear(); 
                cin.ignore(1000, '\n'); 
                continue; 
        }

        switch (choice) {
        case 1:
            ac1.deposit();
            break;
        case 2:
            ac1.getBalance();
            break;
        case 3:
            ac1.withdraw();
            break;
        case 4:
            ac1.getInterestRate();
            break;
        case 5:
            ac1.setInterestRate();
            break;
        case 6:
            ac1.getAccountNumber();
            break;
        case 7:
            double amount;
            cout << "Введите номер счета, с которого нужно перевести средства: ";
            int fromAccount;
            cin >> fromAccount;
            cout << "Введите номер счета, на который нужно перевести средства: ";
            int toAccount;
            cin >> toAccount;
            cout << "Введите сумму для перевода: ";
            cin >> amount;
            if (transfer(ac1, ac2, amount)) {
                cout << "Перевод выполнен успешно" << endl;
            }
            else {
                cout << "Перевод не выполнен" << endl;
            }
            break;
        case 8:
            cout << "Выход из приложения \n";
            break;
        default:
            cout << "Неверный выбор операции. Попробуйте снова. \n";
            break;
        }
        cout << endl;

    } while (choice != 8);

  

    return 0;
}
