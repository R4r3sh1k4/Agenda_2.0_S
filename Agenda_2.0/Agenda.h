#pragma once

#ifndef AGENDA_H
#define AGENDA_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstdlib>

#include "Event.h"

class Agenda {
private:
    std::vector<Event> Events; // Collection of events.

public:
    
    Agenda() = default;// Default constructor
    
    Agenda(const std::vector<Event>& Events_); // Constructor to initialize agenda with a list of events.

    void Add_event(const Event& event_); // Function to add an event to the agenda.
    
    void Remove_event(const std::string& Name); // Function to remove an event from the agenda by name.
    
    void Write_file() const; // Function to write agenda details to a file.
   
    void Read_File();  // Function to read agenda details from a file.
    
    const std::vector<Event>& get_Events() const; // Getter for the list of events.
   
    ~Agenda();  // Destructor.
};

#endif // AGENDA_H


