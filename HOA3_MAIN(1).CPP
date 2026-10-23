#include <iostream>
#include <limits>
#include <string>
#include "playlist_H.H"


int main()
{
    Song* playlistHead = nullptr;
    Song* currentSong = nullptr;

    int menuChoice;
    int selectedSong;

    std::string songTitle;


    do
    {
        if (currentSong == nullptr)
        {
            std::cout << "\nCurrently Playing: None\n";
        }
        else
        {
            std::cout << "\nCurrently Playing: "
                      << currentSong->songName << "\n";
        }


        std::cout << "\n===== MUSIC PLAYLIST MENU =====\n";
        std::cout << "1. Add Song\n";
        std::cout << "2. Remove Song\n";
        std::cout << "3. Next Song\n";
        std::cout << "4. Play All Songs\n";
        std::cout << "5. Exit\n";
        std::cout << "Choose an option: ";


        while (!(std::cin >> menuChoice))
        {
            std::cout << "Invalid input. Enter a number (1-5): ";

            std::cin.clear();

            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n'
            );
        }


        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(),
            '\n'
        );


        switch(menuChoice)
        {

        case 1:
        {
            std::cout << "Enter song title: ";

            getline(std::cin, songTitle);


            addSong(songTitle, &playlistHead);


            if (currentSong == nullptr)
            {
                currentSong = playlistHead;

                std::cout << "Now Playing: "
                          << currentSong->songName
                          << std::endl;
            }


            std::cout << "Song successfully added!\n";

            break;
        }


        case 2:
        {
            if (playlistHead == nullptr)
            {
                std::cout << "Playlist is empty.\n";
                break;
            }


            std::cout << "\nCurrent Playlist:\n";

            showPlaylist(playlistHead);


            std::cout << "\nEnter song number to remove: ";


            while (!(std::cin >> selectedSong))
            {
                std::cout << "Invalid input. Enter a number: ";

                std::cin.clear();

                std::cin.ignore(
                    std::numeric_limits<std::streamsize>::max(),
                    '\n'
                );
            }


            removeSong(
                selectedSong,
                &playlistHead,
                &currentSong
            );


            std::cout << "Remove operation completed.\n";


            break;
        }


        case 3:
        {
            if (currentSong == nullptr)
            {
                std::cout << "Playlist is empty.\n";
            }
            else
            {
                moveToNextSong(&currentSong);

                std::cout << "Next Song: "
                          << currentSong->songName
                          << std::endl;
            }

            break;
        }


        case 4:
        {
            playAllSongs(playlistHead);

            break;
        }


        case 5:
        {
            std::cout << "Closing music playlist...\n";

            break;
        }


        default:
        {
            std::cout << "Please choose only between 1 and 5.\n";
        }

        }


    } while(menuChoice != 5);



    clearPlaylist(&playlistHead);


    return 0;
}