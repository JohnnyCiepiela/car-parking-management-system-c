#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include "Vehicle.h"

//Function responsible for displaying main menu
void displayMenu()
{
    std::cout << "===================================================== \n";
    std::cout << " \t\tCAR PARK MANAGEMENT SYSTEM \t \n ";
    std::cout << "===================================================== \n";
    std::cout << " 1.Add parking entrance\n";
    std::cout << " 2.Display parking logs and charges\n";
    std::cout << " 3.Exit \n";

}

int main()
{
    bool running = false;
    int counter_object = 0;

    //Defining vector for objects storage
    std::vector<Vehicle> objectsVector;

    std::ifstream inFile("FILE.txt");
    std::ofstream inFile2;

    std::string line;
    std::string date_input, vrn_input, timeIn_input, timeOut_input;

    int choice;

    while (1) {

        std::cout << "" << std::endl;
        displayMenu();
        std::cin >> choice;

        switch (choice)
        {
        case 1:

            //User input
            std::cout << "Please enter current date in format 'DD/MM/YYYY':" << std::endl;
            std::cin >> date_input;

            std::cout << "Please car vrn:" << std::endl;
            std::cin >> vrn_input;

            std::cout << "Please enter time-in in format 'hh:mm:ss': " << std::endl;
            std::cin >> timeIn_input;

            std::cout << "Please enter time-out in format 'hh:mm:ss':" << std::endl;
            std::cin >> timeOut_input;

            //Writing user input into a file
            inFile2.open("FILE.txt", std::ios::app);
            inFile2 << date_input << ", " << vrn_input << ", " << timeIn_input << ", " << timeOut_input << std::endl;
            inFile2.close();

            //Printing out current state of the file
            std::cout << "Current records:" << std::endl;
            if (inFile.is_open())
            {
                while (getline(inFile, line))
                {
                    std::cout << line << '\n';
                }
                inFile.close();
            }


            break;
        case 2:

            inFile.open("FILE.txt");
            if (inFile.is_open())
            {
                std::string line;
                std::getline(inFile, line);  //Skipping first line

                //Reading from a file
                while (std::getline(inFile, line))
                {

                    std::stringstream ss(line);

                    std::string date, vrn, timeIn, timeOut;

                    std::getline(ss, date, ',');
                    std::cout << date;

                    std::getline(ss, vrn, ',');
                    std::cout << vrn;

                    std::getline(ss, timeIn, ',');
                    std::cout << timeIn;

                    std::getline(ss, timeOut, ',');
                    std::cout << " " << timeOut;

                    std::cout << std::endl;

                    //Creating a struct object
                    Vehicle obj;

                    //Defining the object with data read from the file
                    obj.setDate(date);
                    obj.setVrn(vrn);
                    obj.setTimeIn(timeIn);
                    obj.setTimeOut(timeOut);

                    //Setting initial value of charge for 0, later to be changed in the next loop
                    obj.setCharge(0);

                    //Pushing created object into a vector of objects
                    objectsVector.push_back(obj);

                }

                inFile.close();


                //Loop responsible for displaying the records of each vehicle identified by a vrn
                for (int i = 0; i < objectsVector.size(); i++) {

                    std::cout << "=============================== \n";
                    std::cout << " \t\t" << objectsVector[i].getVrn() << "\t \n ";
                    std::cout << "=============================== \n";

                    std::cout << "Time in:" << std::endl;
                    std::cout << objectsVector[i].getTimeIn() << std::endl;
                    std::cout << "Converted time in:" << std::endl;
                    std::cout << objectsVector[i].convertTimeInIntoSeconds(objectsVector[i].timeIn) << std::endl;
                    std::cout << "Converted time out:" << std::endl;
                    std::cout << objectsVector[i].convertTimeOutIntoSeconds(objectsVector[i].timeOut) << std::endl;

                    //If statement responsible for applying functions that calculates the charge for the parking
                    if (objectsVector[i].convertTimeOutIntoSeconds(objectsVector[i].timeOut) > 0) {

                        int car_stay;
                        car_stay = objectsVector[i].convertTimeOutIntoSeconds(objectsVector[i].timeOut) - objectsVector[i].convertTimeInIntoSeconds(objectsVector[i].timeIn);

                        std::cout << "The length of parking:" << std::endl;
                        std::cout << car_stay / 60 << " minutes." << std::endl;

                        //Calculating the charge for the parking
                        objectsVector[i].calculateCharge(car_stay);

                        //Setting the value of the charge for the objects
                        objectsVector[i].setCharge(objectsVector[i].calculateCharge(car_stay));

                        std::cout << "Your charge is " << objectsVector[i].getCharge() << " quid." << std::endl;


                    }

                    else {
                        std::cout << "Error\n";
                    }

                    std::cout << "" << std::endl;
                    std::cout << "" << std::endl;

                    //inFile.close();
                }

            }


            break;
        case 3:

            std::cout << "Bye bye!" << std::endl;
            exit(0);

        default: std::cout << "Invalid input";
            break;
        }

    }

}