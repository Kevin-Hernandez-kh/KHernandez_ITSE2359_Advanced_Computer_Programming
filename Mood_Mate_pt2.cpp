/*
Kevin Hernandez
10/8/26
Mood Mate part 2
Description: an updated version of mood mate with a new class added
*/
#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

using namespace std;

//class for public and private memebrs for MoodEntry//
class MoodEntry{

    public:
        MoodEntry();
        MoodEntry(string date, int rating, string note);
        void setDate(string date);
        void setRating(int rating);
        void setNote(string note);
        string getDate() const;
        int getRating() const;
        string getNote() const;
        void printEntry() const;
        string getMoodLabel() const;


    private:
        string date;
        int rating;
        string note;
};

// class for public and private members for MoodTracker
class MoodTracker{
    public:
        MoodTracker();
 
        void addEntry(const MoodEntry& entry);
 
        void displayEntries() const;
 
        double calculateAverage() const;
 
        MoodEntry getHighestMood() const;
 
        MoodEntry getLowestMood() const;
 
        int getEntryCount() const;

    private:
        MoodEntry entries[20];
        int entryCount;

};




//default constructor and parameterized constuctor
MoodEntry :: MoodEntry(){
    
    date = "Unspecific";
    rating = 3;
    note = "No note";

}

MoodEntry :: MoodEntry(string date, int rating, string note){
    setDate(date);
    setRating(rating);
    setNote(note);
}

//setters and getters for the mood entry class//
void MoodEntry :: setDate(string date){
    
    cout << "Enter date (YYYY-MM-DD): ";
    cin >> date;
    
    if (!date.empty()){
        this->date = date;
    }
    

    else{
        this->date = "Unspecific";
    }

}

void MoodEntry :: setRating(int rating){
    
    cout << "Enter rating (1-5): ";
    cin >> rating;

    if (rating >= 1 && rating <= 5){
        this->rating = rating;
    }

    else{
        this->rating = 3;
    }
}

void MoodEntry :: setNote(string note){
    
    cout << "Enter note: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, note);

    if (!note.empty()){
        this->note = note;
    }

    else{
        this->note = "No note";
    }

}

string MoodEntry :: getDate() const{
    return date;
}

int MoodEntry :: getRating() const{
    return rating;
}

string MoodEntry :: getMoodLabel() const{
    switch (rating){

        case(1):
            return "Very Bad";
            break;

        case (2):
            return "Bad";
            break;

        case (3):
            return "Okay";
            break;

        case (4):
            return "Good";
            break;

        case (5):
            return "Great";
            break;

        default:
            return "Unknown";
            break;
        
    }
}


string MoodEntry :: getNote() const{
    return note;
}


void MoodEntry :: printEntry() const{
    cout << "Mood Entry"<< endl;
    cout << "----------------------------------------\n";
    cout << "Date: " << date << endl;
    cout << "Rating: " << rating << "/5" <<endl;
    cout << "Mood: " << getMoodLabel() << endl;
    cout << "Note: " << note << endl;
    cout << "----------------------------------------\n";
    cout << "\n";
}

// Functions for MoodTracker class //
MoodTracker :: MoodTracker(){
    entryCount = 0;
}

void MoodTracker :: addEntry(const MoodEntry& entry){
    if (entryCount < 20){
        entries[entryCount] = entry;
        entryCount++;
    }
    else{
        cout << "ENTRY LIMIT REACHED!" << endl;

    }

}


void MoodTracker :: displayEntries() const{
    if (entryCount == 0){
        cout << "No Mood Entries Found. Add a Mood Entry first." << endl;
    }
    else{
        for (int i = 0; i < entryCount; i++){
            entries[i].printEntry();
        }
    }
}

double MoodTracker :: calculateAverage() const{
    if (entryCount == 0){
        return 0.0;
    }
    
    int totalRating = 0;
    for (int i = 0; i < entryCount; i++){
        totalRating += entries[i].getRating();
    
    }
    double averageRating = static_cast<double>(totalRating) / entryCount;
    return averageRating;
}

MoodEntry MoodTracker :: getHighestMood() const{
    if (entryCount == 0){
        return MoodEntry();
    }

    MoodEntry highestMood = entries[0];

    for (int i = 1; i < entryCount; i++){
        if (entries[i].getRating() > highestMood.getRating()){
            highestMood = entries[i];
        }
    }
    cout << "----- Highest Mood -----" << endl;
    cout << "Date: " << highestMood.getDate() << endl;
    cout << "Mood Rating: " << highestMood.getRating() << endl;
    cout << "Mood: " << highestMood.getMoodLabel() << endl;
    cout << "Note: " << highestMood.getNote() << endl;
    cout << "\n";
    return MoodEntry();

}

MoodEntry MoodTracker :: getLowestMood() const{
    if (entryCount == 0){
        return MoodEntry();
    }

    MoodEntry lowestMood = entries[0];

    for (int i = 1; i < entryCount; i++){
        if (entries[i].getRating() < lowestMood.getRating()){
            lowestMood = entries[i];
        }
    }
    cout << "----- Lowest Mood -----" << endl;
    cout << "Date: " << lowestMood.getDate() << endl;
    cout << "Mood Rating: " << lowestMood.getRating() << endl;
    cout << "Mood: " << lowestMood.getMoodLabel() << endl;
    cout << "Note: " << lowestMood.getNote() << endl;
    cout << "\n";
    return MoodEntry();
}


int MoodTracker :: getEntryCount() const{
    return entryCount;
}

// main loop for the mood entries//
int main(){
        
    MoodEntry entries[20];

    MoodTracker tracker;
    
    string date, note;
    
    int rating;
    
    int entryCount;
        
    
    cout << "=========================\n";
    cout << "       MOODMATE\n";
    cout << "=========================\n";

    cout << "1. Add Entry\n";
    cout << "2. View Entries\n";
    cout << "3. View Average Mood\n";
    cout << "4. View Highest Mood\n";
    cout << "5. View Lowest Mood\n";
    cout << "6. Exit\n";
    cout << "=========================\n";
    cout << " " << endl;
    
    while (true){
        cout << "Choose an option: ";

        
        int userChoice;
        if (!(cin >> userChoice)) {
            cout << "Invalid input. Please enter a number between 1 and 4." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        
        
        // input for the mood entry for the array//
        if (userChoice == 1) {
            
            if (tracker.getEntryCount() >= 20) {
                cout << "Entry limit reached!" << endl;
                continue;
            }
            
            MoodEntry today(date, rating, note);
            tracker.addEntry(today);
            cout << " \n";
            cout << "Mood Entry Added!\n";
            cout << " \n";

        } 
        
        // Displays all of the mood entries in the array//
        else if (userChoice == 2) {
            if (tracker.getEntryCount() == 0) {
                cout << "No Mood Entries Found. Add a Mood Entry first." << endl;
                cout << " \n";
                continue;
            } 
            else {
                tracker.displayEntries();
            }
        } 
        
        // Calculates the average and displays it to the user//
        else if (userChoice == 3) {
            if (tracker.getEntryCount() == 0) {
                cout << "No entries to calculate average rating." << endl;
                cout << " \n";
                continue;
            } 
            
            
            cout << "Average Mood: " << tracker.calculateAverage() << endl;
            cout << " \n";
        } 
        
        //finds the highest mood entry in the array//
        else if (userChoice == 4) {
            if (tracker.getEntryCount() == 0){
                cout << "No entries to find the highest mood" << endl;
                cout << " \n";
                continue;
            }
        
            tracker.getHighestMood();

        }
    
        //finds the lowest mood entry in the array//
        else if (userChoice == 5){
            if (tracker.getEntryCount() == 0){
                cout << "No entries to find the lowest mood" << endl;
                cout << " \n";
                continue;
            }

            tracker.getLowestMood();
            cout << "\n";
        }
        //exits from the while loop
        else if (userChoice == 6){
            cout << "Thank you for using MoodMate!" << endl;
            break;

        }
    
        else{
            cout << "Invalid option. Please try again." << endl;
            cout << " \n";
            continue;
        }
    
    }
    
return 0;
    
}
