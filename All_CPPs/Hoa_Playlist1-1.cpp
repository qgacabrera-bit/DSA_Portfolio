#include <iostream>
#include <string>

class Song {
public:
    std::string title;
    Song* next;
    Song* prev;

    Song(std::string t) : title(t), next(nullptr), prev(nullptr) {}
};

class Playlist {
private:
    Song* head;
    Song* current;

public:
    Playlist() : head(nullptr), current(nullptr) {}

    void addSong(const std::string& title) {
        Song* newSong = new Song(title);
        if (!head) {
            head = newSong;
            head->next = head;
            head->prev = head;
            current = head;
            return;
        }
        Song* last = head->prev;
        last->next = newSong;
        newSong->prev = last;
        newSong->next = head;
        head->prev = newSong;
    }

    void removeSong(const std::string& title) {
        if (!head) {
            std::cout << "Playlist is empty.\n";
            return;
        }

        Song* temp = head;
        Song* toDelete = nullptr;

        do {
            if (temp->title == title) {
                toDelete = temp;
                break;
            }
            temp = temp->next;
        } while (temp != head);

        if (!toDelete) {
            std::cout << "Song not found.\n";
            return;
        }

        if (toDelete->next == toDelete) {
            head = nullptr;
            current = nullptr;
        }
        else {
            toDelete->prev->next = toDelete->next;
            toDelete->next->prev = toDelete->prev;
            if (toDelete == head) head = toDelete->next;
            if (toDelete == current) current = toDelete->next;
        }
        delete toDelete;
    }

    void playAll() {
        if (!head) {
            std::cout << "Playlist is empty.\n";
            return;
        }
        Song* temp = head;
        do {
            std::cout << temp->title << std::endl;
            temp = temp->next;
        } while (temp != head);
    }

    void nextSong() {
        if (!current) {
            std::cout << "Playlist is empty.\n";
            return;
        }
        current = current->next;
        std::cout << "Now playing: " << current->title << std::endl;
    }

    void prevSong() {
        if (!current) {
            std::cout << "Playlist is empty.\n";
            return;
        }
        current = current->prev;
        std::cout << "Now playing: " << current->title << std::endl;
    }
};

int main() {
    Playlist HoASongs;
    int choice;
    std::string songName;

    do {
        std::cout << "\n--- Playlist Menu ---\n";
        std::cout << "1. Add Song\n";
        std::cout << "2. Remove Song\n";
        std::cout << "3. Play All Songs\n";
        std::cout << "4. Play Next Song\n";
        std::cout << "5. Play Previous Song\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
        std::cin.ignore(); 

        switch (choice) {
        case 1:
            std::cout << "Enter song title: ";
            std::getline(std::cin, songName);
            HoASongs.addSong(songName);
            break;
        case 2:
            std::cout << "Enter song title to remove: ";
            std::getline(std::cin, songName);
            HoASongs.removeSong(songName);
            break;
        case 3:
            HoASongs.playAll();
            break;
        case 4:
            HoASongs.nextSong();
            break;
        case 5:
            HoASongs.prevSong();
            break;
        case 6:
            std::cout << "Exiting playlist.\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}