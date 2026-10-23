#ifndef MUSIC_PLAYLIST_H
#define MUSIC_PLAYLIST_H

#include <iostream>
#include <string>

class Song {
public:
    std::string songName;
    Song* nextSong;
};

// Creates a new song node
Song* createSongNode(const std::string& name)
{
    Song* newNode = new Song;

    newNode->songName = name;
    newNode->nextSong = newNode;

    return newNode;
}


// Adds a song to the playlist
void addSong(const std::string& name, Song** playlistHead)
{
    Song* newNode = createSongNode(name);

    // If playlist is empty
    if (*playlistHead == nullptr)
    {
        *playlistHead = newNode;
        return;
    }

    Song* tailNode = *playlistHead;

    while (tailNode->nextSong != *playlistHead)
    {
        tailNode = tailNode->nextSong;
    }

    tailNode->nextSong = newNode;
    newNode->nextSong = *playlistHead;
}


// Displays all songs in the playlist
void showPlaylist(Song* playlistHead)
{
    if (playlistHead == nullptr)
    {
        std::cout << "Playlist is empty." << std::endl;
        return;
    }

    Song* currentSong = playlistHead;
    int songCount = 1;

    do
    {
        std::cout << songCount << ". "
                  << currentSong->songName << std::endl;

        currentSong = currentSong->nextSong;
        songCount++;

    } while (currentSong != playlistHead);
}


// Plays all songs once
void playAllSongs(Song* playlistHead)
{
    if (playlistHead == nullptr)
    {
        std::cout << "Playlist is empty." << std::endl;
        return;
    }

    Song* currentSong = playlistHead;

    std::cout << "\nPlaying Playlist:" << std::endl;

    do
    {
        std::cout << currentSong->songName << std::endl;

        currentSong = currentSong->nextSong;

    } while (currentSong != playlistHead);
}


// Moves to the next song
void moveToNextSong(Song** currentSong)
{
    if (*currentSong == nullptr)
    {
        std::cout << "Playlist is empty." << std::endl;
        return;
    }

    *currentSong = (*currentSong)->nextSong;
}


// Removes a song from the playlist
void removeSong(int songNumber, Song** playlistHead, Song** currentSong)
{
    if (*playlistHead == nullptr)
    {
        std::cout << "Playlist is empty." << std::endl;
        return;
    }

    if (songNumber <= 0)
    {
        std::cout << "Invalid song number." << std::endl;
        return;
    }


    Song* removeNode = *playlistHead;


    // Removing the first song
    if (songNumber == 1)
    {
        if (removeNode->nextSong == *playlistHead)
        {
            delete removeNode;
            *playlistHead = nullptr;
            *currentSong = nullptr;
            return;
        }


        Song* lastNode = *playlistHead;

        while (lastNode->nextSong != *playlistHead)
        {
            lastNode = lastNode->nextSong;
        }


        *playlistHead = removeNode->nextSong;
        lastNode->nextSong = *playlistHead;


        if (*currentSong == removeNode)
        {
            *currentSong = *playlistHead;
        }


        delete removeNode;
        return;
    }


    Song* previousNode = *playlistHead;
    Song* targetNode = (*playlistHead)->nextSong;

    int counter = 2;


    while (targetNode != *playlistHead &&
           counter < songNumber)
    {
        previousNode = targetNode;
        targetNode = targetNode->nextSong;
        counter++;
    }


    if (targetNode == *playlistHead)
    {
        std::cout << "Invalid song number." << std::endl;
        return;
    }


    previousNode->nextSong = targetNode->nextSong;


    if (*currentSong == targetNode)
    {
        *currentSong = targetNode->nextSong;
    }


    delete targetNode;
}


// Deletes the entire playlist
void clearPlaylist(Song** playlistHead)
{
    if (*playlistHead == nullptr)
    {
        return;
    }


    Song* currentSong = (*playlistHead)->nextSong;


    while (currentSong != *playlistHead)
    {
        Song* temporary = currentSong;

        currentSong = currentSong->nextSong;

        delete temporary;
    }


    delete *playlistHead;

    *playlistHead = nullptr;
}


#endif