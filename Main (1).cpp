#include <iostream>
#include <string>
#include <ctime>
#include "SortAlgorithms.h" 

int main() {
    
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // VOTE COUNTING SYSTEM
    const int VOTE_SIZE = 101; // Array A[0...100]
    int votes[VOTE_SIZE];

    std::string candidates[5] = {
        "Bo Dalton Capistrano",
        "Cornelius Raymon Agustin",
        "Deja Jayla Banaga",
        "Lalla Brielle Yabut",
        "Franklin Relano Castro"
    };

    // Generate 101 random votes ranging from 1 to 5
    for (int i = 0; i < VOTE_SIZE; i++) {
        votes[i] = (std::rand() % 5) + 1;
    }

    // Sort the vote array using Insertion Sort
    insertionSort(votes, VOTE_SIZE);

    // Count frequencies per candidate
    int voteCounts[6] = {0}; // Indices 1-5 map to Candidates 1-5
    for (int i = 0; i < VOTE_SIZE; i++) {
        voteCounts[votes[i]]++;
    }

    // Determine winner
    int maxVotes = -1;
    int winningCandidateID = 1;

    for (int c = 1; c <= 5; c++) {
        if (voteCounts[c] > maxVotes) {
            maxVotes = voteCounts[c];
            winningCandidateID = c;
        }
    }

    // Print Results
    std::cout << "Sorted Vote Array:\n";
    for (int i = 0; i < VOTE_SIZE; i++) {
        std::cout << votes[i] << (i == VOTE_SIZE - 1 ? "" : ", ");
    }
    std::cout << "\n\n--- Vote Tallies ---\n";

    for (int c = 1; c <= 5; c++) {
        std::cout << "Candidate " << c << " (" << candidates[c - 1] << "): " 
                  << voteCounts[c] << " votes\n";
    }

    std::cout << "\nWINNER: Candidate " << winningCandidateID << " (" 
              << candidates[winningCandidateID - 1] << ") with " 
              << maxVotes << " votes!\n";

    return 0;
}