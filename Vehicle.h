#ifndef VEHICLE_H
#define VEHICLE_H

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

struct Vehicle {

public:

    //Declaring member variables
    std::string date;
    std::string vrn;
    std::string timeIn;
    std::string timeOut;
    double charge;


    //Defining modifiers
    void setDate(std::string a) {

        date = a;

    }

    void setVrn(std::string b) {

        vrn = b;

    }

    void setTimeIn(std::string c) {

        timeIn = c;

    }

    void setTimeOut(std::string d) {

        timeOut = d;

    }

    void setCharge(double e) {

        charge = e;

    }

    //Defining accessors
    std::string getDate() {

        return date;

    }

    std::string getVrn() {

        return vrn;

    }

    std::string getTimeIn() {

        return timeIn;

    }

    std::string getTimeOut() {

        return timeOut;

    }

    double getCharge() {

        return charge;

    }

    //Defining function responsible for converting time-in into seconds
    int convertTimeInIntoSeconds(std::string x) {

        //Spliting time-in into integers for future calculations
        //Extracting hour integer
        std::string hourString = x.substr(1, 3);
        int hour = stoi(hourString);

        //Extracting minute integer
        std::string minuteString = x.substr(4, 6);
        int minute = stoi(minuteString);

        //Extracting seconds integer
        std::string secondsString = x.substr(7, 9);
        int seconds = stoi(secondsString);

        //Conversion to time in seconds
        int TimeInSeconds = (hour * 3600) + (minute * 60) + seconds;

        return TimeInSeconds;

    }

    //Defining function responsible for converting time-out into seconds
    int convertTimeOutIntoSeconds(std::string x) {
        if (x[0] != '-') {

            //Extracting hour integer
            std::string hourString = x.substr(1, 3);
            int hour = stoi(hourString);

            //Extracting minute integer
            std::string minuteString = x.substr(4, 6);
            int minute = stoi(minuteString);

            //Extracting seconds integer
            std::string secondsString = x.substr(7, 9);
            int seconds = stoi(secondsString);

            //Conversion to time in seconds
            int TimeOutSeconds = (hour * 3600) + (minute * 60) + seconds;

            return TimeOutSeconds;
        }
        else {
            return 0;
        }

    }

    //Method responsible for calculating the charge for parking as per given requirements
    double calculateCharge(int a) {

        double x{};

        if (a <= 1800) {

            x = 0;

        }

        else if (a > 1800 & a <= 3600) {

            x = 1.50;

        }

        else if (a > 3600 & a <= 7200) {

            x = 3.0;

        }

        else if (a > 7200 & a <= 14400) {

            x = 5.0;

        }

        else if (a > 14400 & a <= 28800) {

            x = 15.0;

        }

        else {

            x = 30.0;

        }

        return x;

    }


};

/*
// Function prototypes
int convertTimeInIntoSeconds(std::string x);
int convertTimeOutIntoSeconds(std::string x);
double calculateCharge(int a);
*/

#endif