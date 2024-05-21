#include "Agenda.h"


#include "Agenda.h"

// Constructor to initialize agenda with a list of events
Agenda::Agenda(const std::vector<Event>& Events_) : Events(Events_) {
    /*
    std::cout << std::endl;
    std::cout << "**********************" << std::endl;      // Debug purpose only!
    std::cout << "The agenda is created." << std::endl;     // In the final release,
    std::cout << "**********************" << std::endl;    // please delete! 1
    std::cout << std::endl;
    */
}

// Function to add an event to the agenda
void Agenda::Add_event(const Event& event_) {
    Events.push_back(event_);
    std::cout << "The event: " << event_.get_Name() << " was created." << std::endl; // A cute cout for the user :3
}

// Function to remove an event from the agenda by name
void Agenda::Remove_event(const std::string& Name) {
    auto it = std::remove_if(Events.begin(), Events.end(), [&Name](const Event& event) { return event.get_Name() == Name; });

    if (it != Events.end()) {
        Events.erase(it, Events.end()); // And it gets deleted
        system("cls");
        std::cout << "*************************************************************" << std::endl;
        std::cout << "The event: " << Name << " was deleted successfully from agenda." << std::endl; // Also a cute cout :3
        std::cout << "*************************************************************" << std::endl;
        system("pause");
    }
    else {
        system("cls");
        std::cout << "*************************************************************" << std::endl;
        std::cout << " ERROR! The event: " << Name << " wasn't found in the agenda." << std::endl; // A cute cout for the dummies :3
        std::cout << "*************************************************************" << std::endl;
        system("pause");
    }
}

// Function to write agenda details to a file
void Agenda::Write_file() const {
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

// Function to read agenda details from a file
void Agenda::Read_File() {
    std::ifstream inputFile("Main_Agenda.txt");

    if (inputFile.is_open()) {
        Events.clear();
        std::string line;
        int numPeople = 0, day = 0, month = 0, year = 0;
        std::string name, info;

        while (std::getline(inputFile, line)) {
            if (line.find("Number of people: ") != std::string::npos) {
                std::istringstream(line.substr(18)) >> numPeople;
            }
            else if (line.find("Date: ") != std::string::npos) {
                char discard;
                std::istringstream(line.substr(6)) >> day >> discard >> month >> discard >> year;
            }
            else if (line.find("Event Name: ") != std::string::npos) {
                name = line.substr(12);
            }
            else if (line.find("Event Info: ") != std::string::npos) {
                info = line.substr(12);
                Events.emplace_back(numPeople, day, month, year, name, info);
            }
        }
        inputFile.close();
        std::cout << "  ************************************************" << std::endl;
        std::cout << "   Agenda information read from 'Main_Agenda.txt'" << std::endl;
        std::cout << "  ************************************************" << std::endl;
    }
    else {
        std::cerr << "Unable to open file: Main_Agenda.txt" << std::endl;
    }
}

// Getter for the list of events
const std::vector<Event>& Agenda::get_Events() const {
    return Events;
}

// Destructor
Agenda::~Agenda() {}