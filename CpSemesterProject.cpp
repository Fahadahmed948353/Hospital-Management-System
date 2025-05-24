#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Declaring Global Variables 

const int maxPatient = 100;
const int maxDoctoer = 3;
 
 // PATIENT INFORMATION
 
string patientName[maxPatient];
int patientAge[maxPatient];
int patientId[maxPatient];
string patientDepartment[maxPatient];
string patientDoctor[maxPatient];
float patientBill[maxPatient];
string patientGender[maxPatient];

int patientCount = 0;
 
 //  DECLARING DOCTORS INFORMATION

string radiologistName[maxDoctoer] = {"Dr Fahad", "Dr Rayan","Dr Hamza" };
string radiologistFeild[maxDoctoer] = {"Radiology", "Radiology","Radiology" };
int radiologistCharges[maxDoctoer] = {250, 340, 560};

string OncologistName[maxDoctoer] = {"Dr Ahmed", "Dr Adbullah","Dr Sami" };
string OncologistFeild[maxDoctoer] = {"Oncology", "Oncology","Oncology" };
int OncologistCharges[maxDoctoer] = {950, 840, 760};

string GynecologistName[maxDoctoer] = {"Dr Amir", "Dr Hasan","Dr Sajid" };
string GynecologistFeild[maxDoctoer] = {"Gynecology", "gynocology","gynocology" };
int GynecologistCharges[maxDoctoer] = {95, 84, 76};

string DermatologistName[maxDoctoer] = {"Dr Samreen", "Dr Ali","Dr Sabir" };
string DermatologistFeild[maxDoctoer] = {"Deramtology", "Dermalogy","Dermalogy" };
int DermatologistCharges[maxDoctoer] = {50, 120, 28};

string generalName[maxDoctoer] = {"Dr Tayyab", "Dr Sana","Dr Waseem" };
string generalFeild[maxDoctoer] = {"General","General","General" };
int generalCharges[maxDoctoer] = {20, 30, 29};

// This will show doctors option

void doctor_Options( string doctorName[], string doctorField[], int doctorCharges[]){

    cout << " Select the doctors from availible options " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << i+1 << "   Name :  " << doctorName[i] << "    Field :   " << doctorField[i] << "   Charges :   " << doctorCharges[i] << endl;
    }
    
}

void add_patient(){

    if (patientCount >= maxPatient)
    {
          cout << " Sorry you cant enter further patients " << endl; 
    }

  cout << " Please enter patient name " << endl;
  cin >> patientName[patientCount];

    cout << " Please enter patient age " << endl;
    cin >> patientAge[patientCount];

    cout << " Please enter patient Id " << endl;
    cin >> patientId[patientCount];
     
    cout << " Please enter patient gender. Type only male/female " << endl;
    cin >> patientGender[patientCount];
//  Ensuring that user only enetrs " male " and " female "
   while (patientGender[patientCount] != "male" && patientGender[patientCount] != "female" && patientGender[patientCount] != "Male" && patientGender[patientCount] != "Female")
    {
         cout << "Invalid input. Please enter 'male' or 'female': ";
        cin >> patientGender[patientCount];

    }
    

    // FOR SELECTING DEPARTMENT

    cout << " Please enter patient department " << endl;
    cout << "                                " << endl;
     cout <<" 1. Radiology " << endl;
     cout << "2. Oncology " << endl;
     cout << "3. Dermatology " << endl;
     cout << " 4: general" << endl;
     cout << " 5: Gynecology " << endl;
    cout << "               " << endl;
    cout << " Enter choice between 1-5 " << endl;
    int departmentChoice;
    cin >> departmentChoice;
    
// Ensuring that the user enters number between 1 - 5 .

    while (departmentChoice > 5 && departmentChoice < 1)
    {
       cout << " Please Sir enter number between 1 - 5 " << endl;
       cin >> departmentChoice;
    }
    

    switch (departmentChoice)
    {
    case 1:
        doctor_Options (radiologistName, radiologistFeild, radiologistCharges);
        break;
    case 2:
    doctor_Options (OncologistName, OncologistFeild , OncologistCharges);
    break;
    case 3:
    doctor_Options (DermatologistName, DermatologistFeild, DermatologistCharges);
    break;
    case 4:
    doctor_Options (generalName,  generalFeild,  generalCharges) ;
    break;
     case 5:
    doctor_Options (GynecologistName,  GynecologistFeild,  GynecologistCharges) ;
    break;
    default:
    cout << " You are reffered to General Department " << endl;
     doctor_Options (generalName, generalFeild, generalCharges);
        break;
    }
// Which doctor you want to select
// IN this step we have created Doctor_choice named variable and selected_doctor_choice.
// we have assigned department name to selected_doctor_choice variable .
// [doctorChoice - 1] indicates the we always take values in array from 0th index.   
    cout << " Please select patient Doctor  number " << endl;
    int doctorChoice;
    cout << " Enter choice between 1 - 3 " << endl;
    cin >> doctorChoice;

    // ENSURING THAT USER ENETRS NUMBER BETWEEN 1 - 3;

     if (doctorChoice < 1 || doctorChoice > 3 )
     {
        cout << " Please enter between 1 - 3 " << endl;
        cin >> doctorChoice;
     }

    string selected_doctor_choice;
    switch (departmentChoice)
    {
    case 1:
        selected_doctor_choice = radiologistName[doctorChoice-1];
        break;
    case 2:
       selected_doctor_choice = OncologistName[doctorChoice-1];
       break;
       case 3:
          selected_doctor_choice = DermatologistName[doctorChoice-1];
          break;
          case 4:
             selected_doctor_choice = generalName[doctorChoice-1];
             break;
             case 5:
             selected_doctor_choice = GynecologistName[doctorChoice-1];
             break;
     
    }


 patientDoctor[patientCount] = selected_doctor_choice;

 // ABOUT DOCTOR CHARGES
 // we will be assigning department charges with Doctor charge variable

 float doctorCharge = 0;
    switch (departmentChoice) {
    case 1: doctorCharge = radiologistCharges[doctorChoice - 1]; break;
    case 2: doctorCharge = OncologistCharges[doctorChoice - 1]; break;
    case 3: doctorCharge = DermatologistCharges[doctorChoice - 1]; break;
    case 4: doctorCharge = generalCharges[doctorChoice - 1]; break;
     case 5: doctorCharge = GynecologistCharges[doctorChoice - 1]; break;
    }

    // Asking if patient has any additional checkups

cout << "Do you have any additional checkups . Type y/n " << endl;
char charge_choice;
int additional_charges;
cin >> charge_choice;

// This loop ensures that user will only type 'y' and 'n' other than this wont get accepted. 

while (charge_choice != 'n' && charge_choice != 'y')
{
    cout << " Invalid input. Please try again " << endl;
    cin >> charge_choice;
}

if (charge_choice == 'y')
{
    additional_charges  = 20 ;
}
else { 
    additional_charges = 0;
}

// Creating Total Bill and assigning it to PatientBill

float total_charge;
total_charge = doctorCharge + additional_charges;
float tax_rate = 0.10;
float tax_amount = total_charge * tax_rate;
float total_bill = total_charge + tax_amount;

 patientBill[patientCount] = total_bill;


 // In this w'll be saving data using File handling 


ofstream outFile("patient_records.txt", ios::app);
    if (outFile.is_open()) {
        outFile << "ID: " << patientId[patientCount]
            << ", Name: " << patientName[patientCount]
            << ", Age: " << patientAge[patientCount]
            << ", Gender: " << patientGender[patientCount]
            << ", Department: " << patientDepartment[patientCount]
            << ", Doctor: " << patientDoctor[patientCount]
            << ", Bill: $" << patientBill[patientCount] << "\n";
        outFile.close();
        cout << "Patient record successfully saved to file.\n";
    }
    else {
        cout << "Error: Unable to save patient record to file.\n";
    }
    
    patientCount ++;

    // Showing Bill details 


    cout << "    Bill Details   " << endl;

    cout << "Doctor's Consultation Fee: $" << doctorCharge << "\n";
    cout << "Additional Services Charge: $" << additional_charges << "\n";
    cout << "Subtotal (Before Tax): $" << total_charge << "\n";
    cout << "Tax (10%): $" << tax_amount << "\n";
    cout << "Total Bill: $" << total_bill << "\n";
    cout << "  " << endl;
    cout << "  " << endl;

    cout << " | Patient Added Successfully | " << endl;
   

}

// This function is to view all patients at once entered in hospital.
 
void view_patient(){
    if (patientCount == 0)
    {
        cout << " No patient record found " << endl;
        return;
    }
    for (int i = 0; i < patientCount; i++)
    {
        cout << "Name :  " << patientName[i] << "   Age :   " << patientAge[i] << "    ID :   " << patientId[i]  <<  "   Doctor : " << patientDoctor[i] << "   Bill : $" << patientBill[i] << endl; 
    }
    
}

//  We will check the bill of entered patient using his ID


void calculate_Bill() {
    if (patientCount == 0) {
        cout << "No records available to calculate bills.\n";
        return;
    }
    int id;
    cout << "Enter patient ID to calculate bill: " << endl;
    cin >> id;

    for (int i = 0; i < patientCount; i++) {
        if (patientId[i] == id) {
            cout << " \nPatient:  " << patientName[i] << "\n";
            cout << " Age:   " << patientAge[i] << endl;
            cout << "  ID:  " << patientId[i] << endl;
            cout << "  Doctor:  " << patientDoctor[i] << "\n";
            cout << " Total Bill: $  " << patientBill[i] << "\n";
            return;
        }
    }
     cout << "Patient ID not found!\n";
}

// This will be shown to user at first when he runs code.

    void show_menu (){
        while (true)
        {
            
            cout << " Welcome to Hospital Management System " << endl;
            cout << " 1: Add patient " << endl;
            cout << " 2: view all patients " << endl;
            cout << " 3: Calculated bill " << endl;
            cout << " 4: Exit " << endl;
            cout << " Enter your choice" << endl;

            int my_choice;
            cin >> my_choice;

            switch (my_choice)
            {
            case 1:
                add_patient();
                break;

                case 2:
                view_patient();
                break;

                case 3:
                calculate_Bill();
                break;

                case 4:
                cout <<" Good Bye ! Take care " << endl;
                break;

            
            default:
            cout << " Invalid choice, Try again " << endl;
                break;
            }
        }
        
    }
int main() {
    cout << "Welcome to the Hospital Management System!\n";
    show_menu();
    return 0;
}
