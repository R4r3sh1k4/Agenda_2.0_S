#pragma once

#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

class Event {
private:
    int Number_of_people = 0; // Number of people attending the event
    int Day = 0;              // Day of the event
    int Month = 0;            // Month of the event
    int Year = 0;             // Year of the event
    std::string Name = "";    // Name of the event
    std::string Info = "";    // Additional information about the event

public:
  
    Event(const int& Number_of_people_, const int& Day_, const int& Month_, const int& Year_,
        const std::string& Name_, const std::string& Info_);   // Constructor to initialize an event with given details.

    // Getters for event attributes.

    const int& get_Number_of_people() const;
    const int& get_Day() const;
    const int& get_Month() const;
    const int& get_Year() const;
    const std::string& get_Name() const;
    const std::string& get_Info() const;

    
    void Write_file_E(std::ofstream& Text_file) const; // Function to write event details to a file.
    
    ~Event();  // Destructor.
};

#endif // EVENT_H

