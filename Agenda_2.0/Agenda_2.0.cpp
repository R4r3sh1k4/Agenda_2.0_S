#include"Main_Classes.h"


static void Boot_up() {

    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("HDD_sound.wav")) {
        std::cout << "**************************" << std::endl;
        std::cout << "Failed to load sound file!" << std::endl;
        std::cout << "The program will close    " << std::endl;
        std::cout << "in 10 secounds            " << std::endl;
        std::cout << "**************************" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(10));
        std::exit(0);
    }
    sf::Sound sound_HDD;
    sound_HDD.setBuffer(buffer);
    sound_HDD.play();

    std::cout << "Property of RARES STANCIU.";

    std::this_thread::sleep_for(std::chrono::seconds(3));

    system("cls");

    std::cout << "    _____            _____  ______  _____ " << std::endl;
    std::cout << "   |  __ \\     /\\   |  __ \\|  ____|/ ____|" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "   | |__) |   /  \\  | |__) | |__  | (___  " << std::endl;
    std::cout << "   |  _  /   / /\\ \\ |  _  /|  __|  \\___ \\ " << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "   | | \\ \\  / ____ \\| | \\ \\| |____ ____) |" << std::endl;
    std::cout << "   |_|  \\_\\/_/    \\_\\_|  \\_\\______|_____/ " << std::endl;
    std::cout << "                                          " << std::endl;

    std::cout << "   LOADING.";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    system("cls");
    std::cout << std::endl;
}
static void Welcome() {
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("Boot-up_sound.wav")) {
        std::cout << "**************************" << std::endl;
        std::cout << "Failed to load sound file!" << std::endl;
        std::cout << "The program will close    " << std::endl;
        std::cout << "in 10 secounds            " << std::endl;
        std::cout << "**************************" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(10));
        std::exit(0);
    }
    sf::Sound sound_boot;
    sound_boot.setBuffer(buffer);
    sound_boot.play();

    std::cout << std::endl;
    std::cout << "   /$$      /$$ /$$$$$$$$ /$$        /$$$$$$   /$$$$$$  /$$      /$$ /$$$$$$$$" << std::endl;
    std::cout << "  | $$  /$ | $$| $$_____/| $$       /$$__  $$ /$$__  $$| $$$    /$$$| $$_____/" << std::endl;
    std::cout << "  | $$ /$$$| $$| $$      | $$      | $$  \\__/| $$  \\ $$| $$$$  /$$$$| $$      " << std::endl;
    std::cout << "  | $$/$$ $$ $$| $$$$$   | $$      | $$      | $$  | $$| $$ $$/$$ $$| $$$$$   " << std::endl;
    std::cout << "  | $$$$_  $$$$| $$__/   | $$      | $$      | $$  | $$| $$  $$$| $$| $$__/   " << std::endl;
    std::cout << "  | $$$/ \\  $$$| $$      | $$      | $$    $$| $$  | $$| $$\\  $ | $$| $$      " << std::endl;
    std::cout << "  | $$/   \\  $$| $$$$$$$$| $$$$$$$$|  $$$$$$/|  $$$$$$/| $$ \\/  | $$| $$$$$$$$" << std::endl;
    std::cout << "  |__/     \\__/|________/|________/ \\______/  \\______/ |__/     |__/|________/" << std::endl;
    std::cout<< std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(6));
    system("cls");
}
void Click() {
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("Click_sound.wav")) {
        std::cout << "**************************" << std::endl;
        std::cout << "Failed to load sound file!" << std::endl;
        std::cout << "The program will close    " << std::endl;
        std::cout << "in 10 secounds            " << std::endl;
        std::cout << "**************************" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(10));
        std::exit(0);
    }
    sf::Sound sound_HDD;
    sound_HDD.setBuffer(buffer);
    sound_HDD.play();
    std::this_thread::sleep_for(std::chrono::milliseconds(600));




}
void Click2() {
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("Click2_sound.wav")) {
        std::cout << "**************************" << std::endl;
        std::cout << "Failed to load sound file!" << std::endl;
        std::cout << "The program will close    " << std::endl;
        std::cout << "in 10 secounds            " << std::endl;
        std::cout << "**************************" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(10));
        std::exit(0);
    }
    sf::Sound sound_HDD;
    sound_HDD.setBuffer(buffer);
    sound_HDD.play();
    std::this_thread::sleep_for(std::chrono::milliseconds(200));




}

static void Error() {
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("Error_sound.wav")) {
        std::cout << "**************************" << std::endl;
        std::cout << "Failed to load sound file!" << std::endl;
        std::cout << "The program will close    " << std::endl;
        std::cout << "in 10 secounds            " << std::endl;
        std::cout << "**************************" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(10));
        std::exit(0);
    }
    sf::Sound sound_HDD;
    sound_HDD.setBuffer(buffer);
    sound_HDD.play();
    std::this_thread::sleep_for(std::chrono::milliseconds(450));




}





int main() {
    Boot_up();
    Welcome();
    Agenda agenda;


    agenda.Read_File();              // Load events from the "Main_Agenda.txt" file located in the project directory.
    std::this_thread::sleep_for(std::chrono::seconds(2));





    while (true) {                              // The main menu of the application.
        system("cls");
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "===========================" << std::endl;
        std::cout << std::endl;
        std::cout << "      Options:";
        std::cout << std::endl;   
        std::cout << std::endl;
        std::cout << "     1. Add Event";
        std::cout << std::endl;
        std::cout << "     2. Delete Event";
        std::cout << std::endl;
        std::cout << "     3. View Agenda";
        std::cout << std::endl;
        std::cout << "     4. Exit";
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "  *Enter your choice: ";
        
        int choice;         //The user input variable.
        std::cin >> choice;
        std::cout << "===========================" << std::endl;
        Click();



        switch (choice) {           // A switch loop to acces the desired option.




        case 1: {// Add Event


            system("cls");
            std::cout << "===========================" << std::endl;
            int Num_people, Day, Month, Year;   // Some local variables to store
            std::string Name, Info;            // the information into the vector.


            std::cout << "Enter number of people: ";
            std::cin >> Num_people;  // Number of people.
            Click2();

            std::cout << std::endl;
            std::cout << "Enter the day: "; // ! NOTE TO SELF: CHANGE THIS INTO SEPARATE INPUTS !   -Me from the future, I will not do that.
            std::cin >> Day;
            Click2();

            std::cout << std::endl;
            std::cout << "Enter the month (1, 2, 3,...): ";
            std::cin >> Month;
            Click2();

            std::cout << std::endl;
            std::cout << "Enter year: ";
            std::cin >> Year;
            Click2();

            


            std::cin.ignore();  // Clear the buffer for the "std::getline(...)".

            std::cout << std::endl;
            std::cout << "Enter event name: ";
            std::getline(std::cin, Name);   // The main name for the event.
            Click2();
            

            std::cout << std::endl;
            std::cout << "Enter event info: ";
            std::getline(std::cin, Info);   
            Click2();

            
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;

            Event New_Event(Num_people, Day, Month, Year, Name, Info);  // A new event with the info set above.

            agenda.Add_event(New_Event);    // Basically a push for the "New_Event".

            agenda.Write_file(); // Save events to file
            break;
        }




        case 2: {// Delete Event
            
            std::string Event_name; // A local variable

            std::cout << std::endl;
            std::cout << "*Enter the name of the event to delete: "; // Pretty self explanatory
           


            std::cin.ignore(); // Clear the buffer for the "std::getline(...)", again.
            std::getline(std::cin, Event_name);
            Click();

            std::cout << std::endl;

            agenda.Remove_event(Event_name);    // Calls the function to remove the event with the same name.


            agenda.Write_file(); // Saves the changes.
            break;
        }




        case 3: {
            const std::vector<Event>& events = agenda.get_Events(); // Calls the function to get the events from the events (needs refferance)


            if (events.empty()) {   // If the statement is true, there are no events left.
                system("cls");
                std::cout << std::endl;
                std::cout << "***************************************" << std::endl;
                std::cout << " ERROR! No events found in the agenda. " << std::endl;
                std::cout << "***************************************" << std::endl;     // Confirmation 
                Error();
                system("pause");
                break;
            }

            else {  // Displayes the events.
                std::cout << "************************" << std::endl;
                std::cout << "  Events in the agenda:" << std::endl;
                std::cout << "************************" << std::endl;


                for (const auto& event : events) {

                    std::cout << std::endl;
                    std::cout << "===========================" << std::endl;
                    std::cout << "Name: " << event.get_Name() << std::endl;
                    std::cout << "Date: " << event.get_Day() << "/" << event.get_Month() << "/" << event.get_Year() << std::endl;
                    std::cout << "Number of people: " << event.get_Number_of_people() << std::endl;
                    std::cout << "Info: " << event.get_Info() << std::endl;
                    std::cout << "===========================" << std::endl;
                    std::cout << std::endl;
                }
            }
            system("pause");
            break;
        }




        case 4: {   // Exits the aplication.
            std::cout << "Exiting...\n";
            return 0;
        }
        default: {  // If the user is dumb.

            system("cls");
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "***************************************************" << std::endl;
            std::cout << "Invalid choice. Please enter a number from 1 to 4.\n";
            std::cout << "***************************************************" << std::endl;
            Error();
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;
            system("pause");
            break;
        }




        }
    }

    return 0;
}



