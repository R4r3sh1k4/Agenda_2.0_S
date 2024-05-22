#include "Event.h"

// Constructor to initialize an event with given details
Event::Event(const int& Number_of_people_, const int& Day_, const int& Month_, const int& Year_,
    const std::string& Name_, const std::string& Info_)
    : Number_of_people(Number_of_people_), Day(Day_), Month(Month_), Year(Year_), Name(Name_), Info(Info_) {
    /*
    std::cout << std::endl;
    std::cout << "*********************" << std::endl;      // Debug purpose only!
    std::cout << "The event is created." << std::endl;     // In the final release,
    std::cout << "*********************" << std::endl;    // please delete! 1
    std::cout << std::endl;
    */
}

// Getters for event attributes
const int& Event::get_Number_of_people() const {
    return Number_of_people;
}

const int& Event::get_Day() const {
    return Day;
}

const int& Event::get_Month() const {
    return Month;
}

const int& Event::get_Year() const {
    return Year;
}

const std::string& Event::get_Name() const {
    return Name;
}

const std::string& Event::get_Info() const {
    return Info;
}

// Function to write event details to a file
void Event::Write_file_E(std::ofstream& Text_file) const {
    Text_file << "Number of people: " << Number_of_people << std::endl;
    Text_file << "Date: " << Day << "/" << Month << "/" << Year << std::endl;
    Text_file << "Event Name: " << Name << std::endl;
    Text_file << "Event Info: " << Info << std::endl;
    Text_file << std::endl;
}

// Destructor
Event::~Event() {
    /*
    std::cout << std::endl;
    std::cout << "*********************" << std::endl;      // Debug purpose only!
    std::cout << "The event is Dead.   " << std::endl;     // In the final release,
    std::cout << "*********************" << std::endl;    // please delete! 2
    std::cout << std::endl;
    */
}

