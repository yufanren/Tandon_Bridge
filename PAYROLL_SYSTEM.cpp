#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

const std::string EMPLOYEE_PAYROLL_OUTPUT = "payroll.txt";

//class node.
template<class K>
class node {
public:
    node<K>();
    explicit node<K>(K newData);
    K getData();
    void setData(K newData);
    node<K>* getNext() const;
    void setNext(node<K>* nextNode);
private:
    K data;
    node<K>* next;
};

template<class K>
node<K>::node() : data(K()), next(nullptr) {}

template<class K>
node<K>::node(K newData) : data(newData), next(nullptr) {}

template<class K>
K node<K>::getData() { return data; }

template<class K>
node<K>* node<K>::getNext() const { return next; }

template<class K>
void node<K>::setNext(node<K>* nextNode) { next = nextNode; }

template<class K>
void node<K>::setData(K newData) { data = newData; }

//class linked list.
template<class K>
class linkedList {
public:
    linkedList();
    int getSize();
    void add(K newData);
    void addToFront(K newData);
    void remove(K data);
    bool isEmpty();
    K getAtIndex(int index);
    void replaceAtIndex(int index, K newData);
    ~linkedList<K>();
    linkedList& operator =(const linkedList<K>& list1);
    linkedList(const linkedList<K>& list1);
private:
    int size;
    node<K> nodeZero;
};

//K must implement == operator.
template<class K>
void linkedList<K>::remove(K data) {
    node<K>* current = &nodeZero;
    while (current->getNext() != &nodeZero) {
        if (((current->getNext())->getData()) == data) {
            node<K>* toDelete = current->getNext();
            current->setNext((current->getNext())->getNext());
            delete toDelete;
            size--;
        }
        else
            current = current->getNext();
    }
}

//add to front of the list.
template<class K>
void linkedList<K>::addToFront(K newData) {
    auto* newNode = new node<K>(newData);
    newNode->setNext(nodeZero.getNext());
    nodeZero.setNext(newNode);
    size++;
}

//add to end of the list.
template<class K>
void linkedList<K>::add(K newData) {
    auto* newNode = new node<K>(newData);
    node<K>* current = &nodeZero;
    while (current->getNext() != &nodeZero)
        current = current->getNext();
    current->setNext(newNode);
    newNode->setNext(&nodeZero);
    size++;
}

template<class K>
linkedList<K>::linkedList() : size(0), nodeZero(*(new node<K>)) {
    nodeZero.setNext(&nodeZero);
}

template<class K>
int linkedList<K>::getSize() { return size; }

template<class K>
bool linkedList<K>::isEmpty() { return size == 0; }

template<class K>
K linkedList<K>::getAtIndex(int index) {
    node<K>* current = nodeZero.getNext();
    while (index > 0) {
        current = current->getNext();
        index--;
    }
    return current->getData();
}

template<class K>
void linkedList<K>::replaceAtIndex(int index, K newData) {
    if (index < 0 || index >= size)
        return;
    node<K>* current = nodeZero.getNext();
    while (index > 0) {
        current = current->getNext();
        index--;
    }
    current->setData(newData);
}

template<class K>
linkedList<K>::~linkedList<K>() {
    node<K>* current = nodeZero.getNext();
    while (current != &nodeZero) {
        node<K>* next = current->getNext();
        delete current;
        current = next;
    }
}

template<class K>
linkedList<K>& linkedList<K>::operator = (const linkedList<K>& list1) {
    if (&list1 == this)
        return *this;
    node<K>* current = nodeZero.getNext();
    while (current != &nodeZero) {
        node<K>* next = current->getNext();
        delete current;
        current = next;
    }
    nodeZero.setNext(&nodeZero);
    node<K>* ptr = list1.nodeZero.getNext();
    while (ptr != &(list1.nodeZero)) {
        current->setNext(new node<K>(ptr->getData()));
        ptr = ptr->getNext();
        current = current->getNext();
    }
    current->setNext(&nodeZero);
    this->size = list1.size;
    return *this;
}

template<class K>
linkedList<K>::linkedList(const linkedList<K>& list1) : linkedList<K>() {
    node<K>* current = &nodeZero;
    node<K>* ptr = list1.nodeZero.getNext();
    while (ptr != &(list1.nodeZero)) {
        current->setNext(new node<K>(ptr->getData()));
        ptr = ptr->getNext();
        current = current->getNext();
    }
    current->setNext(&nodeZero);
    this->size = list1.size;
}

//class employee
class employee {
public:
    employee();
    employee(int id, double pay, std::string name);
    int getID() const;
    double getHours();
    double getPayRate();
    std::string getName();
    double getTotalPay();
    void addHours(double newHours);
    void clearHours();
    void setPay(double newRate);
    void updateTotalPay();
    bool operator ==(const employee& employee2);
private:
    int id;
    double hours;
    double payRate;
    std::string name;
    double totalPay;
};

employee::employee() : id(-1), payRate(0), hours(0), name(""), totalPay(0) {}

employee::employee(int id, double pay, std::string name) :
    id(id), payRate(pay), name(std::move(name)), hours(0), totalPay(0) {}

bool employee::operator ==(const employee& employee2) {
    return this->getID() == employee2.getID();
}

int employee::getID() const { return id; }

double employee::getHours() { return hours; }

double employee::getPayRate() { return payRate; }

std::string employee::getName() { return name; }

double employee::getTotalPay() { return totalPay; }

void employee::addHours(double newHours) { hours += newHours; }

void employee::setPay(double newRate) { payRate = newRate; }

void employee::updateTotalPay() { totalPay = payRate * hours; }

void employee::clearHours() {
    hours = 0;
    updateTotalPay();
}

//non-member functions.
void readHours(std::ifstream& inFile) {
    std::string employeeHours;
    do {
        std::cout << "Please enter file name (with extention) for employee hours:" << std::endl;
        std::cin >> employeeHours;
        inFile.open(employeeHours);
    } while (!inFile);
}

void readEmployee(std::ifstream& inFile) {
    std::string employeeRecords;
    do {
        std::cout << "Please enter file name (with extention) for employee records:" << std::endl;
        std::cin >> employeeRecords;
        inFile.open(employeeRecords);
    } while (!inFile);
}


linkedList<employee> buildEmployeeList(std::ifstream& employeeRecord) {
    linkedList<employee> workerList;
    int empID;
    double empRate;
    std::string empName;
    while (employeeRecord >> empID) {
        employeeRecord >> empRate;
        employeeRecord.ignore(9999, ' ');
        std::getline(employeeRecord, empName);
        //empName = empName.substr(0, empName.size() - 1);//this line for linux OS only!
        workerList.add(employee(empID, empRate, empName));
    }
    employeeRecord.close();
    return workerList;
}

void addEmployeeHours(std::ifstream& employeeHours, linkedList<employee>& workerList) {
    int empID;
    double empHours;
    while (employeeHours >> empID) {
        employeeHours >> empHours;
        for (int i = 0; i < workerList.getSize(); i++) {
            if (workerList.getAtIndex(i).getID() == empID) {
                employee newEmp = workerList.getAtIndex(i);
                newEmp.addHours(empHours);
                newEmp.updateTotalPay();
                workerList.replaceAtIndex(i, newEmp);
                break;
            }
        }
    }
    employeeHours.close();
}

//sort employees from highest to lowest paycheck.
//using quick sort.
void sortEmployee(employee* arr, int left, int right) {
    if (left < right) {
        double value = arr[right].getTotalPay();
        int counter = right;
        for (int i = right - 1; i >= 0; i--) {
            if (arr[i].getTotalPay() <= value) {
                counter--;
                employee temp = arr[counter];
                arr[counter] = arr[i];
                arr[i] = temp;
            }
        }
        employee temp = arr[right];
        arr[right] = arr[counter];
        arr[counter] = temp;
        sortEmployee(arr, left, counter - 1);
        sortEmployee(arr, counter + 1, right);
    }
}

void outputPayroll(employee* arr, int arrSize) {
    std::ofstream outFile(EMPLOYEE_PAYROLL_OUTPUT);
    outFile << "*********Payroll Information*********" << std::endl;
    for (int i = 0; i < arrSize; i++) {
        outFile << arr[i].getName();
        int blanks = (26 - (int)(arr[i].getName().size()));
        for (int j = 0; j < blanks; j++)
            outFile << " ";
        outFile << "$" << arr[i].getTotalPay() << std::endl;
    }
    outFile << "*************End Payroll*************" << std::endl;
}

void displayPayroll(employee* arr, int arrSize) {
    std::cout << "*********Payroll Information*********" << std::endl;
    for (int i = 0; i < arrSize; i++) {
        std::cout << arr[i].getName();
        int blanks = (26 - (int)(arr[i].getName().size()));
        for (int j = 0; j < blanks; j++)
            std::cout << " ";
        std::cout << "$" << arr[i].getTotalPay() << std::endl;
    }
    std::cout << "*************End Payroll*************" << std::endl;
}

void printPayroll(linkedList<employee> list) {
    int arrSize = list.getSize();
    auto* arr = new employee[arrSize];
    for (int i = 0; i < arrSize; i++)
        arr[i] = list.getAtIndex(i);
    sortEmployee(arr, 0, arrSize - 1);
    outputPayroll(arr, arrSize);
    displayPayroll(arr, arrSize);
    delete[] arr;
}

int main() {
    std::ifstream employeeRecords;
    readEmployee(employeeRecords);
    linkedList<employee> empList = buildEmployeeList(employeeRecords);

    std::ifstream employeeHours;
    readHours(employeeHours);
    addEmployeeHours(employeeHours, empList);

    printPayroll(empList);
}
