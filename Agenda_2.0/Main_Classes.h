
#include<SFML/Audio.hpp>    // For the personal touch ;)


#include <fstream>          // For the lovely text file :D
#include <sstream>         // Where the info is stored


#include <thread>           // Windows sleep
#include <chrono>          // Also for audios
    

#include <iostream>     // The basic 
#include <string>      // set of
#include <vector>     // libraries I use 



#ifndef EVENT_H
#define EVENT_H

class Event {
private:
    int Number_of_people = 0;           // Attributes for 
    int Day = 0;                       // an event 
    int Month = 0;
    int Year = 0;
    std::string Name = "";
    std::string Info = "";

public:
        
    Event(const int& Number_of_people_, const int& Day_, const int& Month_, const int& Year_, const std::string& Name_, const std::string& Info_) :
        Number_of_people(Number_of_people_), Day(Day_), Month(Month_), Year(Year_), Name(Name_), Info(Info_) {//  Constructor


        /*
        std::cout << std::endl;
        std::cout << "*********************" << std::endl;      // Debug purpose only!
        std::cout << "The event is created." << std::endl;     // In the final release,
        std::cout << "*********************" << std::endl;    // please delete! 1
        std::cout << std::endl;
        */
    }



    const int& get_Number_of_people() const {           // Getter for
        return Number_of_people;                       // the number of people.
    }

    const int& get_Day() const {                       // Getter for
        return Day;                                   // the number of the day.
    }

    const int& get_Month() const {                   // Getter for
        return Month;                               // number of month.
    }

    const int& get_Year() const {                   // Getter for
        return Year;                               // the number of the year.
    }

    const std::string& get_Name() const {          // Getter for
        return Name;                              // the name of the event.
    }

    const std::string& get_Info() const {         // Getter for
        return Info;                             // info about the event.
    }



    void Write_file_E(std::ofstream& Text_file) const {    // A function that basically writes its
                                                          // contents into the text file.
                                                         // (In our case: "Main_Agenda.txt").
        Text_file << "Number of people: " << Number_of_people << std::endl;
        Text_file << "Date: " << Day << "/" << Month << "/" << Year << std::endl;
        Text_file << "Event Name: " << Name << std::endl;
        Text_file << "Event Info: " << Info << std::endl;
        Text_file << std::endl;
    }


        // Deconstructor
    ~Event() {
        /*
        std::cout << std::endl;
        std::cout << "*********************" << std::endl;      // Debug purpose only!
        std::cout << "The event is Dead.   " << std::endl;     // In the final release,
        std::cout << "*********************" << std::endl;    // please delete! 2
        std::cout << std::endl;
        */
    }










};
#endif // EVENT_H




#ifndef AGENDA_H
#define AGENDA_H



class Agenda {


    std::vector<Event> Events;

public:

    Agenda() = default;// Default constructor

    Agenda(const std::vector<Event>& Events_) : Events(Events_) {// Constructor

        /*
        std::cout << std::endl;
        std::cout << "**********************" << std::endl;      // Debug purpose only!
        std::cout << "The agenda is created." << std::endl;     // In the final release,
        std::cout << "**********************" << std::endl;    // please delete! 1
        std::cout << std::endl;
        */

    }




    void Add_event(const Event& event_) {   // A function that pushes the event into the vector.
        Events.push_back(event_);

        std::cout << "The event: " << event_.get_Name() << " was created." << std::endl;    // A cute cout for the user :3
    }





    void Remove_event(const std::string& Name) {    // A function that erases the event
                                                   // based on the name chosen by the user.

        auto it = std::remove_if(Events.begin(), Events.end(), [&Name](const Event& event) { return event.get_Name() == Name; });

        if (it != Events.end()) {   // Checks if the event is found.

            Events.erase(it, Events.end()); // And it gets deleted
            std::cout << "*************************************************************" << std::endl; 
            std::cout << "The event: " << Name << " was deleted successfully from agenda." << std::endl;    // Also a cute cout :3
            std::cout << "*************************************************************" << std::endl;
        }
        else {  // Else the event dosen't exist.
            std::cout << "*************************************************************" << std::endl;
            std::cout << " ERROR! The event: " << Name << " wasn't found in the agenda." << std::endl;  // A cute cout for the dummies :3
            std::cout << "*************************************************************" << std::endl;

        }
    }





    void Write_file() const {
        std::ofstream outputFile("Main_Agenda.txt");
        if (outputFile.is_open()) {
            for (const auto& event : Events) {
                event.Write_file_E(outputFile);
            }
            outputFile.close();
            std::cout << "*************************************************************" << std::endl;
            std::cout << " Agenda information written to Main_Agenda.txt" << std::endl;
            std::cout << "*************************************************************" << std::endl;

        }
        else {
            std::cout << "*************************************************************" << std::endl;
            std::cerr << " ERROR! Unable to open file: Main_Agenda.txt" << std::endl;
            std::cout << "*************************************************************" << std::endl;

        }
    }

    void Read_File() {  // A function that reads the "Main_Agenda.txt".

        std::ifstream inputFile("Main_Agenda.txt");

        if (inputFile.is_open()) {

            Events.clear();

            std::string line;                                   // Some local variables
            int numPeople = 0, day = 0, month = 0, year = 0;   // for display purposes
            std::string name, info;                           // only.

            while (std::getline(inputFile, line)) { // If the .txt file has something written in the lines it means that has info.


                if (line.find("Number of people: ") != std::string::npos) { // A cute cout for the number of people :3
                    std::istringstream(line.substr(18)) >> numPeople;
                }
                else if (line.find("Date: ") != std::string::npos) { // A cute cout for the date :3
                    char discard;
                    std::istringstream(line.substr(6)) >> day >> discard >> month >> discard >> year;
                }
                else if (line.find("Event Name: ") != std::string::npos) { // A cute cout for the event name :3
                    name = line.substr(12);
                }
                else if (line.find("Event Info: ") != std::string::npos) { // A cute cout for the info :3
                    info = line.substr(12);


                    Events.emplace_back(numPeople, day, month, year, name, info);
                }
            }
            inputFile.close();  // A function to close the file after we read the data.



            std::cout << "  ************************************************" << std::endl;     // Confirmation 
            std::cout << "   Agenda information read from 'Main_Agenda.txt'"  << std::endl;    // Confirmation 
            std::cout << "  ************************************************" << std::endl;   // Confirmation 




        }
        else {
            std::cerr << "Unable to open file: Main_Agenda.txt" << std::endl;   // Error
        }
    }

    const std::vector<Event>& get_Events() const {  // A lost getter for events :(
        return Events;
    }

    ~Agenda() {// Deconstructor

        /*
        std::cout << std::endl;
        std::cout << "*********************" << std::endl;      // Debug purpose only!
        std::cout << "The event is dead.   " << std::endl;     // In the final release,
        std::cout << "*********************" << std::endl;    // please delete! 1
        std::cout << std::endl;

        */
    }



  

   
};

#endif // AGENDA_H